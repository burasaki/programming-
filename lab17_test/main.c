#include "main.h"
// 基本的な算術演算
double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    }
    else {
        printf("エラー: 0で割ることはできません。\n");
        return NAN; // Not a Number を返す
    }
}

// 数学関数
double sine(double a) { return sin(a); }
double cosine(double a) { return cos(a); }
double tangent(double a) { return tan(a); }
double logarithm(double a) {
    if (a > 0) {
        return log(a); // 自然対数
    }
    else {
        printf("エラー: 正でない値の対数は定義されていません。\n");
        return NAN;
    }
}
double power(double base, double exp) { return pow(base, exp); }
double square_root(double a) {
    if (a >= 0) {
        return sqrt(a);
    }
    else {
        printf("エラー: 負の数の平方根は実数ではありません。\n");
        return NAN;
    }
}
