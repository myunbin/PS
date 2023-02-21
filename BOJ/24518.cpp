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

ll n,m;
ll f(ll x) {
    ll q=x/m, r=x%m;
    return (q*(m*(m-1)/2%MOD)%MOD+r*(r+1)/2%MOD)%MOD;
}

ll rs(ll a, ll b) { 
    if (a>b) return 0;
    return (f(b)-f(a-1)+MOD)%MOD; 
}

int main() {
    fio();
    cin>>n>>m;

    vector<pll> a;
    for (ll i=1; i*i<=n; i++) a.pb({i,n/i});
    
    ll ans=0; int sz=sz(a);
    for (int i=0; i<sz; i++) {
        ans=(ans+a[i].S*rs(a[i].F, a[i].F)%MOD)%MOD;
        if (i<sz-1) {
            ll t=a[i].F%MOD*rs(a[i+1].S+1, a[i].S)%MOD;
            ans=(ans+t)%MOD;
        }
        else {
            ll t=a[i].F%MOD*rs(a[i].F+1, a[i].S)%MOD;
            ans=(ans+t)%MOD;
        }
    }

    cout<<ans;
    return 0;
}