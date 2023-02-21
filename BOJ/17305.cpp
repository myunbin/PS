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
const int MAX = 252525; // PLZ CHK!

int main() {
    fio();
    int n,w;
    cin>>n>>w;
    
    vector<ll> a,b; a.pb(LINF), b.pb(LINF);
    for (int i=0; i<n; i++) {
        ll x,y; cin>>x>>y;
        if (x==3) a.pb(y);
        else b.pb(y);
    }
    sort(all(a), greater<>());
    sort(all(b), greater<>());

    int na=sz(a)-1, nb=sz(b)-1;
    vector<ll> pa(na+1,0), pb(nb+1,0);
    for (int i=1; i<=na; i++) pa[i]=pa[i-1]+a[i];
    for (int i=1; i<=nb; i++) pb[i]=pb[i-1]+b[i];

    
    ll ans=0;
    for (int i=0; i<=na; i++) {
        int ok=(w-3*i)/5;
        if (w-3*i>0) ans=max(ans, pa[i]+pb[min(nb, ok)]);
    }

    for (int i=0; i<=nb; i++) {
        int ok=(w-5*i)/3;
        if (w-5*i>0) ans=max(ans, pb[i]+pa[min(na, ok)]);
    }

    cout<<ans;
    return 0;
}