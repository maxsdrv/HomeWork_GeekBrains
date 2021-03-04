#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H

#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::endl;


enum PLAYER {HUMAN = 'X', AI = '0', EMPTY = '_'};
using vector = std::vector<std::vector<PLAYER>>;


typedef struct{
    int szX;
    int szY;
    int to_win;
    vector map;
    vector saved_map;
}Field;


bool is_valid(Field &field, int x, int y){
    if(x >= 0 && x < field.szX && y >= 0 && y < field.szY){
        return true;
    }
    return false;
}

bool is_empty(Field &field, int x, int y){
    return field.map.at(y).at(x) == EMPTY;
}

bool is_draw(Field &field){
    for (int y = 0; y < field.szY; ++y){
        for (int x = 0; x < field.szX; ++x){
            if (is_empty(field, x, y)){
                return false;
            }
        }
    }
    return true;
}

bool line_check(Field &field, int row, int column, int vx, int vy,
                PLAYER player){
    const int endX = column + (field.to_win - 1) * vx;
    const int endY = row + (field.to_win - 1) * vy;
    if (!is_valid(field, endX, endY)){
        return false;
    }
    for (int i = 0; i < field.to_win; ++i){
        if (field.map.at(row + i * vy).at(column + i * vx) != player){
            return false;
        }
    }
    return true;
}

bool win_check(Field &field, PLAYER player){
    for (int x = 0; x < field.szX; ++x){
        for (int y = 0; y < field.szY; ++y){
            if (line_check(field, y, x, 1, 0, player)) return true;
            if (line_check(field, y, x, 0, 1, player)) return true;
            if (line_check(field, y, x, 1, 1, player)) return true;
            if (line_check(field, y, x, 1, -1, player)) return true;
        }
    }
    return false;
}

bool saved_moves(Field &field, int row, int column){
    if (!is_valid(field, column, row) || !is_empty(field, column, row)) {
        return false;
    }
    else if (field.saved_map[column][row] == AI){
        return false;
    }
    return true;
}

void ai_learning(Field &field){
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 3);
    int row = dist(mt);
    int column = dist(mt);
    while (!saved_moves(field, row, column)){
        row = dist(mt);
        column = dist(mt);
    }
    field.saved_map.at(row).at(column) = AI;
    field.map.at(row).at(column) = AI;
}

bool ai_win_check(Field &field) {
    for (int y = 0; y < field.szY; y++) {
        for (int x = 0; x < field.szX; x++) {
            if (is_empty(field, x, y)) {
                field.map.at(y).at(x) = AI;
                if (win_check(field, AI))
                    return true;
                field.map.at(y).at(x) = EMPTY;
            }
        }
    }
    return false;
}

bool human_win_check(Field &field) {
    for (int y = 0; y < field.szY; y++) {
        for (int x = 0; x < field.szX; x++) {
            if (is_empty(field, x, y)) {
                field.map.at(y).at(x) = HUMAN;
                if (win_check(field, HUMAN)) {
                    field.map.at(y).at(x) = AI;
                    return true;
                }
                field.map.at(y).at(x) = EMPTY;
            }
        }
    }
    return false;
}


bool game_check(Field &field, PLAYER dot, const std::string &winString){
    if (win_check(field, dot)){
        cout << winString << endl;
        return true;
    }
    if (is_draw(field)){
        cout << "draw" << endl;
        return true;
    }
    return false;
}

void ai_move(Field &field){
    int count = 0;
    for (const auto &row : field.map){
        for (const auto &fm : row){
            if (fm == HUMAN){
                ++count;
            }
        }
    }
    if (count == 1) ai_learning(field);
    ai_win_check(field);
    human_win_check(field);
}


void human_move(Field &field){
    int x = 0;
    int y = 0;
    do {
        cout << "Enter coordinates X or Y from 1 to " << field.szY << endl;
        cin >> x >> y;
        x--; y--;
    }while (!is_valid(field, x, y) || !is_empty(field, x, y));
        field.map[y][x] = HUMAN;
}

void Print(Field &field){
    cout << "______________________" << endl;
    for (int i = 0; i < field.szY; ++i){
        cout << "|";
        for (int j = 0; j < field.szX; ++j){
            cout << static_cast<char>(field.map.at(j).at(i)) << "|";
        }
        cout << endl;
    }
}


void init(Field &field){
    const int cst_row = 3;
    const int cst_column = 3;
    field.to_win = cst_column;
    field.szX = cst_column;
    field.szY = cst_row;
    for (int i = 0; i < field.szY; ++i){
        field.map.resize(field.szY);
        for (int j = 0; j < field.szX; ++j){
            field.map[i].push_back(EMPTY);
        }
    }
    if (field.saved_map.empty()) {
        for (int i = 0; i < field.szY; ++i) {
            field.saved_map.resize(field.szX);
            for (int j = 0; j < field.szX; ++j) {
                field.saved_map[i].push_back(EMPTY);
            }
        }
    }
}


void run_game(){
    Field field;

    while (true){
        init(field);
        Print(field);
        while (true){
            human_move(field);
            Print(field);
            if (game_check(field, HUMAN, "Human win!")) break;
            ai_move(field);
            Print(field);
            if (game_check(field, AI, "AI win")) break;
        }
        std::string answer;
        cout << "Play again? ";
        cin >> answer;
        std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

        if (answer.find('y') != 0) {
            field.map.clear();
            break;
        }

        field.map.clear();
    }
    field.saved_map.clear();
}



#endif //TICTACTOE_GAME_H
