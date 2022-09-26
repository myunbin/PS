#include <bits/stdc++.h>
using namespace std;

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

typedef pair<int, char> pic;
int n,m,k;
int ans;
void dfs(vector<vector<pic>> &g, char lst, int cur, int curk, int len) {
    ans=max(ans, len);
    if (len>m*2) {
        ans=INF;
        return;
    }

    for (auto [nxt, nc]:g[cur]) {
        if ((lst=='A' && nc=='B') || (lst=='B' && nc=='C') || (lst=='C' && nc=='A') || lst=='D') dfs(g, nc, nxt, curk, len+1);
        else if (curk>0) dfs(g, lst, nxt, curk-1, len);
    }
}

void dfs2(vector<vector<pic>> &g, char lst, int cur, int len) {
    ans=max(ans, len);
    if (len>m*2) {
        ans=INF;
        return;
    }

    for (auto [nxt, nc]:g[cur]) {
        if ((lst=='A' && nc=='B') || (lst=='B' && nc=='C') || (lst=='C' && nc=='A') || lst=='D') dfs2(g, nc, nxt, len+1);
        else dfs2(g, nc, nxt, len);
    }
}

void solve() {
    ans=0;
    cin>>n>>m>>k;
    vector<vector<pic>> g(n+1);
    for (int i=0; i<m; i++) {
        int u,v; char c;
        cin>>u>>v>>c;
        g[u].pb({v,c});
    }

    if (n>10 || m>20) {
        cout<<0<<endl;
        return;
    }

    if (k==-1) {
        for (int i=1; i<=n; i++) {
            dfs2(g, 'D', i, 0);
        }
    }
    else {
        for (int i=1; i<=n; i++) {
            dfs(g, 'D', i, k, 0);
        }   
    }

    cout<<(ans==INF?-1:ans)<<endl;
}
int main() {
    fio();
    int t;
    cin>>t;
    for (int i=1; i<=t; i++) {
        cout<<"Case #"<<i<<endl;
        solve();
    }
    return 0;
}