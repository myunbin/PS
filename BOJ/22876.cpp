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

    pll mrg(pll a, pll b) {
        vector<ll> t={a.F,a.S,b.F,b.S};
        sort(all(t));
        return {t[3],t[2]};
    }

    void upd(int nd, int le, int ri, int i, ll v) {
        if (i<le || ri<i) return;
        if (le==ri) {
            tr[nd].F+=v;
            return;
        }
        int md = (le+ri)>>1;
        upd(nd<<1, le, md, i, v), upd(nd<<1|1, md+1, ri, i, v);
        tr[nd] = mrg(tr[nd<<1],tr[nd<<1|1]);
    }
    void upd(int i, ll v) {
        upd(1, 0, n-1, i, v);
    }
    pll qry(int nd, int le, int ri, int ql, int qr) {
        if (qr<le || ri<ql) return {0,0};
        if (ql<=le && ri<=qr) return tr[nd];
        int md = (le+ri)>>1;
        return mrg(qry(nd<<1, le, md, ql, qr),qry(nd<<1|1, md+1, ri, ql, qr));
    }
    pll qry(int le, int ri) {
        return qry(1, 0, n-1, le, ri);
    }
};

int N;
ll VX[MAX],VY[MAX];
vector<pll> X[MAX], Y[MAX];
SEG SX,SY;

int main() {
    fio();
    SX.rst(MAX), SY.rst(MAX);

    cin>>N;
    for (int i=1; i<=N; i++) {
        int x,y,w;
        cin>>x>>y>>w;
        X[x].pb({y,w}), Y[y].pb({x,w});
        SX.upd(x,w), SY.upd(y,w);
        VX[x]+=w, VY[y]+=w;
    }

    sort(VX,VX+MAX,greater<>());
    sort(VY,VY+MAX,greater<>());
    // cout<<VX[0]<<sp<<VX[1]<<sp<<VX[2]<<endl;
    ll ans=max(VX[0]+VX[1]+VX[2], VY[0]+VY[1]+VY[2]);
    
    for (int x=0; x<MAX; x++) {
        ll xs=0;
        for (auto [y,w]:X[x]) {
            SY.upd(y,-w);
            xs+=w;
        }
        auto [mx1,mx2]=SY.qry(0,MAX);
        ans=max(ans, xs+mx1+mx2);
        for (auto [y,w]:X[x]) {
            SY.upd(y,w);
        }
    }

    for (int y=0; y<MAX; y++) {
        ll ys=0;
        for (auto [x,w]:Y[y]) {
            ys+=w;
            SX.upd(x,-w);
        }
        auto [mx1,mx2]=SX.qry(0,MAX);
        ans=max(ans, ys+mx1+mx2);
        for (auto [x,w]:Y[y]) {
            SX.upd(x,w);
        }
    }

    cout<<ans;
    return 0;
}