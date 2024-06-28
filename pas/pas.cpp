#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;
int lista[MAXN];
int main(){
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        int atu; scanf("%d", &lista[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n;){
        for(int j = i + 1; ; ++j){
            if(j > n){
                i = j;
                //printf("cabo\n");
                break;
            }
            if((lista[j] - lista[i]) != (lista[i+1] - lista[i])*(j-i)){ //nao eh pa
                //printf("pa do %d ao %d\n", i, j-1);
                i = j;
                break;
            }
        }
        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}