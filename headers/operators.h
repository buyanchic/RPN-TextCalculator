#pragma once
#ifndef HEADERS_OPERATORS_H
#define HEADERS_OPERATORS_H 1

#include <set>
#include <string>
#include <tuple>

using std::set;
using std::string;
using std::tuple;
using std::pair;
using std::make_pair;
using std::make_tuple;

typedef unsigned short byte;

enum OperatorType {
    BRACKET_OPEN, /* Brackets */
    BRACKET_CLOSE,
    SIN, /* Trigonometry */
    COS,
    SEC,
    COSEC,
    TAN,
    CTG,
    ARC_SIN,
    ARC_COS,
    ARC_TAN,
    ARC_CTG,
    ARC_SEC,
    ARC_COSEC,
    POW, /* Default */
    MUL,
    DIV,
    PLUS,
    MINUS,
    INT_DIV, /* Special divs */
    MOD,
    LN, /* Logarithms */
    LG,
    LOG,
    FACTORIAL, /* Special */
    UNARY_PLUS,
    UNARY_MINUS,
};

enum Priorities {
    P_BRACKETS = 255,
    P_FUNCTION = 200,
    P_POW = 170,
    P_UNARY = 130,
    P_MUL_DIV = 100,
    P_INT_DIV = 80,
    P_MOD = 40,
    P_PLUS_MINUS = 10,
};

inline byte get_priority(const OperatorType op) {
    switch (op) {
        case BRACKET_OPEN:
        case BRACKET_CLOSE:
            return P_BRACKETS;
        case SIN:
        case COS:
        case SEC:
        case COSEC:
        case TAN:
        case CTG:
        case ARC_SIN:
        case ARC_COS:
        case ARC_TAN:
        case ARC_CTG:
        case ARC_SEC:
        case ARC_COSEC:
        case LN:
        case LG:
        case LOG:
        case FACTORIAL:
            return P_FUNCTION;
        case POW:
            return P_POW;
        case MUL:
        case DIV:
            return P_MUL_DIV;
        case PLUS:
        case MINUS:
            return P_PLUS_MINUS;
        case INT_DIV:
            return P_INT_DIV;
        case MOD:
            return P_MOD;
        case UNARY_PLUS:
        case UNARY_MINUS:
            return P_UNARY;
        default:
            return 0;
    }
}

#define BINARY 1
#define UNARY 0
#define PREFIX 1
#define POSTFIX 0

/// Возвращает информацию об операторах без унарных + и -
inline set<tuple<string, OperatorType, bool, bool> > get_operators_info() {
    return set<tuple<string, OperatorType, bool, bool> >
            {
                    {"(",        BRACKET_OPEN,  0,  0},              // 0
                    {")",        BRACKET_CLOSE, 0,  0},              // 1
                    {"sin",      SIN,       UNARY, PREFIX},          // 2
                    {"cos",      COS,       UNARY, PREFIX},          // 3
                    {"sec",      SEC,       UNARY, PREFIX},          // 4
                    {"cosec",    COSEC,     UNARY, PREFIX},          // 5
                    {"tg",       TAN,       UNARY, PREFIX},          // 6
                    {"ctg",      CTG,       UNARY, PREFIX},          // 7
                    {"arcsin",   ARC_SIN,   UNARY, PREFIX},          // 8
                    {"arccos",   ARC_COS,   UNARY, PREFIX},          // 9
                    {"arctg",    ARC_TAN,   UNARY, PREFIX},          // 10
                    {"arcctg",   ARC_CTG,   UNARY, PREFIX},          // 11
                    {"arcsec",   ARC_SEC,   UNARY, PREFIX},          // 12
                    {"arccosec", ARC_COSEC, UNARY, PREFIX},          // 13
                    {"^",        POW,       BINARY, 0},              // 14
                    {"*",        MUL,       BINARY, 0},              // 15
                    {":",        DIV,       BINARY, 0},              // 16
                    {"+",        PLUS,      BINARY, 0},              // 17
                    {"-",        MINUS,     BINARY, 0},              // 18
                    {"/",        INT_DIV,   BINARY, 0},              // 19
                    {"%",        MOD,       BINARY, 0},              // 20
                    {"ln",       LN,        UNARY, PREFIX},          // 21
                    {"lg",       LG,        UNARY, PREFIX},          // 22
                    {"log",      LOG,       UNARY, PREFIX},          // 23
                    {"!",        FACTORIAL, UNARY, POSTFIX},         // 24
            };
}

#endif // HEADERS_OPERATORS_H
