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
const int MAX = 20202; // PLZ CHK!

struct lazy_seg {
    struct node {
        ll v, lz;
    };

    vector<node> tr;
    int n;
    void rst(int sz) {n=sz, tr.resize(sz<<2,{0,0});}

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
        tr[nd].v=max(tr[nd<<1].v,tr[nd<<1|1].v);
    }
    void upd(int l, int r, ll d) {
        upd(1,1,n,l,r,d);
    }
    ll qry(int nd, int s, int e, int l, int r) {
        prp(nd, s, e);
        if (r<s || e<l) return 0;
        if (l<=s && e<=r) return tr[nd].v;
        int m=(s+e)>>1;
        return max(qry(nd<<1, s, m, l, r),qry(nd<<1|1, m+1, e, l, r));
    }
    ll qry(int l, int r) {
        return qry(1,1,n,l,r);
    }
};

int K,N,C;
vector<array<int,3>> G;

int main() {
    fio();
    cin>>K>>N>>C;
    for (int i=0; i<K; i++) {
        int s,e,m;
        cin>>s>>e>>m;
        G.pb({s,e,m});
    }

    sort(all(G), [](auto a, auto b){
        if (a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    });

    lazy_seg seg; seg.rst(MAX);

    int ans=0;
    for (auto [s,e,m]:G) {
        int mx=seg.qry(s,e-1);
        int t=max(0,min(m, C-mx));
        ans+=t;
        seg.upd(s,e-1,t);
    }

    cout<<ans;
    return 0;
}