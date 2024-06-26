#include<stdio.h>
#include<chrono>
#include<algorithm>
using namespace std;

const int MAXN = (2<<26);
volatile int array1[MAXN + 1];
volatile int array2[MAXN + 1];

int main(){
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    volatile int n = 0;
    for(int i = 1; i <= MAXN; ++i){
        array1[i] = i;
        array2[i] = i;
    }
    random_shuffle(array2 + 1, array2 + MAXN + 1);
    auto t1 = high_resolution_clock::now();
    for(int i = 1; i <= MAXN; ++i){
        ++n;
    }
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms_double = t2 - t1;

    printf("%d %f\n", n, ms_double.count());
    //---------------------------------------
    n = 0;
    t1 = high_resolution_clock::now();
    for(int i = array2[0]; n <= MAXN; i = array2[i]){
        ++n;
    }
    t2 = high_resolution_clock::now();
    ms_double = t2 - t1;

    printf("%d %f\n", n, ms_double.count());
    return 0;
}