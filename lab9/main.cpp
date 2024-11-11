#include <iostream>
using namespace std;

void bin(int number)
{
    int binary[32]{0};
    int i = 0;
    while(number > 0)
    {
        binary[i] = number % 2;
        i++;
        number /= 2;

    }
    for(int i = 0 ; i < 32 ; i++)
    {
        cout << binary[i];
    }
}

int main()
{
    int number;
    cin >> number;
    unsigned char* ptr = reinterpret_cast<unsigned char*>(&number);
    for (size_t i = 0 ; i < sizeof(number) ; i++)
    {
        cout << i + 1 << " " << static_cast<int>(ptr[i]) << " ";
        bin(static_cast<int>(ptr[i]));
        cout << endl;
    }

}