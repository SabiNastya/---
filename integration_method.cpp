#include <iostream>
#include <cmath>
#include <clocale>
#include <iomanip>
using namespace std;

double f(double x) // заданная функция
{
    return 1.0 / (3.0 + sin(3.6 * x));
}

int main()
{
    setlocale(LC_ALL, "Russian");
    double x_n = 0.0; // Начальное значение
    double tolerance = 1e-6; // Точность, максимально минимальное число
    int max_iterations = 100; // Максимальное количество итераций
    int iteration_count = 0; // Счетчик итераций
    bool found_solution = false; // Флаг, отвечающий за выход из цикла

    while (iteration_count < max_iterations && !found_solution) {
        double x_next = f(x_n);
        iteration_count++;
        cout << "Точность: " << abs(x_next - x_n) << endl;

        if (abs(x_next - x_n) < tolerance) {
            found_solution = true;
        }

        x_n = x_next;
        cout << "Приближенное значение корня: " << setprecision(10) << x_n << endl;
        cout << "Количество итераций: " << iteration_count << endl;
    }
    
    return 0;
}

