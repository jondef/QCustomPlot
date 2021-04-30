project(QCustomPlot)

################################
# Pre-compilation steps
################################
file(GLOB HEADERS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/plottables/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/items/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/layoutelements/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/axis/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/polar/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
        )

file(GLOB SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/plottables/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/items/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/layoutelements/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/axis/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/polar/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
        )

add_definitions(-DQCUSTOMPLOT_USE_OPENGL)
add_definitions(-DQCUSTOMPLOT_COMPILE_LIBRARY)

################################
# Compiling
################################
add_library(QCustomPlot SHARED ${SOURCES} ${HEADERS})

################################
# Linking
################################
target_link_libraries(QCustomPlot PUBLIC Qt6::Core Qt6::PrintSupport Qt6::OpenGL)

if (${CMAKE_BUILD_TYPE} STREQUAL Debug)
    set_target_properties(QCustomPlot PROPERTIES OUTPUT_NAME "qcustomplotd2" PREFIX "")
elseif (${CMAKE_BUILD_TYPE} STREQUAL Release)
    set_target_properties(QCustomPlot PROPERTIES OUTPUT_NAME "qcustomplot2")
endif ()
