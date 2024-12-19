cmake_minimum_required(VERSION 3.30)
project(classProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(classProject main.cpp
        Doctor.cpp
        Doctor.h
        Patient.cpp
        Patient.h
        Appointment.cpp
        Appointment.h)
