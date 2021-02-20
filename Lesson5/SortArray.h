//
// Created by maxim on 12.02.2021.
//

#ifndef LESSON5_SORTARRAY_H
#define LESSON5_SORTARRAY_H

namespace Lesson5{
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
}

#endif //LESSON5_SORTARRAY_H
