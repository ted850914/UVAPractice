#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		if(s.length()==5)
			cout<<"3"<<endl;
		else{
			if(s[0]=='o'&&s[1]=='n' || s[0]=='o'&&s[2]=='e' || s[1]=='n'&&s[2]=='e')
				cout<<"1"<<endl;
			else
				cout<<"2"<<endl;
		}
	}
}
