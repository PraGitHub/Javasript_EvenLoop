#include <iostream>
#include<map>
#include "rand-string.h"

#define MILLION 1000000
#define NUM_ITERATIONS 10
#define STR_LEN 20

void do_a_million(int iteration)
{
    //cout << "Iteration " << iteration << " start" << endl;
    for (int i = 1; i <= MILLION; i++)
    {
        getRandString(STR_LEN);
    }
    //cout << "Iteration " << iteration << " complete" << endl;
}

int main()
{
    for (int i = 1; i <= NUM_ITERATIONS; i++)
    {
        do_a_million(i);
    }

    return 0;
}
