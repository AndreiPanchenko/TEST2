#include "Fraction.h"

// Конструктор
Fraction::Fraction(long long num, long long denom) : numerator(num), denominator(denom) {
    simplify();
}

// Упрощение дроби
void Fraction::simplify() {
    long long gcd = findGCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
}

// Нахождение НОД
long long Fraction::findGCD(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Операция сложения дробей
Fraction Fraction::operator+(const Fraction& other) const {
    long long commonDenominator = denominator * other.denominator;
    long long newNumerator = numerator * other.denominator + other.numerator * denominator;
    return Fraction(newNumerator, commonDenominator);
}

// Вывод дроби
void Fraction::print() const {
    cout << numerator << " / " << denominator << endl;
}

// Функция для вычисления суммы дробей
Fraction computeSum(int n) {
    Fraction sum(0, 1); // Инициализация суммы как 0/1

    for (int i = 1; i <= n; ++i) {
        long long factorial = 1;

        // Вычисляем i!
        for (int j = 1; j <= i; ++j) {
            factorial *= j;
        }

        // Добавляем 1/i! к сумме
        sum = sum + Fraction(1, factorial);
    }

    return sum;
}

// Функция для преобразования строки в целое число
bool stringToInt(const string& str, int& result) {
    result = 0;
    for (char c : str) {
        if (!isdigit(c)) { // Проверяем, состоит ли строка только из цифр
            return false; // Если нет - возвращаем false
        }
        result = result * 10 + (c - '0'); // Преобразуем символ в число
    }
    return true; // Возвращаем true, если преобразование успешно
}

// Функция для проверки корректности ввода
int getInput() {
    string input;

    while (true) {
        cout << "Введите натуральное число n (n > 10): ";
        getline(cin, input); // Считываем ввод как строку

        int n;
        if (stringToInt(input, n) && n > 10) { // Проверяем корректность и значение
            return n; // Возвращаем корректное значение
        }

        cout << "Некорректный ввод. Пожалуйста, попробуйте снова." << endl;
    }
}
