#include <iostream>
#include <thread>
#include <vector>
#include<map>
#include "rand-string.h"

#define MILLION 1000000
#define NUM_THREADS 10
#define STR_LEN 20

typedef vector<thread> thread_vector;

void do_a_million(int iteration)
{
    cout << "Thread " << iteration << " start" << endl;
    for (int i = 1; i <= MILLION; i++)
    {
        string str = getRandString(STR_LEN);
        cout << str << endl;
    }
    cout << "Thread " << iteration << " complete" << endl;
}

int main()
{
    thread_vector threads;

    for (int i = 1; i <= NUM_THREADS; i++)
    {
        threads.push_back(thread(&do_a_million, i));
    }

    for (thread_vector::iterator iter = threads.begin(); iter != threads.end(); iter++)
    {
        iter->join();
    }

    return 0;
}
