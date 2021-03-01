//
// Created by maxim on 12.02.2021.
//

#ifndef LESSON5_SHIFTARRAY_H
#define LESSON5_SHIFTARRAY_H

#include <iostream>
#include <cassert>

using namespace std;

namespace Lesson5{
    void Shift(int *arr, int size_array, int n){
        int temp = 0;
        if (n < 0) n = -n;
        assert(n != 0);
        for (int i = 0; i < n; ++i){
            if (n > 0){
                temp = arr[size_array - 1];
                for (int j = size_array - 1; j >= 0; --j){
                    arr[j + 1] = arr[j];
                }
                arr[0] = temp;
            }
            else{
                temp = arr[0];
                for (int j = 0; j < size_array; ++j){
                    arr[j - 1] = arr[j];
                }
                    arr[size_array - 1] = temp;
            }
        }
    }

}

#endif //LESSON5_SHIFTARRAY_H
