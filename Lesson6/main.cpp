#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

void Join(const char *w1, const char *w2){
    const int size = 1000;
    char *buff = new char[size];

    //1-ый вариант.
    /*strcat(buff, w1);
    strcat(buff, w2);*/

    //2-ой вариант
    int count1 = 0;
    while (w1[count1] != 0){
        buff[count1] = w1[count1];
        count1++;
    }
    int count2 = 0;
    while (w2[count2] != 0){
        buff[count1] = w2[count2];
        count1++;
        count2++;
    }
    const char* file = "joined_files.txt";
    ofstream join (file, ios::out | ios::app);
    if (!join.is_open()){
        cerr << "Can't open " << file << " file for output." << endl;
        exit (EXIT_FAILURE);
    }
    else{
        cout << "Successful!!! file opened" << endl;
        join << buff;
    }

    delete[] buff;
}

int main() {
/* Task 1. Написать программу, которая создаст два
 * текстовых файла, примерно по 50-100 символов в каждом
 * (особого значения не имеет); */
    const int length = 512;
    char text_part1[length];
    char text_part2[length];

    //Я сделал два файла с текстом чтобы не писать ручками текст в коде.
    ifstream some_file1 ("words1.txt"); //the file contains some text
    ifstream some_file2 ("words2.txt"); // the file contains some text
    if (some_file1.is_open() && some_file2.is_open()){
        some_file1.getline(text_part1, length);
        some_file2.getline(text_part2, length);
    }

    ofstream text1 ("file_text1.txt");
    ofstream text2 ("file_text2.txt");
    if (text1.is_open() && text2.is_open()){
        text1 << text_part1;
        text2 << text_part2;
    }


/* Task 2.   Написать функцию, «склеивающую» эти файлы, предварительно
 * буферизуя их содержимое в динамически выделенный сегмент памяти нужного размера. */

    Join(text_part1, text_part2);

    return 0;
}
