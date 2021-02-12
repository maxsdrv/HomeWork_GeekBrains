//
// Created by maksim.sidorov on 12.02.2021.
//
namespace Lesson5 {
    void Task1(int *array, const int size) {
        for (int i = 0; i < size; ++i) {
            array[i] = 0 ^ 1 ^ array[i];
        }
    }
}

#ifndef LESSON5_CHANGEDARRAY_H
#define LESSON5_CHANGEDARRAY_H

#endif //LESSON5_CHANGEDARRAY_H
