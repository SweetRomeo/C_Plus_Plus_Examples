cmake_minimum_required(VERSION 3.30)
project(C_Plus_Plus_Examples)

set(CMAKE_CXX_STANDARD 20)

add_executable(C_Plus_Plus_Examples main.cpp
        Rectangle.h
        Rectangle.cpp
        Date.h
        Date.cpp
        NumberUtil.h
        NumberUtil.cpp
        BallGame.h
        BallGame.cpp
        ArrayUtil.h
        ArrayUtil.cpp
)
