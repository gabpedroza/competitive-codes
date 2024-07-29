#include<bits/stdc++.h>
using namespace std;
const long long int MAXN = 1000000 + 10;
long long int trees[MAXN];
int main(){
    long long int n, m; scanf("%lld %lld", &n, &m);
    for(long long int i = 1; i <= n; ++i){
        scanf("%lld", &trees[i]);
    }
    sort(trees + 1, trees + n + 1);
    long long int l = 0, r = 2e9;
    long long int mid = (l+r)/2;
    while(l < r){
        mid = (l+r)/2;
        //printf("m: %d\n", mid);
        long long int wood = 0;
        for(long long int i = 1; i <= n; ++i){
            if(trees[i] > mid)
                wood += trees[i] - mid;
        }
        if(wood < m){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    printf("%d\n", mid);
    return 0;
}