#include "../headers/algebraic_interpreter.h"

#include <cmath>
#include <stdexcept>
#include <iostream>
#include <math.h>

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
Number *get_num(const string &ex, int &i) {
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
    i--;
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

/// Проверка наличия конкретного оператора в выражении
bool the_op_in_exp(const string &ex, const string &op, int &i) {
    for (int j = 0; j < op.size(); j++)
        if (ex[j + i] != op[j])
            return false;
    return true;
}

/// Попытка обработки любого определенного оператора в конкретном месте строки
bool any_op_in_exp(const string &ex, int &i, list<Token *> &l) {
    auto ops_info = get_operators_info();
    for (const auto &op: ops_info) {
        // Влезет ли токен в строку
        if (get<0>(op).size() > (ex.size() - i)) continue;
        // Посимвольная проверка токена
        if (!the_op_in_exp(ex, get<0>(op), i)) continue;
        // Добавляем токен в список, результат найден
        l.push_back(new Operator(get<1>(op), get<2>(op), get<3>(op)));
        i += get<0>(op).size() - 1;
        return true;
    }
    return false;
}

/// Проверка буквы
bool check_lett(const char &s) {
    if ((int)s >= 97 && (int)s <= 122)
        return true;
    return false;
}

/// Взять значение переменной и вернуть его
Number *get_var(const char &s) {
    cout << "Enter " << s << ": " << endl;
    NUMBER_TYPE v;
    cin >> v;
    return new Number(v);
}

/// Обработка констант
Number *proc_const(const string &ex, int &i) {
    if (ex[i] == 'p' && ex[i+1]=='i') {
        i++;
        return new Number(M_PI);
    }
    if (ex[i] == 'e') {
        return new Number(M_E);
    }
}

list<Token *> lex(const string &ex) {
    list<Token *> l = {};
    int expr_size = ex.size();
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
        if (any_op_in_exp(ex, i, l)) continue;

        // Обработать константы
        if (ex[i] == 'e' || (ex[i] == 'p' && ex[i+1] =='i')) {
            l.push_back(proc_const(ex, i));
            continue;
        }
        // TODO Обработать переменные - одна и та же переменная = одно и то же значение и цикличность
        if (check_lett(ex[i]) && (l.empty() || l.back()->check_type())) {
            l.push_back(get_var(ex[i]));
            continue;
        }
        // При нахождении токена обязательно делать continue
        throw runtime_error("Unknown token");
    }
    return l;
}
