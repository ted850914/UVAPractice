#include<iostream>
#include<queue>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        priority_queue<int> blue,red;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int save;
            cin>>save;
            if(save>0){
                blue.push(save);
            }
            else{
                red.push(-save);
            }
        }
        int num=0,ans=0;
        bool flag;//true is blue  false is red
        if((!blue.empty())&&(red.empty()||blue.top()>red.top())){
            num=blue.top();
            ans++;
            flag=false;
        }
        else{
            num=red.top();
            ans++;
            flag=true;
        }
        while(!blue.empty()&&!red.empty()){
            if(flag){
                while(!blue.empty()&&blue.top()>num){
                    blue.pop();
                }
                if(!blue.empty()){
                    num=blue.top();
                    ans++;
                    flag=false;
                }
            }
            else{
                while(!red.empty()&&red.top()>num){
                    red.pop();
                }
                if(!red.empty()){
                    num=red.top();
                    ans++;
                    flag=true;
                }
            }
        }
        cout<<ans<<endl;
    }
}
