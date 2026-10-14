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

        bool operator==(const decimal& num) {

            bool result;

            if (sign == num.sign && whole == num.whole && frac == num.frac) {
                result = true;
            } else {
                result = false;
            }

            return result;
        }

        bool operator>(const decimal& num) {

            bool result;

            if (*this == num) {
                result = false;
            } else if (sign == 1 && num.sign == 0) {
                result = true;
            } else if (sign == 0 && num.sign == 1) {
                result = false;
            } else if (sign == num.sign && sign == 1) {
                if (whole > num.whole) {
                    result = true;
                } else if (whole == num.whole && frac > num.frac) {
                    result = true;
                } else {
                    result = false;
                }
            } else if (sign == num.sign && sign == 0) {
                if (whole < num.whole) {
                    result = true;
                } else if (whole == num.whole && frac < num.frac) {
                    result = true;
                } else {
                    result = false;
                }
            }

            return result;

        }

        bool operator<(const decimal& num) {

            bool result;

            if (*this == num) {
                result = false;
            } else if (sign == 1 && num.sign == 0) {
                result = false;
            } else if (sign == 0 && num.sign == 1) {
                result = true;
            } else if (sign == num.sign && sign == 1) {
                if (whole < num.whole) {
                    result = true;
                } else if (whole == num.whole && frac < num.frac) {
                    result = true;
                } else {
                    result = false;
                }
            } else if (sign == num.sign && sign == 0) {
                if (whole > num.whole) {
                    result = true;
                } else if (whole == num.whole && frac > num.frac) {
                    result = true;
                } else {
                    result = false;
                }
            }

            return result;

        }

        decimal operator+(const decimal& num) {

            decimal result;

            if (sign == num.sign && sign == 1) {

                result.whole = whole + num.whole;
                result.frac = frac + num.frac;
                result.sign = 1;

            } else if (sign == num.sign && sign == 0) {

                result.whole = whole + num.whole;
                result.frac = frac + num.frac;
                result.sign = 0;

            } else if (sign == 1 && num.sign == 0) {

                if (*this > num) {

                    decimal num1 = num;
                    num1.sign = 1;
                    result = *this - num1; // currently undefined

                } else if (*this < num) {

                    decimal num1 = num;
                    num1.sign = 1;
                    result = num - this;
                    result.sign = 0;

                } else if (whole == num.whole && frac == num.frac) {
                    result.whole = 0;
                    result.frac = 0;
                    result.sign = 1;
                }
            }

            while (result.frac >= SCALE) {

                result.frac -= SCALE;
                result.whole ++;

            }


            return result;

        } 

        decimal operator-(const decimal& num) {

            decimal result;

            if (sign == num.sign && sign == 1) {
                if (*this > num) {

                    

                } else if (*this < num) {

                }
            }

            return result;

        }

};