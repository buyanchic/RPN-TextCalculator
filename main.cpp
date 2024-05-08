#include <iostream>

#include "headers/algebraic_interpreter.h"

using namespace std;

int main() {
    list<Token *> l = lex("+1");
    for (auto t : l) {
        t->print_info();
    }
    cout << "end of program";
    return 0;
}
