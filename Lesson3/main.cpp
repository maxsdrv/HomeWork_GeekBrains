#include <iostream>
#include <iomanip>

using namespace std;


int main() {
   /*Task 1.  Написать программу, вычисляющую выражение
    a * (b + (c / d)) и выводящую результат с плавающей точкой,
    где a, b, c, d – целочисленные константы; */

    int a = 3;
    int b = 5;
    int c = 6;
    int d = 4;
    double result = a * (b + (double(c) / d));
    cout << fixed;
    cout << setprecision(5) << result << endl;

    /* Task 2.Дано целое число, выведите на экран разницу между
     * этим числом и числом 21. Если же заданное число больше,
     * чем 21, необходимо вывести удвоенную разницу между этим
     * числом и 21. При выполнении задания следует использовать
     * тернарный оператор. */

    int random_decimal = 0;
    const int some_decimal = 21;
    cin >> random_decimal;
    int difference = (random_decimal > some_decimal) ? random_decimal = (random_decimal - some_decimal) * 2
                                    : random_decimal = some_decimal - random_decimal;
    cout << difference << endl;

    /* Task 3.* Написать программу, вычисляющую выражение из первого задания,
     * а переменные для неё инициализировать в другом файле */

    extern int other_a;
    extern int other_b;
    extern int other_c;
    extern int other_d;
    double other_result = other_a * (other_b + (double(other_c) / other_d));
    cout << fixed;
    cout << setprecision(5) << other_result << endl;

    /* Task 4.* Описать трёхмерный целочисленный массив, размером 3х3х3,
     * указатель на значения внутри массива и при помощи операции разыменования
     * вывести на экран значение центральной ячейки получившегося куба [1][1][1]*/

    const int SIZE = 3;
    int array_cube [SIZE][SIZE][SIZE] = {{{1, 2, 3}, {11, 12, 13}, {22, 23, 24}},
                                         {{10, 20, 30}, {101, 102, 103}, {105, 106, 107}},
                                         {{100, 200, 300}, {110, 120, 130}, {150, 160, 170}}};
    int *ptr_array_cube = **array_cube;
    ptr_array_cube = array_cube[1][1];
    cout << "[1][1][1]= " << *(ptr_array_cube + 1)<< endl;






    return 0;
}
