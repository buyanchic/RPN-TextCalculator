#include <iostream>
#include <string>

#include "headers/algebraic_interpreter.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main() {
    string s;
    cout << "Enter expression to calculate:" << endl;
    cin >> s;
    list<Token *> l = lex(s);
    for (auto t: l) {
        t->print_info();
        delete t;
    }
    // NUMBER_TYPE res = calculate();
    // cout << "Result: " << endl;
    return 0;
}
