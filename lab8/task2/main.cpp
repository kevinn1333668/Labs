#include <iostream>
#include <string>
#include <sstream>


#include <functions.hpp>

using namespace std;

int main()
{
    string text, word;
    getline(cin, text);
    int count = OM::HowMuchWords(text); // Сколько слов в тексте 
    istringstream sin(text);
    string newtext[count];
    for(int i = 0; i < count ; i++)
    {
        sin >> word;
        OM::CleanWord(word); // Очистка слова
        newtext[i] = word; 
    }

    if (OM::IsPalindrom(newtext, count)) // Проверка на палиндром
    {
        OM::SortArrayVowelCoef(newtext, count); // Сортировка по доли гласных в тексте
    }
    else 
    {
        OM::DelVowel(newtext, count); //  Удаление гласных
        OM::DoubleConsonant(newtext, count); // Дублирование согласных
        OM::SortArrayAlphabet(newtext, count); // Сортировка по алфавиту
    }

    OM::WriteText(newtext, count);
}