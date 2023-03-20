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
const int MAX = 202020; // PLZ CHK!

struct ed {
    int u,v,w;
};

pii f[MAX];
int vst[MAX];

void dfs(int cur, int st, vector<int> &t, vector<int> &c) {
    vst[cur]=1;
    auto [nxt,cst]=f[cur];
    c.pb(cur), t.pb(cst);
    if (nxt==st) return;
    dfs(nxt, st, t, c);
}

int go(int i, int j, int n, vector<vector<int>> &d, vector<int> &a, int st) {
    if (i==n || (i==n-1 && st)) return 0;
    int &ret=d[i][j];
    if (ret!=-1) return ret;

    ret=a[i]+go(i+1,1,n,d,a,st);
    if (j) ret=min(ret, go(i+1,0,n,d,a,st));

    return ret;
}
int main() {
    fio();
    int n;
    cin>>n;
    vector<ed> v(n);
    for (auto &[u,v,w]:v) {
        cin>>u>>v>>w;
        f[u]={v,w};
    }

    int ans=0;
    for (int i=1; i<=n; i++) {
        if (!vst[i]) {
            vector<int> t,c;
            dfs(i,i,t,c);
            vector<vector<int>> d1(sz(t)+1, vector<int>(2,-1));
            vector<vector<int>> d2(sz(t)+1, vector<int>(2,-1));
            ans+=min(go(0,0,sz(t),d1,t,0), t.back()+go(0,1,sz(t),d2,t,1));
        }
    }
    
    cout<<ans;
    return 0;
}