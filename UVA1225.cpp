#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,digit[10]={0};
        cin>>n;
        do{
            int save=n;
            do{
                digit[save%10]++;
                save/=10;
            }while(save!=0);
        }while(n--&&n>0);
        for(int i=0;i<10;i++){
            if(i)
                 cout<<" "<<digit[i];
            else
                 cout<<digit[i];
        }
        cout<<endl;
    }
}
