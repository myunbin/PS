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
const int MAX = 101010; // PLZ CHK!

vector<int> g[MAX], gi[MAX];
bool v[MAX], f[MAX];
int p[MAX];
vector<int> cyl;

void dfs1(int cur) {
    v[cur]=1;
    for (int nxt:g[cur]) {
        if (v[nxt]) {
            if (!f[nxt]) cyl.pb(nxt);
            continue;
        }
        dfs1(nxt);
    }
    f[cur]=1;
}

void dfs2(int cur) {
    v[cur]=1;
    for (int nxt:gi[cur]) {
        if (v[nxt]) continue;
        dfs2(nxt);
    }
}

int main() {
    fio();
    int n,m;
    cin>>n>>m;
    for (int i=0; i<m; i++) {
        int u,v;
        cin>>u>>v;
        g[u].pb(v), gi[v].pb(u);
    }

    for (int i=1; i<=n; i++) {
        if (!v[i]) dfs1(i);
    }
    fill(v, v+MAX, 0);

    for (int x:cyl) {
        if (!v[x]) dfs2(x);        
    }

    int ans=n;
    for (int i=1; i<=n; i++) ans-=v[i];

    cout<<ans;
    return 0;
}