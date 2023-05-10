#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

bool isRoot = true;
int cnt = 0;

void dfs(int n){
	int a;
	cin>>a;
	if(isRoot==true){
		isRoot = false;
	}else{
		if(a!=0){
			cnt += abs(a-n);
		}
	}
	if(a==0){
		return;
	}else{
		for(int i=0;i<2+(a%2);i++){
			dfs(a);
		}
	}
} 

signed main(){
	dfs(0);
	cout<<cnt<<endl;	

	return 0;
}