/***************************************************************************
**                                                                        **
**  QCustomPlot, a simple to use, modern plotting widget for Qt           **
**  Copyright (C) 2011, 2012 Emanuel Eichhammer                           **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
**                                                                        **
****************************************************************************
**           Author: Emanuel Eichhammer                                   **
**  Website/Contact: http://www.WorksLikeClockwork.com/                   **
**             Date: 09.06.12                                             **
****************************************************************************/

#include "layoutelement-axisrect.h"

#include "../painter.h"
#include "../core.h"
#include "../plottable.h"
#include "../plottables/plottable-graph.h"
#include "../item.h"
#include "../axis.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////// QCPAxisRect
////////////////////////////////////////////////////////////////////////////////////////////////////


QCPAxisRect::QCPAxisRect(QCustomPlot *parentPlot, bool setupDefaultAxes) :
  QCPLayerable(parentPlot, "background"),
  mBackgroundBrush(Qt::NoBrush),
  mBackgroundScaled(true),
  mBackgroundScaledMode(Qt::KeepAspectRatioByExpanding),
  mInsetLayout(new QCPLayoutInset),
  mRangeDrag(Qt::Horizontal|Qt::Vertical),
  mRangeZoom(Qt::Horizontal|Qt::Vertical),
  mRangeZoomFactorHorz(0.85),
  mRangeZoomFactorVert(0.85),
  mDragging(false)
{
  setMinimumSize(50, 50);
  setMinimumMargins(QMargins(15, 15, 15, 15));
  mAxes.insert(QCPAxis::atLeft, QList<QCPAxis*>());
  mAxes.insert(QCPAxis::atRight, QList<QCPAxis*>());
  mAxes.insert(QCPAxis::atTop, QList<QCPAxis*>());
  mAxes.insert(QCPAxis::atBottom, QList<QCPAxis*>());
  
  if (setupDefaultAxes)
  {
    QCPAxis *yAxis = addAxis(QCPAxis::atLeft);
    QCPAxis *yAxis2 = addAxis(QCPAxis::atRight);
    QCPAxis *xAxis2 = addAxis(QCPAxis::atTop);
    QCPAxis *xAxis = addAxis(QCPAxis::atBottom);
    setRangeDragAxes(xAxis, yAxis);
    setRangeZoomAxes(xAxis, yAxis);
    xAxis->setGrid(true);
    yAxis->setGrid(true);
    xAxis2->setGrid(false);
    yAxis2->setGrid(false);
    xAxis2->setZeroLinePen(Qt::NoPen);
    yAxis2->setZeroLinePen(Qt::NoPen);
    xAxis2->setVisible(false);
    yAxis2->setVisible(false);
  }
}

QCPAxisRect::~QCPAxisRect()
{
  delete mInsetLayout;
  mInsetLayout = 0;
  
  QList<QCPAxis*> axesList = axes();
  for (int i=0; i<axesList.size(); ++i)
    removeAxis(axesList.at(i));
}

int QCPAxisRect::axisCount(QCPAxis::AxisType type) const
{
  return mAxes.value(type).size();
}

QCPAxis *QCPAxisRect::axis(QCPAxis::AxisType type, int index) const
{
  QList<QCPAxis*> ax(mAxes.value(type));
  if (index >= 0 && index < ax.size())
  {
    return ax.at(index);
  } else
  {
    qDebug() << Q_FUNC_INFO << "Axis index out of bounds:" << index;
    return 0;
  }
}

QList<QCPAxis*> QCPAxisRect::axes(QCPAxis::AxisTypes types) const
{
  QList<QCPAxis*> result;
  if (types.testFlag(QCPAxis::atLeft))
    result << mAxes.value(QCPAxis::atLeft);
  if (types.testFlag(QCPAxis::atRight))
    result << mAxes.value(QCPAxis::atRight);
  if (types.testFlag(QCPAxis::atTop))
    result << mAxes.value(QCPAxis::atTop);
  if (types.testFlag(QCPAxis::atBottom))
    result << mAxes.value(QCPAxis::atBottom);
  return result;
}

QList<QCPAxis*> QCPAxisRect::axes() const
{
  QList<QCPAxis*> result;
  QHashIterator<QCPAxis::AxisType, QList<QCPAxis*> > it(mAxes);
  while (it.hasNext())
  {
    it.next();
    result << it.value();
  }
  return result;
}

QCPAxis *QCPAxisRect::addAxis(QCPAxis::AxisType type)
{
  QCPAxis *newAxis = new QCPAxis(this, type);
  if (mAxes[type].size() > 0) // multiple axes on one side, add half-bar axis ending to additional axes with offset
  {
    bool invert = (type == QCPAxis::atRight) || (type == QCPAxis::atBottom);
    newAxis->setLowerEnding(QCPLineEnding(QCPLineEnding::esHalfBar, 6, 10, !invert));
    newAxis->setUpperEnding(QCPLineEnding(QCPLineEnding::esHalfBar, 6, 10, invert));
  }
  mAxes[type].append(newAxis);
  return newAxis;
}

QList<QCPAxis*> QCPAxisRect::addAxes(QCPAxis::AxisTypes types)
{
  QList<QCPAxis*> result;
  if (types.testFlag(QCPAxis::atLeft))
    result << addAxis(QCPAxis::atLeft);
  if (types.testFlag(QCPAxis::atRight))
    result << addAxis(QCPAxis::atRight);
  if (types.testFlag(QCPAxis::atTop))
    result << addAxis(QCPAxis::atTop);
  if (types.testFlag(QCPAxis::atBottom))
    result << addAxis(QCPAxis::atBottom);
  return result;
}

bool QCPAxisRect::removeAxis(QCPAxis *axis)
{
  // don't access axis->axisType() to provide safety when axis is an invalid pointer, rather go through all axis containers:
  QHashIterator<QCPAxis::AxisType, QList<QCPAxis*> > it(mAxes);
  while (it.hasNext())
  {
    it.next();
    if (it.value().contains(axis))
    {
      mAxes[it.key()].removeOne(axis);
      parentPlot()->axisRemoved(axis);
      delete axis;
      return true;
    }
  }
  qDebug() << Q_FUNC_INFO << "Axis isn't in axis rect:" << reinterpret_cast<quintptr>(axis);
  return false;
}

/*!
  Convenience function to create an axis on each side, if non-existent, and assign the top and
  right axes the following properties from the bottom/left axes:
  
  \li range (\ref QCPAxis::setRange)
  \li range reversed (\ref QCPAxis::setRangeReversed)
  \li scale type (\ref QCPAxis::setScaleType)
  \li scale log base  (\ref QCPAxis::setScaleLogBase)
  \li ticks (\ref QCPAxis::setTicks)
  \li auto (major) tick count (\ref QCPAxis::setAutoTickCount)
  \li sub tick count (\ref QCPAxis::setSubTickCount)
  \li auto sub ticks (\ref QCPAxis::setAutoSubTicks)
  \li tick step (\ref QCPAxis::setTickStep)
  \li auto tick step (\ref QCPAxis::setAutoTickStep)
  
  Tick labels (\ref QCPAxis::setTickLabels) however, is always set to false.

  If \a connectRanges is true, this function additionally connects the rangeChanged signals of the
  bottom and left axes to the \ref QCPAxis::setRange slots of the top and right axes in order to
  synchronize the ranges permanently.
*/
void QCPAxisRect::setupFullAxesBox(bool connectRanges)
{
  QCPAxis *xAxis, *yAxis, *xAxis2, *yAxis2;
  if (axisCount(QCPAxis::atBottom) == 0)
    xAxis = addAxis(QCPAxis::atBottom);
  else
    xAxis = axis(QCPAxis::atBottom);
  
  if (axisCount(QCPAxis::atLeft) == 0)
    yAxis = addAxis(QCPAxis::atLeft);
  else
    yAxis = axis(QCPAxis::atLeft);
  
  if (axisCount(QCPAxis::atTop) == 0)
    xAxis2 = addAxis(QCPAxis::atTop);
  else
    xAxis2 = axis(QCPAxis::atTop);
  
  if (axisCount(QCPAxis::atRight) == 0)
    yAxis2 = addAxis(QCPAxis::atRight);
  else
    yAxis2 = axis(QCPAxis::atRight);
  
  xAxis2->setVisible(true);
  xAxis2->setTickLabels(false);
  if (xAxis)
  {
    xAxis2->setAutoSubTicks(xAxis->autoSubTicks());
    xAxis2->setAutoTickCount(xAxis->autoTickCount());
    xAxis2->setAutoTickStep(xAxis->autoTickStep());
    xAxis2->setScaleType(xAxis->scaleType());
    xAxis2->setScaleLogBase(xAxis->scaleLogBase());
    xAxis2->setTicks(xAxis->ticks());
    xAxis2->setSubTickCount(xAxis->subTickCount());
    xAxis2->setTickStep(xAxis->tickStep());
    xAxis2->setRange(xAxis->range());
    xAxis2->setRangeReversed(xAxis->rangeReversed());
  }
  
  yAxis2->setVisible(true);
  yAxis2->setTickLabels(false);
  if (yAxis)
  {
    yAxis2->setAutoSubTicks(yAxis->autoSubTicks());
    yAxis2->setAutoTickCount(yAxis->autoTickCount());
    yAxis2->setAutoTickStep(yAxis->autoTickStep());
    yAxis2->setScaleType(yAxis->scaleType());
    yAxis2->setScaleLogBase(yAxis->scaleLogBase());
    yAxis2->setTicks(yAxis->ticks());
    yAxis2->setSubTickCount(yAxis->subTickCount());
    yAxis2->setTickStep(yAxis->tickStep());
    yAxis2->setRange(yAxis->range());
    yAxis2->setRangeReversed(yAxis->rangeReversed());
  }
  
  if (connectRanges)
  {
    connect(xAxis, SIGNAL(rangeChanged(QCPRange)), xAxis2, SLOT(setRange(QCPRange)));
    connect(yAxis, SIGNAL(rangeChanged(QCPRange)), yAxis2, SLOT(setRange(QCPRange)));
  }
}

QList<QCPAbstractPlottable*> QCPAxisRect::plottables() const
{
  // Note: don't append all QCPAxis::plottables() into a list, because we might get duplicate entries
  QList<QCPAbstractPlottable*> result;
  for (int i=0; i<mParentPlot->mPlottables.size(); ++i)
  {
    if (mParentPlot->mPlottables.at(i)->keyAxis()->axisRect() == this ||mParentPlot->mPlottables.at(i)->valueAxis()->axisRect() == this)
      result.append(mParentPlot->mPlottables.at(i));
  }
  return result;
}

QList<QCPGraph*> QCPAxisRect::graphs() const
{
  // Note: don't append all QCPAxis::graphs() into a list, because we might get duplicate entries
  QList<QCPGraph*> result;
  for (int i=0; i<mParentPlot->mGraphs.size(); ++i)
  {
    if (mParentPlot->mGraphs.at(i)->keyAxis()->axisRect() == this || mParentPlot->mGraphs.at(i)->valueAxis()->axisRect() == this)
      result.append(mParentPlot->mGraphs.at(i));
  }
  return result;
}

QList<QCPAbstractItem *> QCPAxisRect::items() const
{
  // Note: don't append all QCPAxis::items() into a list, because we might get duplicate entries
  //       and miss those items that have this axis rect as clipAxisRect.
  QList<QCPAbstractItem*> result;
  for (int itemId=0; itemId<mParentPlot->mItems.size(); ++itemId)
  {
    if (mParentPlot->mItems.at(itemId)->clipAxisRect() == this)
    {
      result.append(mParentPlot->mItems.at(itemId));
      continue;
    }
    QList<QCPItemPosition*> positions = mParentPlot->mItems.at(itemId)->positions();
    for (int posId=0; posId<positions.size(); ++itemId)
    {
      if (positions.at(posId)->axisRect() == this ||
          positions.at(posId)->keyAxis()->axisRect() == this ||
          positions.at(posId)->valueAxis()->axisRect() == this)
      {
        result.append(mParentPlot->mItems.at(itemId));
        break;
      }
    }
  }
  return result;
}

void QCPAxisRect::update()
{
  // update axis tick vectors:
  QHashIterator<QCPAxis::AxisType, QList<QCPAxis*> > it(mAxes);
  while (it.hasNext())
  {
    it.next();
    for (int i=0; i<it.value().size(); ++i)
      it.value().at(i)->setupTickVectors();
  }
  
  QCPLayoutElement::update();
  
  // pass update call on to inset layout (doesn't happen automatically, because QCPAxisRect doesn't derive from QCPLayout):
  mInsetLayout->setOuterRect(rect());
  mInsetLayout->update();
}

QList<QCPLayoutElement*> QCPAxisRect::elements() const
{
  if (mInsetLayout)
    return mInsetLayout->elements();
  else
    return QList<QCPLayoutElement*>();
}

void QCPAxisRect::applyDefaultAntialiasingHint(QCPPainter *painter) const
{
  painter->setAntialiasing(false);
}

void QCPAxisRect::draw(QCPPainter *painter)
{
  drawBackground(painter);
}

/*!
  Sets \a pm as the axis background pixmap. The axis background pixmap will be drawn inside the
  axis rect, before anything else (e.g. the axes themselves, grids, graphs, etc.) is drawn. If the
  provided pixmap doesn't have the same size as the axis rect, scaling can be enabled with \ref
  setBackgroundScaled and the scaling mode (i.e. whether and how the aspect ratio is preserved) can
  be set with \ref setBackgroundScaledMode. To set all these options in one call, consider using
  the overloaded version of this function.

  \see setBackgroundScaled, setBackgroundScaledMode
*/
void QCPAxisRect::setBackground(const QPixmap &pm)
{
  mBackgroundPixmap = pm;
  mScaledBackgroundPixmap = QPixmap();
}

void QCPAxisRect::setBackground(const QBrush &brush)
{
  mBackgroundBrush = brush;
}

/*! \overload
  
  Allows setting the background pixmap of the axis rect, whether it shall be scaled and how it
  shall be scaled in one call.

  \see setBackground(const QPixmap &pm), setBackgroundScaled, setBackgroundScaledMode
*/
void QCPAxisRect::setBackground(const QPixmap &pm, bool scaled, Qt::AspectRatioMode mode)
{
  mBackgroundPixmap = pm;
  mScaledBackgroundPixmap = QPixmap();
  mBackgroundScaled = scaled;
  mBackgroundScaledMode = mode;
}

/*!
  Sets whether the axis background pixmap shall be scaled to fit the axis rect or not. If \a scaled
  is set to true, you may control whether and how the aspect ratio of the original pixmap is
  preserved with \ref setBackgroundScaledMode.
  
  Note that the scaled version of the original pixmap is buffered, so there is no performance
  penalty on replots. (Except when the axis rect is changed continuously.)
  
  \see setBackground, setBackgroundScaledMode
*/
void QCPAxisRect::setBackgroundScaled(bool scaled)
{
  mBackgroundScaled = scaled;
}

/*!
  If scaling of the axis background pixmap is enabled (\ref setBackgroundScaled), use this function to
  define whether and how the aspect ratio of the original pixmap passed to \ref setBackground is preserved.
  \see setBackground, setBackgroundScaled
*/
void QCPAxisRect::setBackgroundScaledMode(Qt::AspectRatioMode mode)
{
  mBackgroundScaledMode = mode;
}

/*!
  Returns the range drag axis of the \a orientation provided
  \see setRangeDragAxes
*/
QCPAxis *QCPAxisRect::rangeDragAxis(Qt::Orientation orientation)
{
  return (orientation == Qt::Horizontal ? mRangeDragHorzAxis.data() : mRangeDragVertAxis.data());
}

/*!
  Returns the range zoom axis of the \a orientation provided
  \see setRangeZoomAxes
*/
QCPAxis *QCPAxisRect::rangeZoomAxis(Qt::Orientation orientation)
{
  return (orientation == Qt::Horizontal ? mRangeZoomHorzAxis.data() : mRangeZoomVertAxis.data());
}

/*!
  Returns the range zoom factor of the \a orientation provided
  \see setRangeZoomFactor
*/
double QCPAxisRect::rangeZoomFactor(Qt::Orientation orientation)
{
  return (orientation == Qt::Horizontal ? mRangeZoomFactorHorz : mRangeZoomFactorVert);
}

/*!
  Sets which axis orientation may be range dragged by the user with mouse interaction.
  What orientation corresponds to which specific axis can be set with
  \ref setRangeDragAxes(QCPAxis *horizontal, QCPAxis *vertical). By
  default, the horizontal axis is the bottom axis (xAxis) and the vertical axis
  is the left axis (yAxis).
  
  To disable range dragging entirely, pass 0 as \a orientations or remove \ref iRangeDrag from \ref
  setInteractions. To enable range dragging for both directions, pass <tt>Qt::Horizontal |
  Qt::Vertical</tt> as \a orientations.
  
  In addition to setting \a orientations to a non-zero value, make sure \ref setInteractions
  contains \ref iRangeDrag to enable the range dragging interaction.
  
  \see setRangeZoom, setRangeDragAxes, setNoAntialiasingOnDrag
*/
void QCPAxisRect::setRangeDrag(Qt::Orientations orientations)
{
  mRangeDrag = orientations;
}

/*!
  Sets which axis orientation may be zoomed by the user with the mouse wheel. What orientation
  corresponds to which specific axis can be set with \ref setRangeZoomAxes(QCPAxis *horizontal,
  QCPAxis *vertical). By default, the horizontal axis is the bottom axis (xAxis) and the vertical
  axis is the left axis (yAxis).

  To disable range zooming entirely, pass 0 as \a orientations or remove \ref iRangeZoom from \ref
  setInteractions. To enable range zooming for both directions, pass <tt>Qt::Horizontal |
  Qt::Vertical</tt> as \a orientations.
  
  In addition to setting \a orientations to a non-zero value, make sure \ref setInteractions
  contains \ref iRangeZoom to enable the range zooming interaction.
  
  \see setRangeZoomFactor, setRangeZoomAxes, setRangeDrag
*/
void QCPAxisRect::setRangeZoom(Qt::Orientations orientations)
{
  mRangeZoom = orientations;
}

/*!
  Sets the axes whose range will be dragged when \ref setRangeDrag enables mouse range dragging
  on the QCustomPlot widget.
  
  \see setRangeZoomAxes
*/
void QCPAxisRect::setRangeDragAxes(QCPAxis *horizontal, QCPAxis *vertical)
{
  mRangeDragHorzAxis = horizontal;
  mRangeDragVertAxis = vertical;
}

/*!
  Sets the axes whose range will be zoomed when \ref setRangeZoom enables mouse wheel zooming on the
  QCustomPlot widget. The two axes can be zoomed with different strengths, when different factors
  are passed to \ref setRangeZoomFactor(double horizontalFactor, double verticalFactor).
  
  \see setRangeDragAxes
*/
void QCPAxisRect::setRangeZoomAxes(QCPAxis *horizontal, QCPAxis *vertical)
{
  mRangeZoomHorzAxis = horizontal;
  mRangeZoomVertAxis = vertical;
}

/*!
  Sets how strong one rotation step of the mouse wheel zooms, when range zoom was activated with
  \ref setRangeZoom. The two parameters \a horizontalFactor and \a verticalFactor provide a way to
  let the horizontal axis zoom at different rates than the vertical axis. Which axis is horizontal
  and which is vertical, can be set with \ref setRangeZoomAxes.

  When the zoom factor is greater than one, scrolling the mouse wheel backwards (towards the user)
  will zoom in (make the currently visible range smaller). For zoom factors smaller than one, the
  same scrolling direction will zoom out.
*/
void QCPAxisRect::setRangeZoomFactor(double horizontalFactor, double verticalFactor)
{
  mRangeZoomFactorHorz = horizontalFactor;
  mRangeZoomFactorVert = verticalFactor;
}

/*! \overload
  
  Sets both the horizontal and vertical zoom \a factor.
*/
void QCPAxisRect::setRangeZoomFactor(double factor)
{
  mRangeZoomFactorHorz = factor;
  mRangeZoomFactorVert = factor;
}

/*! \internal
  
  Draws the background of this axis rect. It may consist of a background fill (a QBrush) and a
  pixmap.
  
  If a brush was given via \ref setBackground, this function first draws an according filling
  inside the axis rect with the provided \a painter.
  
  Then, if a pixmap was provided via \ref setBackground, this function buffers the scaled version
  depending on \ref setBackgroundScaled and \ref setBackgroundScaledMode and then draws it inside
  the axisRect with the provided \a painter. The scaled version is buffered in
  mScaledBackgroundPixmap to prevent expensive rescaling at every redraw. It is only updated, when
  the axis rect has changed in a way that requires a rescale of the background pixmap (this is
  dependant on the \ref setBackgroundScaledMode), or when a differend axis backgroud pixmap was
  set.
  
  \see setBackground, setBackgroundScaled, setBackgroundScaledMode
*/
void QCPAxisRect::drawBackground(QCPPainter *painter)
{
  // draw background fill:
  if (mBackgroundBrush != Qt::NoBrush)
    painter->fillRect(mRect, mBackgroundBrush);
  
  // draw background pixmap (on top of fill, if brush specified):
  if (!mBackgroundPixmap.isNull())
  {
    if (mBackgroundScaled)
    {
      // check whether mScaledBackground needs to be updated:
      QSize scaledSize(mBackgroundPixmap.size());
      scaledSize.scale(mRect.size(), mBackgroundScaledMode);
      if (mScaledBackgroundPixmap.size() != scaledSize)
        mScaledBackgroundPixmap = mBackgroundPixmap.scaled(mRect.size(), mBackgroundScaledMode, Qt::SmoothTransformation);
      painter->drawPixmap(mRect.topLeft(), mScaledBackgroundPixmap, QRect(0, 0, mRect.width(), mRect.height()) & mScaledBackgroundPixmap.rect());
    } else
    {
      painter->drawPixmap(mRect.topLeft(), mBackgroundPixmap, QRect(0, 0, mRect.width(), mRect.height()));
    }
  }
}

void QCPAxisRect::updateAxesOffset(QCPAxis::AxisType type)
{
  const QList<QCPAxis*> axesList = mAxes.value(type);
  for (int i=1; i<axesList.size(); ++i)
    axesList.at(i)->setOffset(axesList.at(i-1)->offset() + axesList.at(i-1)->calculateMargin() + axesList.at(i)->tickLengthIn());
}

int QCPAxisRect::calculateAutoMargin(QCP::MarginSide side)
{
  if (!mAutoMargins.testFlag(side))
    qDebug() << Q_FUNC_INFO << "Called with side that isn't specified as auto margin";
  
  updateAxesOffset(QCPAxis::marginSideToAxisType(side));
  
  // note: only need to look at the last (outer most) axis to determine the total margin, due to updateAxisOffset call
  const QList<QCPAxis*> axesList = mAxes.value(QCPAxis::marginSideToAxisType(side));
  if (axesList.size() > 0)
    return axesList.last()->offset() + axesList.last()->calculateMargin();
  else
    return 0;
}

void QCPAxisRect::mousePressEvent(QMouseEvent *event)
{
  mDragStart = event->pos(); // need this even when not LeftButton is pressed, to determine in releaseEvent whether it was a full click (no position change between press and release)
  if (event->buttons() & Qt::LeftButton)
  {
    mDragging = true;
    // initialize antialiasing backup in case we start dragging:
    if (mParentPlot->noAntialiasingOnDrag())
    {
      mAADragBackup = mParentPlot->antialiasedElements();
      mNotAADragBackup = mParentPlot->notAntialiasedElements();
    }
    // Mouse range dragging interaction:
    if (mParentPlot->interactions().testFlag(QCP::iRangeDrag))
    {
      if (mRangeDragHorzAxis)
        mDragStartHorzRange = mRangeDragHorzAxis.data()->range();
      if (mRangeDragVertAxis)
        mDragStartVertRange = mRangeDragVertAxis.data()->range();
    }
  }
}

void QCPAxisRect::mouseMoveEvent(QMouseEvent *event)
{
  // Mouse range dragging interaction:
  if (mDragging && mParentPlot->interactions().testFlag(QCP::iRangeDrag))
  {
    if (mRangeDrag.testFlag(Qt::Horizontal))
    {
      if (QCPAxis *rangeDragHorzAxis = mRangeDragHorzAxis.data())
      {
        if (rangeDragHorzAxis->mScaleType == QCPAxis::stLinear)
        {
          double diff = rangeDragHorzAxis->pixelToCoord(mDragStart.x()) - rangeDragHorzAxis->pixelToCoord(event->pos().x());
          rangeDragHorzAxis->setRange(mDragStartHorzRange.lower+diff, mDragStartHorzRange.upper+diff);
        } else if (rangeDragHorzAxis->mScaleType == QCPAxis::stLogarithmic)
        {
          double diff = rangeDragHorzAxis->pixelToCoord(mDragStart.x()) / rangeDragHorzAxis->pixelToCoord(event->pos().x());
          rangeDragHorzAxis->setRange(mDragStartHorzRange.lower*diff, mDragStartHorzRange.upper*diff);
        }
      }
    }
    if (mRangeDrag.testFlag(Qt::Vertical))
    {
      if (QCPAxis *rangeDragVertAxis = mRangeDragVertAxis.data())
      {
        if (rangeDragVertAxis->mScaleType == QCPAxis::stLinear)
        {
          double diff = rangeDragVertAxis->pixelToCoord(mDragStart.y()) - rangeDragVertAxis->pixelToCoord(event->pos().y());
          rangeDragVertAxis->setRange(mDragStartVertRange.lower+diff, mDragStartVertRange.upper+diff);
        } else if (rangeDragVertAxis->mScaleType == QCPAxis::stLogarithmic)
        {
          double diff = rangeDragVertAxis->pixelToCoord(mDragStart.y()) / rangeDragVertAxis->pixelToCoord(event->pos().y());
          rangeDragVertAxis->setRange(mDragStartVertRange.lower*diff, mDragStartVertRange.upper*diff);
        }
      }
    }
    if (mRangeDrag != 0) // if either vertical or horizontal drag was enabled, do a replot
    {
      if (mParentPlot->noAntialiasingOnDrag())
        mParentPlot->setNotAntialiasedElements(QCP::aeAll);
      mParentPlot->replot();
    }
  }
}

void QCPAxisRect::mouseReleaseEvent(QMouseEvent *event)
{
  Q_UNUSED(event)
  mDragging = false;
  if (mParentPlot->noAntialiasingOnDrag())
  {
    mParentPlot->setAntialiasedElements(mAADragBackup);
    mParentPlot->setNotAntialiasedElements(mNotAADragBackup);
  }
}

void QCPAxisRect::wheelEvent(QWheelEvent *event)
{
  // Mouse range zooming interaction:
  if (mParentPlot->interactions().testFlag(QCP::iRangeZoom))
  {
    if (mRangeZoom != 0)
    {
      double factor;
      double wheelSteps = event->delta()/120.0; // a single step delta is +/-120 usually
      if (mRangeZoom.testFlag(Qt::Horizontal))
      {
        factor = pow(mRangeZoomFactorHorz, wheelSteps);
        if (mRangeZoomHorzAxis.data())
          mRangeZoomHorzAxis.data()->scaleRange(factor, mRangeZoomHorzAxis.data()->pixelToCoord(event->pos().x()));
      }
      if (mRangeZoom.testFlag(Qt::Vertical))
      {
        factor = pow(mRangeZoomFactorVert, wheelSteps);
        if (mRangeZoomVertAxis.data())
          mRangeZoomVertAxis.data()->scaleRange(factor, mRangeZoomVertAxis.data()->pixelToCoord(event->pos().y()));
      }
      mParentPlot->replot();
    }
  }
}










