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
const int MAX = 303030; // PLZ CHK!

int N,D[MAX],P[MAX];
vector<int> G[MAX];
pii mxd={0,0};

void dfs(int cur, int prv) {
    mxd=max(mxd, {D[cur],cur});

    for (int nxt:G[cur]) {
        if (nxt==prv) continue;
        P[nxt]=cur;
        D[nxt]=D[cur]+1;
        dfs(nxt,cur);
    }
}

vector<int> di;
int V[MAX];

void ans(int cur) {
    V[cur]=1;
    if (cur!=di[1]) cout<<cur<<sp;
    for (int nxt:G[cur]) {
        if (V[nxt]) continue;
        ans(nxt);
    }
}

int main() {
    fio();

    cin>>N;
    for (int i=0; i<N-1; i++) {
        int u,v; cin>>u>>v;
        G[u].pb(v), G[v].pb(u);
    }

    dfs(1,0);
    memset(D,0,sizeof D), memset(P,0,sizeof P);
    int s=mxd.S;
    mxd={0,0};
    dfs(s,0);

    for (int x=mxd.S; x!=0; di.pb(x),x=P[x]);

    if (sz(di)<=3) {
        cout<<"NO";
        return 0;
    }

    cout<<"YES\n";

    cout<<di[1]<<sp;
    ans(di[0]);

    return 0;
}