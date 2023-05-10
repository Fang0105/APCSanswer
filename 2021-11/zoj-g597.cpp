#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

bool cmp(int a,int b){
	return a>b;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int>ve(n,0);
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		ve[a-1]+=c;
		ve[b]-=c;
	}
	vector<int>work;
	int k = 0;
	for(int i:ve){
		k+=i;
		work.push_back(k);
	}
	sort(work.begin(),work.end(),cmp);
	vector<int>machine;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		machine.push_back(a);
	}
	sort(machine.begin(),machine.end());
	int cnt = 0;
	for(int i=0;i<n;i++){
		cnt+=machine[i]*work[i];
	}
	cout<<cnt<<endl;





	return 0;
}