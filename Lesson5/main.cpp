#include <iostream>
#include <cstdarg>
#include <vector>

#include "ChangedArray.h"

using namespace std;

void ChangedArray(int* array, const int size){
    for (int i = 0; i < size; ++i){
        array[i] = 0 ^ 1 ^ array[i];
    }
}
void FillIn(int* arr, const int length){
    for (int i = 0, temp, step = 3; i < length; ++i){
        if (i <= 0){
            arr[i] = 1;
            temp = arr[i] + step;
        }
        else{
            arr[i] = temp;
            temp = arr[i] + step;
        }
    }
}
bool SortArray(const int* arr, const int size){
    bool result = false;
    int temp = 0;
    int sum = 0;
    for (int i = 1; i < size; ++i){
        sum += arr[i];
    }
    for (int i = 0; i < size; ++i){
        temp += arr[i];
        if (temp == sum){
            result = true;
            break;
        }
        else {
            sum -= arr[i + 1];
        }
    }
    return result;
}
void Shift(int *arr, int n){
    int size_array = sizeof(arr) + 1;
    int temp = 0;
    if (n == 0) cout << "Error input shift " << n << " must be > or < 0" << endl;
    if (n > 0){
        for (int i = 0; i < n; ++i){
            for (int j = size_array - 1; j >= 0; --j){
                if (arr[j] == arr[size_array - 1]){
                    temp = arr[size_array - 1];
                }
                else{
                    arr[j + 1] = arr[j];
                }
            }
            arr[0] = temp;
        }
    }
    else{
        n = -n;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < size_array; ++j){
                if (arr[j] == arr[0]){
                    temp = arr[0];
                }
                else{
                    arr[j - 1] = arr[j];
                }
            }
            arr[size_array - 1] = temp;
        }
    }

}

vector<int> FuncWithValue(int s, ...){
    va_list ap;
    va_start(ap, s);
    vector<int> exotic_vector;
    for (int i = 0; i < s; ++i){
        exotic_vector.push_back(0 ^ 1 ^ va_arg(ap, int));
    }

    va_end(ap);
    return exotic_vector;
}

int main() {
/* Task 1. Задать целочисленный массив, состоящий из элементов 0 и 1.
* Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. Написать функцию, заменяющую
 * в принятом массиве 0 на 1, 1 на 0; */
    const int length = 10;
    int array[length] {1, 1, 0, 1, 0, 0, 1, 1, 0, 0};
    ChangedArray(array, length);
    for (const int& i : array){
        cout << i << " ";
    }
    cout << endl;

/* Task 2. Задать пустой целочисленный массив размером 8. Написать функцию,
 * которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22; */

    const int size_array = 8;
    int mass[size_array];
    FillIn(mass, size_array);
    for (const int& i : mass){
        cout << i << " ";
    }
    cout << endl;

/* Task 3. * Написать метод, в который передается не пустой одномерный
 * целочисленный массив, метод должен вернуть истину если в массиве есть
 * место, в котором сумма левой и правой части массива равны.
 * Примеры: checkBalance([1, 1, 1, || 2, 1]) → true, checkBalance
 * ([2, 1, 1, 2, 1]) → false, checkBalance ([10, || 1, 2, 3, 4]) → true.
 * Абстрактная граница показана символами ||, эти символы в массив не входят.
 * */

    const int size_arr2 = 5;
    int arr2[size_arr2] {10, 1, 2, 3, 4};
    cout << "Operation result = " << SortArray(arr2, size_arr2) << endl;

/* Task 4. * Написать функцию, которой на вход подаётся одномерный
 * массив и число n (может быть положительным, или отрицательным),
 * при этом метод должен циклически сместить все элементы массива на n позиций.
 * */
    const int size_shift_array = 5; //Size array for shift
    cout << "Input shift direction" << endl;
    int n = 0; //Shift direction
//    cin >> n;
    int shift_array[size_shift_array] {1, 2, 3, 4, 5};
    cout << "Array before changes: " << endl;
    for (const int i : shift_array){
        cout << i << " ";
    }
    cout << endl << "Array after changes: " << endl;
    Shift(shift_array, n);
    for (const int i : shift_array){
        cout << i << " ";
    }
    cout << endl;

/* Task 5. Написать функцию из первого задания так, чтобы она работала
 * с аргументом переменной длины. */
    const int task5_size = 10;
    vector<int> result = FuncWithValue(task5_size, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0);
    cout << "Result task 5 = " << endl;
    for (const int& r : result){
        cout << r << " ";
    }
    cout << endl;

/* Task 6. ** Написать все функции в отдельных файлах в одном пространстве
 * имён, вызвать их на исполнение в основном файле программы используя
 * указатели на функции. */

    using namespace Lesson5; {
        void (*ptr_changed_array)(int *, int) = Task1;
        const int length = 10;
        int array[length]{1, 1, 0, 1, 0, 0, 1, 1, 0, 0};
        ptr_changed_array(array, length);
        cout << "Using namespace Lesson5" << endl;
        for (const int ar : array){
            cout << ar << " ";
        }
        cout << endl;

    }




    return 0;
}

























