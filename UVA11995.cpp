#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		priority_queue<int> pq;
		queue<int> q;
		stack<int> s;
		bool flag_pq=true,flag_q=true,flag_s=true;
		for(int i=0;i<n;i++){
			int command,x;
			cin>>command>>x;
			if(command==1){
				pq.push(x);
				q.push(x);
				s.push(x);
			} 
			else{
				if(pq.empty()||pq.top()!=x)
					flag_pq=false;
				if(q.empty()||q.front()!=x)
					flag_q=false;
				if(s.empty()||s.top()!=x)
					flag_s=false;
				if(!pq.empty())
					pq.pop();
				if(!q.empty())
					q.pop();
				if(!s.empty())
					s.pop();
			}
		}
		if((flag_pq&&flag_q)||(flag_pq&&flag_s)||(flag_q&&flag_s))
			cout<<"not sure"<<endl;
		else if(flag_pq)
			cout<<"priority queue"<<endl;
		else if(flag_q)
			cout<<"queue"<<endl;
		else if(flag_s)
			cout<<"stack"<<endl;
		else
			cout<<"impossible"<<endl;
	}
} 
