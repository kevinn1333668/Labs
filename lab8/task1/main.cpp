#include <iostream>
#include <fstream>
#include <string>


#include <functions.hpp>

using namespace std;

int main()
{
    char letter;
    int rightWords = 0;
    cout <<  "Введите букву: ";
    cin >> letter;
    int count = MyNamespace::HowMuchWords(letter);
    if (count == 0)
    {
        cout << "Слов с такой буквой нет!" << endl;
        return 0;
    }
    string words[count];
    string word;
    ifstream inputFile("../input.txt");
    if (inputFile.is_open())
    {   
        while (inputFile >> word)
        {
            MyNamespace::CleanWord(word);
            if((tolower(word[0]) == tolower(letter)) && MyNamespace::IsUnique(word, words, rightWords))
            {
                words[rightWords] = word;
                rightWords++;
            }
        }
        inputFile.close();   
    }
    MyNamespace::SortArray(words, rightWords);
    MyNamespace::WriteWords(words, rightWords); //    ofstream outputFile("output.txt")

}