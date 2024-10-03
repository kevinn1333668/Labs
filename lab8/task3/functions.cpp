#include <iostream>
#include <string>
#include <fstream>

#include <functions.hpp>

using namespace std;

namespace OM
{
int UniqueLetters(std::string word, std::string &letters)
{   
    if (word.length() <= 7)
    {
        return word.length();
    }
    int count;
    for (int i = 0 ; i < word.length() ; i++)
    {
        bool flag = true;
        for (int j = 0; j < letters.length() ; j++)
        {
            if (tolower(word[i]) == letters[j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            letters += tolower(word[i]);
        }
    }
    return letters.length();
}

void UpperLetters(std::string &word)
{
    for (int i = 0 ; i < word.length() ; i++)
    {
        word[i] = toupper(word[i]);
    }
}

void Write(std::string word, std::string letters, int count) // ???
{
    ofstream outputFile("../output.txt");
    outputFile << word << " (";
    for (int i =  0 ; i < count ; i++)
    {
        outputFile << letters[i];
    }
    outputFile << ")";
}

}