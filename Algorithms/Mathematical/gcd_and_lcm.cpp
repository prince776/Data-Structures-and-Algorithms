// Implements Algorithms for GCD and LCM.
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int gcdExtended(int a, int b, int *x, int *y)
{
    // Base case.
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int a = 15, b = 20;
    int x, y;
    cout << "GCD of " << a << " and " << b << " is: " << gcd(b, a);
    cout << endl;
    cout << "GCD of " << a << " and " << b << " is: " << gcdExtended(a, b, &x, &y);
    cout << endl;
    cout << "LCM of " << a << " and " << b << " is: " << lcm(b, a);
    cout << endl;
    return 0;
}