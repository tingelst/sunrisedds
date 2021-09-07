cmake_minimum_required(VERSION 3.5)
project(sunrisedds)

find_package(CycloneDDS REQUIRED)
find_package(JNI REQUIRED)
find_package(Java COMPONENTS Development REQUIRED)
include(UseJava)

add_library(${PROJECT_NAME}_interfaces 
    "src/main/cpp/Header.c"
    "src/main/cpp/JointPosition.c"
    "src/main/cpp/JointQuantity.c"
    "src/main/cpp/Time.c")
target_link_libraries(${PROJECT_NAME}_interfaces 
    CycloneDDS::ddsc)

add_library(${PROJECT_NAME} SHARED
    "src/main/cpp/org_sunrisedds_sunrisedds_SunriseDDS.cpp")
target_include_directories(${PROJECT_NAME} PRIVATE ${JNI_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} 
    ${PROJECT_NAME}_interfaces 
    CycloneDDS::ddsc)


# add_jar(${PROJECT_NAME}_jar 
#     "src/main/java/org/sunrisedds/sunrisedds/SunriseDDS.java"
#     OUTPUT_NAME
#     ${PROJECT_NAME})