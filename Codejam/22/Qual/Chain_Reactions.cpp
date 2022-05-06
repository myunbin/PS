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
int n;
vector<ll> a;
vector<vector<int>> g;
ll ans;

ll dfs(int cur) {
    // cout<<cur<<sp;
    if (g[cur].empty()) {
        return a[cur];
    }
    ll sum=0, mn=INF;
    for (int nxt:g[cur]) {
        ll r=dfs(nxt);
        sum+=r;
        mn=min(mn,r);
    }
    ans+=(sum-mn);
    return max(a[cur],mn);
}
void solve() {
    cin>>n;
    g.resize(n+1),a.resize(n+1);

    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=1; i<=n; i++) {
        int x; cin>>x;
        g[x].pb(i);
    }

    ans+=dfs(0);
    cout<<ans<<endl;

    ans=0;
    for (int i=0; i<=n; i++) g[i].clear();
    a.clear();
}
int main() {
    fio();
    int t;
    cin>>t;
    for (int i=1; i<=t; i++) {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}