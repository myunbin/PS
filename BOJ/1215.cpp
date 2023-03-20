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

ll sum(ll a, ll b) {
    if (a>b) return 0;
    ll x=b*(b+1)/2, y=a*(a-1)/2;
    return (x-y);
}

int main() {
    fio();
    ll n,k;
    cin>>n>>k;

    ll ans=0;
    vector<pll> a;
    for (ll i=1; i*i<=k; i++) a.pb({i,k/i});
    
    for (int i=0; i<sz(a); i++) {
        ll t;
        if (i==sz(a)-1) t=a[i].F*sum(a[i].F+1, min(n,a[i].S));
        else t=a[i].F*sum(a[i+1].S+1, min(n,a[i].S));
        
        if (a[i].F<=n) t+=a[i].F*a[i].S;
        ans+=t;
    }
    // cout<<k*min(k,n)<<sp<<ans<<sp<<max(0ll,(n-k)*k)<<endl;
    cout<<k*min(k,n)-ans+max(0ll,(n-k)*k);
    return 0;
}