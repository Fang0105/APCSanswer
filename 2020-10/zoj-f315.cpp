#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define lowbit(X) ((X)&(-X)) 
using namespace std;

int n;
int bit[200010];

void modify(int x,int pos){
	while(pos<=2*n){
		bit[pos]+=x;
		pos += lowbit(pos);	
	}
}

int query(int pos){
	int ans = 0;
	while(pos){
		ans+=bit[pos];
		pos -= lowbit(pos);
	}
	return ans;
}

signed main(){
	cin>>n;
	memset(bit,0,sizeof(bit));
	map<int,pair<int,int> >mp;
	for(int i=1;i<=2*n;i++){
		int a;
		cin>>a;
		if(mp[a].first==0){
			mp[a].first = i;
		}else{
			mp[a].second = i;
			
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		int x=mp[i].first,y=mp[i].second;
		modify(1,x);
		modify(1,y);
		ans+=query(y-1)-query(x);
	}
	cout<<ans<<endl;
	
	
	
	
	
	return 0;
}
