cmake_minimum_required(VERSION 3.0.0...3.5)
project(YoYoMath VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)

option(USE_SIMD "Use SIMD math" OFF)
add_library(YoYoMath STATIC
    src/Defines.h
    src/Defines.cpp

    src/Math/Math.h
    src/Math/Math.cpp

    src/Math/MathTypes.h
    src/Math/MathTypes.cpp

    src/Math/Quaternion.h
    src/Math/Quaternion.cpp

    src/Math/MatrixTransform.h
    src/Math/MatrixTransform.cpp

    src/Math/Random.h
    src/Math/Random.cpp

    src/Math/Geometry/Ray.h
    src/Math/Geometry/Ray.cpp
)
target_precompile_headers(${PROJECT_NAME} PUBLIC src/ypch.h)

target_include_directories(${PROJECT_NAME} PRIVATE src)
target_include_directories(${PROJECT_NAME} PUBLIC src/ include/)

target_compile_definitions(${PROJECT_NAME} PRIVATE Y_EXPORT)

# Detect build type
target_compile_definitions(${PROJECT_NAME}
    PUBLIC
    $<$<CONFIG:Debug>:Y_DEBUG>
    $<$<CONFIG:RelWithDebInfo>:Y_DEBUG>
    $<$<CONFIG:Release>:Y_RELEASE>
    $<$<CONFIG:MinSizeRel>:Y_RELEASE>
)

if(MSVC)
    target_compile_definitions(${PROJECT_NAME} PUBLIC Y_COMPILER_MSVC)
endif()

if (WIN32)
    target_compile_definitions(${PROJECT_NAME} PUBLIC Y_PLATFORM_WIN32)
elseif (APPLE)
    target_compile_definitions(${PROJECT_NAME} PUBLIC Y_PLATFORM_APPLE)
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
