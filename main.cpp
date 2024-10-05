#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

//мама->пама(результат 1)
//пама->папа(результат 1)
//мама->пара(результат 2)

int c(const char* a, const char* b) {
    int c = 0;
    while (*a && *b) {
        if (*a != *b) c++;
        a++; b++;
    }
    return c;
}

int main() {
    setlocale(LC_ALL, "rus");

    // Работа с файлом
    string path = "myFile";
    // cout << "Enter name your file: ";
    // cin >> path;
    const string& FileName = path + ".txt";
    ifstream fin;
    fin.open(FileName);
    vector<string> wordList;
    if (fin.is_open())
    {
        cout << "File is open." << endl;
        string word;
        while(getline(fin, word))
        {
            wordList.push_back(word);
        }

        // Вывод всех слов из файла
        for(int i = 0; i < wordList.size(); i++)
        {
            cout << i << '.'  << ' ' << wordList[i] << endl;
        }
        //
    }
    else
        cout << "File is not open." << endl;
    fin.close();
    //

    int result = 0;
    int NumberEndWord, NumberStartWord;

    // Ввод и вывод Начального и Конечного слов
    cout << "Enter the number start word: ";
    cin >> NumberStartWord;
    cout << "\nEnter the number end word: ";
    cin >> NumberEndWord;
    string StartWord = wordList[NumberStartWord];
    string EndWord = wordList[NumberEndWord];
    cout << endl << "Start word is a " << '<' << StartWord << '>' << endl <<"End word is a " <<  '<' << EndWord << '>' << endl << endl;
    //

    // Проверка на условие задачи
    if (StartWord == EndWord || StartWord.size() != EndWord.size()) {
        cout << "You can't find this word." << endl;
        return -1;
    }
    //

    // Попытка сразу получить преобразование от начального в конечное
    result = c(StartWord.data(), EndWord.data());
    if (result == 1) {
        cout << StartWord << " -> " << EndWord << endl;
        return 0;
    }
    //

    int j = 0;

    while (true) {
        while (true) {
            if (StartWord.size() == wordList[j].size())
                result = c(StartWord.data(), wordList[j].data());
            if (result == 1) {
                result = 0;
                string NextWord = wordList[j];
                cout << StartWord << " -> " << NextWord << endl;
                erase(wordList, StartWord);
                StartWord = NextWord;
                erase(wordList, NextWord);
                j = 0;
                if (StartWord.size() == EndWord.size())
                    result = c(StartWord.data(), EndWord.data());
                if (result == 1) {
                    cout << StartWord << " -> " << EndWord << endl;
                    return 0;
                }
            }
            else
                break;
            if (StartWord == EndWord) {
                return 0;
            }
        }
        j++;
    }
}

// 12 - 18 +
// 0 - 8 +
// 2 - 14 +
// 4 - 14 -+ первый вариант невозможно получить по принципу работы кода
// 6 - 17 -+  первый вариант невозможно получить по принципу работы кода
// 8 - 18 +
// 1 - 3 +
// 3 - 19 +