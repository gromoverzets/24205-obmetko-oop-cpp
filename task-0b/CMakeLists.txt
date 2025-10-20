cmake_minimum_required(VERSION 3.14)
project(WordCount)

set(CMAKE_CXX_STANDARD 17)

# Find packages
find_package(GTest REQUIRED)

# Main executable
add_executable(word_count 
    main.cpp 
    FileReader.cpp 
    WordCounter.cpp 
    WordStatistics.cpp 
    CSVWriter.cpp
)

# Test executables
add_executable(test_filereader test_filereader.cpp FileReader.cpp)
add_executable(test_wordcounter test_wordcounter.cpp FileReader.cpp WordCounter.cpp)
add_executable(test_wordstatistics test_wordstatistics.cpp WordStatistics.cpp)
add_executable(test_csvwriter test_csvwriter.cpp CSVWriter.cpp)

# Link tests with GTest
target_link_libraries(test_filereader GTest::gtest GTest::gtest_main)
target_link_libraries(test_wordcounter GTest::gtest GTest::gtest_main FileReader.cpp)
target_link_libraries(test_wordstatistics GTest::gtest GTest::gtest_main)
target_link_libraries(test_csvwriter GTest::gtest GTest::gtest_main)