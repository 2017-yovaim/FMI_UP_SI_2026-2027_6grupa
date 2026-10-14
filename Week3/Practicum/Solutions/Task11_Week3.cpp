#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int current = 1; 

    int row = 1;
    while (row <= n)
    {
        int count = 0;
        while (count < row)
        {
            cout << current << " ";
            current++;
            count++;
        }

        cout << endl;
        row++;
    }

    return 0;
}