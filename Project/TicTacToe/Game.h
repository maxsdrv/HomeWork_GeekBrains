#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H

#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <vector>
#include <map>

using std::cout;
using std::cin;
using std::endl;

const int cst_row = 3;
const int cst_column = 3;

enum PLAYER {HUMAN = 'X', AI = '0', EMPTY = '_'};
using vector = std::vector<std::vector<PLAYER>>;
typedef struct{
    int szX;
    int szY;
    int to_win;
    vector map;
}Field;


void Print(Field &field){
    system("clear");
    cout << "______________________" << endl;
    for (int i = 0; i < field.szY; ++i){
        cout << "|";
        for (int j = 0; j < field.szX; ++j){
            cout << static_cast<char>(field.map.at(j).at(i)) << "|";
        }
        cout << endl;
    }
}


void init(Field &field, int x, int y){
    field.to_win = 3;
    field.szX = 3;
    field.szY = 3;
    for (int i = 0; i < field.szY; ++i){
        field.map.resize(field.szY);
        for (int j = 0; j < field.szX; ++j){
            field.map[i].push_back(EMPTY);
        }
    }

}





#endif //TICTACTOE_GAME_H
