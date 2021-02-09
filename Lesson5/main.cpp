#include <iostream>

using namespace std;

void ChangedArray(int* array, int size){
    for (int i = 0; i < size; ++i){
        if (array[i] == 0){
            array[i] = 1;
        }
        else{
            array[i] = 0;
        }
    }
}

int main() {

    const int length = 10;
    int array[length] {1, 1, 0, 1, 0, 0, 1, 1, 0, 0};
    ChangedArray(array, length);
    for (int i = 0; i < length; ++i){
        cout << array[i] << " ";
    }
    cout << endl;


    return 0;
}
