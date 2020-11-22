#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second; return os;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> &v){for(T i : v)os << i << ", "; return os;}
template <typename T>
ostream &operator <<(ostream &os, set<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

int N;
vector<string> attr[100];
 
int main(){
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
	cin >> N;
	int match = 0;
	for(int i = 0; i < N; i++){
		string junk; cin >> junk;
		int K; cin >> K;
		for(int j = 0; j < K; j++){
			string x; cin >> x;
			attr[i].push_back(x);
		}
		sort(attr[i].begin(), attr[i].end());
		for(int j = 0; j < i; j++){
			int cmatch = 0;
			string isect[100];
			auto it = set_intersection(attr[i].begin(), attr[i].end(), attr[j].begin(), attr[j].end(), isect);
			match = max(match, (int)(it - isect));
		}
	}
	cout << match + 1 << endl;
	return 0;
}
