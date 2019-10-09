#include <iostream>
using namespace std;

#define N 3

void fastestWay(int a[][N], int t[][N - 1], int *e, int *x, int n)
{
    int f1[N], f2[N], f;
    string w1, w2;
    f1[0] = e[0] + a[0][0];
    f2[0] = e[1] + a[1][0];
    w1 = "e1 - a11";
    w2 = "e2 - a21";
    for (int j = 1; j < n; j++)
    {
        if ((f1[j - 1] + a[0][j]) <= (f2[j - 1] + t[1][j - 1] + a[0][j]))
        {
            f1[j] = f1[j - 1] + a[0][j];
            w1 = w1 + "- a1" + to_string(j+1);
        }
        else
        {
            f1[j] = f2[j - 1] + t[1][j - 1] + a[0][j];
            w1 = w2 + "- a1" + to_string(j+1);
        }

        if ((f2[j - 1] + a[1][j]) <= (f1[j - 1] + t[0][j - 1] + a[1][j]))
        {
            f2[j] = f2[j - 1] + a[1][j];
            w2 = w2 + "- a2" + to_string(j+1);
        }
        else
        {
            f2[j] = f1[j - 1] + t[0][j - 1] + a[1][j];
            w2 = w1 + "- a2" + to_string(j+1);
        }
    }

    if ((f1[n-1] + x[0]) <= (f2[n-1] + x[1]))
    {
        f = f1[n-1] + x[0];
        cout << w1 << " -x1 " << endl;
    }
    else
    {
        f = f2[n-1] + x[1];
        cout << w2 << " -x2" << endl;
    }
    cout << "Ruta: " << f << endl;
}

int main(int argc, char const *argv[])
{
    int a[][N] = {{8, 5, 10},
                  {4, 2, 3}};
    int t[][N - 1] = {{2, 6},
                      {1, 1}};
    int e[] = {7, 2}, x[] = {5, 2};

    fastestWay(a, t, e, x, N);

    return 0;
}