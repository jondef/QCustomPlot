/***************************************************************************
**                                                                        **
**  QCustomPlot, an easy to use, modern plotting widget for Qt            **
**  Copyright (C) 2011-2018 Emanuel Eichhammer                            **
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
**  Website/Contact: http://www.qcustomplot.com/                          **
**             Date: 25.06.18                                             **
**          Version: 2.0.1                                                **
****************************************************************************/

#ifndef QCP_PLOTTABLE1D_H
#define QCP_PLOTTABLE1D_H

#include "global.h"
#include "datacontainer.h"
#include "plottable.h"

class QCPPlottableInterface1D {
public:
    virtual ~QCPPlottableInterface1D() {}

    // introduced pure virtual methods:
    virtual int dataCount() const = 0;

    virtual double dataMainKey(int index) const = 0;

    virtual double dataSortKey(int index) const = 0;

    virtual double dataMainValue(int index) const = 0;

    virtual QCPRange dataValueRange(int index) const = 0;

    virtual QPointF dataPixelPosition(int index) const = 0;

    virtual bool sortKeyIsMainKey() const = 0;

    virtual QCPDataSelection selectTestRect(const QRectF &rect, bool onlySelectable) const = 0;

    virtual int findBegin(double sortKey, bool expandedRange = true) const = 0;

    virtual int findEnd(double sortKey, bool expandedRange = true) const = 0;
};

template<class DataType>
class QCPAbstractPlottable1D
        : public QCPAbstractPlottable, public QCPPlottableInterface1D // no QCP_LIB_DECL, template class ends up in header (cpp included below)
{
    // No Q_OBJECT macro due to template class

public:
    QCPAbstractPlottable1D(QCPAxis *keyAxis, QCPAxis *valueAxis);

    virtual ~QCPAbstractPlottable1D();

    // virtual methods of 1d plottable interface:
    virtual int dataCount() const Q_DECL_OVERRIDE;

    virtual double dataMainKey(int index) const Q_DECL_OVERRIDE;

    virtual double dataSortKey(int index) const Q_DECL_OVERRIDE;

    virtual double dataMainValue(int index) const Q_DECL_OVERRIDE;

    virtual QCPRange dataValueRange(int index) const Q_DECL_OVERRIDE;

    virtual QPointF dataPixelPosition(int index) const Q_DECL_OVERRIDE;

    virtual bool sortKeyIsMainKey() const Q_DECL_OVERRIDE;

    virtual QCPDataSelection selectTestRect(const QRectF &rect, bool onlySelectable) const Q_DECL_OVERRIDE;

    virtual int findBegin(double sortKey, bool expandedRange = true) const Q_DECL_OVERRIDE;

    virtual int findEnd(double sortKey, bool expandedRange = true) const Q_DECL_OVERRIDE;

    // reimplemented virtual methods:
    virtual double selectTest(const QPointF &pos, bool onlySelectable, QVariant *details = 0) const Q_DECL_OVERRIDE;

    virtual QCPPlottableInterface1D *interface1D() Q_DECL_OVERRIDE { return this; }

protected:
    // property members:
    QSharedPointer<QCPDataContainer<DataType> > mDataContainer;

    // helpers for subclasses:
    void getDataSegments(QList<QCPDataRange> &selectedSegments, QList<QCPDataRange> &unselectedSegments) const;

    void drawPolyline(QCPPainter *painter, const QVector<QPointF> &lineData) const;

private:
    Q_DISABLE_COPY(QCPAbstractPlottable1D)

};

// include implementation in header since it is a class template:
#include "plottable1d.cpp"

#endif // QCP_PLOTTABLE1D_H
