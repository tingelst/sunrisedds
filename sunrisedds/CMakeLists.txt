cmake_minimum_required(VERSION 3.5)
project(sunrisedds)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(string_camel_case_to_lower_case_underscore)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(NOT WIN32)
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(CycloneDDS REQUIRED)
find_package(JNI REQUIRED)
find_package(Java COMPONENTS Development REQUIRED)
include(UseJava)

set(SUNRISE_JAVA_VERSION "1.6.0.45")

option(BUILD_JAR "Build JAR file" ON)
if(BUILD_JAR) 

set(${PROJECT_NAME}_exported_jars "")
find_jar(COMMONS_LANG3_JAR NAMES commons-lang3 PATHS jars)

if(${COMMONS_LANG3_JAR})
  list(APPEND ${PROJECT_NAME}_exported_jars ${COMMONS_LANG3_JAR})
else()
  set(commons_lang3_version "3.7")
  set(commons_lang3_sha256 "6e8dc31e046508d9953c96534edf0c2e0bfe6f468966b5b842b3f87e43b6a847")
  set(commons_lang3_url
    "https://repo1.maven.org/maven2/org/apache/commons/commons-lang3/${commons_lang3_version}/commons-lang3-${commons_lang3_version}.jar")
  set(commons_lang3_jar_path "${CMAKE_CURRENT_BINARY_DIR}/jars/commons-lang3-${commons_lang3_version}.jar")
  file(DOWNLOAD ${commons_lang3_url} ${commons_lang3_jar_path} EXPECTED_HASH SHA256=${commons_lang3_sha256})

  install(FILES
    ${commons_lang3_jar_path}
    DESTINATION
    "share/${PROJECT_NAME}/java")

  set(COMMONS_LANG3_JAR "${commons_lang3_jar_path}")
  list(APPEND ${PROJECT_NAME}_exported_jars "share/${PROJECT_NAME}/java/commons-lang3-${commons_lang3_version}.jar")
endif()

find_jar(SFL4J_JAR NAMES slf4j-api PATHS jars)
if(${SFL4J_JAR})
  list(APPEND ${PROJECT_NAME}_exported_jars ${SFL4J_JAR})
else()
  set(slf4j_version "1.7.21")
  set(slf4j_api_sha256 "1d5aeb6bd98b0fdd151269eae941c05f6468a791ea0f1e68d8e7fe518af3e7df")
  set(slf4j_api_url "https://repo1.maven.org/maven2/org/slf4j/slf4j-api/${slf4j_version}/slf4j-api-${slf4j_version}.jar")
  set(slf4j_api_jar_path "${CMAKE_CURRENT_BINARY_DIR}/jars/slf4j-api-${slf4j_version}.jar")
  file(DOWNLOAD ${slf4j_api_url} ${slf4j_api_jar_path} EXPECTED_HASH SHA256=${slf4j_api_sha256})

  install(FILES
    ${slf4j_api_jar_path}
    DESTINATION
    "share/${PROJECT_NAME}/java")

  set(SFL4J_JAR "${slf4j_api_jar_path}")
  list(APPEND ${PROJECT_NAME}_exported_jars "share/${PROJECT_NAME}/java/slf4j-api-${slf4j_version}.jar")

  set(log4j_version "1.2.17")

  set(log4j_sha256 "1d31696445697720527091754369082a6651bd49781b6005deb94e56753406f9")
  set(slf4j_log4j_sha256 "9563e26fd7863cca0f5d468ef09f2927047f8b85a8c76d98766ed5863cb678b2")
  set(slf4j_jdk14_sha256 "2c369503c911bf9ac7c5f4813bc1f8f95866e2e029fae203a02712f5671f5e4a")

  set(log4j_url "https://repo1.maven.org/maven2/log4j/log4j/${log4j_version}/log4j-${log4j_version}.jar")
  set(slf4j_log4j_url "https://repo1.maven.org/maven2/org/slf4j/slf4j-log4j12/${slf4j_version}/slf4j-log4j12-${slf4j_version}.jar")
  set(slf4j_jdk14_url "https://repo1.maven.org/maven2/org/slf4j/slf4j-jdk14/${slf4j_version}/slf4j-jdk14-${slf4j_version}.jar")

  set(log4j_jar_path "${CMAKE_CURRENT_BINARY_DIR}/jars/log4j-${log4j_version}.jar")
  set(slf4j_log4j_jar_path "${CMAKE_CURRENT_BINARY_DIR}/jars/slf4j-log4j12-${slf4j_version}.jar")
  set(slf4j_jdk14_jar_path "${CMAKE_CURRENT_BINARY_DIR}/jars/slf4j-jdk14-${slf4j_version}.jar")

  file(DOWNLOAD ${log4j_url} ${log4j_jar_path} EXPECTED_HASH SHA256=${log4j_sha256})
  file(DOWNLOAD ${slf4j_log4j_url} ${slf4j_log4j_jar_path} EXPECTED_HASH SHA256=${slf4j_log4j_sha256})
  file(DOWNLOAD ${slf4j_jdk14_url} ${slf4j_jdk14_jar_path} EXPECTED_HASH SHA256=${slf4j_jdk14_sha256})
  list(APPEND logging_jars "${log4j_jar_path}")
  list(APPEND logging_jars "${slf4j_log4j_jar_path}")
  list(APPEND logging_jars "${slf4j_jdk14_jar_path}")

  install(FILES
    ${log4j_jar_path} ${slf4j_api_jar_path}
    ${slf4j_log4j_jar_path} ${slf4j_android_jar_path}
    ${slf4j_jdk14_jar_path}
    DESTINATION
    "share/${PROJECT_NAME}/java")

  list(APPEND ${PROJECT_NAME}_exported_jars "share/${PROJECT_NAME}/java/log4j-${log4j_version}.jar")
  list(APPEND ${PROJECT_NAME}_exported_jars "share/${PROJECT_NAME}/java/slf4j-log4j12-${slf4j_version}.jar")
  list(APPEND ${PROJECT_NAME}_exported_jars "share/${PROJECT_NAME}/java/slf4j-jdk14-${slf4j_version}.jar")
endif()

set(${PROJECT_NAME}_sources
  "src/main/java/no/ntnu/mtp/ra/sunrisedds/SunriseDDS.java"

  "src/main/java/no/ntnu/mtp/ra/sunrisedds/core/policy/QosPolicy.java"
  "src/main/java/no/ntnu/mtp/ra/sunrisedds/core/policy/Reliability.java"
  "src/main/java/no/ntnu/mtp/ra/sunrisedds/core/DDSException.java"
  "src/main/java/no/ntnu/mtp/ra/sunrisedds/core/Duration.java"
  "src/main/java/no/ntnu/mtp/ra/sunrisedds/core/Entity.java"
  "src/main/java/no/ntnu/mtp/ra/sunrisedds/core/WaitSet.java"

  "src/main/java/no/ntnu/mtp/ra/sunrisedds/domain/DomainParticipant.java"

  "src/main/java/no/ntnu/mtp/ra/sunrisedds/pub/DataWriter.java"
  "src/main/java/no/ntnu/mtp/ra/sunrisedds/pub/Publisher.java"

  "src/main/java/no/ntnu/mtp/ra/sunrisedds/sub/DataReader.java"
  "src/main/java/no/ntnu/mtp/ra/sunrisedds/sub/InstanceState.java"
  "src/main/java/no/ntnu/mtp/ra/sunrisedds/sub/ReadCondition.java"
  "src/main/java/no/ntnu/mtp/ra/sunrisedds/sub/SampleState.java"
  "src/main/java/no/ntnu/mtp/ra/sunrisedds/sub/Subscriber.java"
  "src/main/java/no/ntnu/mtp/ra/sunrisedds/sub/ViewState.java"

  "src/main/java/no/ntnu/mtp/ra/sunrisedds/topic/Topic.java"

  "src/main/java/no/ntnu/mtp/ra/sunrisedds/utils/JNIUtils.java"

  "src/main/java/no/ntnu/mtp/ra/sunrisedds/msg/MessageDefinition.java"
  "src/main/java/no/ntnu/mtp/ra/sunrisedds/msg/Time.java"
  "src/main/java/no/ntnu/mtp/ra/sunrisedds/msg/Header.java"
  "src/main/java/no/ntnu/mtp/ra/sunrisedds/msg/JointQuantity.java"
  "src/main/java/no/ntnu/mtp/ra/sunrisedds/msg/JointPosition.java"
  "src/main/java/no/ntnu/mtp/ra/sunrisedds/msg/JointState.java"

  "src/main/java/std_msgs/msg/Header.java"
  "src/main/java/sensor_msgs/msg/JointState.java"
  "src/main/java/builtin_interfaces/msg/Time.java"
)

option(GENERATE_NATIVE_HEADERS "Generate native headers" OFF)
if(GENERATE_NATIVE_HEADERS)
add_jar("${PROJECT_NAME}_jar"
  ${${PROJECT_NAME}_sources}
  OUTPUT_NAME
  ${PROJECT_NAME}
  INCLUDE_JARS
  "${SFL4J_JAR}"
  GENERATE_NATIVE_HEADERS
  "${PROJECT_NAME}_native_headers"
  DESTINATION
  "${CMAKE_CURRENT_SOURCE_DIR}/src/main/cpp"
)
else()
add_jar("${PROJECT_NAME}_jar"
  ${${PROJECT_NAME}_sources}
  OUTPUT_NAME
  ${PROJECT_NAME}
  INCLUDE_JARS
  "${SFL4J_JAR}"
)
endif()

endif(BUILD_JAR)

set(${PROJECT_NAME}_jni_sources
  "src/main/cpp/no_ntnu_mtp_ra_sunrisedds_SunriseDDS.cpp"
  "src/main/cpp/no_ntnu_mtp_ra_sunrisedds_msg_Time.cpp"
  "src/main/cpp/no_ntnu_mtp_ra_sunrisedds_msg_Header.cpp"
  "src/main/cpp/no_ntnu_mtp_ra_sunrisedds_msg_JointQuantity.cpp"
  "src/main/cpp/no_ntnu_mtp_ra_sunrisedds_msg_JointPosition.cpp"
  "src/main/cpp/no_ntnu_mtp_ra_sunrisedds_msg_JointState.cpp"

  "src/main/cpp/builtin_interfaces_msg_Time.cpp"
  "src/main/cpp/sensor_msgs_msg_JointState.cpp"
  "src/main/cpp/std_msgs_msg_Header.cpp"
)

set("${PROJECT_NAME}_msg_sources"
  "src/main/cpp/Time.c"
  "src/main/cpp/Header.c"
  "src/main/cpp/JointQuantity.c"
  "src/main/cpp/JointPosition.c"
  "src/main/cpp/JointState.c"

)

set("${PROJECT_NAME}_sources"
  "src/main/cpp/sunrisedds_converters.cpp"
  "src/main/cpp/sunrisedds_exceptions.cpp"
)


foreach(_jni_source ${${PROJECT_NAME}_jni_sources})

  get_filename_component(_target_name "${_jni_source}" NAME_WE)
  string_camel_case_to_lower_case_underscore("${_target_name}" _target_name)

  add_library(${_target_name}
    SHARED 
    ${_jni_source} 
    ${${PROJECT_NAME}_msg_sources}
    ${${PROJECT_NAME}_sources}
  )

  set_target_properties(${_target_name} PROPERTIES
    OUTPUT_NAME "${_jni_prefix}${_target_name}__jni"
  )

  target_include_directories(${_target_name}
    PUBLIC
    ${JNI_INCLUDE_DIRS}
  )

  target_link_libraries(${_target_name}
    PUBLIC
    CycloneDDS::ddsc
  )

  install(TARGETS ${_target_name}
    ARCHIVE DESTINATION lib/jni
    LIBRARY DESTINATION lib/jni
  )

endforeach()
