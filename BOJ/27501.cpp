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

const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 505050; // PLZ CHK!

int n, a[MAX][3];
vector<int> g[MAX],t[MAX];

void dfs(int cur, int prv) {
    for (int nxt:g[cur]) {
        if (prv==nxt) continue;
        t[cur].pb(nxt);
        dfs(nxt, cur);
    }
}

int d[MAX][4];
int go(int i, int j) {
    int &ret=d[i][j];
    if (ret!=-1) return ret;

    ret=a[i][j];
    for (int k:t[i]) {
        int mx=0;
        for (int l=0; l<3; l++) {
            if (j==l) continue;
            mx=max(mx, go(k,l));
        }
        ret+=mx;
    }
    return ret;
}

int ans[MAX];

void tr(int i, int j) {
    ans[i]=j;
    for (int k:t[i]) {
        pii mx={0,0};
        for (int l=0; l<3; l++) {
            if (j==l) continue;
            mx=max(mx, {go(k,l),l});
        }
        tr(k,mx.S);
    }
}

int main() {
    fio();
    memset(d,-1,sizeof d);

    cin>>n;
    for (int i=0; i<n-1; i++) {
        int u,v;
        cin>>u>>v;
        g[u].pb(v), g[v].pb(u);
    }

    for (int i=1; i<=n; i++) {
        for (int j=0; j<3; j++) {
            cin>>a[i][j];
        }
    }

    dfs(1,0);
    
    vector<pii> can={{go(1,0),0}, {go(1,1),1}, {go(1,2),2}};
    sort(all(can));
    tr(1, can.back().S);

    cout<<can.back().F<<endl;
    for (int i=1; i<=n; i++) {
        if (ans[i]==0) cout<<'R';
        else if (ans[i]==1) cout<<'G';
        else cout<<'B';
    }

    return 0;
}