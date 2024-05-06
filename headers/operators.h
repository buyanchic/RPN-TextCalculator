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
        case BRACKET_CLOSE: return P_BRACKETS;
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
        case FACTORIAL: return P_FUNCTION;
        case POW: return P_POW;
        case MUL:
        case DIV: return P_MUL_DIV;
        case PLUS:
        case MINUS: return P_PLUS_MINUS;
        case INT_DIV: return P_INT_DIV;
        case MOD: return P_MOD;
        case UNARY_PLUS:
        case UNARY_MINUS: return P_UNARY;
        default: return 0;
    }
}

#define BINARY 1
#define UNARY 0
#define PREFIX 1
#define POSTFIX 0

inline set<tuple<string, OperatorType, bool, bool> > get_operators_info() {
    return set<tuple<string, OperatorType, bool, bool> >
    {
        {"(", BRACKET_OPEN, 0, 0},
        {")", BRACKET_CLOSE, 0, 0},
        {"sin", SIN, UNARY, PREFIX},
        {"cos", COS, UNARY, PREFIX},
        {"sec", SEC, UNARY, PREFIX},
        {"cosec", COSEC, UNARY, PREFIX},
        {"tg", TAN, UNARY, PREFIX},
        {"ctg", CTG, UNARY, PREFIX},
        {"arcsin", ARC_SIN, UNARY, PREFIX},
        {"arccos", ARC_COS, UNARY, PREFIX},
        {"arctg", ARC_TAN, UNARY, PREFIX},
        {"arcctg", ARC_CTG, UNARY, PREFIX},
        {"arcsec", ARC_SEC, UNARY, PREFIX},
        {"arccosec", ARC_COSEC, UNARY, PREFIX},
        {"^", POW, BINARY, 0},
        {"*", MUL, BINARY, 0},
        {":", DIV, BINARY, 0},
        {"+", PLUS, BINARY, 0},
        {"-", MINUS, BINARY, 0},
        {"/", INT_DIV, BINARY, 0},
        {"%", MOD, BINARY, 0},
        {"ln", LN, UNARY, PREFIX},
        {"lg", LG, UNARY, PREFIX},
        {"log", LOG, UNARY, PREFIX},
        {"!", FACTORIAL, UNARY, POSTFIX},
    };
}

#endif // HEADERS_OPERATORS_H
