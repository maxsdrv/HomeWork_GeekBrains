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

bool is_empty(Field &field, const int x, const int y){
    if (getval(field.map, x, y) == EMPTY) return true;
    return false;
}

bool is_valid(Field &field, const int x, const int y){
    if ((x >= 0 && x < field.szX) && (y >= 0 && y < field.szY))
        return true;
    return false;
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
    system("clear");
    cout << "---------------" << endl;
    for (int i = 0; i < field.szY; ++i){
        cout << "|";
        for (int j = 0; j < field.szX; ++j){
            cout << (char)getval(field.map, j, i) << "|";
        }
        cout << endl;
    }
}

void human_move(Field &field){
    int x = 0, y = 0;
    do{
        cout << "Enter number from 1 to " << field.szY << endl;
        cin >> x >> y;
        x--, y--;
    }while (!is_valid(field, x, y) && (!is_empty(field, x, y)));
    setval(field.map, y, x, HUMAN);
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
        human_move(field);
        print(field);
        break;
    }
    clear_game(field);
}




#endif //TICTACTOE_GAME_H
