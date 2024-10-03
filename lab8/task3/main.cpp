#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include <functions.hpp>

using namespace std;

int main()
{
    string line;
    ifstream inputFile("../input.txt");
    ofstream outputFile("../output.txt");
    while(getline(inputFile, line))
    {
        string word;
        for (int i = 0 ; i < line.length() ; i++)
        {
            char letter = line[i];
            if (isalpha(letter))
            {
                word += letter;
            }
            else
            {
                if (!word.empty()) // Если слово непустое
                {
                    string letters;
                    int uniqueCount = OM::UniqueLetters(word, letters); // Возвращет количество уникальных слов и записывает их в letters
                    if (uniqueCount > 7) // Если уникальных слов больше 7
                    {
                        OM::UpperLetters(word); // Выделяем слово
                        outputFile << word << " (";
                        for (int j =  0 ; j < uniqueCount ; j++)
                        {
                            outputFile << letters[j];
                        }
                        outputFile << ")";

                    }
                    else
                    {
                        outputFile << word;
                    }
                }
                word = "";
                outputFile << letter; // Запись небуквенного символа
            }
        }
        if (!word.empty()) // Если слово непустое
        {
            string letters;
            int uniqueCount = OM::UniqueLetters(word, letters); // Возвращет количество уникальных слов и записывает их в letters
            if (uniqueCount > 7) // Если уникальных слов больше 7
            {
                OM::UpperLetters(word); // Выделяем слово
                // ???  OM::Write(word, letters, uniqueCount); ???
                outputFile << word << " (";
                for (int i =  0 ; i < uniqueCount ; i++)
                {
                    outputFile << letters[i];
                }
                outputFile << ")";
            }
            else
            {
                outputFile << word;
            }
        }
        outputFile << '\n'; // Перенос строки
    }
    inputFile.close();
    outputFile.close();
    cout << "Файл записан!" << endl;
}