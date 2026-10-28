#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void Print(int* a, const int size, int i);
bool IsNonIncreasing(int* a, const int size, int i);

template <typename T>
void Print(T* a, const int size, int i);

template <typename T>
bool IsNonIncreasing(T* a, const int size, int i);

int main()
{
    const int n = 10;

    int a[n] = { 9, 7, 7, 4, 5, 0, -1, -3, -3, -8 };
    Print(a, n, 0);
    bool s1 = IsNonIncreasing(a, n, 1);
    cout << "IsNonIncreasing(a, n) = " << s1 << endl;

    Print<int>(a, n, 0);
    bool s2 = IsNonIncreasing<int>(a, n, 1);
    cout << "IsNonIncreasing<int>(a, n) = " << s2 << endl;

    double b[n] = { 10.5, 9.1, 9.1, 8.0, 7.7, 6.0, 5.0, 4.4, 3.0, 1.5 };
    Print<double>(b, n, 0);
    bool s3 = IsNonIncreasing<double>(b, n, 1);
    cout << "IsNonIncreasing<double>(b, n) = " << s3 << endl;

    string c[n] = { "j", "i", "h", "g", "f", "e", "d", "c", "b", "a" };
    Print<string>(c, n, 0);
    bool s4 = IsNonIncreasing<string>(c, n, 1);
    cout << "IsNonIncreasing<string>(c, n) = " << s4 << endl;

    return 0;
}

void Print(int* a, const int size, int i)
{
    if (i < size)
    {
        cout << setw(6) << a[i];
        Print(a, size, i + 1);
    }
    else
        cout << endl;
}

bool IsNonIncreasing(int* a, const int size, int i)
{
    if (i < size)
        return a[i] <= a[i - 1] && IsNonIncreasing(a, size, i + 1);
    else
        return true;
}

template <typename T>
void Print(T* a, const int size, int i)
{
    if (i < size)
    {
        cout << setw(6) << a[i];
        Print<T>(a, size, i + 1);
    }
    else
        cout << endl;
}

template <typename T>
bool IsNonIncreasing(T* a, const int size, int i)
{
    if (i < size)
        return a[i] <= a[i - 1] && IsNonIncreasing<T>(a, size, i + 1);
    else
        return true;
}