#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

enum PLAYER{HUMAN = 'X', AI = 'O', EMPTY = '_'};

typedef struct{
    int szX;
    int szY;
    PLAYER**map;
    int towin;
}Field;

void setval(PLAYER **map, int x, int y, PLAYER state){
    map[y][x] = state;
}

PLAYER getval(PLAYER **map, int x, int y){
    return map[y][x];
}

bool isvalid(Field &field, int x, int y){
    return true;
}
bool isempty(Field &field, int x, int y){
    return true;
}
bool check_line(Field &field, int x, int y, int vx, int vy, PLAYER c){
    return true;
}

void init(Field &field){
    field.towin = 3;
    field.szX = 3;
    field.szY = 3;
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
    int x, y;
    do{
        cout << "Enter X and Y: " << endl;
        cin >> x >> y;
        x--;
        y--;
    }while (!isvalid(field, x, y) || !isempty(field, x, y));
    setval(field.map, x, y, HUMAN);
}
void ai_move(Field &field){
    int x, y;
    do{
        x = rand() % field.szX;
        y = rand() % field.szY;

    }while (!isempty(field, x, y));
    setval(field.map, x, y, AI);
}

bool check_win(Field &field, PLAYER player){
    for (int x = 0; x < field.szX; ++x){
        for (int y = 0; y < field.szY; ++y){
            if (check_line(field, x, y, 1, 0, player)) return true;
            if (check_line(field, x, y, 0, 1, player)) return true;
            if (check_line(field, x, y, 1, 1, player)) return true;
            if (check_line(field, x, y, 1, -1, player)) return true;
        }
    }
    return false;
}
bool check_draw(Field &field){
    for (int x = 0; x < field.szX; ++x){
        for (int y = 0; y < field.szY; ++y){
            if (isempty(field, x, y)) return false;
        }
    }
    return true;
}

bool check_game(Field &field, PLAYER p, const std::string &winString){
    if (check_win(field, p)){
        cout << winString << endl;
        return true;
    }
    if (check_draw(field)){
        cout << "draw" << endl;
        return true;
    }
    return false;
}

void tictactoe(){
    Field field;
    while(true){
        init(field);
        print(field);
        while(true){
            human_move(field);
            print(field);
            if (check_game(field, HUMAN, "Human win!")) break;
            ai_move(field);
            print(field);
            if (check_game(field, AI, "AI win!")) break;
        }
        std::string answer;
        cout << "Play again?" << endl;
        cin >> answer;
        if (answer != "y") break;
    }
}
void clear_game(Field &field){
    for (int i = 0; i < sizeof(field.map); ++i){
        delete[] field.map[i];
    }
    delete[] field.map;
}

int main() {
    srand(time(0));
    Field field;
    init(field);
    print(field);
    tictactoe();

    clear_game(field); // delete memory allocation

    return 0;
}
