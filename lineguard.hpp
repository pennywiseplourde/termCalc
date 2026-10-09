#pragma once
#include <iostream>

struct lineGuard {
    ~lineGuard() {
        std::cout << std::endl;
    }
};