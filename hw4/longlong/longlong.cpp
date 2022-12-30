#include <iostream>
#include <vector>
#include "ypglpk.hpp"

using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a, b, w;
    vector<vector<double>> A(3 * n + m, std::vector<double>(m + n, 0));
    // A:constrain
    // B:smaller
    // C:weight
    vector<double> B(3 * n + m, 0), C(n + m, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        a--;
        b--;
        C[n + i] = w;
        // for cycle
        A[i][a] = 1;
        A[i][b] = -1;
        A[i][n + i] = 10000;
        B[i] = 9999;
        // for in and out
        A[m + a][n + i] = -1;
        A[m + b][n + i] = 1;
        A[m + n + a][n + i] = 1;
        A[m + n + b][n + i] = -1;
        // for out
        A[m + 2 * n + a][n + i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            B[m + i] = -1;
            B[m + n + i] = 1;
            B[m + 2 * n + i] = 1;
        }
        else if (i == n - 1)
        {
            B[m + i] = 1;
            B[m + n + i] = -1;
            B[m + 2 * n + i] = 0;
        }
        else
        {
            B[m + i] = 0;
            B[m + 2 * n + i] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        C[i] = 0;
    }
    // for (int i = 0; i < 3 * n + m; i++)
    // {
    //     for (int j = 0; j < n + m; j++)
    //     {
    //         cout << A[i][j] << ',';
    //     }
    //     cout << '<' << B[i] << '\n';
    // }
    // cout << '\n';
    // for (int i = 0; i < n + m; i++)
    // {
    //     cout << C[i] << ',';
    // }
    std::vector<int> vartype(m + n, GLP_BV);
    for (int i = 0; i < n; i++)
    {
        vartype[i] = GLP_IV;
    }
    std::pair<double, std::vector<double>> res;
    res = ypglpk::mixed_integer_linear_programming(A, B, C, vartype);
    if (res.first == -ypglpk::INF)
    {
        cout << -1;
    }
    else
    {
        cout << static_cast<long long>(res.first) << '\n';
        for (int i = 0; i < m; i++)
        {
            cout << res.second[n + i];
        }
    }
}