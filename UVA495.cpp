#include<iostream>
#include<string.h>
using namespace std;
int n,a[301],b[301],c[5001][301];
void add(int num){
    int carry=0;
    if(num%2==0){
        for(int i=300;i>=0;i--){
            a[i]=a[i]+b[i]+carry;
            carry=a[i]/10000;
            a[i]=a[i]%10000;
        }
    }
    else{
        for(int i=300;i>=0;i--){
            b[i]=a[i]+b[i]+carry;
            carry=b[i]/10000;
            b[i]=b[i]%10000;
        }
    }
}
int main(){
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    a[300]=0;
    b[300]=1;
    for(int i=2;i<=5000;i++){
        add(i);
        if(i%2==0){
            memcpy(c[i],a,sizeof(c[i]));
        }
        else{
            memcpy(c[i],b,sizeof(c[i]));
        }
    }
    while(cin>>n){
        cout<<"The Fibonacci number for "<<n<<" is ";
        if(n==0||n==1)
            cout<<n<<endl;
        else{
            bool flag=false,flag2=false;
            for(int i=0;i<=300;i++){
                if(c[n][i])
                    flag=true;
                if(flag&&!flag2){
                    cout<<c[n][i];
                    flag2=true;
                }
                else if(flag2){
                    if(c[n][i]/1000==0)
                        cout<<"0";
                    else{
                        cout<<c[n][i]/1000;
                        c[n][i]=c[n][i]%1000;
                    }
                    if(c[n][i]/100==0)
                        cout<<"0";
                    else{
                        cout<<c[n][i]/100;
                        c[n][i]=c[n][i]%100;
                    }
                    if(c[n][i]/10==0)
                        cout<<"0";
                    else{
                        cout<<c[n][i]/10;
                        c[n][i]=c[n][i]%10;
                    }
                    cout<<c[n][i];
                }
            }
            cout<<endl;
        }
    }
}
