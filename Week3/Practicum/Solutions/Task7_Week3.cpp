#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // горен ред: n интервала, после " |"
    int s = 0;
    while (s < n)
    {
        cout << ' ';
        s++;
    }
    cout << " |" << endl;

    // редове с 1, 2, ..., n звезди
    int i = 1;
    while (i <= n)
    {
        // интервали вляво (подравняване надясно)
        int spaces = 0;
        while (spaces < n - i)
        {
            cout << ' ';
            spaces++;
        }

        // звезди в лявата половина
        int stars = 0;
        while (stars < i)
        {
            cout << '*';
            stars++;
        }

        cout << " | ";

        // звезди в дясната половина
        stars = 0;
        while (stars < i)
        {
            cout << '*';
            stars++;
        }

        cout << endl;
        i++;
    }

    return 0;
}