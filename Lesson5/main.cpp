#include <iostream>

using namespace std;

void ChangedArray(int* array, int size){
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
void Shift(int* arr, int n, int s){
    if (n > 0){
        int temp = arr[s - 1];
        for (int i = s - 1; i > 0; --i){
            arr[i] = arr[i - 1];
        }
        arr[0] = temp;
    }
    else{
        int tmp = arr[0];
        for (int i = 0; i < s - 1; ++i){
            arr[i] = arr[i + 1];
        }
        arr[s - 1] = tmp;
    }
}

int main() {

    const int length = 10;
    int array[length] {1, 1, 0, 1, 0, 0, 1, 1, 0, 0};
    ChangedArray(array, length);
    for (const int& i : array){
        cout << i << " ";
    }
    cout << endl;

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
    const int size_shift_array = 5;
    const int n = -1; //Direction of shift
    int shift_array[size_shift_array] {1, 2, 3, 4, 5};
    cout << "Array before changes: " << endl;
    for (const int i : shift_array){
        cout << i << " ";
    }
    cout << endl << "Array after changes: " << endl;
    Shift(shift_array, n, size_shift_array);
    for (const int i : shift_array){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
