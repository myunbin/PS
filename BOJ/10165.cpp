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
const int MAX = 1010101; // PLZ CHK!

struct fwt {
    // 1-indexed!
    vector<ll> tr;
    void rst(int n) {tr.resize(n+1);}
    void upd(int i, ll v) {
        for (; i<sz(tr); i+=(i&-i)) tr[i]+=v;
    }
    ll qry(int r) { //[1,r]
        ll sum=0;
        for (; r; r-=(r&(-r))) sum+=tr[r];
        return sum;
    }
    ll qry(int l, int r) { //[l, r]
        if(l==0) return qry(r);
        return qry(r)-qry(l-1);
    }
};

int main() {
    fio();
    int n,m;
    cin>>n>>m;
    vector<tpi> a;
    for (int i=0; i<m; i++) {
        int s,e; 
        cin>>s>>e;
        if (s<=e) a.pb({s,e,i+1}), a.pb({s+n,e+n,i+1});
        else a.pb({s,e+n,i+1});
    }

    sort(all(a),[](auto x, auto y){
        auto [xs,xe,xi]=x; auto [ys,ye,yi]=y;
        if (xs==ys) return xe>ye;
        return xs<ys;
    });

    vector<int> y;
    for (auto [s,e,i]:a) y.pb(e);
    cmprs(y);
    
    fwt fw; 
    fw.rst(MAX);
    vector<bool> v(m+1,1);
    for (auto [s,e,i]:a) {
        e=lb(all(y),e)-y.begin()+1;
        if (fw.qry(e,MAX-1)) v[i]=0;
        fw.upd(e,1);
    }

    for (int i=1; i<=m; i++) if (v[i]) cout<<i<<sp;
    
    return 0;
}