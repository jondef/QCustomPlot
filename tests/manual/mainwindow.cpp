#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  setGeometry(300, 300, 500, 500);
  mStatusBarLabel = new QLabel(this);
  ui->statusBar->addPermanentWidget(mStatusBarLabel);
  
  mCustomPlot = new QCustomPlot(this);
  QHBoxLayout *layout = new QHBoxLayout();
  ui->centralWidget->setLayout(layout);
  layout->insertWidget(0, mCustomPlot);
  mCustomPlot->axisRect()->setupFullAxesBox(true);
  connect(mCustomPlot, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(testbedMouseClick(QMouseEvent*)));
  connect(mCustomPlot, SIGNAL(afterReplot()), this, SLOT(showReplotTime()));
  
  presetInteractive(mCustomPlot);
  //setupItemAnchorTest(mCustomPlot);
  //setupItemTracerTest(mCustomPlot);
  //setupGraphTest(mCustomPlot);
  //setupExportTest(mCustomPlot);
  //setupExportMapTest(mCustomPlot);
  //setupLogErrorsTest(mCustomPlot);
  //setupLogCurveTest(mCustomPlot);
  //setupSelectTest(mCustomPlot);
  //setupDateTest(mCustomPlot);
  //setupIntegerTickStepCase(mCustomPlot);
  //setupTickLabelTest(mCustomPlot);
  //setupDaqPerformance(mCustomPlot);
  //setupLayoutTest(mCustomPlot);
  //setupMultiAxisTest(mCustomPlot);
  //setupLayoutElementBugTest(mCustomPlot);
  //setupMarginGroupTest(mCustomPlot);
  //setupInsetLayoutTest(mCustomPlot);
  //setupLegendTest(mCustomPlot);
  //setupMultiAxisRectInteractions(mCustomPlot);
  //setupAdaptiveSamplingTest(mCustomPlot);
  //setupColorMapTest(mCustomPlot);
  //setupBarsTest(mCustomPlot);
  //setupBarsGroupTest(mCustomPlot);
  //setupLargeDataSetDelete(mCustomPlot);
  //setupMultiValueGraph(mCustomPlot);
  //setupDataSelectTest(mCustomPlot);
  //setupErrorBarTest(mCustomPlot);
  //setupScatterSkipTest(mCustomPlot);
  //setupTimeZoneTest(mCustomPlot);
  setupPolarAxisTest(mCustomPlot);
  //setupTestbed(mCustomPlot);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::setupItemAnchorTest(QCustomPlot *customPlot)
{
  customPlot->xAxis->setRange(-3, 3);
  customPlot->yAxis->setRange(-3, 3);
  customPlot->xAxis->ticker()->setTickCount(5);
  customPlot->yAxis->ticker()->setTickCount(5);
 
  QCPItemPixmap *pixmapItem = new QCPItemPixmap(customPlot);
  pixmapItem->setPixmap(QPixmap("./gnu.png"));
  pixmapItem->setScaled(true);
  pixmapItem->topLeft->setCoords(-2, 2);
  pixmapItem->bottomRight->setCoords(-1, 1);
  labelItemAnchors(pixmapItem);
  
  QCPItemPixmap *pixmapItem2 = new QCPItemPixmap(customPlot);
  pixmapItem2->setPixmap(QPixmap("./gnu.png"));
  pixmapItem2->setScaled(true);
  pixmapItem2->topLeft->setCoords(1, 0.5);
  pixmapItem2->bottomRight->setCoords(0, 2);
  labelItemAnchors(pixmapItem2);
  
  QCPItemRect *rect = new QCPItemRect(customPlot);
  rect->topLeft->setCoords(-2, 0);
  rect->bottomRight->setCoords(-1, -0.5);
  labelItemAnchors(rect);
  
  QCPItemRect *rect2 = new QCPItemRect(customPlot);
  rect2->topLeft->setCoords(0, -1);
  rect2->bottomRight->setCoords(-0.5, 0);
  labelItemAnchors(rect2);
  
  QCPItemEllipse *ellipse = new QCPItemEllipse(customPlot);
  ellipse->topLeft->setCoords(0.5, 0);
  ellipse->bottomRight->setCoords(1, -1);
  labelItemAnchors(ellipse);
  
  QCPItemEllipse *ellipse2 = new QCPItemEllipse(customPlot);
  ellipse2->topLeft->setCoords(2, -1);
  ellipse2->bottomRight->setCoords(1.1, 0.2);
  labelItemAnchors(ellipse2);
  
  QCPItemLine *line = new QCPItemLine(customPlot);
  line->start->setCoords(-2, -1.5);
  line->end->setCoords(-1, -1.2);
  labelItemAnchors(line);
  
  QCPItemCurve *curve = new QCPItemCurve(customPlot);
  curve->start->setCoords(0, -1.5);
  curve->startDir->setCoords(1, -1.5);
  curve->endDir->setCoords(1, -1.2);
  curve->end->setCoords(2, -1.2);
  labelItemAnchors(curve);
  
  QCPItemBracket *bracket = new QCPItemBracket(customPlot);
  bracket->left->setCoords(-2, -2);
  bracket->right->setCoords(2, -2);
  bracket->setLength(12);
  labelItemAnchors(bracket);
  
  QCPItemText *text = new QCPItemText(customPlot);
  text->position->setCoords(0, -2.6);
  text->setText("QCustomPlot");
  text->setFont(QFont(font().family(), 26));
  text->setRotation(12);
  text->setPadding(QMargins(5, 5, 40, 5));
  text->setBrush(QBrush(QColor(0, 0, 0, 30)));
  labelItemAnchors(text);
}

void MainWindow::setupItemTracerTest(QCustomPlot *customPlot)
{
  QCPItemTracer *tracer1 = new QCPItemTracer(customPlot);
  tracer1->position->setCoords(1, 3);
  tracer1->setStyle(QCPItemTracer::tsCircle);
  tracer1->setSize(20);

  QCPItemTracer *tracer2 = new QCPItemTracer(customPlot);
  tracer2->position->setCoords(2, 2.5);
  tracer2->setStyle(QCPItemTracer::tsCrosshair);

  QCPItemTracer *tracer3 = new QCPItemTracer(customPlot);
  tracer3->position->setCoords(3, 2);
  tracer3->setStyle(QCPItemTracer::tsPlus);
  tracer3->setSize(20);

  QCPItemTracer *tracer4 = new QCPItemTracer(customPlot);
  tracer4->position->setCoords(4, 1.5);
  tracer4->setStyle(QCPItemTracer::tsSquare);
  tracer4->setSize(20);

  QCPGraph *graph = customPlot->addGraph();
  int n = 20;
  QVector<double> x(n), y(n);
  for (int i=0; i<n; ++i)
  {
    x[i] = 0.5+i/double(n)*4;
    y[i] = qSin(x[i])+1.5;
  }
  graph->setData(x, y);

  QCPItemTracer *graphTracer = new QCPItemTracer(customPlot);
  graphTracer->setGraph(graph);
  graphTracer->setGraphKey(2.3);
  graphTracer->setStyle(QCPItemTracer::tsNone);
  graphTracer->setInterpolating(true);
  tracerTestTracer = graphTracer;
  connect(customPlot, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(tracerTestMouseMove(QMouseEvent*)));
  graphTracer->setStyle(QCPItemTracer::tsSquare);

  QCPItemText *text = new QCPItemText(customPlot);
  text->setText("Tracer");
  text->setPositionAlignment(Qt::AlignBottom|Qt::AlignHCenter);
  text->position->setType(QCPItemPosition::ptAxisRectRatio);
  text->position->setCoords(0.5, 0.05);
  text->setPen(QPen());
  
  QCPItemText *vtext = new QCPItemText(customPlot);
  vtext->setText("Height");
  vtext->setPositionAlignment(Qt::AlignVCenter|Qt::AlignRight);
  vtext->position->setParentAnchorY(graphTracer->position);
  vtext->position->setTypeX(QCPItemPosition::ptAxisRectRatio);
  vtext->position->setCoords(1, 0);
  vtext->setPen(QPen());

  QCPItemCurve *curve = new QCPItemCurve(customPlot);
  curve->start->setParentAnchor(text->bottom);
  curve->startDir->setParentAnchor(curve->start);
  curve->startDir->setCoords(0, 100);
  curve->end->setParentAnchor(tracerTestTracer->position);
  curve->end->setCoords(0, -5);
  curve->endDir->setParentAnchor(curve->end);
  curve->endDir->setCoords(0, -100);
  curve->setHead(QCPLineEnding::esSpikeArrow);
}

void MainWindow::setupGraphTest(QCustomPlot *customPlot)
{
  customPlot->addGraph();

  QSharedPointer<QCPGraphDataContainer> data(new QCPGraphDataContainer);
  int n = 10e6;
  QElapsedTimer t;
  t.start();
  for (int i=0; i<n; ++i)
  {
    data->add(QCPGraphData(i, i));
  }
  qDebug() << "data" << t.restart();
  customPlot->graph(0)->setData(data);
  qDebug() << "set" << t.restart();
  customPlot->xAxis->setRange(0, 50);
  customPlot->yAxis->setRange(-1, 1);
  t.restart();
  customPlot->rescaleAxes();
  customPlot->replot();
  qDebug() << "replot" << t.restart();
  //customPlot->rescaleAxes();
}

void MainWindow::setupExportTest(QCustomPlot *customPlot)
{
  QDir dir("./");
  dir.mkdir("export-test");
  dir.cd("export-test");
  
  // test cosmetic/non-cosmetic pen and scaling of export functions:
  int n = 10;
  for (int penWidth=0; penWidth<5; ++penWidth)
  {
    QVector<double> x(n), y(n);
    for (int i=0; i<n; ++i)
    {
      x[i] = i;
      y[i] = qSin(i/2.0)+penWidth;
    }
    customPlot->addGraph();
    customPlot->graph()->setData(x, y);
    customPlot->graph()->setPen(QPen(Qt::blue, penWidth));
  }
  customPlot->rescaleAxes();
  qDebug() << customPlot->savePdf(dir.filePath("exportTest_cosmetic.pdf"), 500, 400, QCP::epAllowCosmetic);
  qDebug() << customPlot->savePdf(dir.filePath("exportTest_noncosmetic.pdf"), 500, 400, QCP::epNoCosmetic);
  qDebug() << customPlot->savePng(dir.filePath("exportTest_1x.png"), 500, 400);
  qDebug() << customPlot->savePng(dir.filePath("exportTest_2x.png"), 500, 400, 2);
  qDebug() << customPlot->saveJpg(dir.filePath("exportTest_1x.jpg"), 500, 400);
  qDebug() << customPlot->saveJpg(dir.filePath("exportTest_2x.jpg"), 500, 400, 2);
  customPlot->clearPlottables();
  
  // test floating-point precision of vectorized (pdf) export:
  QCPGraph *graph = customPlot->addGraph();
  QVector<double> x, y;
  for (int i=1; i<100; ++i)
  {
    x << 1.0 - 1.0/double(i);
    y << i;
  }
  x << 0.3 << 0.6; // point that should perfectly match grid
  y << 15 << 45; // point that should perfectly match grid
  graph->setData(x, y);
  graph->setLineStyle(QCPGraph::lsNone);
  graph->setScatterStyle(QCPScatterStyle::ssPlus);
  customPlot->xAxis->setRange(0, 1.1);
  customPlot->yAxis->setRange(0, 101);
  //customPlot->setAntialiasedElements(QCP::aeAll);
  qDebug() << customPlot->savePng(dir.filePath("float-precision-raster0.2x.png"), 500, 400, 0.2);
  qDebug() << customPlot->savePng(dir.filePath("float-precision-raster1x.png"), 500, 400);
  qDebug() << customPlot->savePng(dir.filePath("float-precision-raster5x.png"), 500, 400, 5);
  qDebug() << customPlot->savePdf(dir.filePath("float-precision-vector.pdf"), 500, 400);
  customPlot->clearPlottables();
  
  // test transparent/colored background:
  customPlot->addGraph();
  x.clear();
  y.clear();
  for (int i=0; i<100; ++i)
  {
    x << i;
    y << qSin(i/20.0);
  }
  customPlot->graph()->setData(x, y);
  customPlot->rescaleAxes();
  customPlot->setBackground(Qt::transparent);
  qDebug() << customPlot->savePng(dir.filePath("exportTest_bg_transparent.png"), 500, 400);
  qDebug() << customPlot->savePdf(dir.filePath("exportTest_bg_transparent.pdf"), 500, 400, QCP::epNoCosmetic);
  customPlot->setBackground(QColor(100, 100, 155));
  qDebug() << customPlot->savePng(dir.filePath("exportTest_bg_color.png"), 500, 400);
  qDebug() << customPlot->savePdf(dir.filePath("exportTest_bg_color.pdf"), 500, 400, QCP::epNoCosmetic);
  customPlot->clearPlottables();
  
  QTimer::singleShot(100, qApp, SLOT(quit()));
}

void MainWindow::setupExportMapTest(QCustomPlot *customPlot)
{
  QCPColorScale *s = new QCPColorScale(customPlot);
  customPlot->plotLayout()->addElement(0, 1, s);
  s->setDataRange(QCPRange(0, 10));
  s->setGradient(QCPColorGradient::gpPolar);
  QCPMarginGroup *group = new QCPMarginGroup(mCustomPlot);
  s->setMarginGroup(QCP::msBottom|QCP::msTop, group);
  mCustomPlot->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, group);
  
  QCPColorMap *m = new QCPColorMap(customPlot->xAxis, customPlot->yAxis);
  m->data()->setSize(3, 3);
  m->data()->setRange(QCPRange(10, 100), QCPRange(10, 1000));
  m->data()->setCell(0, 0, 1);
  m->data()->setCell(0, 1, 2);
  m->data()->setCell(0, 2, 3);
  m->data()->setCell(1, 0, 6);
  m->data()->setCell(1, 1, 1);
  m->data()->setCell(1, 2, 2);
  m->data()->setCell(2, 0, 0);
  m->data()->setCell(2, 1, 5);
  m->data()->setCell(2, 2, 2);
  m->setColorScale(s);
  m->rescaleDataRange(true);
  m->setInterpolate(false);
  m->setTightBoundary(false);
  customPlot->xAxis->setScaleType(QCPAxis::stLogarithmic);
  customPlot->yAxis->setScaleType(QCPAxis::stLogarithmic);
  customPlot->xAxis->setRange(1, 1000);
  customPlot->yAxis->setRange(1, 10000);
  customPlot->setAntialiasedElement(QCP::aeAxes, true);
  customPlot->setAntialiasedElement(QCP::aeGrid, true);
  customPlot->savePdf("./out.pdf", 400, 300);
  customPlot->savePng("./out.png", 400, 300, 3.0);
}

void MainWindow::setupLogErrorsTest(QCustomPlot *customPlot)
{
  customPlot->yAxis->setScaleType(QCPAxis::stLogarithmic);
  customPlot->yAxis->setTicker(QSharedPointer<QCPAxisTickerLog>(new QCPAxisTickerLog));
  customPlot->yAxis->setNumberFormat("eb");
  customPlot->yAxis->setNumberPrecision(0);
  customPlot->yAxis->grid()->setSubGridVisible(true);
  int n = 11;
  QVector<double> x(n), y(n), yerr(n), xerr(n);
  for (int i=0; i<n; ++i)
  {
    x[i] = i;
    y[i] = i*0.11;
    yerr[i] = 0.5;
    xerr[i] = qAbs(qCos(i/2.0)*0.5);
  }
  customPlot->addGraph();
  customPlot->graph()->setScatterStyle(QCPScatterStyle::ssCross);
  customPlot->graph()->setData(x, y);
  
  QCPErrorBars *keyErrors = new QCPErrorBars(customPlot->xAxis, customPlot->yAxis);
  keyErrors->setErrorType(QCPErrorBars::etKeyError);
  keyErrors->setDataPlottable(customPlot->graph());
  keyErrors->setData(xerr);
  QCPErrorBars *valueErrors = new QCPErrorBars(customPlot->xAxis, customPlot->yAxis);
  valueErrors->setErrorType(QCPErrorBars::etValueError);
  valueErrors->setDataPlottable(customPlot->graph());
  valueErrors->setData(yerr);
  
  customPlot->rescaleAxes();
}

void MainWindow::setupLogCurveTest(QCustomPlot *customPlot)
{
  customPlot->yAxis->setScaleType(QCPAxis::stLogarithmic);
  customPlot->yAxis->setTicker(QSharedPointer<QCPAxisTickerLog>(new QCPAxisTickerLog));
  customPlot->yAxis2->setScaleType(QCPAxis::stLogarithmic);
  customPlot->yAxis2->setTicker(QSharedPointer<QCPAxisTickerLog>(new QCPAxisTickerLog));
  
  customPlot->xAxis->setScaleType(QCPAxis::stLogarithmic);
  customPlot->xAxis->setTicker(QSharedPointer<QCPAxisTickerLog>(new QCPAxisTickerLog));
  customPlot->xAxis2->setScaleType(QCPAxis::stLogarithmic);
  customPlot->xAxis2->setTicker(QSharedPointer<QCPAxisTickerLog>(new QCPAxisTickerLog));
  
  QCPCurve *curve =  new QCPCurve(customPlot->xAxis, customPlot->yAxis);
  curve->addData(3, 1);
  curve->addData(2, 30);
  curve->addData(1, 1);
  curve->addData(4, 3);
  
  //customPlot->xAxis->setRangeReversed(true);
  //customPlot->yAxis->setRangeReversed(true);
  
  customPlot->rescaleAxes();
}

void MainWindow::setupSelectTest(QCustomPlot *customPlot)
{
  customPlot->axisRect()->setAutoMargins(QCP::msNone);
  customPlot->axisRect()->setMargins(QMargins(40, 10, 10, 20));
  customPlot->xAxis->setRange(-10, 10);
  customPlot->yAxis->setRange(-10, 10);
  
  QBrush defaultBrush(QColor(255,255,255,30));
  //defaultBrush = Qt::NoBrush;
  
  /*
  // QCPItemPixmap
  QCPItemPixmap *pixmapItem = new QCPItemPixmap(customPlot);
  pixmapItem->setPixmap(QPixmap("./gnu.png"));
  pixmapItem->setScaled(true, Qt::IgnoreAspectRatio);
  pixmapItem->topLeft->setCoords(-0.2, 1);
  pixmapItem->bottomRight->setCoords(0.3, 0);
  QCPItemPixmap *pixmapItem2 = new QCPItemPixmap(customPlot);
  pixmapItem2->setPixmap(QPixmap("./gnu.png"));
  pixmapItem2->setScaled(true, Qt::IgnoreAspectRatio);
  pixmapItem2->topLeft->setCoords(1.2, 0);
  pixmapItem2->bottomRight->setCoords(0.7, 1);
  
  // QCPItemRect
  QCPItemRect *rect = new QCPItemRect(customPlot);
  rect->setBrush(defaultBrush);
  rect->topLeft->setCoords(0, 1);
  rect->bottomRight->setCoords(1, 0);
  
  // QCPItemEllipse
  QCPItemEllipse *ellipse = new QCPItemEllipse(customPlot);
  ellipse->setBrush(defaultBrush);
  ellipse->topLeft->setCoords(-0.15, 1.1);
  ellipse->bottomRight->setCoords(1.15, 0);
  

  // QCPItemLine
  QCPItemLine *line = new QCPItemLine(customPlot);
  line->start->setCoords(-0.1, 0.8);
  line->end->setCoords(1.1, 0.2);
  line->setHead(QCPLineEnding::esSpikeArrow);
  
  // QCPItemStraightLine
  QCPItemStraightLine *straightLine = new QCPItemStraightLine(customPlot);
  straightLine->point1->setCoords(0, 0.4);
  straightLine->point2->setCoords(1, 0.6);

  // QCPItemCurve
  QCPItemCurve *curve = new QCPItemCurve(customPlot);
  curve->start->setCoords(0, 1);
  curve->startDir->setCoords(0.5, 1);
  curve->endDir->setCoords(0.7, 0.2);
  curve->end->setCoords(1, 0);
  curve->setHead(QCPLineEnding::esSpikeArrow);
  curve->setTail(QCPLineEnding::esLineArrow);

  // QCPItemBracket
  QCPItemBracket *bracket = new QCPItemBracket(customPlot);
  bracket->left->setCoords(-0.2, 0.35);
  bracket->right->setCoords(1.2, 0.65);
  bracket->setLength(22);
  
  // QCPFinancial:
  QCPFinancial *f = new QCPFinancial(customPlot->xAxis, customPlot->yAxis);
  QVector<double> key, open, high, low, close;
  open <<190.16<<184.67<<182.26<<178.59<<201.35<<207.28<<216.61<<210.91<<207.73<<207.89<<206.92<<198.51<<199.85<<207.86<<207.99<<218.64<<204.38<<198.12<<199.11<<193.91;
  high <<191.34<<187.19<<183.4<<194.4<<210.2<<218.6596<<217.69<<211.36<<214.02<<208.16<<207.149<<203.7899<<206.7<<212.8<<216.74<<219.33<<206.2<<202.29<<199.99<<199.29;
  low <<183<<179.88<<177.22<<178<<197.25<<206.85<<208.52<<206.52<<205.69<<201.28<<195.5301<<190.5<<197.65<<203.2<<207<<205.01<<194<<194.08<<190.82<<184.32;
  close <<183.76<<183.87<<179.86<<182<<209.64<<216.6<<209.48<<208.6<<207.08<<203.6<<198.21<<200<<202<<210.81<<216.33<<206.36<<197.08<<199.61<<197<<199.09;
  for (int i=0; i<open.size(); ++i)
    key << i;
  f->setData(key, open, high, low, close);
  f->setChartStyle(QCPFinancial::csCandlestick);
  //customPlot->yAxis->setRangeReversed(true);
  //customPlot->xAxis->setRangeReversed(true);
  customPlot->xAxis->setRange(-2, 22);
  customPlot->yAxis->setRange(160, 220);
  */
  
  // QCPGraph:
  QCPGraph *g = customPlot->addGraph();
  g->addData(QVector<double>() << -15 << -12 << -5 << 0 << 0.1 << 0.1 << 5 << 10 << 11,
             QVector<double>() << 0 << -5 << 5 << 0 << 6 << -2 << 4 << 7 << 5);
  
  connect(customPlot, SIGNAL(beforeReplot()), this, SLOT(selectTestColorMapRefresh()));
}

void MainWindow::setupDateTest(QCustomPlot *customPlot)
{
  customPlot->xAxis->setTicker(QSharedPointer<QCPAxisTicker>(new QCPAxisTickerDateTime));
  customPlot->xAxis->setRange(QDateTime(QDate(2015, 1, 1).startOfDay()).toMSecsSinceEpoch()/1000.0,
                              QDateTime(QDate(2020, 1, 1).startOfDay()).toMSecsSinceEpoch()/1000.0);
  QCPGraph *g = customPlot->addGraph();
  g->addData(QCPAxisTickerDateTime::dateTimeToKey(QDate(2015,1,1)), 1);
  g->addData(QCPAxisTickerDateTime::dateTimeToKey(QDate(2015,6,1)), 2);
  g->addData(QCPAxisTickerDateTime::dateTimeToKey(QDate(2015,6,12)), 4);
  g->addData(QCPAxisTickerDateTime::dateTimeToKey(QDate(2017,12,15)), 8);
  g->rescaleAxes();
}

void MainWindow::setupTickLabelTest(QCustomPlot *customPlot)
{
  customPlot->axisRect()->setupFullAxesBox();
  customPlot->xAxis2->setTickLabels(true);
  customPlot->yAxis2->setTickLabels(true);
  connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
  connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));
  customPlot->setPlottingHint(QCP::phCacheLabels, false);
  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(tickLabelTestTimerSlot()));
  timer->start(1000);
  connect(customPlot, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(mouseMoveRotateTickLabels(QMouseEvent*)));
}

void MainWindow::setupDaqPerformance(QCustomPlot *customPlot)
{
  customPlot->addGraph();
  customPlot->yAxis->setRange(-1, 1);
  mReplotTimer.setInterval(25);
  mDataTimer.setInterval(0);
  connect(&mReplotTimer, SIGNAL(timeout()), this, SLOT(daqPerformanceReplotSlot()));
  connect(&mDataTimer, SIGNAL(timeout()), this, SLOT(daqPerformanceDataSlot()));
  mReplotTimer.start();
  mDataTimer.start();
}

void MainWindow::setupLayoutTest(QCustomPlot *customPlot)
{
  
  QCPLayoutGrid *mainLayout = customPlot->plotLayout();
  mainLayout->removeAt(0);
  // create 3x3 grid:
  mainLayout->addElement(0, 0, new QCPAxisRect(customPlot));
  mainLayout->addElement(0, 1, new QCPAxisRect(customPlot));
  mainLayout->addElement(0, 2, new QCPAxisRect(customPlot));
  mainLayout->addElement(1, 0, new QCPAxisRect(customPlot));
  mainLayout->addElement(1, 1, new QCPAxisRect(customPlot));
  mainLayout->addElement(1, 2, new QCPAxisRect(customPlot));
  mainLayout->addElement(2, 0, new QCPAxisRect(customPlot));
  mainLayout->addElement(2, 1, new QCPAxisRect(customPlot));
  mainLayout->addElement(2, 2, new QCPAxisRect(customPlot));
  QList<QCPAxisRect*> rlist;
  for (int i=0; i<mainLayout->elementCount(); ++i)
  {
    rlist << qobject_cast<QCPAxisRect*>(mainLayout->elementAt(i));
    rlist.last()->addAxes(QCPAxis::atLeft|QCPAxis::atRight|QCPAxis::atTop|QCPAxis::atBottom);
  }
  
  mainLayout->setColumnStretchFactors(QList<double>() << 1 << 2 << 1);
  mainLayout->setRowStretchFactors(QList<double>() << 1 << 2 << 3);
  
  mainLayout->element(0, 0)->setMinimumSize(200, 100);
  mainLayout->element(0, 1)->setMaximumSize(150, 100);
  mainLayout->element(2, 2)->setMinimumSize(100, 100);
  
  
  /*
  customPlot->setFont(QFont(customPlot->font().family(), 7));
  customPlot->axisRect(0)->axis(QCPAxis::atRight)->setTickLabels(true);
  customPlot->axisRect(0)->axis(QCPAxis::atTop)->setTickLabels(true);
  customPlot->axisRect(0)->axis(QCPAxis::atLeft)->setTickLabelFont(customPlot->font());
  customPlot->axisRect(0)->axis(QCPAxis::atRight)->setTickLabelFont(customPlot->font());
  customPlot->axisRect(0)->axis(QCPAxis::atTop)->setTickLabelFont(customPlot->font());
  customPlot->axisRect(0)->axis(QCPAxis::atBottom)->setTickLabelFont(customPlot->font());
  
  QCPLayoutGrid *layout = customPlot->plotLayout();
  layout->setRowSpacing(8);
  layout->setColumnSpacing(8);
  layout->addElement(0, 1, new QCPAxisRect(customPlot));
  layout->addElement(1, 0, new QCPAxisRect(customPlot));
  
  QCPLayoutGrid *subLayout = new QCPLayoutGrid;
  subLayout->addElement(0, 0, new QCPAxisRect(customPlot));
  subLayout->addElement(0, 1, new QCPAxisRect(customPlot));
  subLayout->setColumnStretchFactor(0, 0.7);
  layout->addElement(1, 1, subLayout);
  
  QList<QCPAxisRect*> rects = customPlot->axisRects();
  for (int i=0; i<rects.size(); ++i)
  {
    rects.at(i)->addAxes(QCPAxis::atLeft|QCPAxis::atRight|QCPAxis::atTop|QCPAxis::atBottom);
    rects.at(i)->axis(QCPAxis::atLeft)->grid()->setVisible(true);
    rects.at(i)->axis(QCPAxis::atBottom)->grid()->setVisible(true);
  }
  
  QCPCurve *c = new QCPCurve(customPlot->xAxis, customPlot->yAxis);
  
  QCPCurveDataMap *d1 = new QCPCurveDataMap;
  d1->insert(0, QCPCurveData(0, 2, 1));
  d1->insert(1, QCPCurveData(1, 3, 2));
  d1->insert(2, QCPCurveData(2, 6, 4));
  
  c->data()->clear();
  c->setData(d1, false);
  
  QCPCurveDataMap *d2 = new QCPCurveDataMap;
  d2->insert(0, QCPCurveData(0, 26, 14));
  d2->insert(2, QCPCurveData(2, 31, 22));
  d2->insert(4, QCPCurveData(4, 61, 42));
  
  c->data->clear();
  c->setData(d2, false);
  
  customPlot->replot();
  */
  
  /*
  QCPLayoutGrid *topLayout = customPlot->plotLayout();
  QList<QCPAxisRect*> rects;
  for (int i=0; i<5; ++i)
    rects << new QCPAxisRect(customPlot);
  
  for (int i=0; i<rects.size(); ++i)
  {
    topLayout->addElement(0, i+1, rects.at(i));
    rects.at(i)->addAxis(QCPAxis::atLeft);
    rects.at(i)->addAxis(QCPAxis::atRight);
    rects.at(i)->addAxis(QCPAxis::atBottom);
    rects.at(i)->addAxis(QCPAxis::atTop);
    for (int k=0; k<rects.at(i)->axes().size(); ++k)
    {
      QCPAxis *ax = rects.at(i)->axes().at(k);
      ax->setTicks(false);
      ax->setTickLabels(false);
      ax->grid()->setVisible(false);
    }
    rects.at(i)->setAutoMargins(QCP::msNone);
    rects.at(i)->setMargins(QMargins(1, 1, 1, 1));
  }
  
  topLayout->setColumnStretchFactors(QList<double>() << 1 << 1e9 << 1e7 << 1e9 << 1e3 << 1e1);
  rects.at(0)->setMaximumSize(300, QWIDGETSIZE_MAX);
  rects.at(1)->setMaximumSize(250, QWIDGETSIZE_MAX);
  rects.at(2)->setMinimumSize(200, 0);
  rects.at(3)->setMaximumSize(150, QWIDGETSIZE_MAX);
  rects.at(4)->setMaximumSize(100, QWIDGETSIZE_MAX);
  
  QCPLayoutGrid *subLayout = new QCPLayoutGrid;
  topLayout->addElement(1, 3, subLayout);
  QCPAxisRect *r0 = new QCPAxisRect(customPlot);
  subLayout->addElement(0, 0, r0);
  r0->addAxes(QCPAxis::atLeft|QCPAxis::atRight|QCPAxis::atTop|QCPAxis::atBottom);
  QCPAxisRect *r1 = new QCPAxisRect(customPlot);
  subLayout->addElement(0, 1, r1);
  r1->addAxes(QCPAxis::atLeft|QCPAxis::atRight|QCPAxis::atTop|QCPAxis::atBottom);
  r1->setMaximumSize(200, QWIDGETSIZE_MAX);*/
}

void MainWindow::setupMultiAxisTest(QCustomPlot *customPlot)
{
  presetInteractive(customPlot);
  customPlot->axisRect()->removeAxis(customPlot->axisRect()->axis(QCPAxis::atRight));
  customPlot->axisRect()->removeAxis(customPlot->axisRect()->axis(QCPAxis::atTop));
  customPlot->axisRect()->addAxes(QCPAxis::atLeft|QCPAxis::atRight|QCPAxis::atTop|QCPAxis::atBottom);
  customPlot->axisRect()->addAxes(QCPAxis::atLeft|QCPAxis::atRight|QCPAxis::atTop|QCPAxis::atBottom);
  customPlot->axisRect()->addAxes(QCPAxis::atLeft|QCPAxis::atRight|QCPAxis::atTop|QCPAxis::atBottom);
  customPlot->axisRect()->addAxes(QCPAxis::atTop|QCPAxis::atRight);
  customPlot->axisRect()->axis(QCPAxis::atRight, 0)->setTickLabels(true);
  customPlot->axisRect()->axis(QCPAxis::atTop, 0)->setTickLabels(true);
  
  QList<QCPAxis*> dragZoomAxes;
  dragZoomAxes << customPlot->axisRect()->axis(QCPAxis::atTop, 2)
               << customPlot->axisRect()->axis(QCPAxis::atBottom, 3)
               << customPlot->axisRect()->axis(QCPAxis::atLeft, 3)
               << customPlot->axisRect()->axis(QCPAxis::atRight, 1)
               << customPlot->axisRect()->axis(QCPAxis::atRight, 0);
  
  customPlot->axisRect()->setRangeDragAxes(dragZoomAxes);
  customPlot->axisRect()->setRangeZoomAxes(dragZoomAxes);
}

void MainWindow::setupLayoutElementBugTest(QCustomPlot *customPlot)
{
  QCPLayoutGrid *topLayout = qobject_cast<QCPLayoutGrid*>(customPlot->plotLayout());
  
  QCPAxisRect *r = new QCPAxisRect(customPlot);
  r->addAxes(QCPAxis::atLeft);
  topLayout->addElement(0, 0, r);
}

void MainWindow::setupMarginGroupTest(QCustomPlot *customPlot)
{
  QCPLayoutGrid *topLayout =customPlot->plotLayout();
  
  QCPAxisRect *r = new QCPAxisRect(customPlot);
  topLayout->addElement(1, 0, r);
  r->addAxes(QCPAxis::atLeft|QCPAxis::atRight|QCPAxis::atBottom|QCPAxis::atTop);
  r->addAxes(QCPAxis::atLeft|QCPAxis::atRight|QCPAxis::atBottom|QCPAxis::atTop);
  
  QCPMarginGroup *group = new QCPMarginGroup(customPlot);
  topLayout->element(0, 0)->setMarginGroup(QCP::msAll, group);
  topLayout->element(1, 0)->setMarginGroup(QCP::msAll, group);
}

void MainWindow::setupInsetLayoutTest(QCustomPlot *customPlot)
{
  customPlot->addLayer("insetLayer");
  customPlot->setCurrentLayer("insetLayer");
  QCPAxisRect *insetAxRect = new QCPAxisRect(customPlot);
  insetAxRect->setMinimumSize(300, 250);
  customPlot->axisRect(0)->insetLayout()->addElement(insetAxRect, Qt::AlignRight|Qt::AlignTop);
  insetAxRect->setupFullAxesBox(true);
  insetAxRect->setBackground(QBrush(QColor(240, 240, 240)));
}

void MainWindow::setupLegendTest(QCustomPlot *customPlot)
{
  customPlot->legend->setVisible(true);
  //customPlot->legend->setMinimumSize(300, 150);
  //customPlot->axisRect()->setMinimumMargins(QMargins(15, 0, 15, 15));
  
  customPlot->addGraph()->setName("first graph");
  customPlot->addGraph()->setName("second longer graph");
  customPlot->addGraph()->setName("some stupid text\nthat has a line break\nand some more text");
  customPlot->addGraph()->setName("yadayada");
  //customPlot->legend->addElement(0, 1, customPlot->legend->element(3, 0));
  //customPlot->legend->addElement(1, 1, customPlot->legend->element(2, 0));
  customPlot->addGraph()->setName("yadayaasdda");
  customPlot->graph(3)->removeFromLegend();
  customPlot->graph(3)->addToLegend();
  
  QCPLayoutGrid *grid = customPlot->plotLayout();
  grid->addElement(1, 0, grid->element(0, 0));
  
  QCPTextElement *title = new QCPTextElement(customPlot);
  title->setText("This is a Plot Title");
  title->setFont(QFont(title->font().family(), 15, QFont::Bold));
  title->setSelectedFont(title->font());
  title->setSelectable(true);
  grid->addElement(0, 0, title);
  
  customPlot->graph(0)->addData(QVector<double>() << 1 << 2, QVector<double>() << 1 << 1.2);
}

void MainWindow::setupMultiAxisRectInteractions(QCustomPlot *customPlot)
{
  QCPAxisRect *r1 = new QCPAxisRect(customPlot);
  customPlot->plotLayout()->addElement(1, 0, r1);
  QCPAxisRect *r2 = new QCPAxisRect(customPlot);
  customPlot->plotLayout()->addElement(0, 1, r2);
  QCPAxisRect *r3 = new QCPAxisRect(customPlot);
  customPlot->plotLayout()->addElement(1, 1, r3);
  
  QCPAxisRect *inset = new QCPAxisRect(customPlot);
  inset->setMinimumSize(150, 120);
  inset->setupFullAxesBox(true);
  foreach (QCPAxis *ax, inset->axes())
    ax->ticker()->setTickCount(3);
  r3->insetLayout()->addElement(inset, Qt::AlignLeft|Qt::AlignTop);
  
  connect(mCustomPlot, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(setupMultiAxisRectInteractionsMouseMove(QMouseEvent*)));
}

void MainWindow::setupColorMapTest(QCustomPlot *customPlot)
{
  customPlot->legend->setVisible(true);
  presetInteractive(customPlot);
  QCPColorMap *colorMap = new QCPColorMap(customPlot->xAxis, customPlot->yAxis);
  colorMap->setName("Color Map");
  customPlot->addLayer("maplayer", customPlot->layer("grid"), QCustomPlot::limAbove);
  colorMap->setLayer("maplayer");
  
  int nx = 400;
  int ny = 400;
  colorMap->data()->setSize(nx, ny);
  colorMap->data()->setRange(QCPRange(0, 10), QCPRange(0, 10));
  colorMap->setInterpolate(true);
  colorMap->setTightBoundary(false);
  for (int x=0; x<nx; ++x)
  {
    for (int y=0; y<ny; ++y)
    {
      colorMap->data()->setCell(x, y, qExp(-qSqrt((x-310)*(x-310)+(y-260)*(y-260))/200.0)+
                                      qExp(-qSqrt((x-200)*(x-200)+(y-290)*(y-290))/80.0)-qExp(-qSqrt((x-180)*(x-180)+(y-140)*(y-140))/200.0));
      colorMap->data()->setAlpha(x, y, static_cast<unsigned char>(qBound(0.0, (1-((x-nx*0.5)*(x-nx*0.5)+(y-ny*0.5)*(y-ny*0.5))/double(nx*nx*0.25))*255.0, 255.0)));
    }
  }
  
  /* manual test of coordinate to cell transformations (and vice versa):
  connect(customPlot, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(colorMapMouseMove(QMouseEvent*)));
  colorMap->data()->setRange(QCPRange(0, 1), QCPRange(0, 1));
  colorMap->data()->setSize(2,2);
  colorMap->data()->setCell(0, 0, 0);
  colorMap->data()->setCell(0, 1, 0);
  colorMap->data()->setCell(1, 0, 2);
  colorMap->data()->setCell(1, 1, 4);
  */
  
  //customPlot->xAxis->setRangeReversed(true);
  //customPlot->yAxis->setRangeReversed(true);
  
  colorMap->setInterpolate(false);
  
  QCPColorScale *colorScale = new QCPColorScale(customPlot);
  customPlot->plotLayout()->addElement(0, 1, colorScale);
  colorMap->setColorScale(colorScale);
  colorScale->setLabel("test");
  
  QCPMarginGroup *group = new QCPMarginGroup(customPlot);
  colorScale->setMarginGroup(QCP::msTop|QCP::msBottom, group);
  customPlot->axisRect()->setMarginGroup(QCP::msTop|QCP::msBottom, group);
  
  QCPColorGradient gradient = colorMap->gradient();
  gradient.loadPreset(QCPColorGradient::gpJet);
  gradient.setPeriodic(false);
  gradient.setColorStopAt(0.5, QColor(255, 255, 255, 0));
  colorMap->setGradient(gradient);
  colorMap->rescaleDataRange(true);
  
  connect(customPlot, SIGNAL(beforeReplot()), colorMap, SLOT(updateLegendIcon()));
  customPlot->rescaleAxes();
  customPlot->replot();
}

void MainWindow::setupBarsTest(QCustomPlot *customPlot)
{
  QVector<double> datax = QVector<double>() << 2 << 3 << 4 << 5;
  QVector<double> datay1 = QVector<double>() << 0.2 << 0.3 << 0.4 << 0.5;
  QVector<double> datay2 = QVector<double>() << 0.5 << 0.4 << 0.3 << 0.2;
  QVector<double> datay3 = QVector<double>() << 0.1 << 0.2 << 0.1 << 0.2;
  QVector<double> datay1n = QVector<double>() << -0.2 << -0.3 << -0.4 << -0.5;
  QVector<double> datay2n = QVector<double>() << -0.5 << -0.4 << -0.3 << -0.2;
  QVector<double> datay3n = QVector<double>() << -0.1 << -0.2 << -0.1 << -0.2;
  
  customPlot->yAxis->setRangeReversed(false);
  QCPBars *bars;
  QCPAxis *keyAxis, *valueAxis;
  
  // stacked bars:
  keyAxis = customPlot->xAxis;
  valueAxis = customPlot->yAxis;
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay1);
  bars->setWidthType(QCPBars::wtAbsolute);
  bars->setWidth(50);
  bars->setBrush(QColor(255, 0, 0, 50));
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay2);
  bars->setWidthType(QCPBars::wtAxisRectRatio);
  bars->setWidth(0.05);
  bars->setBrush(QColor(0, 255, 0, 50));
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay3);
  bars->setWidthType(QCPBars::wtPlotCoords);
  bars->setWidth(0.25);
  bars->setBrush(QColor(0, 0, 255, 50));
  qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-2))->moveAbove(qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-3)));
  qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-1))->moveAbove(qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-2)));
  // stacked negative bars:
  keyAxis = customPlot->xAxis;
  valueAxis = customPlot->yAxis;
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay1n);
  bars->setWidthType(QCPBars::wtAbsolute);
  bars->setWidth(50);
  bars->setBrush(QColor(255, 0, 0, 50));
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay2n);
  bars->setWidthType(QCPBars::wtAxisRectRatio);
  bars->setWidth(0.05);
  bars->setBrush(QColor(0, 255, 0, 50));
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay3n);
  bars->setWidthType(QCPBars::wtPlotCoords);
  bars->setWidth(0.25);
  bars->setBrush(QColor(0, 0, 255, 50));
  qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-2))->moveAbove(qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-3)));
  qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-1))->moveAbove(qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-2)));
  
  // stacked bars with swapped x and y axis:
  keyAxis = customPlot->yAxis;
  valueAxis = customPlot->xAxis;
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay1);
  bars->setWidthType(QCPBars::wtAbsolute);
  bars->setWidth(50);
  bars->setBrush(QColor(255, 0, 0, 50));
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay2);
  bars->setWidthType(QCPBars::wtAxisRectRatio);
  bars->setWidth(0.05);
  bars->setBrush(QColor(0, 255, 0, 50));
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay3);
  bars->setWidthType(QCPBars::wtPlotCoords);
  bars->setWidth(0.25);
  bars->setBrush(QColor(0, 0, 255, 50));
  qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-2))->moveAbove(qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-3)));
  qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-1))->moveAbove(qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-2)));
  // stacked negative bars with swapped x and y axis:
  keyAxis = customPlot->yAxis;
  valueAxis = customPlot->xAxis;
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay1n);
  bars->setWidthType(QCPBars::wtAbsolute);
  bars->setWidth(50);
  bars->setBrush(QColor(255, 0, 0, 50));
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay2n);
  bars->setWidthType(QCPBars::wtAxisRectRatio);
  bars->setWidth(0.05);
  bars->setBrush(QColor(0, 255, 0, 50));
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay3n);
  bars->setWidthType(QCPBars::wtPlotCoords);
  bars->setWidth(0.25);
  bars->setBrush(QColor(0, 0, 255, 50));
  qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-2))->moveAbove(qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-3)));
  qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-1))->moveAbove(qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-2)));
  
  // stacked bars with base value offset:
  keyAxis = customPlot->xAxis;
  valueAxis = customPlot->yAxis;
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay1);
  bars->setBaseValue(2);
  bars->setWidthType(QCPBars::wtAbsolute);
  bars->setWidth(50);
  bars->setBrush(QColor(255, 0, 0, 50));
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay2);
  bars->setWidthType(QCPBars::wtAxisRectRatio);
  bars->setWidth(0.05);
  bars->setBrush(QColor(0, 255, 0, 50));
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay3);
  bars->setWidthType(QCPBars::wtPlotCoords);
  bars->setWidth(0.25);
  bars->setBrush(QColor(0, 0, 255, 50));
  qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-2))->moveAbove(qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-3)));
  qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-1))->moveAbove(qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-2)));
  // stacked negative bars with base value offset:
  keyAxis = customPlot->xAxis;
  valueAxis = customPlot->yAxis;
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay1n);
  bars->setBaseValue(2);
  bars->setWidthType(QCPBars::wtAbsolute);
  bars->setWidth(50);
  bars->setBrush(QColor(255, 0, 0, 50));
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay2n);
  bars->setWidthType(QCPBars::wtAxisRectRatio);
  bars->setWidth(0.05);
  bars->setBrush(QColor(0, 255, 0, 50));
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay3n);
  bars->setWidthType(QCPBars::wtPlotCoords);
  bars->setWidth(0.25);
  bars->setBrush(QColor(0, 0, 255, 50));
  qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-2))->moveAbove(qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-3)));
  qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-1))->moveAbove(qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-2)));
  
  // stacked bars with negative base value offset:
  keyAxis = customPlot->xAxis;
  valueAxis = customPlot->yAxis;
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay1);
  bars->setBaseValue(-2);
  bars->setWidthType(QCPBars::wtAbsolute);
  bars->setWidth(50);
  bars->setBrush(QColor(255, 0, 0, 50));
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay2);
  bars->setWidthType(QCPBars::wtAxisRectRatio);
  bars->setWidth(0.05);
  bars->setBrush(QColor(0, 255, 0, 50));
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay3);
  bars->setWidthType(QCPBars::wtPlotCoords);
  bars->setWidth(0.25);
  bars->setBrush(QColor(0, 0, 255, 50));
  qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-2))->moveAbove(qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-3)));
  qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-1))->moveAbove(qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-2)));
  // stacked negative bars with negative base value offset:
  keyAxis = customPlot->xAxis;
  valueAxis = customPlot->yAxis;
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay1n);
  bars->setBaseValue(-2);
  bars->setWidthType(QCPBars::wtAbsolute);
  bars->setWidth(50);
  bars->setBrush(QColor(255, 0, 0, 50));
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay2n);
  bars->setWidthType(QCPBars::wtAxisRectRatio);
  bars->setWidth(0.05);
  bars->setBrush(QColor(0, 255, 0, 50));
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay3n);
  bars->setWidthType(QCPBars::wtPlotCoords);
  bars->setWidth(0.25);
  bars->setBrush(QColor(0, 0, 255, 50));
  qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-2))->moveAbove(qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-3)));
  qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-1))->moveAbove(qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-2)));

  customPlot->rescaleAxes();
}

void MainWindow::setupBarsGroupTest(QCustomPlot *customPlot)
{
  QVector<double> datax = QVector<double>() << 2 << 5 << 8 << 11;
  QVector<double> datay1 = QVector<double>() << 0.2 << 0.3 << 0.4 << 0.5;
  QVector<double> datay2 = QVector<double>() << 0.5 << 0.4 << 0.3 << 0.2;
  QVector<double> datay3 = QVector<double>() << 0.1 << 0.2 << 0.1 << 0.2;
  
  QCPBarsGroup *group1 = new QCPBarsGroup(customPlot);
  QCPBarsGroup *group2 = new QCPBarsGroup(customPlot);
  QCPBars *bars;
  QCPAxis *keyAxis, *valueAxis;
  
  // 3 stacked bars:
  keyAxis = customPlot->xAxis;
  valueAxis = customPlot->yAxis;
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay1);
  bars->setBrush(QColor(255, 0, 0, 50));
  bars->setBarsGroup(group1);
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay2);
  bars->setBrush(QColor(0, 255, 0, 50));
  bars->setBarsGroup(group1);
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay3);
  bars->setBrush(QColor(0, 0, 255, 50));
  bars->setBarsGroup(group1);
  qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-2))->moveAbove(qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-3)));
  qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-1))->moveAbove(qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-2)));
  // 3 stacked bars:
  keyAxis = customPlot->xAxis;
  valueAxis = customPlot->yAxis;
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay1);
  bars->setBrush(QColor(255, 0, 0, 50));
  bars->setBarsGroup(group1);
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay2);
  bars->setBrush(QColor(0, 255, 0, 50));
  bars->setBarsGroup(group1);
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay3);
  bars->setBrush(QColor(0, 0, 255, 50));
  bars->setBarsGroup(group1);
  qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-2))->moveAbove(qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-3)));
  qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-1))->moveAbove(qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-2)));
  // 3 stacked bars:
  keyAxis = customPlot->xAxis;
  valueAxis = customPlot->yAxis;
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay1);
  bars->setBrush(QColor(255, 0, 0, 50));
  bars->setBarsGroup(group1);
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay2);
  bars->setBrush(QColor(0, 255, 0, 50));
  bars->setBarsGroup(group1);
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay3);
  bars->setBrush(QColor(0, 0, 255, 50));
  bars->setBarsGroup(group1);
  qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-2))->moveAbove(qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-3)));
  qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-1))->moveAbove(qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-2)));
  
  // 2 stacked bars:
  keyAxis = customPlot->xAxis;
  valueAxis = customPlot->yAxis;
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay1);
  bars->setBrush(QColor(255, 0, 0, 50));
  bars->setBarsGroup(group2);
  bars->setBaseValue(1);
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay3);
  bars->setBrush(QColor(0, 255, 0, 50));
  bars->setBarsGroup(group2);
  qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-1))->moveAbove(qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-2)));
  // 2 stacked bars:
  keyAxis = customPlot->xAxis;
  valueAxis = customPlot->yAxis;
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay3);
  bars->setBrush(QColor(255, 0, 0, 50));
  bars->setBarsGroup(group2);
  bars->setBaseValue(1);
  bars = new QCPBars(keyAxis, valueAxis);
  bars->setData(datax, datay2);
  bars->setBrush(QColor(0, 255, 0, 50));
  bars->setBarsGroup(group2);
  qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-1))->moveAbove(qobject_cast<QCPBars*>(customPlot->plottable(customPlot->plottableCount()-2)));
  
  customPlot->rescaleAxes();
}

void MainWindow::setupLargeDataSetDelete(QCustomPlot *customPlot)
{
#if QT_VERSION >= QT_VERSION_CHECK(4, 8, 0)
  // create large initial set that would take long to clear as a whole:
  QElapsedTimer timer;
  timer.start();
  for (int n=0; n<50; ++n)
  {
    QCPGraph *g = customPlot->addGraph();
    QSharedPointer<QCPGraphDataContainer> data(new QCPGraphDataContainer);
    for (int i=0; i<82000; ++i)
      data->add(QCPGraphData(i, n+rand()/double(RAND_MAX)*0.3));
    g->setData(data);
  }
  qDebug() << "create" << timer.nsecsElapsed()/1e6 << "ms";
  customPlot->rescaleAxes();
  customPlot->replot(QCustomPlot::rpImmediateRefresh);
  
  timer.start();
  customPlot->clearPlottables();
  qDebug() << "remove" << timer.nsecsElapsed()/1e6 << "ms";
  
  customPlot->replot(QCustomPlot::rpImmediateRefresh);
  
  // create next set right away:
  for (int n=0; n<10; ++n)
  {
    QCPGraph *g = customPlot->addGraph();
    QSharedPointer<QCPGraphDataContainer> data(new QCPGraphDataContainer);
    for (int i=0; i<5000; ++i)
      data->add(QCPGraphData(i, n+rand()/double(RAND_MAX)*0.3));
    g->setData(data);
  }
  customPlot->rescaleAxes();
  customPlot->replot(QCustomPlot::rpImmediateRefresh);
#else
  qDebug() << Q_FUNC_INFO << "unavailable in Qt < 4.7";
#endif
}

void MainWindow::setupMultiValueGraph(QCustomPlot *customPlot)
{
  QCPGraph *g = customPlot->addGraph();
  
  QVector<double> x, y;
  x << 1 << 2 << 3 << 4 << 3 << 5 << 3; // three values at key 3, with exit point in center but out of order key data
  y << 1 << 1 << 2 << 3 << 4 << 3 << 3;
  g->setData(x, y);
  
  // now merge with second dataset which lies in same key range and has own multi-key:
  QVector<double> u, v;
  u << 2.5 << 2.6 << 3.5 << 3.5 << 3.5 << 3.6; // three values at key 3.5, with exit point in center
  v << 0   << 0   << 0   << 0.5 << 0.25 << 0;
  g->addData(u, v);
  
  customPlot->rescaleAxes();
  customPlot->replot();
}

void MainWindow::setupErrorBarTest(QCustomPlot *customPlot)
{
  customPlot->axisRect()->setMinimumMargins(QMargins(100, 100, 100, 100));
  QCPAxis *keyAxis = customPlot->xAxis;
  QCPAxis *valueAxis = customPlot->yAxis;
  
  QCPCurve *graph = new QCPCurve(keyAxis, valueAxis);
  graph->setData(QVector<double>() << 1 << 2 << 3 << 4 << 2.5 << -2, QVector<double>() << -2 << 0 << 1 << 2 << 1.5 << 1.2);
  //graph->setScatterStyle(QCPScatterStyle::ssCircle);
  
  QCPErrorBars *keyErrors = new QCPErrorBars(keyAxis, valueAxis);
  keyErrors->setDataPlottable(graph);
  keyErrors->setData(QVector<double>() << 0.2 << 0.4 << 1.6 << 0.8 << 0.2 << 0.2, QVector<double>() << 0.2 << 0.2 << 2.2 << 0.2 << 0.2 << 0.2);
  keyErrors->setErrorType(QCPErrorBars::etKeyError);
  QCPErrorBars *valueErrors = new QCPErrorBars(keyAxis, valueAxis);
  valueErrors->setDataPlottable(graph);
  valueErrors->setData(QVector<double>() << 0.2 << 0.4 << 1.6 << 0.8 << 0.2 << 0.2, QVector<double>() << 0.2 << 0.2 << 2.2 << 0.2 << 0.2 << 0.2);
  valueErrors->setErrorType(QCPErrorBars::etValueError);
  valueErrors->setSelectable(QCP::stMultipleDataRanges);
}

void MainWindow::setupDataSelectTest(QCustomPlot *customPlot)
{
  std::srand(1);
  customPlot->setSelectionRectMode(QCP::srmSelect);
  
  QCPGraph *g = customPlot->addGraph();
  int n = 10000;
  QVector<double> x, y;
  x << -6;
  y << 2;
  for (int i=0; i<n/2; ++i)
  {
    x << i/double(n/2-1)*4-5;
    if (std::rand()%(n/25) == 0)
      y << std::rand()/double(RAND_MAX)*7; // generate outliers (must be preserved in adaptive-sampling-algorithm)
    else
      y << qCos(std::rand()/double(RAND_MAX)*2*M_PI)*qSqrt(-2*qLn(std::rand()/double(RAND_MAX))) + 5*qSin(x[i]);
  }
  x << 0.5;
  y << 2;
  for (int i=0; i<n/2; ++i)
  {
    x << i/double(n/2-1)*4+1;
    if (std::rand()%(n/25) == 0)
      y << std::rand()/double(RAND_MAX)*7; // generate outliers (must be preserved in adaptive-sampling-algorithm)
    else
      y << qCos(std::rand()/double(RAND_MAX)*2*M_PI)*qSqrt(-2*qLn(std::rand()/double(RAND_MAX))) + qSin(5*x[i]);
  }
  x << 6;
  y << -1;
  g->setData(x, y);
  g->setScatterStyle(QCPScatterStyle::ssPlus);
  g->setLineStyle(QCPGraph::lsLine);
  g->selectionDecorator()->setPen(QPen(Qt::red));
  g->selectionDecorator()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::red));
  g->selectionDecorator()->setUsedScatterProperties(QCPScatterStyle::spPen|QCPScatterStyle::spShape);
  g->setSelectable(QCP::stMultipleDataRanges);
  
  //g->setBrush(QBrush(QColor(100, 0, 255, 90)));
  //g->selectionDecorator()->setBrush(QBrush(QColor(255, 0, 50, 60)));
  
  QCPCurve *curve = new QCPCurve(customPlot->xAxis, customPlot->yAxis);
  curve->addData(QVector<double>() << 1 << 2 << 3 << 4 << 3 << 2 << 1, QVector<double>() << 5 << 4 << 7 << 8 << 2 << 1 << 1);
  curve->setScatterStyle(QCPScatterStyle::ssPlus);
  curve->selectionDecorator()->setPen(QPen(Qt::red));
  curve->selectionDecorator()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::red));
  curve->selectionDecorator()->setUsedScatterProperties(QCPScatterStyle::spPen|QCPScatterStyle::spShape);
  curve->setSelectable(QCP::stMultipleDataRanges);
  
  QCPStatisticalBox *statBox = new QCPStatisticalBox(customPlot->xAxis, customPlot->yAxis);
  statBox->addData(10, 1, 3, 3.5, 5, 7);
  statBox->addData(11, 2, 3.5, 5, 6, 7.5, QVector<double>() << 0 << 0.5 << 7.9 << 9 << 11);
  statBox->addData(12, 3, 4, 5, 6.5, 9);
  statBox->setSelectable(QCP::stMultipleDataRanges);
  
  QCPBars *bars = new QCPBars(customPlot->xAxis, customPlot->yAxis);
  bars->addData(13, 1);
  bars->addData(14, 2);
  bars->addData(15, 3);
  bars->setSelectable(QCP::stMultipleDataRanges);
  
  QCPFinancial *financial = new QCPFinancial(customPlot->xAxis, customPlot->yAxis);
  financial->addData(16, 1, 3, 0, 2.2);
  financial->addData(17, 2, 3.5, 1.2, 3.2);
  financial->addData(18, 3, 7, 2, 6);
  financial->setTwoColored(true);
  financial->setChartStyle(QCPFinancial::csCandlestick);
  financial->setSelectable(QCP::stMultipleDataRanges);
  
  customPlot->rescaleAxes();
}

void MainWindow::setupScatterSkipTest(QCustomPlot *customPlot)
{
  QCPCurve *c = new QCPCurve(customPlot->xAxis, customPlot->yAxis);
  c->setLineStyle(QCPCurve::lsLine);
  c->setScatterStyle(QCPScatterStyle::ssPlus);
  c->setScatterSkip(4);
  int n = 1000;
  for (int i=0; i<n; ++i)
    c->addData(qCos(i/double(n)*10*M_PI)*i/double(n)*2+2, qSin(i/double(n)*10*M_PI)*i/double(n)*2);
  
  QCPGraph *g = new QCPGraph(customPlot->xAxis, customPlot->yAxis);
  n = 10000;
  QVector<double> x, y;
  x << -6;
  y << 2;
  for (int i=0; i<n/2; ++i)
  {
    x << i/double(n/2-1)*4-5;
    if (std::rand()%(n/25) == 0)
      y << std::rand()/double(RAND_MAX)*7; // generate outliers (must be preserved in adaptive-sampling-algorithm)
    else
      y << qCos(std::rand()/double(RAND_MAX)*2*M_PI)*qSqrt(-2*qLn(std::rand()/double(RAND_MAX))) + 5*qSin(x[i]);
  }
  g->setData(x, y);
  g->setScatterStyle(QCPScatterStyle::ssPlus);
  g->setScatterSkip(4);
  
  customPlot->rescaleAxes();
}

void MainWindow::setupTimeZoneTest(QCustomPlot *customPlot)
{
# if QT_VERSION >= QT_VERSION_CHECK(5, 2, 0)
  QSharedPointer<QCPAxisTickerDateTime> ticker(new QCPAxisTickerDateTime);
  customPlot->xAxis->setTicker(ticker);
  QCPGraph *graph = customPlot->addGraph();
  
  double timeStamp = 1577883600; // Wednesday, January 1, 2020 13:00:00 (UTC)
  graph->setData({timeStamp+3600*0, timeStamp+3600*1, timeStamp+3600*2, timeStamp+3600*3}, {1.0, 2.0, 2.5, 2.75});
  
  ticker->setDateTimeFormat("yyyy-MM-dd\nhh:mm:ss");
  ticker->setTickOrigin(QDateTime(QDate(2020, 1, 15), QTime(17, 17, 17), QTimeZone("UTC")));
  //qDebug() << QTimeZone::availableTimeZoneIds();
  ticker->setTimeZone(QTimeZone("Europe/Berlin"));
  
  customPlot->xAxis->rescale();
  customPlot->xAxis->scaleRange(1.1);
# endif
}

void MainWindow::setupPolarAxisTest(QCustomPlot *customPlot)
{
  presetInteractive(customPlot);
  customPlot->setPlottingHint(QCP::phCacheLabels, true);
  customPlot->plotLayout()->clear();
  QCPPolarAxisAngular *polarAxis = new QCPPolarAxisAngular(customPlot);
  customPlot->plotLayout()->addElement(0, 0, polarAxis);
  QSharedPointer<QCPAxisTickerPi> ticker(new QCPAxisTickerPi);
  ticker->setPiValue(180);
  ticker->setTickCount(8);
  polarAxis->setTicker(ticker);
  polarAxis->setRangeDrag(true);
  polarAxis->setTickLabelMode(QCPPolarAxisAngular::lmUpright);
  
  polarAxis->radialAxis()->setTickLabelMode(QCPPolarAxisRadial::lmUpright);
  //polarAxis->radialAxis()->setScaleType(QCPPolarAxisRadial::stLogarithmic);
  //polarAxis->radialAxis()->setTicker(QSharedPointer<QCPAxisTicker>(new QCPAxisTickerLog));
  //polarAxis->radialAxis()->setRange(0.001, 1e1);
  polarAxis->radialAxis()->setTickLabelRotation(0);
  polarAxis->radialAxis()->setAngle(45);
  
  polarAxis->grid()->setAngularPen(QPen(QColor(200, 200, 200), 0, Qt::SolidLine));
  polarAxis->grid()->setSubGridType(QCPPolarGrid::gtAll);
  //polarAxis->radialAxis()->setRangeReversed(true);
  
  QCPPolarGraph *g1 = new QCPPolarGraph(polarAxis, polarAxis->radialAxis());
  QCPPolarGraph *g2 = new QCPPolarGraph(polarAxis, polarAxis->radialAxis());
  g2->setPen(QPen(QColor(255, 150, 20)));
  g2->setBrush(QColor(255, 150, 20, 50));
  g1->setScatterStyle(QCPScatterStyle::ssStar);
  for (int i=0; i<360; ++i)
  {
    g1->addData(i, qSin(i/360.0*M_PI*8)*8+1);
    g2->addData(i, qSin(i/360.0*M_PI*6)*2);
  }
  polarAxis->radialAxis()->rescale();
  
  /*
  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(tickLabelTestTimerSlot()));
  timer->start(2000);
  */
  //connect(customPlot, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(mouseMoveRotateAngularTickLabels(QMouseEvent*)));
}

void MainWindow::setupAdaptiveSamplingTest(QCustomPlot *customPlot)
{
  std::srand(1);
  QCPGraph *g = customPlot->addGraph();
  int n = 200000;
  QVector<double> x, y;
  x << -6;
  y << 2;
  for (int i=0; i<n/2; ++i)
  {
    x << i/double(n/2-1)*4-5;
    if (std::rand()%(n/25) == 0)
      y << std::rand()/double(RAND_MAX)*7; // generate outliers (must be preserved in adaptive-sampling-algorithm)
    else
      y << qCos(std::rand()/double(RAND_MAX)*2*M_PI)*qSqrt(-2*qLn(std::rand()/double(RAND_MAX))) + 5*qSin(x[i]);
  }
  x << 0.5;
  y << 2;
  for (int i=0; i<n/2; ++i)
  {
    x << i/double(n/2-1)*4+1;
    if (std::rand()%(n/25) == 0)
      y << std::rand()/double(RAND_MAX)*7; // generate outliers (must be preserved in adaptive-sampling-algorithm)
    else
      y << qCos(std::rand()/double(RAND_MAX)*2*M_PI)*qSqrt(-2*qLn(std::rand()/double(RAND_MAX))) + qSin(5*x[i]);
  }
  x << 6;
  y << -1;
  g->setData(x, y);
  //g->setScatterStyle(QCPScatterStyle::ssPlus);
  //g->setLineStyle(QCPGraph::lsNone);
  g->setAdaptiveSampling(true);
  
  customPlot->setPlottingHint(QCP::phFastPolylines, true);
  customPlot->rescaleAxes();
  customPlot->xAxis->scaleRange(1, customPlot->xAxis->range().center());
  customPlot->yAxis->scaleRange(1, customPlot->yAxis->range().center());
}

void MainWindow::presetInteractive(QCustomPlot *customPlot)
{
  customPlot->setInteractions(QCP::iRangeDrag|
                              QCP::iRangeZoom|
                              QCP::iSelectAxes|
                              QCP::iSelectItems|
                              QCP::iSelectLegend|
                              QCP::iSelectPlottables|
                              QCP::iSelectOther|
                              QCP::iMultiSelect);
  if (customPlot->axisRect())
  {
    customPlot->axisRect()->setRangeDrag(Qt::Horizontal|Qt::Vertical);
    customPlot->axisRect()->setRangeZoom(Qt::Horizontal|Qt::Vertical);
  }
  connect(customPlot, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(selectionRectChooser(QMouseEvent*)), Qt::UniqueConnection);
}

void MainWindow::labelItemAnchors(QCPAbstractItem *item, int fontSize, bool circle, bool labelBelow)
{
  QList<QCPItemAnchor*> anchors = item->anchors();
  for (int i=0; i<anchors.size(); ++i)
  {
    if (circle)
    {
      QCPItemEllipse *circ = new QCPItemEllipse(item->parentPlot());
      circ->topLeft->setParentAnchor(anchors.at(i));
      circ->bottomRight->setParentAnchor(anchors.at(i));
      circ->topLeft->setCoords(-4, -4);
      circ->bottomRight->setCoords(4, 4);
      QPen p(Qt::blue, 0, Qt::CustomDashLine);
#if (QT_VERSION >= QT_VERSION_CHECK(4, 8, 0)) // Qt 4.8 changed the meaning of this completely...
      p.setDashPattern(QVector<qreal>()<<2<<1);
#else
      p.setDashPattern(QVector<qreal>()<<1<<3);
#endif
      circ->setPen(p);
      if (dynamic_cast<QCPItemPosition*>(anchors.at(i)))
      {
        QCPItemEllipse *circ2 = new QCPItemEllipse(item->parentPlot());
        circ2->topLeft->setParentAnchor(anchors.at(i));
        circ2->bottomRight->setParentAnchor(anchors.at(i));
        circ2->topLeft->setCoords(-2.5, -2.5);
        circ2->bottomRight->setCoords(2.5, 2.5);
        circ2->setPen(Qt::NoPen);
        circ2->setBrush(Qt::blue);
      }
    }
    if (fontSize > 0)
    {
      QCPItemText *label = new QCPItemText(item->parentPlot());
      label->setFont(QFont(font().family(), fontSize));
      label->setColor(Qt::blue);
      label->setText(QString("%2 (%1)").arg(i).arg(anchors.at(i)->name()));
      label->position->setParentAnchor(anchors.at(i));
      if (circle)
        label->position->setCoords(0, fontSize*2*(labelBelow?1:-1));
      else
        label->position->setCoords(0, 0);
      label->setTextAlignment(Qt::AlignCenter);
    }
  }
}

void MainWindow::showSelectTestColorMap(QCustomPlot *customPlot)
{
  QImage colorMap(customPlot->axisRects().first()->size(), QImage::Format_RGB32);
  colorMap.fill(QColor(Qt::blue).rgb());
  int offsetx = customPlot->axisRects().first()->left();
  int offsety = customPlot->axisRects().first()->top();
  // for items:
  for (int i=0; i<customPlot->itemCount(); ++i)
  {
    QCPAbstractItem *item = customPlot->item(i);
    for (int y=0; y<colorMap.height(); ++y)
    {
      QRgb *p = reinterpret_cast<QRgb*>(colorMap.scanLine(y));
      for (int x=0; x<colorMap.width(); ++x)
      {
        double dist = item->selectTest(QPointF(x+offsetx, y+offsety), false);
        if (dist >= 0)
        {
          int r = qRed(p[x]);
          int g = qGreen(p[x]);
          int b = qBlue(p[x]);
          r += int(255.0/(dist*0.25+1.0));
          b += int(-255.0/(dist*0.25+1.0));
          if (qAbs(dist-customPlot->selectionTolerance()) < 0.5)
            g += 255;
          p[x] = qRgb(qBound(0, r, 255), qBound(0, g, 255), qBound(0, b, 255));
        }
      }
    }
  }
  // for plottables:
  for (int i=0; i<customPlot->plottableCount(); ++i)
  {
    QCPAbstractPlottable *plottable = customPlot->plottable(i);
    for (int y=0; y<colorMap.height(); ++y)
    {
      QRgb *p = reinterpret_cast<QRgb*>(colorMap.scanLine(y));
      for (int x=0; x<colorMap.width(); ++x)
      {
        double dist = plottable->selectTest(QPointF(x+offsetx, y+offsety), false);
        if (dist >= 0)
        {
          int r = qRed(p[x]);
          int g = qGreen(p[x]);
          int b = qBlue(p[x]);
          r += int(255.0/(dist*0.25+1.0));
          b += int(-255.0/(dist*0.25+1.0));
          if (qAbs(dist-customPlot->selectionTolerance()) < 0.5)
            g += 255;
          p[x] = qRgb(qBound(0, r, 255), qBound(0, g, 255), qBound(0, b, 255));
        }
      }
    }
  }
  // set as plot background:
  customPlot->axisRects().first()->setBackground(QPixmap::fromImage(colorMap), false);
}

void MainWindow::setupTestbed(QCustomPlot *customPlot)
{
  Q_UNUSED(customPlot)
}

void MainWindow::setupIntegerTickStepCase(QCustomPlot *customPlot)
{
  QSharedPointer<QCPAxisTickerFixed> ticker(new QCPAxisTickerFixed);
  ticker->setTickStep(5.0);
  ticker->setScaleStrategy(QCPAxisTickerFixed::ssMultiples);
  
  customPlot->xAxis->setTicker(ticker);
  customPlot->yAxis->setTicker(ticker);
}

void MainWindow::selectionRectChooser(QMouseEvent *event)
{
  if (event->button() == Qt::RightButton)
  {
    if (event->modifiers().testFlag(Qt::ShiftModifier))
      mCustomPlot->setSelectionRectMode(QCP::srmZoom);
    else
      mCustomPlot->setSelectionRectMode(QCP::srmSelect);
  } else
    mCustomPlot->setSelectionRectMode(QCP::srmNone);
}

void MainWindow::tracerTestMouseMove(QMouseEvent *event)
{
  tracerTestTracer->setGraphKey(mCustomPlot->xAxis->pixelToCoord(event->pos().x()));
  mCustomPlot->replot();
}

void MainWindow::selectTestColorMapRefresh()
{
  showSelectTestColorMap(mCustomPlot);
}

void MainWindow::mouseMoveRotateTickLabels(QMouseEvent *event)
{
  mCustomPlot->xAxis->setTickLabelRotation(event->pos().y()-mCustomPlot->height()/2.0);
  mCustomPlot->yAxis->setTickLabelRotation(event->pos().y()-mCustomPlot->height()/2.0);
  mCustomPlot->yAxis2->setTickLabelRotation(event->pos().x()-mCustomPlot->width()/2.0);
  mCustomPlot->xAxis2->setTickLabelRotation(event->pos().x()-mCustomPlot->width()/2.0);
  mCustomPlot->replot();
}

void MainWindow::mouseMoveRotateAngularTickLabels(QMouseEvent *event)
{
  if (QCPPolarAxisAngular *polarAxis = qobject_cast<QCPPolarAxisAngular*>(mCustomPlot->plotLayout()->element(0, 0)))
  {
    //polarAxis->setTickLabelRotation(event->pos().x()-mCustomPlot->width()/2.0);
    polarAxis->setAngle(std::atan2(event->pos().y()-mCustomPlot->height()/2.0, event->pos().x()-mCustomPlot->width()/2.0)/M_PI*180.0);
  }
  mCustomPlot->replot();
}

void MainWindow::tickLabelTestTimerSlot()
{
  mCustomPlot->setPlottingHint(QCP::phCacheLabels, !mCustomPlot->plottingHints().testFlag(QCP::phCacheLabels));
  ui->statusBar->showMessage(mCustomPlot->plottingHints().testFlag(QCP::phCacheLabels) ? "Cached" : "Not Cached");
  mCustomPlot->replot();
}

void MainWindow::setupMultiAxisRectInteractionsMouseMove(QMouseEvent *event)
{
  foreach(QCPAxisRect *r, mCustomPlot->axisRects())
    r->setBackground(Qt::NoBrush);
  if (QCPAxisRect *ar = mCustomPlot->axisRectAt(event->pos()))
    ar->setBackground(QColor(230, 230, 230));
  mCustomPlot->replot();
}

void MainWindow::daqPerformanceDataSlot()
{
  static qint64 start = qint64(QCPAxisTickerDateTime::dateTimeToKey(QDateTime::currentDateTime())*1000);
  qint64 currentMillisecond = qint64(QCPAxisTickerDateTime::dateTimeToKey(QDateTime::currentDateTime())*1000) - start;
  static qint64 lastMillisecond = currentMillisecond;
  static int ptsInThisMillisecond = 0;
  if (lastMillisecond != currentMillisecond)
  {
    ptsInThisMillisecond = 0;
    lastMillisecond = currentMillisecond;
  }
  static int dir = 1;
  static bool grow = true;
  if (mCustomPlot->graph()->data()->size() > 100000)
    grow = false;
  
  if (std::rand()%100000 < 100)
  {
    if (grow)
    {
      if (std::rand()%1000 < 280)
        dir = -1;
      else
        dir = 1;
    } else
    {
      if (std::rand()%1000 < 450)
        dir = -1;
      else
        dir = 1;
    }
  }
  if (dir == 1)
  {
    if (ptsInThisMillisecond < 100)
    {
      ptsInThisMillisecond++;
      double x = currentMillisecond/1000.0 + ptsInThisMillisecond/1e6;
      double y = qSin(x*10)*qCos(x/2.0);
      mCustomPlot->graph(0)->addData(x,y+qSin(ptsInThisMillisecond*10)*0.001);
      mCustomPlot->graph(0)->addData(-x,y+qSin(ptsInThisMillisecond*10)*0.001);
    }
  } else
  {
    if (std::rand()%10 < 1)
      mCustomPlot->graph(0)->data()->removeBefore(mCustomPlot->graph(0)->data()->constBegin()->key+0.00000001);
    else
      mCustomPlot->graph(0)->data()->remove((mCustomPlot->graph(0)->data()->constEnd()-1)->key);
    if (mCustomPlot->graph(0)->data()->isEmpty())
      qApp->quit();
  }
}

void MainWindow::daqPerformanceReplotSlot()
{
  static bool hasRescaled = false;
  if (!hasRescaled)
  {
    mCustomPlot->rescaleAxes();
    hasRescaled = true;
  }
  mCustomPlot->replot();
  
  int dataPoints = mCustomPlot->graph(0)->data()->size();
  static int lastDataPoints = dataPoints;
  qint64 now = qint64(QCPAxisTickerDateTime::dateTimeToKey(QDateTime::currentDateTime())*1000);
  static qint64 lastT = now;
  static QString dataPointFrequency("0 Hz");
  if (now-lastT > 1000)
  {
    dataPointFrequency = QString::number((dataPoints-lastDataPoints)/double(now-lastT)*1000.0)+" Hz";
    lastT = now;
    lastDataPoints = dataPoints;
  }
  ui->statusBar->showMessage(QString("Data Points: %1, Data Frequency: %2").arg(dataPoints).arg(dataPointFrequency));
}

void MainWindow::colorMapMouseMove(QMouseEvent *event)
{
  if (QCPColorMap *map = qobject_cast<QCPColorMap*>(mCustomPlot->plottable(0)))
  {
    double keyCoord = map->keyAxis()->pixelToCoord(map->keyAxis()->orientation()==Qt::Horizontal ? event->pos().x() : event->pos().y());
    double valueCoord = map->valueAxis()->pixelToCoord(map->valueAxis()->orientation()==Qt::Horizontal ? event->pos().x() : event->pos().y());
    int ik, iv;
    map->data()->coordToCell(keyCoord, valueCoord, &ik, &iv);
    map->data()->fill(0);
    map->data()->setCell(ik, iv, 1);
    map->rescaleDataRange(true);
    
    double ck, cv;
    map->data()->cellToCoord(ik, iv, &ck, &cv);
    if (mCustomPlot->itemCount() == 0)
    {
      QCPItemTracer *t = new QCPItemTracer(mCustomPlot);
      t->position->setType(QCPItemPosition::ptPlotCoords);
      t->position->setCoords(ck, cv);
      t->position->setAxes(map->keyAxis(), map->valueAxis());
      t->setClipToAxisRect(false);
      t->setStyle(QCPItemTracer::tsCircle);
      t->setPen(QPen(Qt::red));
    } else if (QCPItemTracer *t = qobject_cast<QCPItemTracer*>(mCustomPlot->item(0)))
      t->position->setCoords(ck, cv);
    
    mCustomPlot->replot();
  }
}

void MainWindow::testbedMouseClick(QMouseEvent *event)
{
  Q_UNUSED(event)
}

void MainWindow::showReplotTime()
{
  static QDateTime lastShow = QDateTime::fromMSecsSinceEpoch(0);
  if (lastShow.msecsTo(QDateTime::currentDateTime()) > 100) // only update status bar label at most every 100ms
  {
    mStatusBarLabel->setText(QString("%1 ms (avg %2 ms)").arg(mCustomPlot->replotTime(false), 0, 'f', 1).arg(mCustomPlot->replotTime(true), 0, 'f', 1));
    lastShow = QDateTime::currentDateTime();
  }
}
