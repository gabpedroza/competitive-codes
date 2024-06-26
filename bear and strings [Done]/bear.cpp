#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5000 + 10;
char phrase[MAXN];
set<pair<int, int> > garantido;
int main(){
    scanf(" %[^\n]", phrase + 5);
    int ans = 0;
    int size = 0;
    for(int i = 5; phrase[i] != '\0'; size = i++);
    /*for(int i = 5; i <= size; ++i){
        for(int j = i; j <= size; ++j){
            int tem = 0;
            for(int k = i; k <= j - 3; ++k){
                if(phrase[k] == 'b' && phrase[k + 1] == 'e'
                && phrase[k + 2] == 'a' && phrase[k + 3] == 'r'){
                    tem = 1;
                    break;
                }
            }
            if(tem == 1) 
                garantido.insert({i, j});
        }
    }*/
    for(int i = 5; i <= size; ++i){
        int temBear = 0;
        int contBear = 0;
        for(int j = i; j <= size - 3; ++j){
            if(phrase[j] == 'b' && phrase[j + 1] == 'e'
            && phrase[j + 2] == 'a' && phrase[j + 3] == 'r'){
                temBear = 1;
            }
            /*if(temBear == 1)
                garantido.erase(garantido.find({i, j}));*/
            ans += temBear;
        }
    }
    /*for(auto el : garantido){
        printf("didnt find bear here: ");
        for(int k = el.first; k <= el.second; ++k){
            printf("%c", phrase[k]);
        }
        printf("\n");
    }*/
    //printf("%d\n", ans + garantido.size());
    printf("%d\n", ans);
    return 0;
}