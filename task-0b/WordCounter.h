#pragma once

#include <fstream>
#include <string>
#include "FileReader.cpp"
#include "WordStatistics.cpp"
#include "CSVWriter.cpp"

class WordCounter {
private:
    WordExtractor extractor;
    WordStatistics statistics;
    CSVWriter writer;

public:
    void processFile(const std::string& filename);

    void writeCSV(const std::string& filename) const;

    size_t getTotalWords() const;
    
    size_t getWordCount(const std::string& word);
    
    void clear();
};