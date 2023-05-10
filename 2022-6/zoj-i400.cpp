#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int m,n;
	cin>>m>>n;
	string encrypt;
	string num[m];
	for(int i=0;i<m;i++){
		string str;
		cin>>str;
		num[i] = str;
	}
	cin>>encrypt;
	while(m--){
		bool isEven = true;
		for(int i=0;i<n;i++){
			if(num[m][i]=='1'){
				isEven = !isEven;
			}
		}
		string ans = "";
		for(int i=n-1;i>=0;i--){
			if(num[m][i]=='0'){
				ans = encrypt[i]+ans;
			}else{
				ans = ans+encrypt[i];
			}
		}
		if(!isEven){
			encrypt = "";
			for(int i=(n+1)/2;i<n;i++){
				encrypt += ans[i];
			}
			if(n%2==1){
				encrypt += ans[n/2];
			}
			for(int i=0;i<n/2;i++){
				encrypt += ans[i];
			}
		}else{
			encrypt = ans;
		}
	}
	cout<<encrypt<<endl;





	return 0;
}