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

int main()
{
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
    int j = 0;

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

    //Обратный ход по списку
    // if(NumberEndWord < NumberStartWord) {
    //     vector<string> temp(wordList.begin(), wordList.end());
    //     wordList.clear();
    //     for(int i = temp.size() - 1; i != 0; i--) {
    //         wordList.push_back(temp[i]);
    //     }
    //     temp.clear();
    // }
    //

    // Попытка сразу получить преобразование от начального в конечное
    result = c(StartWord.data(), EndWord.data());
    if (result == 1) {
        cout << StartWord << " -> " << EndWord << endl;
        return 0;
    }
    bool bAvtife = false;
    //
    while(true) {
        if(result == 1) {
            cout << StartWord << " -> " << wordList[j] << endl;
            StartWord = wordList[j];
            // Попытка сразу получить преобразование от текущего в конечное
            if (wordList[j].size() == StartWord.size()) {
                result = c(StartWord.data(), EndWord.data());
                if (result == 1) {
                    cout << StartWord << " -> " << EndWord << endl;
                    return 0;
                }
            }
            j++;
            //
        }
        else {
            if (bAvtife == true)
                j++;
        }
        if (j >= wordList.size() - 1) {
            cout << "\nIt is impossible to get the given word: " << EndWord << endl;
            return -1;
        }
        if (StartWord == EndWord) {
            return 0;
        }
        bAvtife = true;
        if (StartWord.size() == wordList[j].size())
            result = c(StartWord.data(), wordList[j].data());
    }
}
