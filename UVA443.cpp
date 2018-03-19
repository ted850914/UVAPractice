#include<iostream>
#include<algorithm>
#include<vector>
#define maximum 2000000000
using namespace std;
vector<long long int> array;
bool check(long long int n){
	for(int i=0;i<array.size();i++){
		if(n==array[i])
			return false;
	}
	return true;
}
void solve(int n){
	long long int tmp;

	tmp=array[n]*2;
	if(tmp<=maximum&&check(tmp)){
		array.push_back(tmp);
	}

	tmp=array[n]*3;
	if(tmp<=maximum&&check(tmp)){
		array.push_back(tmp);
	}

	tmp=array[n]*5;
	if(tmp<=maximum&&check(tmp)){
		array.push_back(tmp);
	}

	tmp=array[n]*7;
	if(tmp<=maximum&&check(tmp)){
		array.push_back(tmp);
	}
	if(n<array.size())
		solve(n+1);
}
int main(){
	array.push_back(1);
	solve(0);
	sort(array.begin(),array.end());
	int num;
	while(cin>>num&&num!=0){
		if(num%10==1&&num%100!=11)
			cout<<"The "<<num<<"st humble number is "<<array[num]<<"."<<endl;
		else if(num%10==2&&num%100!=12)
			cout<<"The "<<num<<"nd humble number is "<<array[num]<<"."<<endl;
		else if(num%10==3&&num%100!=13)
			cout<<"The "<<num<<"rd humble number is "<<array[num]<<"."<<endl;
		else
			cout<<"The "<<num<<"th humble number is "<<array[num]<<"."<<endl;
	}
}
