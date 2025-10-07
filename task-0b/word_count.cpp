#include <iostream>

#include "WordCounter.cpp"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "there must be 3 arguments" << std::endl;
        return 1;
    }

    try {
        WordCounter counter;
        counter.processFile(argv[1]);
        counter.writeCSV(argv[2]);
    } catch (const std::exception& e) {
        std::cout << "Error: " << std::endl;
        return 1;
    }

    return 0;
}