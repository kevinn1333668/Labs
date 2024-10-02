#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

#include <functions.hpp>

using namespace std;

namespace OM
{
int HowMuchWords(std::string text) // Сколько слов в тексте
{
    int count = 0;
    istringstream sin(text);
    std::string word;
    while (sin >> word) // Пока можем считывать слова, плюсуем count
    {
        count++;
    }
    return count;
}
void CleanWord(std::string &word) // Очистка слова
{
    string clear_word = "";
    for (int i = 0 ; i < word.length() ; i++)
    {
        if (isalpha(word[i])) // Если буква, то пропускаем
        {
            clear_word += word[i];
        }
    }
    word = clear_word;

}
bool IsPalindrom(std::string *text,int count) // Проверка на палиндром
{
    char temp;
    string tempWord;
    bool flag = false;
    for (int i = 0; i < count ; i++)
    {
        if ((text[i].length() < 2)) // Если в слове меньше двух символов
            continue;
        tempWord = text[i];
        for (int l1 = 0, l2 = (text[i].length() - 1) ; l1 < l2 ; l1++, l2--) // Реверс слова
        {
            temp = tempWord[l1];
            tempWord[l1] = tempWord[l2];    // l1 -> middle <- l2
            tempWord[l2] = temp;
        }
        if (tempWord == text[i])
        {
            flag = true;
            break;
        }
    }
    return flag;
}
void SortArrayAlphabet(std::string *text, int count) // Сортировка по алфавиту пузырьком
{
    string temp;
    bool flag = true;
    int i = 0;
    while ((flag) && (i < count))
    {
        flag = false;
        for (int j = 0 ; j < count - 1 - i; j++)
        {
            if (text[j] > text[j + 1])
            {
                temp = text[j + 1];
                text[j + 1] = text[j];
                text[j] = temp;
                flag = true;
            }
        }
        i++;
    }
}

float VowelCoefficent(std::string word) // Возвращает коэффицент гласных в слове
{
    float coefficent, count = 0, length = word.length();
    for (int i = 0 ; i < length ; i++)
    {
        char letter = tolower(word[i]);
        if ((letter == 'a') || (letter == 'o') || (letter == 'u') || (letter == 'i') || (letter == 'y') || (letter == 'e'))
        {
            count += 1;
        }
    }
    coefficent = (count / length);
    return coefficent;
}

void SortArrayVowelCoef(std::string *text, int count) // Сортировка по доли гласных в слове
{
    string temp;
    bool flag = true;
    int i = 0;
    while ((flag) && (i < count))
    {
        flag = false;
        for (int j = 0 ; j < count - 1 - i ; j++)
        {
            if (VowelCoefficent(text[j]) < VowelCoefficent(text[j + 1]))
            {
                temp = text[j + 1];
                text[j + 1] = text[j];
                text[j] = temp;
                flag = true;
            }
        }
        i++;
    }
}



void DelVowel(std::string *text, int count) // Удаление гласных
{
    char letter;
    for (int i = 0 ; i < count ; i++)
    {
        string &word = text[i];
        int length = word.length(); // Длина слова
        for (int j = 0 ; j < length ; j++)
        {
            letter = tolower(word[j]); 
            // Проверка на гласную
            if ((letter == 'a') || (letter == 'o') || (letter == 'u') || (letter == 'i') || (letter == 'y') || (letter == 'e'))
            {
                word.erase(word.begin() + j); // Удаление гласной буквы по индексу
                j--;
                length--;
            }
        }
    }

}
void DoubleConsonant(std::string *text, int count) // Удаление согласных
{
    char temp;
    for (int i = 0 ; i < count ; i++)
    {
        string &word = text[i];
        string new_word;
        for (int j = 0 ; j < word.length() ; j++)
        {
            new_word = new_word + word[j] + word[j]; // ???
        }
        word = new_word;
    }
}


void WriteText(std::string *text, int count)
{
    for (int i = 0 ; i < count ; i++)
    {
        cout << text[i] << " " << endl;
    }
}
}