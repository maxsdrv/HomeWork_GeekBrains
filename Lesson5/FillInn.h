//
// Created by maxim on 12.02.2021.
//

#ifndef LESSON5_FILLINN_H
#define LESSON5_FILLINN_H
namespace Lesson5{
    void Task2(int* arr, const int length){
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
}

#endif //LESSON5_FILLINN_H
