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

int p[MAX];

int fd(int a) {
    if (a==p[a]) return a;
    return p[a]=fd(p[a]);
}

bool mg(int a, int b) {
    a=fd(a), b=fd(b);
    if (a==b) return 0;
    p[b]=a; return 1;
}

struct ed{
    int u,v;
    ll w;
};

int main() {
    fio();
    for (int i=0; i<MAX; i++) p[i]=i;

    int n,m;
    cin>>n>>m;
    vector<pll> a(n);
    for (auto &[x,y]:a) cin>>x>>y;

    int cnt=0;
    double ans=0.0;
    for (int i=0; i<m; i++) {
        int u,v; cin>>u>>v;
        --u,--v;
        cnt+=mg(u,v);
    }

    vector<ed> e;
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            ll d=(a[i].F-a[j].F)*(a[i].F-a[j].F)+(a[i].S-a[j].S)*(a[i].S-a[j].S);
            e.pb({i,j,d});
        }
    }
    sort(all(e), [](ed a, ed b){
        return a.w<b.w;
    });

    for (auto [u,v,w]:e) {
        if (cnt==n-1) break;
        if (mg(u,v)) {
            cnt++;
            ans+=sqrt((double)w);
        }
    }

    cout<<fixed;
    cout.precision(2);
    cout<<ans;
    return 0;
}