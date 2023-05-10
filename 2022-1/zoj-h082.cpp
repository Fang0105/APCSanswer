#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

struct Man{
	int s,t,lose,id;
};

bool cmp(Man *man1, Man *man2){
	return (man1->s*man1->t >= man2->s*man2->t);
}

signed main(){
	int n,m;
	cin>>n>>m;
	int S[n+1],T[n+1];
	for(int i=1;i<=n;i++){
		cin>>S[i];
	}
	for(int i=1;i<=n;i++){
		cin>>T[i];
	}
	vector<Man*>game;
	for(int i=0;i<n;i++){
		int id;
		cin>>id;
		Man *man = (Man*)malloc(sizeof(Man));
		man->s = S[id];
		man->t = T[id];
		man->lose = 0;
		man->id = id;
		game.push_back(man);
	}
	while(game.size()!=1){
		queue<Man*>winner;
		queue<Man*>loser;
		for(int i=1;i<game.size();i+=2){
			Man *man1 = game[i-1];
			Man *man2 = game[i];
			if(cmp(man1,man2)){
				int man1s=man1->s, man1t=man1->t, man2s=man2->s, man2t=man2->t;
				man1->s += ((man2s*man2t)/(2*man1t));
				man1->t += ((man2s*man2t)/(2*man1s));
				man2->s += man2s/2;
				man2->t += man2t/2;
				man2->lose++;
				winner.push(man1);
				loser.push(man2);
			}else{
				int man1s=man1->s, man1t=man1->t, man2s=man2->s, man2t=man2->t;
				man2->s += ((man1s*man1t)/(2*man2t));
				man2->t += ((man1s*man1t)/(2*man2s));
				man1->s += man1s/2;
				man1->t += man1t/2;
				man1->lose++;
				winner.push(man2);
				loser.push(man1);
			}
		}
		if(game.size()%2==1){
			winner.push(game[game.size()-1]);
		}
		game.clear();
		while(!winner.empty()){
			game.push_back(winner.front());
			winner.pop();
		}
		while(!loser.empty()){
			if(loser.front()->lose!=m){
				game.push_back(loser.front());
			}
			loser.pop();
		}
	}
	cout<<game[0]->id<<endl;

	return 0;
}
