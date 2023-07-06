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
const double pi = acos(-1.0);
const double eps = 1e-9;

double f(pll a, pll b) {
    pll c={-a.S, a.F};
    bool r=0;

    if (c.F*b.F+c.S*b.S<=0) r=1;
    double x=(double)a.F*b.F+(double)a.S*b.S, y=(double)a.F*a.F+(double)a.S*a.S;
    double z=x/y;
    
    if (abs(z-1.0)<eps) z=1.0;
    else if (abs(z+1.0)<eps) z=-1.0;

    double ret=180.0*acos(z)/pi;
    return (r?360.0-ret:ret);
}

int main() {
    fio();

    int n;
    cin>>n;

    vector<pll> a(n), b;
    ll mx=0;
    for (auto &[x,y]:a) cin>>x>>y, mx=max(mx, x*x+y*y);
    for (auto [x,y]:a) {
        if (x*x+y*y==mx) b.pb({x,y});
    }

    int m=sz(b);
    double ans=0.0;
    for (int i=0; i<m; i++) {
        ans=max(ans, f(b[i], b[(i+1)%m]));
    }

    cout<<fixed;
    cout.precision(10);
    cout<<ans;

    return 0;
}