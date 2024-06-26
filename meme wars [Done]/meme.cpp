#include<bits/stdc++.h>
using namespace std;
string subs[2];
int main(){
    int n; scanf("%d", &n);
    subs['a' - 'a'] = "a";
    for(int i = 'a' - 'a' + 1; i <= 'z' - 'a' - 1; ++i){
        if(true || subs[i%2].empty()){
            subs[i%2] = subs[(i-1)%2] + (char)(i + 'a') + subs[(i-1)%2];
        }
    }
    printf("%c\n", subs[('z' - 'a' - 1)%2][n - 1]);
    return 0;
}