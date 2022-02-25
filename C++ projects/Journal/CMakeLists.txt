cmake_minimum_required(VERSION 3.0.0)

project(Journal)


include_directories(./include/Journal ./src ./libs)
link_directories(./include ./src ./libs)


add_executable(journal_exec ./src/main.cpp ./src/hash_password.cpp ./src/Registration.cpp ./libs/sha256.cpp ./src/User.cpp ./src/UserList.cpp  ./src/Login.cpp ./src/Date.cpp ./include/Journal/Date.h )

target_link_libraries (journal_exec sqlite3)



