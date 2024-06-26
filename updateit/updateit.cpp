#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10000 + 10;

int BIT[MAXN];
int n;
int sum(int id){
    int res = 0;
    while(id > 0){
        res += BIT[id];
        id -= id&-id;
    }
    return res;
}

void insert(int id, int val){
    while(id <= n){
        BIT[id] += val;
        id += id&-id;
    }
}

int main(){
    int t; scanf("%d", &t);
    while(t-- > 0){
        int u; scanf("%d %d", &n, &u);
        for(int i = 1; i <= u; ++i){
            int l, r, val; scanf("%d %d %d", &l, &r, &val);
            insert(++l, val);
            insert(++r + 1, -val);
        }
        int q; scanf("%d", &q);
        for(int i = 1; i <= q; ++i){
            int id; scanf("%d", &id);
            printf("%d\n", sum(++id));
        }
        for(int i = 0; i <= n; ++i){
            BIT[i] = 0;
        }
    }
    return 0;
}