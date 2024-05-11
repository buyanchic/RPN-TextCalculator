#pragma once
#ifndef HEADERS_DEFINES_H
#define HEADERS_DEFINES_H 1

#include <iostream>
#include "operators.h"

#define NUMBER_TYPE long double

class Token {
public:
    virtual void print_info() = 0;
    /// Возвращает true если это оператор, false - число
    virtual bool check_type() = 0;
    virtual bool is_bracket_open() = 0;

    virtual ~Token() = default;
};

class Number : public Token {
public:
    NUMBER_TYPE number;

    Number(const NUMBER_TYPE &number) : number(number) {}

    void print_info() override {
        std::cout << "Num: " << number << std::endl;
    }

    bool check_type() override {
        return 0;
    }

    bool is_bracket_open() override {
        return false;
    }

};

class Operator : public Token {
public:
    OperatorType op;
    bool is_binary;
    bool is_prefix;

    Operator(const OperatorType &_op, const bool &binary, const bool &prefix)
            : op(_op), is_binary(binary), is_prefix(prefix) {}

    void print_info() override {
        std::cout << "Op: " << op << std::endl;
    }

    bool check_type() override {
        return 1;
    }

    bool is_bracket_open() override {
        if (op==BRACKET_OPEN)
            return true;
        return false;
    }
};

#endif // HEADERS_DEFINES_H
