#include <iostream>
#include <string.h>
using namespace std;
int array[47000]={0},prime[4900];
void Prime(){
	int num=0;
	long long int i,j;
	for(i=2;i<47000;i++){
		if(!array[i]){
			prime[num]=i;
			num++;
			for(j=i*i;j<47000;j+=i){
				array[j]=1;
			}
		}
	}
}
bool judge(int num){
	for(int i=0;i<4900&&num>prime[i]&&prime[i];i++){
		if(num%prime[i]==0){
			return false;
		} 
	} 
	return true;
}
int main(){
	Prime();
	long long int L,U;
	while(cin>>L>>U){
		if(L==1)
			L++;
		long long int a=0,b=0,min=99999999,max=0,ans1,ans2,ans3,ans4;
		for(long long int i=L;i<=U;i++){
			if(judge(i)){
				if(a==0){
					a=i;
					continue;
				}
				b=i;
				if(b-a>max){
					max=b-a;
					ans3=a;
					ans4=b;
				}
				if(b-a<min){
					min=b-a;
					ans1=a;
					ans2=b;
				}
				a=b;
			}
		}
		if(b==0)
			cout<<"There are no adjacent primes."<<endl;
		else
			cout<<ans1<<","<<ans2<<" are closest, "<<ans3<<","<<ans4<<" are most distant."<<endl;
	}
}
