#include <iostream>
#include <random>

#define CONDITION(X, Y) ((X) >= (0) && (X) < (Y) ? ("true") : ("false"))
#define ACCESS(arr, n1, n2) arr[n1][n2]

int main() {
    using std::cout;
    using std::cin;
    using std::endl;

    //Random decimals
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 10);
/* Task 1. Описать макрокоманду, проверяющую, входит ли переданное
 * ей число в диапазон от нуля (включительно) до переданного ей
 * второго аргумента (исключительно) */
    cout << CONDITION(11, 10) << endl;

/* Task 2.  Описать макрокоманду, получающую доступ к элементу
 * двумерного массива (организованного динамически) посредством
 * разыменования указателей */
    int **array = new int*[3];
    for (int i = 0; i < 3; ++i){
        array[i] = new int[2];
    }
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 2; ++j){
            array[i][j] = dist(mt);
        }
    }
    cout << "Enter the number of item in your array:  " << endl;
    int x = 0, y = 0;
    //cin >> x >> y;
    cout << ACCESS(array, x, y) << endl;
    for (int i = 0; i < 3; ++i){
      delete[] array[i];
    }
    delete[] array;


    return 0;
}
