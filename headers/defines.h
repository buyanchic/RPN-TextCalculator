#pragma once
#ifndef HEADERS_DEFINES_H
#define HEADERS_DEFINES_H 1

#include <iostream>
#include "operators.h"

#define NUMBER_TYPE long double

class Token {
public:
    virtual void print_info() = 0;
};

class Number : public Token {
public:
    NUMBER_TYPE number;

    Number(const NUMBER_TYPE &number)
        : number(number) {
    }

    virtual void print_info() override {
        std::cout << "Num: " << number << std::endl;
    };
};

class Operator : public Token {
public:
    OperatorType op;
    bool is_binary;
    bool is_prefix;

    Operator(const OperatorType &_op, const bool &binary, const bool &prefix)
        : op(_op), is_binary(binary), is_prefix(prefix) {
    }

    virtual void print_info() override {
        std::cout << "Op: " << op << std::endl;
    };
};

#endif // HEADERS_DEFINES_H
