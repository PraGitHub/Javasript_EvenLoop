#include <iostream>
#include <thread>
#include <vector>
#include<map>
#include "rand-string.h"

#define TASK_LENGTH 65536
#define NUM_THREADS 128
#define STR_LEN 16

typedef vector<thread> thread_vector;

void do_task(int iteration)
{
    cout << "Thread " << iteration << " start" << endl;
    for (int i = 1; i <= TASK_LENGTH; i++)
    {
        string str = getRandString(STR_LEN);
        cout << "multi-thread : do_task : str = " << str << endl;
    }
    cout << "Thread " << iteration << " complete" << endl;
}

int main()
{
    thread_vector threads;

    for (int i = 1; i <= NUM_THREADS; i++)
    {
        threads.push_back(thread(&do_task, i));
    }

    for (thread_vector::iterator iter = threads.begin(); iter != threads.end(); iter++)
    {
        iter->join();
    }

    return 0;
}
