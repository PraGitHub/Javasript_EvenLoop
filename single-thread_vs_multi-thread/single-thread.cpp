#include <iostream>
#include<chrono>
#include<cstdint>
#include<map>

using namespace std;

#define MILLION 1000000
#define NUM_ITERATIONS 50
#define STR_LEN 20

static char chars[] = {"QWERTYUIOPASDFGHJKLZXCVBNM1234567890qwertyuiopasdfghjklzxcvbnm"};
static char magical_ten_chars[] = { "ilrawjoagk" };
static char magical_five_chars[] = {"sptde"};

string getRandString(int len = 40)
{
	string randString = "";
	using namespace std::chrono;
	uint64_t nanoTime = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
    uint tenPos = nanoTime % 10;
    uint64_t start = nanoTime/magical_ten_chars[tenPos];
    for(uint64_t i=start; i < start + len; i++)
    {
        uint64_t num = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count() + i;
        if(num % 7 == 0)
        {
            num = num * magical_five_chars[0];
        }
        else if(num % 5 == 0)
        {
            num = num * magical_five_chars[1];
        }
        else if(num % 3 == 0)
        {
            num = num * magical_five_chars[2];
        }
        else if(num % 2 == 0)
        {
            num = num * magical_five_chars[3];
        }
        else
        {
            num = num * magical_five_chars[4];
        }
        int charPos = num % 62;
        randString = randString + string(1, chars[charPos]);
    }
    return randString;
}

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
