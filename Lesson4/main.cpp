#include <iostream>
#include <vector>

using namespace std;

int main() {
/*Task 1. Написать программу, проверяющую что сумма двух чисел лежит
 * в пределах от 10 до 20 (включительно), если да – вывести true,
 * в противном случае – false;*/
    int foo1 = 15;
    int foo2 = 2;
    int sum = foo1 + foo2;
    const int range = 10;
    const int range2 = 20;
    if (sum >= range && sum <= range2){
        cout << "true" << endl;
    }else
        cout << "false" << endl;

/*Task 2. Написать программу, проверяющую, является ли некоторое число
 * - натуральным простым. Простое число - это число, которое делится без
 * остатка только на единицу и себя само.*/
    const int size_vector {200};
    vector<int> some_vector;//Использовал std::vector так как я его знаю
    for (int i = 0; i < size_vector; ++i){
        some_vector.push_back(i);
    }
    for (int i = 2; i < some_vector.size(); ++i){
        if (some_vector.at(i)!= 0){
            cout << some_vector.at(i) << endl;
            for (int j = i * i; j < some_vector.size(); j += i){
                some_vector.at(j) = 0;
            }
        }
    }

/*Task 3. Написать программу, выводящую на экран “истину”, если две
 * целочисленные константы, объявленные в её начале либо равны десяти
 * сами по себе, либо их сумма равна десяти.*/
    const int not_change {10};
    int a, b = 0;
    cin >> a >> b;
    while (a == not_change || b == not_change || a + b == not_change){
        cout << "true" << endl;
        break;
    }

/*Task 4. * Написать программу, которая определяет является ли год високосным.
* Каждый 4-й год является високосным, кроме каждого 100-го, при этом каждый 400-й
 * – високосный. Для проверки работы вывести результаты работы программы в консоль*/
    int year = 0;
    cout << "Input year please: ";
    cin >> year;
    if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)){
        cout << year << " is not leap year" << endl;
    }
    else
        cout << year << " is leap year" << endl;



    return 0;
}





















