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
const int MAX = 101010; // PLZ CHK!

struct segtr{
    //0-indexed!
    vector<ll> tr, a;
    int n;
    void rst(int sz) {
        n=sz;
        tr.resize((n+1)<<1), a.resize(n+1);
    }

    void upd(int i, ll v) {
        tr[i+n] = max(tr[i+n], v); i+=n; //AWARE OF UPD POLICY!!
        for (i>>=1; i; i>>=1) tr[i] = max(tr[i<<1], tr[i<<1|1]);
    }

    ll qry(int l, int r) {
        ll ret = -LINF;
        for (l+=n, r+=n; l<=r; l>>=1, r>>=1) {
            if (l&1) ret = max(ret, tr[l++]);
            if (~r&1) ret = max(ret, tr[r--]);
        }
        return ret;
    }
};

void solve() {
    int n;
    cin>>n;
    
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) cin>>a[i];

    segtr seg1,seg2; seg1.rst(n+10), seg2.rst(n+10);
    seg1.upd(a[1],1);

    vector<vector<int>> d(n+1,vector<int>(2));
    int ans=1;
    for (int i=2; i<=n; i++) {
        d[i][0]=seg1.qry(a[i]+1,n+1)+1;
        d[i][1]=seg2.qry(0,a[i]-1)+1;
        
        if (d[i][0]>1) seg2.upd(a[i], d[i][0]);
        seg1.upd(a[i], d[i][1]);

        // cout<<d[i][0]<<sp<<d[i][1]<<endl;
        ans=max({ans, d[i][0], d[i][1]});
    }

    cout<<ans<<endl;
}
int main() {
    fio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}