#--------------------------------------------------------------------------
# mathlibtest project
#--------------------------------------------------------------------------

PROJECT(mathlibtest)
FILE(GLOB mathlibtest_headers code/*.h)
FILE(GLOB mathlibtest_sources code/*.cc)

SET(files_mathlibtest ${mathlibtest_headers} ${mathlibtest_sources})
SOURCE_GROUP("mathlibtest" FILES ${files_mathlibtest})

ADD_EXECUTABLE(mathlibtest ${files_mathlibtest})
TARGET_LINK_LIBRARIES(mathlibtest core render)
ADD_DEPENDENCIES(mathlibtest core render)