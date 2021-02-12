//
// Created by maxim on 12.02.2021.
//

#ifndef LESSON5_SHIFTARRAY_H
#define LESSON5_SHIFTARRAY_H

#include <iostream>

using namespace std;

namespace Lesson5{
    void Shift(int *arr, int size_array, int n){
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

}

#endif //LESSON5_SHIFTARRAY_H
