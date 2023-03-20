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

ll ev(ll a, ll b) {return (b/2-(a-1)/2);}
ll od(ll a, ll b) {return ((b+1)/2-a/2);}
ll eo(ll a, ll b) {
    if (a>b) return 0;
    return (ev(a,b)-od(a,b));
}

ll f(ll n) {
    vector<pll> a;
    for (ll i=1; i*i<=n; i++) a.pb({i,n/i});

    ll ans=0, sig=-1;
    for (int i=0; i<sz(a); i++) {
        ll t;
        if (i==sz(a)-1) t=sig*a[i].S+a[i].F*eo(a[i].F+1, a[i].S);
        else t=sig*a[i].S+a[i].F*eo(a[i+1].S+1, a[i].S);
        ans+=t;
        sig*=-1;
    }
    return ans;
}
int main() {
    fio();
    ll s,t;
    cin>>s>>t;
    cout<<f(t)-f(s-1);
    return 0;
}