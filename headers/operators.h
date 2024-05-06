#pragma once
#ifndef PROJECT_OPERATORS_H
#define PROJECT_OPERATORS_H 1

typedef unsigned short byte;

enum OperatorType
{
    BRACKET_OPEN,   /* Brackets */
    BRACKET_CLOSE,
    SIN,            /* Trigonometry */
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
    POW,            /* Default */
    MUL,
    DIV,
    PLUS,
    MINUS,
    INT_DIV,        /* Special divs */
    MOD,
    LN,             /* Logarithms */
    LG,
    LOG,
    FACTORIAL,      /* Special */
    UNARY_PLUS,
    UNARY_MINUS,
};

const byte get_priority(OperatorType type)
{
    return 0;
}

#endif //PROJECT_OPERATORS_H
