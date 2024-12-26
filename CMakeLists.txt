cmake_minimum_required(VERSION 3.27)

set(CMAKE_FIND_DEBUG_MODE TRUE)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_DEBUG "-Werror -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer -g")

project("nicbarker-clay-playground" CXX)

find_package(clay REQUIRED) # PATHS "P:\\Downloads\\cpp-libraries\\portaudio\\build\\cmake\\portaudio")

if(clay_FOUND)
    message(STATUS "YES")
else()
    message(STATUS "NO")
endif()

add_executable(${PROJECT_NAME}
    "src/main.cpp"
)

target_link_libraries(${PROJECT_NAME} clay)
target_link_options(${PROJECT_NAME} PRIVATE "-static")


