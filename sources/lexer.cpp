#include "../headers/algebraic_interpreter.h"

#include <cmath>
#include <stdexcept>

using namespace std;

/// Получить мантиссу вещественного числа
NUMBER_TYPE get_mantis(const string &ex, int &i, bool digit_before_dot) {
    NUMBER_TYPE man = 0;
    int mantis_len = 0;
    bool digit_after_dot = false;
    // Чтение числа после точки
    while (isdigit(ex[i])) {
        man = man * 10 + (int) (ex[i] - 48);
        digit_after_dot = true;
        mantis_len++;
        i++;
    }
    // Обработка возможных ошибок
    if (!digit_before_dot && !digit_after_dot)
        throw runtime_error("Only dot in number!");
    if (ex[i] == '.' && mantis_len > 0)
        throw runtime_error("Many dots in a number!");
    // Возврат результата
    man *= pow(10, -mantis_len);
    return man;
}

/// Получить число из выражения, перейти к следующей лексеме
Number* get_num(const string &ex, int &i) {
    NUMBER_TYPE num = 0;
    bool digit_before_dot = false;
    // Чтение числа до точки
    while (isdigit(ex[i])) {
        num = num * 10 + (int) (ex[i] - 48);
        digit_before_dot = true;
        i++;
    }
    // Чтение точки и далее
    if (ex[i] == '.') {
        num += get_mantis(ex, ++i, digit_before_dot);
    }
    return new Number(num);
}

/// Проверка являются ли плюс и минус унарными
bool check_unary(const string &ex, int i, list<Token *> &l) {
    if (ex[i] != '+' && ex[i] != '-')
        return false;
    if (l.empty() || (ex[i - 1]) == '(')
        return true;
    return false;
}

/// Получить унарный оператор, перейти к следующему символу
void get_unary(const string &ex, int &i, list<Token *> &l) {
    if (ex[i] == '+')
        l.push_back(new Operator(UNARY_PLUS, UNARY, PREFIX));
    else
        l.push_back(new Operator(UNARY_MINUS, UNARY, PREFIX));
}

list<Token *> lex(const string &ex) {
    list<Token *> l = {};
    int expr_size = ex.size();
    auto ops_info = get_operators_info();
    // Посимвольное чтение
    for (int i = 0; i < expr_size; i++) {
        // Обработка чисел
        if (isdigit(ex[i]) || ex[i] == '.') {
            l.push_back(get_num(ex, i));
            continue;
        }
        // Обработка унарных + и -
        if (check_unary(ex, i, l)) {
            get_unary(ex, i, l);
            continue;
        }
        // Обработка операторов

        // При нахождении токена обязательно делать continue
        throw runtime_error("Unknown token");
    }
    return l;
}
