#include<iostream>
using namespace std;
struct node{
	int num;
	node* left;
	node* right;
};
void solve(node* now);
void put(node* root,int n);
int main(){
	int n;
	node* root=NULL;
	while(cin>>n){
		if(root==NULL){
			root=new node;
			root->num=n;
			root->left=NULL;
			root->right=NULL;
		}
		else
			put(root,n);
	}
	solve(root);
}
void put(node* root,int n){
	node* now=root;
	while(1){
		if(n>now->num){
			if(now->right==NULL){
				now->right=new node;
				now->right->num=n;
				now->right->left=NULL;
				now->right->right=NULL;
				return;
			}
			else
				now=now->right;
		}
		else{
			if(now->left==NULL){
				now->left=new node;
				now->left->num=n;
				now->left->left=NULL;
				now->left->right=NULL;
				return;
			}
			else
				now=now->left;
		}
	}
}
void solve(node* now){
	if(now->left!=NULL)
		solve(now->left);
	if(now->right!=NULL)
		solve(now->right);
	cout<<now->num<<endl;
}
