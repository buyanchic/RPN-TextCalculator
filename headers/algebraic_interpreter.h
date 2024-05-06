#pragma once
#ifndef HEADERS_ALGEBRAIC_INTERPRETER_H
#define HEADERS_ALGEBRAIC_INTERPRETER_H 1

#include <list>
#include <string>

#include "defines.h"

using namespace std;

void get_unary(const string &ex, int &i, list<Token *> &l);

Number get_num(const string &ex, int &i);

/// Считает результат строкового арифметического выражения
NUMBER_TYPE calculate(string &expression);

/// Переделывает строку в инфиксную последовательность токенов
list<Token *> lex(const string &ex);

/// Переделывает инфиксную последовательность токенов в постфиксную
list<Token *> rpn_parse(list<Token *> &tokens);

/// Вычисляет результат постфиксной последовательности
NUMBER_TYPE eval(list<Token *> &tokens);

#endif // HEADERS_ALGEBRAIC_INTERPRETER_H
