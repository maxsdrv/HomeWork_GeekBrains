#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void ConnectFiles(const string &f1, const string &f2){

}

int main() {
/* Task 1. Написать программу, которая создаст два
 * текстовых файла, примерно по 50-100 символов в каждом
 * (особого значения не имеет); */

    string words1;
    string words2;
    ifstream file_in_words1;
    ifstream file_in_words2;
    file_in_words1.open("words1.txt");
    file_in_words2.open("words2.txt");
    if (file_in_words1.is_open() && file_in_words2.is_open()){
        getline(file_in_words1, words1);
        getline(file_in_words2, words2);
    }

    ofstream file1, file2;
    file1.open("file1.txt");
    file2.open("file2.txt");
    if (file1.is_open() && file2.is_open()){
        file1 << words1;
        file2 << words2;
    }

/* Task 2.   Написать функцию, «склеивающую» эти файлы, предварительно
 * буферизуя их содержимое в динамически выделенный сегмент памяти нужного размера. */



    return 0;
}
