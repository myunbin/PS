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

struct lazy_seg {
    struct node {
        ll v, lz;
    };

    vector<node> tr;
    vector<ll> a;
    int n;
    void rst(int sz) {n=sz, tr.resize((sz+1)<<2,{0,0}), a.resize(sz+1,0);}

    void prp(int nd, int s, int e) {
        if (tr[nd].lz!=0) {
            tr[nd].v+=tr[nd].lz;
            if (s!=e) {
                tr[nd<<1].lz+=tr[nd].lz;
                tr[nd<<1|1].lz+=tr[nd].lz;
            }
            tr[nd].lz=0;
        }
    }

    void upd(int nd, int s, int e, int l, int r, ll d) {
        prp(nd, s, e);        
        if (r<s || e<l) return;
        if (l<=s && e<=r) {
            tr[nd].v+=d;
            if (s!=e) {
                tr[nd<<1].lz+=d;
                tr[nd<<1|1].lz+=d;
            }
            return;
        }
        int m=(s+e)>>1;
        upd(nd<<1, s, m, l, r, d);
        upd(nd<<1|1, m+1, e, l, r, d);
        tr[nd].v=max(tr[nd<<1].v, tr[nd<<1|1].v);
    }
    void upd(int l, int r, ll d) {
        upd(1,0,n,l,r,d);
    }
    ll qry(int nd, int s, int e, int l, int r) {
        prp(nd, s, e);
        if (r<s || e<l) return -LINF;
        if (l<=s && e<=r) return tr[nd].v;
        int m=(s+e)>>1;
        return max(qry(nd<<1, s, m, l, r), qry(nd<<1|1, m+1, e, l, r));
    }
    ll qry(int l, int r) {
        return qry(1,0,n,l,r);
    }

    int qry2(int nd, int s, int e) {
        if (s==e) return s;
        int m=(s+e)>>1;
        prp(nd, s, e);
        prp(nd<<1, s, m);
        prp(nd<<1|1, m+1, e);
        ll v1=tr[nd<<1].v, v2=tr[nd<<1|1].v;
        if (v2>=0) return qry2(nd<<1|1, m+1, e);   
        return qry2(nd<<1, s, m);
    }

    int qry2() {
        return qry2(1,0,n);
    }
};

int main() {
    fio();
    int n;
    cin>>n;
    lazy_seg sg; sg.rst(n);
    for (int i=0; i<=n; i++) sg.upd(i,i,-i);
    
    vector<pii> ab(n);
    for (auto &[a,b]:ab) {
        cin>>a>>b;
        sg.upd(a,b,1);
    }
    
    int q;
    cin>>q;
    cout<<sg.qry2()<<sp;
    while (q--) {
        int p,l,r;
        cin>>p>>l>>r;
        --p;

        sg.upd(ab[p].F, ab[p].S, -1);
        ab[p]={l,r};
        sg.upd(ab[p].F, ab[p].S, 1);
        cout<<sg.qry2()<<sp;
    }
    
    return 0;
}