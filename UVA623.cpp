#include<iostream>
#include<string.h>
using namespace std;
int n,array[2001],minn;
void mul(int num){
    int carry=0;
    for(int i=2000;i>=0;i--){
        array[i]=array[i]*num+carry;
        carry=array[i]/10000;
        array[i]=array[i]%10000;
    }
}
int main(){
    while(cin>>n){
        cout<<n<<"!"<<endl;
        memset(array,0,sizeof(array));
        minn=2000;
        array[2000]=1;
        for(int i=2;i<=n;i++){
            mul(i);
        }
        bool flag=false,flag2=false;
        for(int i=0;i<=2000;i++){
            if(array[i])
                flag=true;
            if(flag&&!flag2){
                cout<<array[i];
                flag2=true;
            }
            else if(flag2){
                if(array[i]/1000==0)
                    cout<<"0";
                else{
                    cout<<array[i]/1000;
                    array[i]=array[i]%1000;
                }
                if(array[i]/100==0)
                    cout<<"0";
                else{
                    cout<<array[i]/100;
                    array[i]=array[i]%100;
                }
                if(array[i]/10==0)
                    cout<<"0";
                else{
                    cout<<array[i]/10;
                    array[i]=array[i]%10;
                }
                cout<<array[i];
            }

        }
        cout<<endl;
    }
}
