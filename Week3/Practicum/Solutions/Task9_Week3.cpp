#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    //важно досещане!!!
    if (n < 0)
    {
        n = -n; // делителите на -12 са същите като на 12
    }

    int count = 0;
    int i = 1;
    while (i <= n)
    {
        if (n % i == 0)
        {
            count++;
        }
        i++;
    }

    cout << count << endl;
    return 0;
}