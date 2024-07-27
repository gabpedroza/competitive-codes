#include<bits/stdc++.h>
const int MAXN = 2000 + 10;
int sticks[MAXN];
int bb(int l, int r, const int i, const int j){
    while(l < r){
        int mid = (l + r)/2;
        if(sticks[mid] > sticks[i] + sticks[j]){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    int mid = (l+r)/2;
    if(sticks[mid] > sticks[i] + sticks[j]){
        return mid;
    }
    else return 0;
}
int main(){
    int n; scanf("%d", &n);
    for(; n != 0; scanf("%d", &n)){
        for(int i = 0; i < n; ++i){
            scanf("%d", &sticks[i]);
        }
        std::sort(sticks, sticks + n);
        int cont = 0;
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                int temp = bb(j + 1, n-1, i, j);
                if(temp != 0){
                    cont += n - temp;
                }
            }
        }
        printf("%d\n", cont);
    }
    printf("\n");
    return 0;
}