#include <iostream>
#include <thread>

using namespace std;

#define MILLION 1000000
#define NUM_THREADS 16

void do_a_million(int iteration)
{
    cout << "Iteration " << iteration << " start" << endl;
    for (int i=1; i<=MILLION; i++){}
    cout << "Iteration " << iteration << " complete" << endl;
}

int main()
{
    for (int i=1; i<=NUM_THREADS; i++){}

    return 0;
}
