add_executable(
     ${CMAKE_PROJECT_NAME}

     main.cpp

     application/implementation/application.cpp
)

target_include_directories(
     ${CMAKE_PROJECT_NAME}

     PUBLIC ${PROJECT_SOURCE_DIR}/
)