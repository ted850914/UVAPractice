#include<iostream>
#include<stack>
using namespace std;
int main(){
    int t;
    stack<int> s;
    while(cin>>t&&t!=0){
        int array[1100];
        while(cin>>array[0]&&array[0]!=0){
            int top=0;
            for(int i=1;i<t;i++){
                cin>>array[i];
            }
            for(int i=1;i<=t;i++){
                s.push(i);
                while(!s.empty()&&s.top()==array[top]){
                    top++;
                    s.pop();
                }
            }
            if(top==t)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
            while(!s.empty())
                s.pop();
        }
        cout<<endl;
    }
}
Close
CPP

