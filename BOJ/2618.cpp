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
const int MAX = 1010; // PLZ CHK!

int n,w;
ll d[MAX][MAX];
vector<pll> cs;
ll dst(pll a, pll b) {return abs(a.F-b.F)+abs(a.S-b.S);}

ll go(int i, int j) {
    if (i>=w || j>=w) return 0;
    ll &ret=d[i][j];
    if (ret!=-1) return ret;
    
    ret=LINF;
    ll d1, d2;
    int nx=max(i,j)+1;
    if (i==0) d1=dst(cs[0], cs[nx]);
    else d1=dst(cs[i], cs[nx]);
    if (j==0) d2=dst(cs.back(), cs[nx]);
    else d2=dst(cs[j], cs[nx]);

    return ret=min(d1+go(nx,j), d2+go(i,nx));   
}

void trk(int i, int j) {
    if (i>=w || j>=w) return;
    ll res=d[i][j];
    
    ll d1, d2;
    int nx=max(i,j)+1;
    if (i==0) d1=dst(cs[0], cs[nx]);
    else d1=dst(cs[i], cs[nx]);
    if (j==0) d2=dst(cs.back(), cs[nx]);
    else d2=dst(cs[j], cs[nx]);
    
    if (d1+go(nx,j) < d2+go(i,nx)) {
        cout<<1<<endl;
        trk(nx,j);
    }
    else {
        cout<<2<<endl;
        trk(i,nx);
    }
}
int main() {
    fio();
    memset(d,-1,sizeof d);

    cin>>n>>w;
    cs.resize(w+1);
    cs[0]={1,1};
    for (int i=1; i<=w; i++) cin>>cs[i].F>>cs[i].S;
    cs.pb({n,n});

    cout<<go(0,0)<<endl;
    trk(0,0);
    return 0;
}