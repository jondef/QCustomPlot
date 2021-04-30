QT += core gui testlib
#lessThan(QT_MAJOR_VERSION, 5): QT += opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

greaterThan(QT_MAJOR_VERSION, 4): CONFIG += c++11
lessThan(QT_MAJOR_VERSION, 5): QMAKE_CXXFLAGS += -std=c++11

lessThan(QT_MAJOR_VERSION, 5): QMAKE_CXXFLAGS += -w # don't spam warnings for old Qt versions

TEMPLATE = app
DEPENDPATH = .
INCLUDEPATH = .

HEADERS += ../../qcustomplot.h \
    test-qcustomplot/test-qcustomplot.h\
    test-qcpgraph/test-qcpgraph.h \
    test-qcpcurve/test-qcpcurve.h \
    test-qcpbars/test-qcpbars.h \
    test-qcpfinancial/test-qcpfinancial.h \
    test-qcplayout/test-qcplayout.h \
    test-qcpaxisrect/test-qcpaxisrect.h \
    test-colormap/test-colormap.h \
    test-datacontainer/test-datacontainer.h \
    test-qcplegend/test-qcplegend.h

SOURCES += ../../qcustomplot.cpp \
           autotest.cpp \
    test-qcustomplot/test-qcustomplot.cpp\
    test-qcpgraph/test-qcpgraph.cpp \
    test-qcpcurve/test-qcpcurve.cpp \
    test-qcpbars/test-qcpbars.cpp \
    test-qcpfinancial/test-qcpfinancial.cpp \
    test-qcplayout/test-qcplayout.cpp \
    test-qcpaxisrect/test-qcpaxisrect.cpp \
    test-colormap/test-colormap.cpp \
    test-datacontainer/test-datacontainer.cpp \
    test-qcplegend/test-qcplegend.cpp
    
