#include <iostream>
#include <stdio.h>
using namespace std;
void printhex(int n){
    if(n==10)
        cout<<'A';
    else if(n==11)
        cout<<'B';
    else if(n==12)
        cout<<'C';
    else if(n==13)
        cout<<'D';
    else if(n==14)
        cout<<'E';
    else if(n==15)
        cout<<'F';
    else
        cout<<n;
}
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int array[100]={0},now=0;
        string s;
        cin>>s;
        for(int j=0;j<s.length();j++){
            if(s[j]=='<'){
                if(now==0)
                    now=99;
                else
                    now--;
            }
            else if(s[j]=='>'){
                if(now==99)
                    now=0;
                else
                    now++;
            }
            else if(s[j]=='+'){
                if(array[now]==255)
                    array[now]=0;
                else
                    array[now]++;
            }
            else if(s[j]=='-'){
                if(array[now]==0)
                    array[now]=255;
                else
                    array[now]--;
            }
        }
        cout<<"Case "<<i<<":";
        for(int j=0;j<100;j++){
            cout<<" ";
            int save=0;

            save=array[j]%16;
            array[j]/=16;
            printhex(array[j]);
            array[j]=save;
            printhex(array[j]);
        }
        cout<<endl;
    }
}
