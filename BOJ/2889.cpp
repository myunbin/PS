#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")

#define fileio() freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define allr(x) x.rbegin(), x.rend()
#define cmprs(x) sort(all(x)),x.erase(unique(all(x)),x.end())
#define endl "\n"
#define sp " "
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define rz resize
#define sz(a) (int)(a.size())
#define clr(a) a.clear()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef pair<double, int> pdi;

const int dx[] = {1,-1,0,0,1,1,-1,-1};
const int dy[] = {0,0,1,-1,1,-1,1,-1};
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010; // PLZ CHK!

int N,M;
set<int> G[MAX];
vector<int> T;

void dfs(int cur) {
    while (!G[cur].empty()) {
        int nxt=*G[cur].begin();
        G[cur].erase(G[cur].begin());

        if (G[nxt].find(cur)!=G[nxt].end()) {
            G[nxt].erase(cur);
            dfs(nxt);
        }
    }
    T.pb(cur);
}

int ans[MAX],D[MAX];
pii res[MAX];
map<pii,int> E;

int main() {
    fio();
    cin>>N>>M;
    for (int i=0; i<M; i++) {
        int u,v; cin>>u>>v;
        G[u].insert(v), G[v].insert(u);
        D[u]++,D[v]++;
        E[{min(u,v),max(u,v)}]=i;
    }

    for (int i=1; i<=N; i++) {
        if (sz(G[i])&1) {
            G[0].insert(i);
            G[i].insert(0);
        }
    }

    int x=0;
    for (int i=0; i<=N; i++) {
        if (!G[i].empty()) {
            T.clear();
            dfs(i);
            for (int i=0; i<sz(T)-1; i++) {
                if (T[i]==0 || T[i+1]==0) continue;
                int u=min(T[i],T[i+1]), v=max(T[i],T[i+1]);
                ans[E[{u,v}]]=x+1;
                if (x^1) res[u].F++, res[v].F++;
                else res[u].S++, res[v].S++;

                x^=1;
            }
        }
    }

    for (int i=1; i<=N; i++) {
        if (D[i]>1 && (res[i].F==0 || res[i].S==0)) {
            cout<<0;
            return 0;
        }
    }

    for (int i=0; i<M; i++) {
        cout<<ans[i]<<endl;
    }

    return 0;
}