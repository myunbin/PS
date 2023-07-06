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
const int MAX = 202020; // PLZ CHK!

struct lazy_seg {
    struct node {
        ll v, lz, mv;
    };

    vector<node> tr;
    int n;
    void rst(int sz) {n=sz, tr.resize(sz<<2,{0,0,0});}

    void prp(int nd, int s, int e) {
        if (tr[nd].lz!=0) {
            tr[nd].v+=1ll*(e-s+1)*tr[nd].lz;
            tr[nd].mv+=tr[nd].lz;

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
            tr[nd].v+=1ll*(e-s+1)*d;
            tr[nd].mv+=d;
            if (s!=e) {
                tr[nd<<1].lz+=d;
                tr[nd<<1|1].lz+=d;
            }
            return;
        }

        int m=(s+e)>>1;
        upd(nd<<1, s, m, l, r, d);
        upd(nd<<1|1, m+1, e, l, r, d);

        tr[nd].v=tr[nd<<1].v+tr[nd<<1|1].v;
        tr[nd].mv=min(tr[nd<<1].mv, tr[nd<<1|1].mv);
    }

    void upd(int l, int r, ll d) {
        upd(1,1,n,l,r,d);
    }

    ll sq(int nd, int s, int e, int l, int r) {
        prp(nd, s, e);
        if (r<s || e<l) return 0;
        if (l<=s && e<=r) return tr[nd].v;
        int m=(s+e)>>1;
        return sq(nd<<1, s, m, l, r)+sq(nd<<1|1, m+1, e, l, r);
    }
    ll sq(int l, int r) {
        return sq(1,1,n,l,r);
    }

    ll mq(int nd, int s, int e, int l, int r) {
        prp(nd,s,e);
        if (r<s || e<l) return LINF;
        if (l<=s && e<=r) return tr[nd].mv;
        int m=(s+e)>>1;
        return min(mq(nd<<1,s,m,l,r), mq(nd<<1|1,m+1,e,l,r));
    }

    ll mq(int l, int r) {
        return mq(1,1,n,l,r);
    }
};

int main() {
    fio();
    int n,q;
    cin>>n>>q;
    
    lazy_seg seg; seg.rst(MAX);
    for (int i=1; i<=n; i++) {
        int x; cin>>x;
        seg.upd(i,i,x);
    }

    while (q--) {
        char c; cin>>c;
        if (c=='M') {
            int a,b; cin>>a>>b;
            cout<<seg.mq(a,b)<<endl;
        }   
        else if (c=='P') {
            int a,b,c; cin>>a>>b>>c;
            seg.upd(a,b,c);
        }
        else {
            int a,b; cin>>a>>b;
            cout<<seg.sq(a,b)<<endl;
        }
    }
    return 0;
}