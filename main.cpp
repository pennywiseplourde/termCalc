#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <cstdint>
#include <cmath>
#include "decimal.hpp"
#include "lineguard.hpp"
#include "stringlinkedlist.hpp"

void logErr(stringLinkedList& list, std::string reason = "none") {

    list.append(reason);

}

void returnErrs(stringLinkedList& list) {

    node_sll* temp = list.head;

    std::cout << "<------ERRORS------>\n";

    while (temp != nullptr) {

        std::cout << temp->errorMessage << "\n";
        temp = temp->next;

    }

}

void helper() {

    std::cout << "placeholder for help";

}

int main(const int argc, const char* const argv[]) {

    lineGuard guard;

    stringLinkedList errors;

    if (argc <= 1) {
        helper();
        return 1;
    }

    for (int i = 1; i < argc; i++) {

        if (argv[i] == "help" || argv[i] == "--help" || argv[i] == "-h") {
            helper();
            return 0;
        } 

    }
    
}