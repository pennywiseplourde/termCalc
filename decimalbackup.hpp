#ifndef DECIMAL_HPP
#define DECIMAL_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <cstdint>
#include <cmath>

class decimal {
    public: 
        int64_t whole = 0;
        u_int64_t part = 0;
        static constexpr u_int64_t SCALE = 1000000000ULL;

        decimal() = default;

        decimal(const char* str) {
            std::string s(str);
            size_t dot = s.find(".");

            if (dot == std::string::npos) {
                whole = std::stoll(s);
                part = 0;
            } else {
                whole = std::stoll(s.substr(0, dot));
                std::string fracstr = s.substr(dot + 1);

                if (fracstr.length() < 9) {
                    fracstr.append(9 - fracstr.length(), '0');

                } else {
                    fracstr = fracstr.substr(0, 9);
                }

                part = std::stoull(fracstr);
            }
        }

        void print() const {
            std::cout << whole << "." << std::setfill('0') << std::setw(9) << part;
        }

        decimal operator+(const decimal& num) const {

            decimal result;

            result.whole = whole + num.whole;

            result.part = part + num.part;

            if (result.part >= SCALE) {
                result.part -= SCALE;
                result.whole += 1;
            }

            return result;

        }

};

#endif