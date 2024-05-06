#include "../headers/algebraic_interpreter.h"

NUMBER_TYPE calculate(string &expression) {
    auto c1 = lex(expression);
    auto c2 = rpn_parse(c1);
    auto c3 = eval(c2);
    return c3;
}

NUMBER_TYPE eval(list<Token> &tokens) {
    return 0;
}