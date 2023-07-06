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
const int MAX = 1010101; // PLZ CHK!

//AWARE of..
//1. type of query - might be max, min, gcd.. etc
//2. policy of update - tr[nd] = eg. max(tr[nd], v)
struct SEG{
    //0-indexed!
    vector<pll> tr;
    int n;
    void rst(int sz) {
        n = sz;
        tr.resize((n+1)<<2);
    }
    void upd(int nd, int le, int ri, int i, pll v) {
        if (i<le || ri<i) return;
        if (le==ri) {
            if (tr[nd].F==v.F) tr[nd].S=(tr[nd].S+v.S)%MOD;
            else tr[nd]=max(tr[nd], v);
            return;
        }
        int md = (le+ri)>>1;
        upd(nd<<1, le, md, i, v), upd(nd<<1|1, md+1, ri, i, v);

        if (tr[nd<<1].F==tr[nd<<1|1].F) tr[nd]={tr[nd<<1].F, (tr[nd<<1].S+tr[nd<<1|1].S)%MOD};
        else tr[nd]=max(tr[nd<<1], tr[nd<<1|1]);
    }

    void upd(int i, pll v) {
        upd(1, 0, n-1, i, v);
    }

    pll qry(int nd, int le, int ri, int ql, int qr) {
        if (qr<le || ri<ql) return {0,0};
        if (ql<=le && ri<=qr) return tr[nd];
        int md = (le+ri)>>1;
        pll lq=qry(nd<<1, le, md, ql, qr), rq=qry(nd<<1|1, md+1, ri, ql, qr);
        if (lq.F==rq.F) return {lq.F, (lq.S+rq.S)%MOD};
        return max(lq, rq);
    }

    pll qry(int le, int ri) {
        return qry(1, 0, n-1, le, ri);
    }
};

int main() {
    fio();
    int n;
    cin>>n;
    vector<int> a(n),b;
    for (int &x:a) cin>>x;
    b=a; cmprs(b); for (int &x:a) x=lb(all(b),x)-b.begin()+1;

    SEG seg; seg.rst(MAX); seg.upd(0,{0,1});
    pll ans={0,0};
    for (int i=0; i<n; i++) {
        auto [d,cnt]=seg.qry(0,a[i]-1);

        if (ans.F==d+1) ans.S=(ans.S+cnt)%MOD;
        else ans=max(ans, {d+1, cnt});

        seg.upd(a[i], {d+1,cnt});
    }

    cout<<ans.F<<sp<<ans.S;
    return 0;
}