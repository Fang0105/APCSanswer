#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ull unsigned long long
using namespace std;
int MAX = LONG_MAX;
int MIN = LONG_MIN;


signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a,b;
	cin>>a>>b;
	int n;
	cin>>n;
	int tot = 0;
	while(n--){
		int f;
		int ca=0,cb=0;
		while(cin>>f&&f){
			if(f==a){
				ca++;
			}else if(f==b){
				cb++;
			}else if((f+a)==0){
				ca--;
			}else if((f+b)==0){
				cb--;
			}
		}
		if(ca&&cb){
			tot++;
		}		
	}
	cout<<tot<<endl;



	return 0;
}