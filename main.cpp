#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

//мама->пама(результат 1)
//пама->папа(результат 1)
//мама->пара(результат 2)

int c(const char* a, const char* b, const vector<string>& wordList, const string& CurrentWord = "", int j = -1) {
    int c = 0;
    if (CurrentWord.size() == wordList[j].size() ) {
        while (*a && *b) {
            if (*a != *b) c++;
            a++; b++;
        }
    }
    else {
        int res = wordList[j].size() - CurrentWord.size();
        c = abs(res);
        while (*a && *b) {
            if (*a != *b) c++;
            a++; b++;
        }
    }
    return c;
}

int main()
{
    setlocale(LC_ALL, "rus");
    string path = "myFile.txt";
    // cout << "Enter name your file: ";
    // cin >> path;
    const string& FileName = path ;//+ ".txt";
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

        for(int i = 0; i < wordList.size(); i++)
        {
            cout << i << '.'  << ' ' << wordList[i] << endl;
        }
    }
    else
        cout << "File is not open." << endl;
    fin.close();
    int result = 0;
    int NumberEndWord, NumberStartWord;
    int j = 0;
    cout << "Enter the number start word: ";
    cin >> NumberStartWord;
    string StartWord = wordList[NumberStartWord];
    cout << "\nEnter the number end word: ";
    cin >> NumberEndWord;
    string EndWord = wordList[NumberEndWord];
    cout << endl << "Start word is a " << '<' << StartWord << '>' << endl <<"End word is a " <<  '<' << EndWord << '>' << endl << endl;
    if (StartWord == EndWord) {
        cout << "You can't find this word." << endl;
        return -1;
    }
    if(NumberEndWord < NumberStartWord) {
        j = wordList.size() - 1;
        j *= -1;
    }
    while(true) {
        if (result == 0) {
            result = c(StartWord.data(), EndWord.data(), wordList, StartWord, NumberEndWord);
            if (result == 1) {
                cout << StartWord << " -> " << EndWord << endl;
                return 0;
            }
            else {
                j++;
            }
        }
        else if(result == 1) {
            cout << StartWord << " -> " << wordList[abs(j)] << endl;
            StartWord = wordList[abs(j)];
            result = c(StartWord.data(), EndWord.data(), wordList, StartWord, NumberEndWord);
            if (result == 1) {
                cout << StartWord << " -> " << EndWord << endl;
                return 0;
            }
            j++;
            if (abs(j) >= wordList.size() - 1)
                j = 0;
        }
        else {
            j++;
            if (abs(j) >= wordList.size() - 1)
                j = 0;
        }
        if (StartWord == EndWord) {
            return 0;
        }
        result = c(StartWord.data(), wordList[abs(j)].data(), wordList, StartWord, abs(j));
    }
}
