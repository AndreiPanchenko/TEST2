#include "Fraction.h"

// �����������
Fraction::Fraction(long long num, long long denom) : numerator(num), denominator(denom) {
    simplify();
}

// ��������� �����
void Fraction::simplify() {
    long long gcd = findGCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
}

// ���������� ���
long long Fraction::findGCD(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// �������� �������� ������
Fraction Fraction::operator+(const Fraction& other) const {
    long long commonDenominator = denominator * other.denominator;
    long long newNumerator = numerator * other.denominator + other.numerator * denominator;
    return Fraction(newNumerator, commonDenominator);
}

// ����� �����
void Fraction::print() const {
    cout << numerator << " / " << denominator << endl;
}

// ������� ��� ���������� ����� ������
Fraction computeSum(int n) {
    Fraction sum(0, 1); // ������������� ����� ��� 0/1

    for (int i = 1; i <= n; ++i) {
        long long factorial = 1;

        // ��������� i!
        for (int j = 1; j <= i; ++j) {
            factorial *= j;
        }

        // ��������� 1/i! � �����
        sum = sum + Fraction(1, factorial);
    }

    return sum;
}

// ������� ��� �������������� ������ � ����� �����
bool stringToInt(const string& str, int& result) {
    result = 0;
    for (char c : str) {
        if (!isdigit(c)) { // ���������, ������� �� ������ ������ �� ����
            return false; // ���� ��� - ���������� false
        }
        result = result * 10 + (c - '0'); // ����������� ������ � �����
    }
    return true; // ���������� true, ���� �������������� �������
}

// ������� ��� �������� ������������ �����
int getInput() {
    string input;

    while (true) {
        cout << "������� ����������� ����� n (n > 10): ";
        getline(cin, input); // ��������� ���� ��� ������

        int n;
        if (stringToInt(input, n) && n > 10) { // ��������� ������������ � ��������
            return n; // ���������� ���������� ��������
        }

        cout << "������������ ����. ����������, ���������� �����." << endl;
    }
}
