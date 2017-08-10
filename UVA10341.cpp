#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int p,q,r,s,t,u;
double f(double a){
    return p*exp(-a)+q*sin(a)+r*cos(a)+s*tan(a)+t*a*a+u;
}
int main(){
    double up,down,mid;
    bool flag;
    cout<<fixed<<setprecision(4);
    while(cin>>p>>q>>r>>s>>t>>u){
        flag=false;
        up=1;
        down=0;
        while(up!=down){
            mid=(up+down)/2;
            if(int(f(up)*1000000)==0){
                cout<<up<<endl;
                flag=true;
                break;
            }
            if(int(f(down)*1000000)==0){
                cout<<down<<endl;
                flag=true;
                break;
            }
            if(int(f(mid)*1000000)==0){
                cout<<mid<<endl;
                flag=true;
                break;
            }
            if(f(up)*f(mid)*1000000<0){
                down=mid;
            }
            else{
                up=mid;
            }
        }
        if(!flag){
            cout<<"No solution"<<endl;
        }
    }
}
