#include<bits/stdc++.h>
using namespace std;
constexpr uint64_t fact(uint64_t&& num){
    if(num <= 2) return num;

    return num*fact(num-1);
}
template <uint64_t N>
struct Factorial 
{
    enum { value = N * Factorial<N - 1LL>::value};
};

template <>
struct Factorial<0> 
{
    enum { value = 1LL };
};
int main(){
    printf("%lld\n", Factorial<6>::value);
    return 0;
}