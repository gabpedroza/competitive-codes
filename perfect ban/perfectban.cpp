#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10, MAXM = 1000 + 10;
int pwr[MAXN][MAXM];
int main(){
    int n, m; scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            scanf("%d", &pwr[i][j]);
        }
    }
    int max1[] = {0, 0, 0}, max2[] = {0, 0, 0};
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(pwr[i][j] > max1[0]){
                max1[0] = pwr[i][j];
                max1[1] = i;
                max1[2] = j;
            }
        }
    }
    //testando: j do max1, i do max2
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(j == max1[2]) continue;
            if(pwr[i][j] > max2[0]){
                max2[0] = pwr[i][j];
                max2[1] = i;
                max2[2] = 0;
            }
        }
    }
    int max3[] = {0, 0, 0};
    //testando: i do max1
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(i == max1[1]) continue;
            if(pwr[i][j] > max3[0]){
                max3[0] = pwr[i][j];
                max3[1] = i;
                max3[2] = j;
            }
        }
    }
    if(max2[0] > max3[0]){
        printf("%d %d\n", max2[1], max1[2]);
    }else{
        printf("%d %d\n", max1[1], max3[2]);
    }
    return 0;
}