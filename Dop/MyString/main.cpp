#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class MyString
{
    public:
    MyString() // Конструктор
    {
        string = nullptr;
    }
    ~MyString() // Деструктор
    {
        delete[] string;
    }

    MyString(char *string) // Конструктор
    {
        Copy(string);
    }


    MyString(const MyString &other) // Конструктор копирования
    {
        Copy(other.string);
    }

    MyString& operator =(const MyString &other) // Конструктор опрератора присваивания
    {
        if (this->string != nullptr)
        {
            delete[] string;
        }
        Copy(other.string);
        return *this;
    }
    MyString operator +(const MyString &other) // Конструктор опрератора сложения
    {
        MyString newstring;
        int lenghtThis = strlen(this->string);
        int lenghtOther = strlen(other.string);
        newstring.string = new char[lenghtThis + lenghtOther + 1];
        int i = 0;
        for ( ; i < lenghtThis ; i++)
        {
            newstring.string[i] = this->string[i];
        }
        for (int j = 0 ; j < lenghtOther ; j++ , i++)
        {
            newstring.string[i] = other.string[j];
        }
        newstring.string[lenghtThis + lenghtOther] = '\0';
        return newstring;
    }
    char& operator[](int index) // Конструктор по индексам
    {
        return this->string[index];
    }


    bool operator ==(const MyString &other) // Конструктор опрератора равенства
    {
        size = strlen(this->string);
        if (size != strlen(other.string))
        {
            return false;;
        }
        for (int i = 0 ; i < size ; i++)
        {
            if (this->string[i] != other.string[i])
            {
                return false;
            }
        }
        return true;
    }
    bool operator !=(const MyString &other) // Конструктор опрератора неравенства
    {
        return !(operator ==(other));
    }
    int Size() // Возвращает лину строки
    {
        return size;
    }

    bool operator >(const MyString &other) // Оператор >
    {
        int otherlenght = strlen(other.string), length = min(size, otherlenght);
        for (int i = 0 ; i < length ; i++)
        {
            if (this->string[i] < other.string[i])
            {
                return false;
            }
        }
        if (size <= otherlenght)
        {
            return false;
        }
        return true;
    }

    bool operator <(const MyString &other) // Оператор <
    {
        int otherlenght = strlen(other.string), length = min(size, otherlenght);
        for (int i = 0 ; i < length ; i++)
        {
            if (this->string[i] > other.string[i])
            {
                return false;
            }
        }
        if (size >= otherlenght)
        {
            return false;
        }
        return true;
    }

    bool operator >=(const MyString &other) // Оператор >=
    {
        return !(operator <(other));
    }

    bool operator <=(const MyString &other) // Оператор <=
    {
        return !(operator >(other));
    }

    MyString& operator =(MyString &&other) // Оператор перемещения
    {
        this->size = other.size;
        this->string = other.string;
        other.string = nullptr;
        return *this;
    }
    void append(const MyString& other)
    {
        int lenghtThis = strlen(this->string);
        int lenghtOther = strlen(other.string);
        char* newstring = new char[lenghtThis + lenghtOther + 1];
        int i = 0;
        for ( ; i < lenghtThis ; i++)
        {
            newstring[i] = this->string[i];
        }
        for (int j = 0 ; j < lenghtOther ; j++ , i++)
        {
            newstring[i] = other.string[j];
        }
        newstring[lenghtThis + lenghtOther] = '\0';
        delete[] this->string; // ?
        this->string = newstring;
    }

    bool empty() // метод проверки пустой строки
    {
        return (this->size == 0);
    }

    friend ostream& operator <<(ostream& os, const MyString& obj) // Оператор вывода
    {  
        os << obj.string;
        return os;
    }
    friend istream& operator >>(istream& is, const MyString& obj) // Оператор вывода
    {
        is >> obj.string;
        return is;
    }

    void clear() // Метод очищение строки
    {
        size = 0;
        delete[] string;
        string = new char[1];
        string[0] = '\0';
    }
    int find(int begin, int end, char value)
    {
        for ( ; begin < end ; begin++)
        {
            if(this->string[begin] == value)
            {
                return begin;
            }
        }
        return end;
    }

    private:
    char *string;
    int size;
    int strlen(char *string) // Счёт количества символов в строке
    {
        int count = 0;
        while (string[count] != '\0')
        {
            count++;
        }
        return count;
    }
    void Copy(char *string) // Копирование массива
    {
        size = strlen(string);
        this->string = new char[size + 1];
        for (int i = 0; i < (size) ; i++)
        {
            this->string[i] = string[i];
        }
        this->string[size] = '\0';
    }


};



int main()
{
    MyString a = "absgdge";
    MyString b(a);
    string c = "fwa";
    cout << a.find(0, 3, 's') << endl;
}