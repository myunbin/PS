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

int n;
vector<int> g[MAX], a(MAX), ans(MAX);
set<int> s[MAX];

pii dfs(int cur) {
    s[cur].insert(a[cur]);
    if (g[cur].empty()) {
        ans[cur]=(a[cur]==0?1:0);
        return {ans[cur], cur};
    }

    pii mxc={0,0};
    vector<pii> mx;
    for (int nxt:g[cur]) {
        mx.pb(dfs(nxt));
    }
    sort(all(mx), [&](pii a, pii b){
        return sz(s[a.S])>sz(s[b.S]);
    });
    
    s[mx[0].S].insert(a[cur]);
    s[cur].clear();
    int mex=mx[0].F;
    for (int i=1; i<sz(mx); i++) {
        for (int x:s[mx[i].S]) s[mx[0].S].insert(x);
        s[mx[i].S].clear();
    }
    while (s[mx[0].S].find(mex)!=s[mx[0].S].end()) mex++;

    ans[cur]=mex;
    return {mex, mx[0].S};
}

int main() {
    fio();
    int rt;
    cin>>n;
    for (int i=1; i<=n; i++) {
        int x; cin>>x;
        if (x==-1) rt=i;
        else g[x].pb(i);
    }
    for (int i=1; i<=n; i++) cin>>a[i];
    dfs(rt);

    for (int i=1; i<=n; i++) cout<<ans[i]<<endl;
    

    return 0;
}