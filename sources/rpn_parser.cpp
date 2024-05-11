#include "../headers/algebraic_interpreter.h"

#include <typeinfo>

list<Token *> rpn_parse(list<Token *> &in) {
    list<Token *> st = {}, out = {};
    for(const auto &t : in) {
        if (auto o = dynamic_cast<Operator *>(t)) {
            if (o->op == BRACKET_OPEN || o->is_prefix) {
                st.push_back(o);
            }
            if (!o->is_prefix) {
                out.push_back(o);
            }
            if(o->is_binary) {
                // Обработка бинарных
            }
            if (o->op == BRACKET_CLOSE) {
                while (!st.back()->is_bracket_open() || !st.empty()) {
                    auto q = st.back();
                    out.push_back(q);
                    st.pop_back();
                }
                if (st.empty())
                    throw runtime_error("Error when placing brackets");
                st.pop_back();
            }
        } else {
            auto n = dynamic_cast<Number *>(t);
            out.push_back(n);
        }
    }
    return out;
}