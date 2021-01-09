cmake_minimum_required(VERSION 3.17)
project(QCustomPlot)

FIND_PACKAGE(Qt5 COMPONENTS Core Gui Widgets OpenGL PrintSupport REQUIRED)
set(CMAKE_AUTOMOC ON) # Instruct CMake to run moc automatically when needed
add_definitions(-DQCUSTOMPLOT_USE_OPENGL)
add_definitions(-DQCUSTOMPLOT_COMPILE_LIBRARY)

file(GLOB HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/global.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/painter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/paintbuffer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/layer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/axis/range.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/axis/axis.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/axis/axisticker.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/plottable.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/item.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lineending.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/layout.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/plottables/plottable-graph.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/plottables/plottable-curve.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/plottables/plottable-bars.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/plottables/plottable-statisticalbox.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/plottables/plottable-colormap.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/plottables/plottable-financial.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/plottables/plottable-errorbar.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/items/item-straightline.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/items/item-line.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/items/item-curve.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/items/item-rect.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/items/item-text.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/items/item-ellipse.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/items/item-pixmap.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/items/item-tracer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/items/item-bracket.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/layoutelements/layoutelement-axisrect.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/layoutelements/layoutelement-legend.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/layoutelements/layoutelement-textelement.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/layoutelements/layoutelement-colorscale.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/colorgradient.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vector2d.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/axis/axistickerdatetime.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/axis/axistickertime.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/axis/axistickerfixed.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/axis/axistickertext.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/axis/axistickerpi.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/axis/axistickerlog.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/datacontainer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/selection.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/selectionrect.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/plottable1d.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/scatterstyle.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/selectiondecorator-bracket
)

file(GLOB SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/painter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/paintbuffer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/layer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/axis/range.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/axis/axis.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/axis/axisticker.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/plottable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/item.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lineending.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/layout.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/plottables/plottable-graph.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/plottables/plottable-curve.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/plottables/plottable-bars.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/plottables/plottable-statisticalbox.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/plottables/plottable-colormap.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/plottables/plottable-financial.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/plottables/plottable-errorbar.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/items/item-straightline.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/items/item-line.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/items/item-curve.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/items/item-rect.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/items/item-text.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/items/item-ellipse.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/items/item-pixmap.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/items/item-tracer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/items/item-bracket.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/layoutelements/layoutelement-axisrect.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/layoutelements/layoutelement-legend.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/layoutelements/layoutelement-textelement.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/layoutelements/layoutelement-colorscale.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/colorgradient.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vector2d.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/axis/axistickerdatetime.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/axis/axistickertime.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/axis/axistickerfixed.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/axis/axistickertext.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/axis/axistickerpi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/axis/axistickerlog.cpp
#    ${CMAKE_CURRENT_SOURCE_DIR}/src/datacontainer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/selection.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/selectionrect.cpp
#    ${CMAKE_CURRENT_SOURCE_DIR}/src/plottable1d.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/scatterstyle.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/selectiondecorator-bracket.cpp
)

add_library(QCustomPlot SHARED ${SOURCES} ${HEADERS})
target_link_libraries(QCustomPlot PUBLIC Qt5::Core Qt5::PrintSupport)

if (${CMAKE_BUILD_TYPE} STREQUAL Debug)
    set_target_properties(QCustomPlot PROPERTIES OUTPUT_NAME "qcustomplotd2" PREFIX "")
elseif (${CMAKE_BUILD_TYPE} STREQUAL Release)
    set_target_properties(QCustomPlot PROPERTIES OUTPUT_NAME "qcustomplot2")
endif ()