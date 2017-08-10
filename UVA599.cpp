#include<iostream>
#include<string.h>
using namespace std;
bool array[26][26],color[26];
int cnt;
void DFS(int num){
    if(color[num]){
        cnt++;
        color[num]=false;
        for(int i=0;i<26;i++){
            if(array[num][i]){
                DFS(i);
            }
        }
    }
}
int main(){
    int t,tree,acorn;
    char save[100],garbage;
    cin>>t;
    cin.get(garbage);
    while(t--){
        memset(array,false,sizeof(array));
        memset(color,false,sizeof(color));
        tree=0;
        acorn=0;

        while(cin.getline(save,100)&&save[0]!='*'){
            array[save[1]-'A'][save[3]-'A']=true;
            array[save[3]-'A'][save[1]-'A']=true;
        }
        cin.getline(save,100);
        for(int i=0;i<strlen(save);i+=2){
            color[save[i]-'A']=true;
        }
        for(int i=0;i<26;i++){
            cnt=0;
            if(color[i]){
                DFS(i);
            }
            if(cnt>1)
                tree++;
            else if(cnt==1){

                acorn++;
            }
        }
        cout<<"There are "<<tree<<" tree(s) and "<<acorn<<" acorn(s)."<<endl;
    }
}
