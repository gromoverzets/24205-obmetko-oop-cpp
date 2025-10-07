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
                           size_t totalWords) const;
};