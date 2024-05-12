cmake_minimum_required(VERSION 3.28)
project(Staff)

set(CMAKE_CXX_STANDARD 17)

add_executable(Staff src/StaffManagementSystem.cpp
        src/WorkerManager.cpp
        include/WorkerManager.h
        include/Worker.h
        src/Employee.cpp
        include/Employee.h
        src/Manager.cpp
        include/Manager.h
        src/Boss.cpp
        include/Boss.h
)
