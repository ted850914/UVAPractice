#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    cin.get();
    for(int i=1;i<=t;i++){
        cout<<"Case "<<i<<": ";
        char c;
        int num;
        while(cin.get(c)&&c!='\n'){
            cin>>num;
            for(int i=0;i<num;i++)
                cout<<c;
        }
        cout<<endl;
    }
}
