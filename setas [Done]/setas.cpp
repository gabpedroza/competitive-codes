#include<bits/stdc++.h>
using namespace std;

const int MAXN = 500 + 10;
uint_fast8_t marc[MAXN][MAXN];
char tabu[MAXN][MAXN];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

char setas[3][3] = {
    {0, 'V', 0},
    {'>', 0, '<'},
    {0, 'A', 0}
};

void dfs(int i, int j){
    marc[i][j] = 1;
    for(int k = 0; k <= 3; ++k){
        if(tabu[i + dx[k]][j + dy[k]] == setas[1 + dx[k]][1 + dy[k]] 
            && marc[i + dx[k]][j + dy[k]] == 0){
            dfs(i + dx[k], j + dy[k]);
        }
    }
}
int main(){
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            scanf(" %c", &tabu[i][j]);

    for(int i = 1; i <= n; ++i){
        if(tabu[1][i] == 'A')
            dfs(1, i);
        if(tabu[n][i] == 'V')
            dfs(n , i);
    }
    for(int j = 1; j <= n; ++j){
        if(tabu[j][1] == '<')
            dfs(j, 1);
        if(tabu[j][n] == '>')
            dfs(j, n);
    }
    
    int c = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            c += (marc[i][j] == 0);

    printf("%d\n", c);
    return 0;
}