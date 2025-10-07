#pragma once

#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

class CSVWriter {
public:
    void writeWordStatistics(const std::string& filename, 
                           const std::unordered_map<std::string, size_t>& wordCount,
                           size_t totalWords) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Cannot open file: " + filename);
        }

        std::vector<std::pair<std::string, size_t>> sortedWords(wordCount.begin(), wordCount.end());
        std::sort(sortedWords.begin(), sortedWords.end(),
            [](const auto& a, const auto& b) {
                return a.second > b.second;
            });

        for (const auto& pair : sortedWords) {
            double percentage = (static_cast<double>(pair.second) / totalWords) * 100.0;
            file << pair.first << "," << pair.second << "," 
                 << std::fixed << std::setprecision(2) << percentage << "\n";
        }
    }
};