#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,coin[110],total=0,ans;
        bool value[55000]={false};
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>coin[i];
            total+=coin[i];
            for(int j=55000-1;j>=0;j--){
                if(value[j]==true){
                    value[j+coin[i]]=true;
                }
            }
            value[coin[i]]=true;
        }
        int i=(total+1)/2,j=(total+1)/2;
        if(total%2==0){
            ans=0;
        }
        else{
            ans=1;
        }
        while(!value[i]&&!value[j]){
            i--;
            j++;
            ans+=2;
        }
        if(n==0)
            cout<<"0"<<endl;
        else
            cout<<ans<<endl;
    }
}
