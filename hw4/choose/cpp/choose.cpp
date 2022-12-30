#include "choose.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Feel free to use global variables.
However, if you want to write your code more "correctly",
you can search for the keyword "anonymous namespace", a helpful tool in C++.
*/
bool compare(int &a, int &b)
{
    return compare_task(a, b) == 1;
}
// this is an example usage
void schedule(int N)
{
    vector<int> task(N + 1);
    for (int i = 1; i <= N; i++)
    {
        task[i] = i;
    }
    sort(task.begin() + 1, task.end(), compare);
    int endtime[3];
    endtime[1] = endtime[2] = 0;
    // if (compare_task(1, 2) <= 0)
    // {
    //     endtime[1] = assign_task(1, 1);
    //     endtime[2] = assign_task(2, 2);
    // }
    // else
    // {
    //     endtime[2] = assign_task(2, 1);
    //     endtime[1] = assign_task(1, 2);
    // }
    for (auto &v : task)
    {
        if (v > 0)
        {
            endtime[1] <= endtime[2] ? endtime[1] = assign_task(1, v) : endtime[2] = assign_task(2, v);
        }
    }
}
