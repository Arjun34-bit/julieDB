#include "page.h"
#include <iostream>
#include <filesystem>
#include <stdexcept>     
#include <cstdio>    

Pager::Pager(const std::string& filename, size_t pageSize)
    : pageSize(pageSize)
{
    file.open(filename, std::ios::in | std::ios::out | std::ios::binary);

    if (!file.is_open()) {
        file.open(filename, std::ios::out | std::ios::binary);
        file.close();

        file.open(filename, std::ios::in | std::ios::out | std::ios::binary);
    }

    std::cout << "Pager initialized for file: " << filename << std::endl;
}

Pager::~Pager() {
    if (file.is_open())
        file.close();
}

std::vector<uint8_t> Pager::readPage(size_t pageNumber) {
    std::vector<uint8_t> buffer(pageSize);

    file.seekg(pageNumber * pageSize, std::ios::beg);
    file.read(reinterpret_cast<char*>(buffer.data()), pageSize);

    return buffer;
}

void Pager::writePage(size_t pageNumber, const std::vector<uint8_t>& data) {
    if (data.size() != pageSize) {
        throw std::runtime_error("Page data size mismatch");
    }

    file.seekp(pageNumber * pageSize, std::ios::beg);
    file.write(reinterpret_cast<const char*>(data.data()), pageSize);
    file.flush();
}

size_t Pager::numPages() const {
    size_t size = std::filesystem::file_size("data.db");
    return size / pageSize;
}
