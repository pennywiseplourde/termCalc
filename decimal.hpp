#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <cstdint>
#include <cmath>

class decimal {

    public:
        u_int64_t whole;
        u_int64_t frac;
        unsigned int sign : 1;

        static constexpr u_int64_t SCALE = 1'000'000'000'000'000ULL;

        decimal() = default;

        decimal(const char* str) {

            std::string s(str);

            if (s[0] == '-') {
                sign = 0;
                s = s.substr(1);
            } else if (s[0] == '+') {
                sign = 1;
                s = s.substr(1);
            } else {
                sign = 1;
            }

            size_t dot = s.find(".");

            if (dot == std::string::npos) {
                whole = std::stoll(s);
                frac = 0;
            } else {
                whole = std::stoll(s.substr(0, dot));
                std::string fracstr = s.substr(dot + 1);

                if (fracstr.length() < 9) {
                    fracstr.append(9 - fracstr.length(), '0');

                } else {
                    fracstr = fracstr.substr(0, 9);
                }

                frac = std::stoull(fracstr);
            }

        }

        decimal operator+(const decimal& num) {

            decimal result;

            if (sign == num.sign && sign == 1) {

                result.whole = whole + num.whole;
                result.frac = frac + num.whole;
                result.sign = 1;

            } else if (sign == num.sign && sign == 0) {

                result.whole = whole + num.whole;
                result.frac = frac + num.frac;
                result.sign = 0;

            } else if (sign == 1 && num.sign == 0) {

                if () // continue here

            }

            while (result.frac >= SCALE) {

                result.frac -= SCALE;
                result.whole ++;

            }




        }

};