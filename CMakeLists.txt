PROJECT(LEETCODE)
CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(./list)
ADD_SUBDIRECTORY(./array)

FILE(GLOB SRC *.cpp)
FILE(GLOB INC *.h *.hpp)
ADD_EXECUTABLE(leetcode ${SRC} ${INC})
TARGET_LINK_LIBRARIES(leetcode list array)



