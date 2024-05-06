#include <iostream>
#include <string>
#include <typeinfo>

#include "headers/algebraic_interpreter.h"

using namespace std;

int main() {
    list<Token *> l = lex("+1");
    for (auto *t : l) {
        t->print_info();
    }
    // string s;
    // cout << "Введите выражение: ";
    // cin >> s;
    // cout << "Результат: " << calculate(s);
    cout << "end of program";
    return 0;
}
