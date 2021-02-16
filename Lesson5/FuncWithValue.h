//
// Created by maxim on 12.02.2021.
//

#ifndef LESSON5_FUNCWITHVALUE_H
#define LESSON5_FUNCWITHVALUE_H

#include <vector>
#include <cstdarg>

namespace Lesson5{
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

}

#endif //LESSON5_FUNCWITHVALUE_H
