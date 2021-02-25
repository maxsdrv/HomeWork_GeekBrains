#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H

#include <iostream>
#include <string>
#include <random>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;

enum PLAYER {HUMAN = 'X', AI = '0', EMPTY = '_'};

const int size_fieldX = 3;
const int size_fieldY = 3;

typedef struct{
    int szX;
    int szY;
    PLAYER**map;
    int towin;
}Field;

void setval(PLAYER **map, int row, int column, PLAYER state){
    map[column][row] = state;
}

PLAYER getval(PLAYER **map, int row, int column){
    return map[column][row];
}

void init(Field &field, int x, int y){
    field.towin = 3;
    field.szX = x;
    field.szY = y;
    field.map = new PLAYER*[field.szY];
    for (int i = 0; i < field.szY; ++i){
        field.map[i] = new PLAYER[field.szX];
        for (int j = 0; j < field.szX; ++j){
            setval(field.map, j, i, EMPTY);
        }
    }
}
void print(Field &field){
    system("cls");
    cout << "---------------" << endl;
    for (int i = 0; i < field.szY; ++i){
        cout << "|";
        for (int j = 0; j < field.szX; ++j){
            cout << (char)getval(field.map, j, i) << "|";
        }
        cout << endl;
    }
}

void clear_game(Field &field){
    for (int i = 0; i < field.szY; ++i){
        delete[] field.map[i];
    }
    delete[] field.map;
}

void run_game(){
    Field field;
    while(true){
        init(field, size_fieldX, size_fieldY);
        print(field);
        break;
    }
    clear_game(field);
}




#endif //TICTACTOE_GAME_H
