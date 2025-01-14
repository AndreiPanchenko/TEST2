#pragma once
#include <iostream>
#include <string>

using namespace std;

// Структура для представления дроби
struct Fraction {
    long long numerator;   // Числитель
    long long denominator; // Знаменатель

    // Конструктор
    Fraction(long long num, long long denom);

    // Упрощение дроби
    void simplify();

    // Операция сложения дробей
    Fraction operator+(const Fraction& other) const;

    // Вывод дроби
    void print() const;

private:
    // Нахождение НОД
    long long findGCD(long long a, long long b);
};

// Функция для вычисления суммы дробей
Fraction computeSum(int n);

// Функция для преобразования строки в целое число
bool stringToInt(const string& str, int& result);

// Функция для проверки корректности ввода
int getInput();