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

int A,B,E,P;
vector<vector<int>> G,RG;

int v[MAX],c[MAX],d[MAX];
int dfs(int cur, vector<vector<int>> &g) {
    v[cur]=1;
    int ret=1;
    for (int nxt:g[cur]) {
        if (v[nxt]) continue;
        ret+=dfs(nxt, g);
    }
    return ret;
}

int main() {
    fio();
    cin>>A>>B>>E>>P;
    G.resize(E+1), RG.resize(E+1);

    for (int i=0; i<P; i++) {
        int u,v; cin>>u>>v;
        G[u].pb(v), RG[v].pb(u);
    }

    for (int i=0; i<E; i++) {
        fill(v,v+MAX,0);
        c[i]=dfs(i,G);
    }

    for (int i=0; i<E; i++) {
        fill(v,v+MAX,0);
        d[i]=dfs(i,RG);
    }

    int x=0,y=0,z=0;
    for (int i=0; i<E; i++) {
        if (E-A<c[i]) x++;
        if (E-B<c[i]) y++;
        if (B<d[i]) z++;
    }

    cout<<x<<endl<<y<<endl<<z;
    return 0;
}