# Задача 1

```cpp
#include <iostream>
using namespace std;

int main() {
    unsigned n;
    int k;
    cin >> n >> k;

    cout << ((n >> k) & 1) << endl;
    return 0;
}
```

# Задача 2

```cpp
#include <iostream>
using namespace std;

int main() {
    unsigned n;
    int k;
    cin >> n >> k;

    unsigned mask = 1u << k;

    cout << (n | mask) << " "
         << (n & ~mask) << " "
         << (n ^ mask) << endl;
    return 0;
}
```

# Задача 3

```cpp
#include <iostream>
using namespace std;

int main() {
    unsigned n;
    cin >> n;

    int count = 0;
    while (n != 0) {
        n = n & (n - 1);
        count++;
    }

    cout << count << endl;
    return 0;
}
```

# Задача 4

```cpp
#include <iostream>
using namespace std;

int main() {
    unsigned n;
    cin >> n;

    unsigned result = 0;
    for (int i = 0; i < 8; i++) {
        result = (result << 1) | (n & 1);
        n >>= 1;
    }

    cout << result << endl;
    return 0;
}
```

# Задача 5

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int result = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        result ^= x;
    }

    cout << result << endl;
    return 0;
}
```

# Задача 6

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[20];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int S;
    cin >> S;

    int count = 0;
    for (unsigned mask = 0; mask < (1u << n); mask++) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                sum += a[i];
            }
        }
        if (sum == S) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
```
