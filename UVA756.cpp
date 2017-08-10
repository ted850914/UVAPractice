#include <iostream>
#include <string.h>
using namespace std;
int main(){
	int a,b,c,d,day[30000],i,num=0;
	while(cin>>a>>b>>c>>d){
		num++;
		if(a==-1&&b==-1&&c==-1&&d==-1)
			break;
		memset(day,0,sizeof(day));
		a=a%23;
		b=b%28;
		c=c%33;
		for(;a<30000;a+=23){
			day[a]++;
		}
		for(;b<30000;b+=28){
			day[b]++;
		}
		for(;c<30000;c+=33){
			day[c]++;
		}
		for(i=1;i<30000;i++){
			if(day[i]==3)
				break;
		}
		if(i-d<=0)
			i+=21252;
		cout<<"Case "<<num<<": the next triple peak occurs in "<<i-d<<" days."<<endl;
	}
}
