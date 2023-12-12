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
const int MAX = 5050; // PLZ CHK!

int N;
vector<int> G[MAX];

void dfs(int cur, int prv, int dep, map<int,vector<pii>> &d, int idx) {
    if (d[dep].empty() || d[dep].back().F!=idx) d[dep].pb({idx,1});
    else d[dep].back().S++;

    for (int nxt:G[cur]) {
        if (nxt==prv) continue;
        dfs(nxt,cur,dep+1,d,idx);
    }
}

ll f(int s) {
    map<int,vector<pii>> d;
    for (int i=0; i<sz(G[s]); i++) dfs(G[s][i],s,1,d,i);

    ll ret=0;
    for (auto &[dd,v]:d) {
        int sz=sz(v);
        ll sum=0;
        vector<ll> P(sz+1);
        
        for (int i=1; i<=sz; i++) {
            sum+=v[i-1].S;
            P[i]=P[i-1]+v[i-1].S;
        }

        for (int i=2; i<=sz; i++) {
            ret+=P[i-1]*1ll*v[i-1].S*(sum-P[i]);
        }
    }

    return ret;
}

int main() {
    fio();
    cin>>N;
    for (int i=0; i<N-1; i++) {
        int u,v; cin>>u>>v;
        G[u].pb(v), G[v].pb(u);
    }

    // f(5);
    ll ans=0;
    for (int i=1; i<=N; i++) {
        ans+=f(i);
    }

    cout<<ans;
    return 0;
}