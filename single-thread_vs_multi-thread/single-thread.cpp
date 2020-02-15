#include <iostream>
#include<map>
#include "rand-string.h"

#define TASK_LENGTH 65536
#define NUM_ITERATIONS 128
#define STR_LEN 16

void do_task(int iteration)
{
    cout << "Iteration " << iteration << " start" << endl;
    for (int i = 1; i <= TASK_LENGTH; i++)
    {
        string str = getRandString(STR_LEN);
        cout << "single-thread : do_task : str = " << str << endl;
    }
    cout << "Iteration " << iteration << " complete" << endl;
}

int main()
{
    for (int i = 1; i <= NUM_ITERATIONS; i++)
    {
        do_task(i);
    }

    return 0;
}
