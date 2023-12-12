#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;

int n, m, chk;
vector<pair<int, int>> vtx[200005];
int vst[200005];
int d[200005];

void dfs(int cur){
	if(!chk){
		return;
	}
	vst[cur] = 1;
	for(auto x : vtx[cur]){
		if(!vst[x.first]){
			d[x.first] = d[cur]+x.second;
			dfs(x.first); 
		}
		else{
			if(d[x.first]-d[cur] != x.second){
				chk = 0;
			}
		}
	}
}

void solve(){
	chk = 1;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		vtx[i].clear();
		vst[i] = d[i] = 0;
	}
	for(int i=0; i<m; i++){
		int u, v, x;
		scanf("%d %d %d", &u, &v, &x);
			vtx[u].push_back({v, x});
			vtx[v].push_back({u, -x});
	}
	for(int i=1; i<=n; i++){
		if(vtx[i].empty()){
			continue;
		}
		if(vst[i]){
			continue;
		}
		dfs(i);
	}
	printf("%s\n", chk ? "YES" : "NO");
}

signed main(){
	int t = 1;
	scanf("%d", &t);
	while(t--) solve();
}