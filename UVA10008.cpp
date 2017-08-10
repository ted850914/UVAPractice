#include<iostream>
#include<string.h>
using namespace std;
int main(){
	int n,num[2][30];
	char s[100000];
	while(cin>>n){
		cin.get();
		memset(num,0,sizeof(num));
		for(int i=1;i<=26;i++){
			num[0][i]=i;
		}
		while(n--){
			cin.getline(s,100000);
			for(int i=0;i<strlen(s);i++){
				if(s[i]>='A'&&s[i]<='Z'){
					num[1][s[i]-64]++;
				}
				else if(s[i]>='a'&&s[i]<='z'){
					num[1][s[i]-96]++;
				}
			}
		}
		for(int i=1;i<=26;i++){
			for(int j=i+1;j<=26;j++){
				if(num[1][i]<num[1][j]){
					int a=num[1][i];
					num[1][i]=num[1][j];
					num[1][j]=a;
					a=num[0][i];
					num[0][i]=num[0][j];
					num[0][j]=a;
				}
				else if(num[1][i]==num[1][j]){
					if(num[0][i]>num[0][j]){
						int a=num[1][i];
						num[1][i]=num[1][j];
						num[1][j]=a;
						a=num[0][i];
						num[0][i]=num[0][j];
						num[0][j]=a;
					}
				}
			}
		}
		
		for(int i=1;i<=26;i++){
			if(num[1][i]){
				cout<<(char)(num[0][i]+64)<<" "<<num[1][i]<<endl;
			}
		}
	}
} 
