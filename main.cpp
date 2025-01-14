#include <iostream>
#include "Fraction.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int n = getInput(); // Получаем корректный ввод от пользователя

    Fraction result = computeSum(n); // Вычисляем сумму дробей

    cout << "Сумма дробей: ";
    result.print(); // Выводим результат

    return 0;
}
