#include <iostream>
#include "storage/page.h"

int main(){
    std::cout << "Welcome to JulieDB" << std::endl;

    Pager pager("data.db");

    std::vector<uint8_t> data(4096, 65);
    pager.writePage(0, data);

    auto page = pager.readPage(0);

    std::cout<< "Read page[0] first byte: " << page[0] << std::endl;

    return 0;
}