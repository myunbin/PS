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

struct SEG{
    //0-indexed!
    vector<ll> tr, a;
    int n;
    void rst(int sz) {
        n = sz;
        tr.resize((n+1)<<2);
    }
    void upd(int nd, int le, int ri, int i, ll v) {
        if (i<le || ri<i) return;
        if (le==ri) {
            tr[nd]=(tr[nd]+v)%MOD;
            return;
        }
        int md = (le+ri)>>1;
        upd(nd<<1, le, md, i, v), upd(nd<<1|1, md+1, ri, i, v);
        tr[nd]=(tr[nd<<1]+tr[nd<<1|1])%MOD;
    }
    void upd(int i, ll v) {
        upd(1, 0, n-1, i, v);
    }
    ll qry(int nd, int le, int ri, int ql, int qr) {
        if (qr<le || ri<ql) return 0;
        if (ql<=le && ri<=qr) return tr[nd];
        int md = (le+ri)>>1;
        return (qry(nd<<1, le, md, ql, qr)+qry(nd<<1|1, md+1, ri, ql, qr))%MOD;
    }
    ll qry(int le, int ri) {
        return qry(1, 0, n-1, le, ri);
    }
} seg[12];

int n, a[MAX];
ll d[MAX][12];

int main() {
    fio();
    
    
    cin>>n;
    for (int i=0; i<12; i++) seg[i].rst(n+10);
    for (int i=1; i<=n; i++) cin>>a[i];

    for (int i=1; i<=n; i++) {
        d[i][0]=1;
        seg[0].upd(a[i],1);
        for (int j=1; j<12; j++) {
            d[i][j]=seg[j-1].qry(0,a[i]-1);
            seg[j].upd(a[i],d[i][j]);
        }
    }

    ll ans=0;
    for (int i=1; i<=n; i++) ans=(ans+d[i][10])%MOD;

    cout<<ans;

    return 0;
}