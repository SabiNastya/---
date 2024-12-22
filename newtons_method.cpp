#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

double f(double x) 
{
    return x - 1.0 / (3 + sin(3.6 * x));
}

double df(double x) 
{
    // Производная f(x)
    double sin_term = sin(3.6 * x);
    double cos_term = cos(3.6 * x);
    return 1 + (3.6 * cos_term) / pow(3 + sin_term, 2);
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    double x0 = 0.0; // Начальное приближение
    double tolerance = 1e-6; // Точность
    int max_iterations = 1000; // Максимальное количество итераций
    int iteration_count = 0;
    bool found_solution = false; // Флаг для решения

    while (iteration_count < max_iterations && !found_solution) {
        double fx0 = f(x0);
        double dfx0 = df(x0);

        if (fabs(dfx0) < 1e-10) { // Проверка на ноль производной
            cout << "Производная близка к нулю. Метод не может продолжаться." << endl;
            return -1;
        }

        double x1 = x0 - fx0 / dfx0; // Формула метода Ньютона

        if (fabs(x1 - x0) < tolerance) {
            found_solution = true; // решение найдено
        }


        cout << "x = " << x1 << endl;
        cout << "Точность = " << fabs(x1 - x0) << endl;
        cout << "Количество итераций: " << iteration_count + 1 << endl;

        x0 = x1; 
        iteration_count++;
    }

    if (!found_solution) {
        cout << "Не удалось найти решение за заданное количество итераций." << endl;
    }

    return 0;
}
