#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include <string>

class Pager{
    public:
        explicit Pager(const std:: string& filename, size_t pageSize = 4096);
        ~Pager();

        std::vector<uint8_t> readPage(size_t pageNumber);
        void writePage(size_t pageNumber, const std::vector<uint8_t>& data);
        size_t numPages() const;

    private:
        std::fstream file;
        size_t pageSize;
};