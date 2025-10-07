#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class WordStatistics {
private:
    std::unordered_map<std::string, size_t> wordCount;
    size_t totalWords = 0;

public:
    void addWord(const std::string& word);

    void addWords(const std::vector<std::string>& words);

    size_t getTotalWords() const;
    
    size_t getWordCount(const std::string& word) const;

    const std::unordered_map<std::string, size_t>& getWordCountMap() const;

    void clear();
};