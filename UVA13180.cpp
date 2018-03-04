#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int pearls[1100];
    while(cin>>pearls[0] && pearls[0]!=0){
        int cnt = 1;
        while(cin>>pearls[cnt] && pearls[cnt]!=0){
            cnt++;
        }
        sort(pearls,pearls+cnt);
        bool flag=true;
        if(cnt%2==0){
            flag=false;
        }
        else{
            for(int i=0;i<cnt-1;i+=2){
                if(pearls[i] != pearls[i+1]){
                    flag=false;
                }
            }
        }

        if(flag){
            cout<<pearls[0];
            for(int i=2;i<cnt;i+=2){
                cout<<" "<<pearls[i];
            }
            for(int i=cnt-3;i>=0;i-=2){
                cout<<" "<<pearls[i];
            }
            cout<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
