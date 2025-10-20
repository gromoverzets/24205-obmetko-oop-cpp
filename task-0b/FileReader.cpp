#include "FileReader.h"
#include <stdexcept>

FileReader::FileReader(const std::string& filename) : filename(filename), file(nullptr) {}

void FileReader::open() {
    if (file != nullptr) close();
    file = new std::ifstream(filename);
    if (!file->is_open()) {
        throw std::runtime_error("Cannot open file: " + filename);
    }
}

void FileReader::close() {
    if (file != nullptr) {
        file->close();
        delete file;
        file = nullptr;
    }
}

bool FileReader::hasNext() {
    return file != nullptr && !file->eof();
}

std::string FileReader::next() {
    std::string line;
    if (file != nullptr && std::getline(*file, line)) {
        return line;
    }
    return "";
}

void FileReader::reset() {
    if (file != nullptr) {
        file->clear();
        file->seekg(0);
    }
}

FileReader::~FileReader() {
    close();
}