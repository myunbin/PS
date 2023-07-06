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

//AWARE of..
//1. type of query - might be max, min, gcd.. etc
//2. policy of update - tr[nd] = eg. max(tr[nd], v)
struct sumseg{
    //0-indexed!
    vector<ll> tr;
    int n;
    void rst(int sz) {
        n = sz;
        tr.resize((n+1)<<2);
    }
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

struct maxseg{
    //0-indexed!
    vector<ll> tr, a;
    int n;
    void rst(int sz) {
        n=sz;
        tr.resize((n+1)<<1);
    }

    void upd(int i, ll v) {
        tr[i+n] = v; i+=n; //AWARE OF UPD POLICY!!
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

int main() {
    fio();
    int n,q;
    cin>>n>>q;
    vector<pii> p(n+1);
    for (int i=1; i<=n; i++) cin>>p[i].F>>p[i].S;

    sumseg ssg; maxseg msg; 
    ssg.rst(MAX), msg.rst(MAX);

    auto dst=[](pii a, pii b){
        return abs(a.F-b.F)+abs(a.S-b.S);
    };

    for (int i=1; i<=n-1; i++) ssg.upd(i, dst(p[i], p[i+1]));
    for (int i=2; i<=n-1; i++) msg.upd(i, dst(p[i-1], p[i])+dst(p[i], p[i+1])-dst(p[i-1], p[i+1]));

    while (q--) {
        char c; 
        cin>>c;

        if (c=='Q') {
            int l,r;
            cin>>l>>r;
            ll ans=0;
            if (l<=r-1) ans+=ssg.qry(l,r-1);
            if (l+1<=r-1) ans-=msg.qry(l+1,r-1);
            cout<<ans<<endl;
        }
        else {
            int i; pii np;
            cin>>i>>np.F>>np.S;
            p[i]=np;
            if (2<=i) {
                int v=dst(p[i-1], p[i]);
                ssg.upd(i-1, v);
            }
            if (i<=n-1) {
                int v=dst(p[i], p[i+1]);
                ssg.upd(i, v);
            }

            if (2<=i) {
                int v=dst(p[i-1], p[i])+dst(p[i], p[i+1])-dst(p[i-1],p[i+1]);
                msg.upd(i, v);
            }
            if (3<=i) {
                int v=dst(p[i-2], p[i-1])+dst(p[i-1], p[i])-dst(p[i-2], p[i]);
                msg.upd(i-1, v);
            }
            if (i+2<=n) {
                int v=dst(p[i], p[i+1])+dst(p[i+1], p[i+2])-dst(p[i], p[i+2]);
                msg.upd(i+1, v);
            }
        }
    }
    
    return 0;
}