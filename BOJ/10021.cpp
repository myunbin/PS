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
const int MAX = 2020; // PLZ CHK!

struct ed{
    int u,v,w;
    bool operator < (const ed &a) const {
        return w<a.w;
    }
};


int main() {
    fio();
    int n,c;
    cin>>n>>c;
    vector<pii> a(n);
    for (auto &[x,y]:a) cin>>x>>y;
    
    vector<ed> e;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int w=(a[i].F-a[j].F)*(a[i].F-a[j].F)+(a[i].S-a[j].S)*(a[i].S-a[j].S);
            if (w>=c) e.pb({i,j,w});
        }
    }

    int p[MAX];
    for (int i=0; i<MAX; i++) p[i]=i;

    function<int(int)> fd=[&](int u) {
        if (u==p[u]) return u;
        return p[u]=fd(p[u]);
    };

    function<bool(int,int)> mg=[&](int u, int v) {
        u=fd(u), v=fd(v);
        if (u==v) return 0;
        p[v]=u; return 1;
    };
    
    sort(all(e));

    int cnt=0, ans=0;
    for (int i=0; i<sz(e); i++) {
        if (cnt==n-1) break;
        if (mg(e[i].u, e[i].v)) {
            cnt++;
            ans+=e[i].w;
        }
    }
    cout<<(cnt<n-1?-1:ans);
    return 0;
}