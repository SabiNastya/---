#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

double f(double x) {
    return x - 1.0 / (3.0 + sin(3.6 * x));
}

double bisection(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        cout << "Функция имеет одинаковые знаки на концах интервала." << endl;
        return NAN; // Возвращаем NaN, если нет корня
    }

    double c;
    while ((b - a) >= tol) {
        // Находим среднюю точку
        c = (a + b) / 2;
        cout << "Cередина интервала " << "["<< a << ";" << b << "] : " << c << endl;

        // Проверяем, является ли c корнем
        if (f(c) == 0.0) {
            break; // Нашли корень
        }
        // Определяем, в каком подинтервале искать корень
        if (f(c) * f(a) < 0) {
            b = c; // Корень находится в [a, c]
        }
        else {
            a = c; // Корень находится в [c, b]
        }
    }
    return c; // Возвращаем приближенное значение корня
}

int main() {
    setlocale(LC_ALL, "Russian");
    double a = 0; // Начало интервала
    double b = 0.85; // Конец интервала
    double tol = 1e-6; // Точность

    double root = bisection(a, b, tol);

    if (!isnan(root)) {
        cout << "Приближенное значение корня: " << root << endl;
    }

    return 0;
}

