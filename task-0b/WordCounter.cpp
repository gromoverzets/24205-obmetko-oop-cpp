#pragma once

#include <fstream>
#include <string>

#include "WordCounter.h"
#include "FileReader.cpp"
#include "WordStatistics.cpp"
#include "CSVWriter.cpp"

class WordCounter {
private:
    WordExtractor extractor;
    WordStatistics statistics;
    CSVWriter writer;

public:
    void processFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Cannot open file: " + filename);
        }

        std::string line;
        while (std::getline(file, line)) {
            auto words = extractor.extractWords(line);
            statistics.addWords(words);
        }
    }

    void writeCSV(const std::string& filename) const {
        writer.writeWordStatistics(filename, statistics.getWordCountMap(), statistics.getTotalWords());
    }

    size_t getTotalWords() const { return statistics.getTotalWords(); }
    
    size_t getWordCount(const std::string& word) const {
        return statistics.getWordCount(word);
    }
    
    void clear() {
        statistics.clear();
    }
};