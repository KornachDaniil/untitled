#include <iostream>
#include <string>
#include <fstream>
#include <queue>

using namespace std;

//мама->пама(результат 1)
//пама->папа(результат 1)
//мама->пара(результат 2)

int c(char* a, char* b, const vector<string>& wordList) {
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
    int i = 0, g =  0;
    int SearhWord;
    string currentWord = wordList[i];
    cout << "Enter the number of words you want to search: ";
    cin >> SearhWord;
    cout << endl << "You want find the " <<  '<' << wordList[SearhWord] << '>' << endl << endl;
    if (wordList[SearhWord] == wordList[0])
        cout << "You can't find this word." << endl;
    while(true) {
        if (result == 1) {
            cout << currentWord << "->" << wordList[g] << endl;
            currentWord = wordList[g];
            i++; g++;
        }
        else {
            g++;
        }
        if(currentWord == wordList[SearhWord]) {
            return 0;
        }
        result = c(currentWord.data(), wordList[g].data(), wordList);
    }
}