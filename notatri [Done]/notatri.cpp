#include<bits/stdc++.h>
const int MAXN = 2000 + 10;
int sticks[MAXN];
int bb(int l, int r, const int i, const int j){
    //printf("starting bb with %d %d\n", a, b);
    while(l < r){
        int mid = (l + r)/2;
        
        //printf("testing %d\n", mid);
        if(sticks[mid] > sticks[i] + sticks[j]){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    if(sticks[(r+l)/2] > sticks[i] + sticks[j]){
        //printf("min %d e %d: %d\n", i, j, (r+l)/2);
        return (r+l)/2;
    }
    else return 0;
}
int main(){
    int n; scanf("%d", &n);
    for(; n != 0; scanf("%d", &n)){
        for(int i = 1; i <= n; ++i){
            scanf("%d", &sticks[i]);
        }
        std::sort(sticks + 1, sticks + 1 + n);
        //for(int i = 1; i <= n; ++i){
        //    printf("%d ", sticks[i]);
        //}
        //printf("\nR:");
        int cont = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = i + 1; j <= n; ++j){
                int temp = bb(j + 1, n, i, j);
                if(temp != 0){
                    cont += n - temp + 1;
                }
                //printf("cont = %d\n", cont);
            }
        }
        printf("%d\n", cont);
    }
    printf("\n");
    return 0;
}