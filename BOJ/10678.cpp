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
const int MAX = 22; // PLZ CHK!

void dfs(int cur, int tm, vector<vector<pii>> &g, vector<vector<int>> &v) {
    v[cur][tm]=1;
    for (auto [nxt,cst]:g[cur]) {
        if (v[nxt][tm+cst]) continue;
        dfs(nxt, tm+cst, g, v);
    }
}

int main() {
    fio();
    int n,m;
    cin>>n>>m;
    
    vector<vector<pii>> g1(MAX), g2(MAX);
    for (int i=0; i<m; i++) {
        int u,v,a,b;
        cin>>u>>v>>a>>b;
        g1[u].pb({v,a});
        g2[u].pb({v,b});
    }

    vector<vector<int>> v1(MAX, vector<int>(MAX*1000,0));
    dfs(1,0,g1,v1);

    vector<vector<int>> v2(MAX, vector<int>(MAX*1000,0)); 
    dfs(1,0,g2,v2);

    for (int i=1; i<MAX*1000; i++) {
        if (v1[n][i] && v2[n][i]) {
            cout<<i;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}