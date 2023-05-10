#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ull unsigned long long
using namespace std;
int MAX = LONG_MAX;
int MIN = LONG_MIN;

struct Jelly{
	int x,y;
};

bool comp(Jelly j1,Jelly j2){
	if(j1.x==j2.x){
		return j1.y<j2.y;
	}else{
		return j1.x<j2.x;
	}
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	Jelly jelly[n+1];
	jelly[0].x = MAX;
	jelly[0].y = MAX;
	for(int i=1;i<=n;i++){
		cin>>jelly[i].x>>jelly[i].y;
	}
	sort(jelly,jelly+(n+1),comp);
	int mx = 0;
	int tail[n+5];
	bool re[n+5];
	memset(re,false,sizeof(re));
	re[0] = true;
	tail[0] = 0;
	for(int i=0;i<n;i++){
		int pos = upper_bound(tail,tail+mx+1,jelly[i].y)-tail-1;
		if(re[pos+1]==true){
			tail[pos+1] = min(tail[pos+1],jelly[i].y);
		}else{
			re[pos+1] = true;
			tail[pos+1] = jelly[i].y;
		}
		mx = max(mx,pos+1);
	}
	cout<<mx<<endl;

	
	
	
	return 0;
}
