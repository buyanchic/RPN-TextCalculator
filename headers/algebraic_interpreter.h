#pragma once
#ifndef HEADERS_ALGEBRAIC_INTERPRETER_H
#define HEADERS_ALGEBRAIC_INTERPRETER_H 1

#include <list>
#include <string>

#include "defines.h"

using namespace std;

/// Считает результат строкового арифметического выражения
NUMBER_TYPE calculate(const string &expression);

/// Переделывает строку в инфиксную последовательность токенов
list<Token *> lex(const string &ex);

/// Переделывает инфиксную последовательность токенов в постфиксную
list<Token *> rpn_parse(list<Token *> &in);

/// Вычисляет результат постфиксной последовательности
NUMBER_TYPE eval(list<Token *> &tokens);

#endif // HEADERS_ALGEBRAIC_INTERPRETER_H
