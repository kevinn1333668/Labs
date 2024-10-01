#pragma once FUNCTIONS.HPP

namespace MyNamespace
{
int HowMuchWords(char letter); 
void CleanWord(std::string &word);
void SortArray(std::string *words, int count);
void WriteWords(std::string *words, int count);
bool IsUnique(std::string &word, std::string *words, int count);

}