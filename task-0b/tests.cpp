#include <iostream>
#include <vector>

struct TestCase {
    std::string name;
    std::string inputContent;
    std::vector<std::string> expectedPatterns;
};

// Определяем все тесты
std::vector<TestCase> tests = {
	{"Empty File", "", {}},
	{"Single Word", "hello", {"hello,1,100.00"}},
	{"Multiple Words", "hello hello hello", {"hello,3,100.00"}},
	{"Sorting", "apple banana apple cherry banana apple", 
		{"apple,3,50.00", "banana,2,33.33", "cherry,1,16.67"}},
	{"Punctuation", "Hello, world! Hello! 123 test123", 
		{"hello,2,40.00", "world,1,20.00", "123,1,20.00", "test123,1,20.00"}}
};