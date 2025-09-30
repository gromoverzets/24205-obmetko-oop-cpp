#pragma once

#include <string>
#include <vector>

class WordExtractor {
public:
    std::vector<std::string> extractWords(const std::string& line) const {
        std::vector<std::string> words;
        std::string currentWord;
        
        for (char c : line) {
            if (std::isalnum(static_cast<unsigned char>(c))) {
                currentWord += std::tolower(static_cast<unsigned char>(c));
            } else if (!currentWord.empty()) {
                words.push_back(currentWord);
                currentWord.clear();
            }
        }
        if (!currentWord.empty()) {
            words.push_back(currentWord);
        }
        return words;
    }
};