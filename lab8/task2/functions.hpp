#pragma once FUNCTIONS.HPP

namespace OM
{
// ОБРАБОТКА
int HowMuchWords(std::string text); // Сколько слов в тексте 

void CleanWord(std::string &word); // Очистка слова

bool IsPalindrom(std::string *text,int count); // Проверка на палиндром

void SortArrayAlphabet(std::string *text, int count); // Сортировка по алфавиту

void SortArrayVowelCoef(std::string *text, int count); // Сортировка по доли гласных в слове

float VowelCoefficent(std::string word); // Возвращает коэффицент гласных в слове

void DelVowel(std::string *text, int count); // Удаление гласных

void DoubleConsonant(std::string *text, int count); // Дублирование согласных




// ВЫВОД
void WriteText(std::string *text, int count);


}