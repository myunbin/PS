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
const int MAX = 303030; // PLZ CHK!

struct SUM{
    vector<ll> tr; int n;
    void rst(int sz) {n = sz;tr.resize((n+1)<<2);}
    void upd(int nd, int le, int ri, int i, ll v) {
        if (i<le || ri<i) return;
        if (le==ri) {
            tr[nd] = v;
            return;
        }
        int md = (le+ri)>>1;
        upd(nd<<1, le, md, i, v), upd(nd<<1|1, md+1, ri, i, v);
        tr[nd] = tr[nd<<1]+tr[nd<<1|1];
    }
    void upd(int i, ll v) {
        upd(1, 0, n-1, i, v);
    }
    ll qry(int nd, int le, int ri, int ql, int qr) {
        if (qr<le || ri<ql) return 0;
        if (ql<=le && ri<=qr) return tr[nd];
        int md = (le+ri)>>1;
        return qry(nd<<1, le, md, ql, qr)+qry(nd<<1|1, md+1, ri, ql, qr);
    }
    ll qry(int le, int ri) {
        return qry(1, 0, n-1, le, ri);
    }
};

struct MIN{
    vector<pll> tr; int n;
    void rst(int sz) {n = sz;tr.resize((n+1)<<2,{LINF,LINF});}
    void upd(int nd, int le, int ri, int i, ll v) {
        if (i<le || ri<i) return;
        if (le==ri) {
            tr[nd]=min(tr[nd], {v,i});
            return;
        }
        int md = (le+ri)>>1;
        upd(nd<<1, le, md, i, v), upd(nd<<1|1, md+1, ri, i, v);
        tr[nd]=min(tr[nd<<1],tr[nd<<1|1]);
    }
    void upd(int i, ll v) {
        upd(1, 0, n-1, i, v);
    }
    pll qry(int nd, int le, int ri, int ql, int qr) {
        if (qr<le || ri<ql) return {LINF,LINF};
        if (ql<=le && ri<=qr) return tr[nd];
        int md = (le+ri)>>1;
        return min(qry(nd<<1, le, md, ql, qr),qry(nd<<1|1, md+1, ri, ql, qr));
    }
    pll qry(int le, int ri) {
        return qry(1, 0, n-1, le, ri);
    }
};

SUM len;
MIN dep;

priority_queue<ll> pq;
ll go(ll h, int l, int r) {
    if (l>r) return 0;
    auto [mn,mi]=dep.qry(l,r);
    ll cur=(mn-h)*len.qry(l,r);
    ll x=go(mn,l,mi-1), y=go(mn,mi+1,r);
    pq.push(min(x,y));

    return max(x,y)+cur;
}

int main() {
    fio();
    
    vector<ll> L,D;
    int N; cin>>N;

    vector<pll> v;
    for (int i=0; i<N; i++) {
        ll x,y; cin>>x>>y;
        v.pb({x,y});
        
        if (i && i%2==0) {
            L.pb(v[i].F-v[i-1].F);
            D.pb(v[i].S);
        }
    }

    int sz=sz(L);
    len.rst(sz+10), dep.rst(sz+10);
    for (int i=0; i<sz; i++) {
        len.upd(i, L[i]);
        dep.upd(i, D[i]);
    }
    pq.push(go(0,0,sz-1));

    int K; cin>>K;
    ll ans=0;
    for (int i=0; i<K && !pq.empty(); i++) {
        ans+=pq.top(); pq.pop();
    }

    cout<<ans;
    return 0;
}