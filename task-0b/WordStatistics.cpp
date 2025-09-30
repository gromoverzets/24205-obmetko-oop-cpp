#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class WordStatistics {
private:
    std::unordered_map<std::string, size_t> wordCount;
    size_t totalWords = 0;

public:
    void addWord(const std::string& word) {
        wordCount[word]++;
        totalWords++;
    }

    void addWords(const std::vector<std::string>& words) {
        for (const auto& word : words) {
            addWord(word);
        }
    }

    size_t getTotalWords() const { return totalWords; }
    
    size_t getWordCount(const std::string& word) const {
        auto it = wordCount.find(word);
        return (it != wordCount.end()) ? it->second : 0;
    }

    const std::unordered_map<std::string, size_t>& getWordCountMap() const {
        return wordCount;
    }

    void clear() {
        wordCount.clear();
        totalWords = 0;
    }
};