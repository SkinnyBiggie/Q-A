# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\e913_913_Hornea_Dorian_Alexandru_1_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\e913_913_Hornea_Dorian_Alexandru_1_autogen.dir\\ParseCache.txt"
  "e913_913_Hornea_Dorian_Alexandru_1_autogen"
  )
endif()
