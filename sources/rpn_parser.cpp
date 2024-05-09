#include "../headers/algebraic_interpreter.h"

#include <typeinfo>

list<Token *> rpn_parse(list<Token *> &in) {
    list<Token *> st = {}, out = {};
    for(const auto &t : in) {
        if (auto o = dynamic_cast<Operator *>(t)) {
            if (o->op == BRACKET_OPEN) {
                st.push_back(o);
            }
            
        } else {
            auto n = dynamic_cast<Number *>(t);

        }
    }
    return in;
}