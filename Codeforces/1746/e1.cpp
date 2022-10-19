#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N;

bool qry(vector<int> &v){
	moo << "? " << v.size();
	for(int i : v){
		moo << ' ' << i;
	}
	moo << endl;
	moo.flush();
	string res; eat >> res;
	if(res == "YES") return 1;
	else return 0;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	vector<int> all;
	for(int i = 1; i <= N; i++) all.push_back(i);
	while(all.size() > 3){
		vector<int> q12, q13;
		for(int i = 0; i < all.size()/4; i++){
			q12.push_back(all[i]);
			q13.push_back(all[i]);
		}
		for(int i = all.size()/4; i < 2*all.size()/4; i++){
			q12.push_back(all[i]);
		}
		for(int i = 2*all.size()/4; i < 3*all.size()/4; i++){
			q13.push_back(all[i]);
		}
		bool a = qry(q12), b = qry(q13);
		int rq = 0;
		if(a && b) rq = 4;
		if(a && !b) rq = 3;
		if(!a && b) rq = 2;
		if(!a && !b) rq = 1;
		set<int> bad;
		for(int i = (rq-1) * all.size()/4; i < rq * all.size()/4; i++){
			bad.insert(all[i]);
		}
		vector<int> all2;
		for(int i : all){
			if(bad.count(i)) continue;
			all2.push_back(i);
		}
		all = all2;
	}
	if(all.size() == 3){
		vector<int> q1, q2;
		q1.push_back(all[0]);
		q2.push_back(all[1]);
		bool a = qry(q1);
		bool b = qry(q2);
		bool c = qry(q2);
		bool d = qry(q1);
		if(b && c){
			all.erase(all.begin());
		}else if(!b && !c){
			all.erase(all.begin()+1);
		}else if(a && b || c && d){
			all.erase(all.begin()+2);
		}else{
			all.erase(all.begin());
		}
	}
	moo << "! " << all[0] << endl;
	moo.flush();
	string res; eat >> res;
	if(res[1] == '('){
		moo << "! " << all[1] << endl;
	}
}