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

//AWARE of..
//1. type of query - might be max, min, gcd.. etc
//2. policy of update - tr[nd] = eg. max(tr[nd], v)
struct SEG{
    //0-indexed!
    vector<ll> tr, a;
    int n;
    void rst(int sz) {
        n = sz;
        tr.resize((n+1)<<2);
        a.resize(n+1);
    }
    void init(int nd, int le, int ri) {
        if (le==ri) {
            tr[nd] = a[le];
            return;
        }
        int md = le+ri>>1;
        init(nd<<1, le, md), init(nd<<1|1, md+1, ri);
        tr[nd] = tr[nd<<1]+tr[nd<<1|1];
    }
    void upd(int nd, int le, int ri, int i, ll v) {
        if (i<le || ri<i) return;
        if (le==ri) {
            tr[nd] = v;
            return;
        }
        int md = le+ri>>1;
        upd(nd<<1, le, md, i, v), upd(nd<<1|1, md+1, ri, i, v);
        tr[nd] = tr[nd<<1]+tr[nd<<1|1];
    }
    void upd(int i, ll v) {
        upd(1, 0, n-1, i, v);
    }
    ll qry(int nd, int le, int ri, int ql, int qr) {
        if (qr<le || ri<ql) return 0;
        if (ql<=le && ri<=qr) return tr[nd];
        int md = le+ri>>1;
        return qry(nd<<1, le, md, ql, qr)+qry(nd<<1|1, md+1, ri, ql, qr);
    }
    ll qry(int le, int ri) {
        return qry(1, 0, n-1, le, ri);
    }
};


int main() {
    fio();
    SEG sg[1<<10+1];
    for (int i=1; i<=(1<<10); i++) sg[i].rst((1<<10)+1);

    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            ll x; cin>>x;
            sg[i].upd(j,x);
        }
    }

    
    return 0;
}