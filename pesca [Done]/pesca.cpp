#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;
int mar[MAXN][MAXN];
int main(){
    int n; scanf("%d\n", &n);
    for(int i = 1; i <= n; ++i){
        int xi, xf, yi, yf; scanf("%d %d %d %d", &xi, &xf, &yi, &yf);
        for(int j = xi; j < xf; ++j)
            for(int k = yi; k < yf; ++k)
                mar[j][k] = 1;
    }
    int ans = 0;
    for(int i = 1; i < MAXN; ++i)
        for(int j = 1; j < MAXN; ++j)
            ans += mar[i][j];

    printf("%d\n", ans);
    return 0;
}