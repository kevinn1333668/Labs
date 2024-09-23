 #include <iostream>
 #include <ctime>
using namespace std;


int main()
{
    int const SIZE = 10;
    int arr[SIZE];
    int value, mn = 999;
    srand(time(NULL));
    bool flag;

    for (int i = 0; i < SIZE ; )
    {
        flag = true;
        value = rand()%1000;
        for (int j = 0 ; j < i; j++)
        {
            if  (arr[j] == value)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            arr[i] = value;
            if (value < mn)
            {
                mn = value;
            }
            cout << arr[i] << endl;
            i++;
        }
    }
cout << mn << endl;
cout << double(float(10) - 0.1 - 0.1 - 0.1) << endl;
}