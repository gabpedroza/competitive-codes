#include<bits/stdc++.h>
#include<execution>
using namespace std;
const int MAXN = 11000;
array<int, MAXN> ind;
int A[MAXN][MAXN];
int B[MAXN][MAXN];
int C[MAXN][MAXN];
int main(){
    for(int i = 0; i < MAXN; ++i)
        ind[i] = i;
    srand(time(0));
    auto start = chrono::system_clock::now();
    for(int aa = 1; aa <= 3; ++aa){
        for(int i = 0; i < MAXN; ++i){
            for(int j = 0; j < MAXN; ++j){
                A[i][j] = rand();
                B[i][j] = rand();
            }
        }
        for_each(std::execution::par_unseq, ind.begin(), ind.end(), [](int i){
            for_each(std::execution::par_unseq, ind.begin(), ind.end(), [i](int j){
                for_each(std::execution::par_unseq, ind.begin(), ind.end(), [i, j](int k){
                    C[i][j] = A[i][k]*B[k][j];
                });
            });
        });
    }
    auto end = chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    printf("%f\n", elapsed_seconds);
    return 0;
}