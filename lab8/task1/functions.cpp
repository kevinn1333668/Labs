#include <iostream>
#include <string>
#include <fstream>

#include <functions.hpp>

using namespace std;

namespace MyNamespace 
{
int HowMuchWords(char letter) // СЧЁТ СЛОВ С ЗАДАННОЙ БУКВОЙ
{
    int count = 0;
    string word;
    std::ifstream inputFile("../input.txt", std::ifstream::in);
    if (!inputFile.is_open()) {
        std::cerr << "Ошибка: файл не открыт!" << std::endl;
        return -1;  // Возвращаем код ошибки
    }
    while (inputFile >> word)
    {
        if (tolower(word[0]) == tolower(letter))
        {
            count++;
        }
    }
    inputFile.close();
    return count;
}

void CleanWord(std::string &word) // УДАЛЕНИЕ ЛИШНИХ СИМВОЛОВ ИЗ СЛОВА
{
    string clear_word = "";
    for (int i = 0 ; i < word.length() ; i++)
    {
        if (isalpha(word[i]))
        {
            clear_word += word[i];
        }
    }
    word = clear_word;
}


void SortArray(std::string *words, int count) // СОРТИРОВКА ПО ДЛИНЕ СЛОВ
{
    string temp;
    bool flag = true;
    int i = 0;
    while ((flag) && (i < count))
    {
        flag = false;
        for (int j = 0 ; j < count - 1 - i; j++)
        {
            if (words[j].length() < words[j + 1].length())
            {
                temp = words[j + 1];
                words[j + 1] = words[j];
                words[j] = temp;
                flag = true;
            }
        }
        i++;
    }

}

void WriteWords(std::string *words, int count) // ЗАПИСЬ В ФАЙЛ
{
    int const MAX_COUNT = 2000;
    int min_count;
    min_count = min(MAX_COUNT, count);
    ofstream outputFile("../output.txt");
    if (count < MAX_COUNT)
    {
        for (int i = 0 ; i < count ; i++)
        {
            outputFile << words[i] << " ";
        }
        cout << "Слова записаны!" << endl;
    }


}

bool IsUnique(std::string &word, std::string *words, int count) // ПРОВЕРКА НА УНИКАЛЬНОСТЬ СЛОВА
{
    bool flag = true;
    for (int i = 0 ; i < count ; i++)
    {
        if (words[i] == word)
        {
            flag = false;
        }
    }
    return flag;
}


}