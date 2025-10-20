#include <gtest/gtest.h>
#include <fstream>
#include "FileReader.h"

class FileReaderTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Create test file
        std::ofstream testFile("test_input.txt");
        testFile << "Hello world\nThis is a test\nFile reader test";
        testFile.close();
    }

    void TearDown() override {
        remove("test_input.txt");
    }
};

TEST_F(FileReaderTest, ConstructorAndOpen) {
    FileReader reader("test_input.txt");
    EXPECT_NO_THROW(reader.open());
}

TEST_F(FileReaderTest, ReadLines) {
    FileReader reader("test_input.txt");
    reader.open();
    
    EXPECT_TRUE(reader.hasNext());
    std::string line1 = reader.next();
    EXPECT_EQ(line1, "Hello world");
    
    EXPECT_TRUE(reader.hasNext());
    std::string line2 = reader.next();
    EXPECT_EQ(line2, "This is a test");
    
    EXPECT_TRUE(reader.hasNext());
    std::string line3 = reader.next();
    EXPECT_EQ(line3, "File reader test");
    
    EXPECT_FALSE(reader.hasNext());
}

TEST_F(FileReaderTest, ResetFunctionality) {
    FileReader reader("test_input.txt");
    reader.open();
    
    // Read first line
    std::string line1 = reader.next();
    EXPECT_EQ(line1, "Hello world");
    
    // Reset and read again
    reader.reset();
    std::string line1_again = reader.next();
    EXPECT_EQ(line1_again, "Hello world");
}
