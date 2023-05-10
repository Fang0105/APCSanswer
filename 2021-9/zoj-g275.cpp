#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;


signed main(){
	int n;
	cin>>n;
	while(n--){
		int a1[8],a2[8];
		for(int i=1;i<8;i++){
			cin>>a1[i];
		}
		for(int i=1;i<8;i++){
			cin>>a2[i];
		}
		bool violation = false;
		if(!((a1[2]!=a1[4]&&a1[2]==a1[6])&&(a2[2]!=a2[4]&&a2[2]==a2[6]))){
			cout<<"A";
			violation = true;
		}
		if(!(a1[7]==1&&a2[7]==0)){
			cout<<"B";
			violation = true;
		}
		if(!(a1[2]!=a2[2]&&a1[4]!=a2[4]&&a1[6]!=a2[6])){
			cout<<"C";
			violation = true;
		}
		if(!violation){
			cout<<"None";
		}
		cout<<endl;
	}

	return 0;
}
