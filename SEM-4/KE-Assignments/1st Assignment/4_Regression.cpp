#include <bits/stdc++.h>
using namespace std;
int sum(vector<int> a)
{
    int sum = 0;
    for (int i : a)
        sum += i;
    return sum;
}
int sum_of_square(vector<int> a)
{
    int sum = 0;
    for (int i : a)
        sum += i * i;
    return sum;
}
int sum_of_product(vector<int> a, vector<int> b)
{
    int n = a.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i] * b[i];
    return sum;
}
void printcoords(vector<int> x, vector<int> y)
{
    int n = x.size();
    for (int i = 0; i < n; i++)
    {
        cout << "(" << x[i] << ", " << y[i] << ")";
        if (i != n - 1)
            cout << ",";
    }
}
int main()
{
    vector<int> x = {8, 7, 3, 5, 9, 1, 6, 2, 7, 2};
    vector<int> y = {2, 1, 4, 9, 4, 2, 8, 6, 9, 5};
    int n = x.size(), sum_of_x, sum_of_y, sq_sum_x, p_sum_xy;
    sum_of_x = sum(x);
    sum_of_y = sum(y);
    sq_sum_x = sum_of_square(x);
    p_sum_xy = sum_of_product(x, y);
    double a = double(sum_of_y * sq_sum_x - sum_of_x * p_sum_xy) / double(n * sq_sum_x - sum_of_x * sum_of_x);
    double b = double(n * p_sum_xy - sum_of_x * sum_of_y) / double(n * p_sum_xy - sum_of_x * sum_of_x);
    cout << "Equation of line is : y = " << a << " + " << b << "x" << endl;
    vector<int> ynew(n, 0);
    for (int i = 0; i < n; i++)
        ynew[i] = a + b * x[i];
    cout << "Old Coords are : ";
    printcoords(x, y);
    cout << endl;
    cout << "New Coords are : ";
    printcoords(x, ynew);
    return 0;
}
