#include<bits/stdc++.h>
const int MAXN = 2000 + 10;
int sticks[MAXN];
int mapa[30][30];
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
        printf("min %d e %d: %d\n", i, j, (r+l)/2);
        return (r+l)/2;
    }
    else return 0;
}
int main(){
    std::srand(std::time(0));
    int n = 10;
    for(int aa = 1; aa <= 1; ++aa){
        for(int i = 1; i <= n; ++i){
            sticks[i] = rand()%15;
        }
        std::sort(sticks + 1, sticks + 1 + n);
        //for(int i = 1; i <= n; ++i){
        //    printf("%d ", sticks[i]);
        //}
        //printf("\nR:");
        int cont = 0;
        int cont2 = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = i + 1; j <= n; ++j){
                for(int k = j + 1; k <= n; ++k){
                    if(sticks[k] > sticks[i] + sticks[j]){
                        //printf("%d > %d + %d\n", k, i, j);
                        cont2++;
                    }else{
                        mapa[i][j] = 1;
                    }
                }
            }
        }
        for(int i = 1; i <= n; ++i){
            for(int j = i + 1; j <= n; ++j){
                int temp = bb(j + 1, n, i, j);
                if(temp != 0){
                    cont += n - temp + 1;
                }
                //printf("cont = %d\n", cont);
            }
        }
        if(cont2 != cont){
            printf("1: %d; 2: %d\n", cont, cont2);
            for(int i = 1; i <= n; ++i){
                printf("%d ", sticks[i]);
            }
            printf("\n");
        }
    }
    return 0;
}