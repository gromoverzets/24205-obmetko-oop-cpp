#include "WordCounter.cpp"

#include "tests.cpp"


class TempFileManager {
private:
    std::vector<std::string> filesToKeep;
    
public:
    void keepFile(const std::string& filename) {
        filesToKeep.push_back(filename);
    }
    
    void cleanupExcept(const std::vector<std::string>& excludeFiles = {}) {
        for (const auto& file : filesToKeep) {
            // Удаляем файл только если его нет в списке исключений
            if (std::find(excludeFiles.begin(), excludeFiles.end(), file) == excludeFiles.end()) {
                std::remove(file.c_str());
            }
        }
    }
};

bool isEqual(const std::vector<std::string>& lines, 
             const std::vector<std::string>& patterns) {
    for (const auto& pattern : patterns) {
        bool found = false;
        for (const auto& line : lines) {
            if (line.length() == pattern.length() && line == pattern) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

int main() {
    std::cout << "==================================" << std::endl;
    std::cout << "Starting Word Count Tests" << std::endl;
    std::cout << "==================================" << std::endl;
    
    int passedTests = 0;
    int totalTests = tests.size();
    std::vector<std::string> failedTestFiles;
    
    // Общие имена файлов для всех тестов
    std::string inputFile = "test_input.txt";
    std::string outputFile = "test_output.csv";
    
    TempFileManager fileManager;
    fileManager.keepFile(inputFile);
    fileManager.keepFile(outputFile);
    
    for (size_t i = 0; i < tests.size(); ++i) {
        const auto& test = tests[i];
        
        std::cout << "Test " << (i + 1) << " - ";
        
        // Создаем входной файл
        std::ofstream input(inputFile);
        input << test.inputContent;
        input.close();
        
        // Обрабатываем файл
        WordCounter counter;
        try {
            counter.processFile(inputFile);
            counter.writeCSV(outputFile);
            
            // Проверяем результат
            std::ifstream output(outputFile);
            std::string line;
            std::vector<std::string> lines;
            
            while (std::getline(output, line)) {
                lines.push_back(line);
            }
            
            bool passed = isEqual(lines, test.expectedPatterns);
            
            if (passed) {
                std::cout << "PASSED " << '"' << test.name << '"' << std::endl;
                passedTests++;
            } else {
                std::cout << "FAILED " << '"' << test.name << '"'  <<  std::endl;
                // Сохраняем информацию о неудачном тесте
                failedTestFiles.push_back("Failed: " + test.name);
				break;
            }
            
        } catch (const std::exception& e) {
            std::cout << "ERROR: " << e.what() << std::endl;
            failedTestFiles.push_back("ERROR in " + test.name + ": " + e.what());
        }
        
        counter.clear();
    }
    
    // Удаляем файлы, если все тесты пройдены
    // if (passedTests == totalTests) {
    //     std::remove(inputFile.c_str());
    //     std::remove(outputFile.c_str());
    // }
    
    std::cout << passedTests << "/" << totalTests << " tests passed" << std::endl;
	std::cout << "Input:  " << inputFile << "\n" 
              << "Output: " << outputFile << std::endl;
    
    return (passedTests == totalTests) ? 0 : 1;
}