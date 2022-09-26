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
struct edge {
    int u,v;
    ll w;
};
struct node {
    int i;
    ll x,y;
};

inline ll cst(pll a, pll b) {
    return (a.F-b.F)*(a.F-b.F)+(a.S-b.S)*(a.S-b.S);
}

int p[MAX];
int f(int a) {
    if (a==p[a]) return a;
    return p[a]=f(p[a]);
}

bool m(int a, int b) {
    a=f(a), b=f(b);
    if (a==b) return 0;
    p[b]=a; return 1;
}

int main() {
    fio();
    for (int i=0; i<MAX; i++) p[i]=i;

    int n;
    cin>>n;
    vector<node> a(n);
    vector<pair<ll,int>> sy[11];
    for (int i=0; i<n; i++) {
        cin>>a[i].x>>a[i].y;
        a[i].i=i;
        sy[a[i].y].pb({a[i].x, i});
    }
    for (int i=0; i<=10; i++) sort(all(sy[i]));
    sort(all(a), [](node u, node v){
        if (u.x==v.x) return u.y<v.y;
        return u.x<v.x;
    });
    
    vector<edge> ed;
    for (auto [i1, x1, y1]:a) {
        for (ll y2=0; y2<=10; y2++) {
            auto j=lb(all(sy[y2]), make_pair(x1,-1))-sy[y2].begin();
            if (y1==y2) j++;
            if (j>=sz(sy[y2])) continue;
            auto [x2,i2]=sy[y2][j];
            ed.pb({i1,i2, cst({x1,y1}, {x2,y2})});
        }
    }

    sort(all(ed), [](edge a, edge b){return a.w<b.w;});
    int cnt=0; ll ans=0;
    for (auto [a,b,c]:ed) {
        if (m(a,b)) {
            ans+=c;
            cnt++;
        }
        if (cnt==n-1) break;
    }
    cout<<ans;
    return 0;
}