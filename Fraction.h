#pragma once
#include <iostream>
#include <string>

using namespace std;

// ��������� ��� ������������� �����
struct Fraction {
    long long numerator;   // ���������
    long long denominator; // �����������

    // �����������
    Fraction(long long num, long long denom);

    // ��������� �����
    void simplify();

    // �������� �������� ������
    Fraction operator+(const Fraction& other) const;

    // ����� �����
    void print() const;

private:
    // ���������� ���
    long long findGCD(long long a, long long b);
};

// ������� ��� ���������� ����� ������
Fraction computeSum(int n);

// ������� ��� �������������� ������ � ����� �����
bool stringToInt(const string& str, int& result);

// ������� ��� �������� ������������ �����
int getInput();