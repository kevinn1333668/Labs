#include <iostream>
using namespace std;

int main()
{
    int Q1, Q2, P1, P2, A, gruz1, gruz2, remains, price, travels2, min_price = __INT_MAX__;
    cin >> Q1 >> P1 >> Q2 >> P2 >> A;
    for (int travels1 = 0; travels1 <= ((A + Q1 - 1) / Q1) ; travels1++)
    {
        gruz1 = travels1 * Q1;
        remains = A - gruz1;
        travels2 = 0;
        if (remains > 0)
        {
            travels2 = ((remains + Q2 - 1) / Q2);
        }
        price = travels1 * P1 + travels2 * P2;
        min_price = min(min_price, price);
    }
    cout << min_price << endl;
}