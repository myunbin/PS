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
ll n,a,b,k;
ll niv;

ll pw(ll a, ll b) {
    if (b==0) return 1;
    if (b&1) return a*pw(a,b-1)%MOD;
    ll r=pw(a,b>>1)%MOD; return r*r%MOD;
}

ll f(ll i) {
    ll r=1;
    r=(r*k*k)%MOD;
    r=(r*i)%MOD;
    r=(r*(n-i))%MOD;
    r=(r*niv)%MOD;
    r=(r*niv)%MOD;
    return r;
}

int main() {
    fio();
    cin>>n>>a>>b;
    k=b-a;

    niv=pw(n,MOD-2);

    ll ans=0;
    for (int i=0; i<=n; i++) {
        ll t=f(1ll*i);
        if (i!=0 && i!=n) t=(t*2)%MOD;
        ans=(ans+t)%MOD;
    }

    ll t=k*niv%MOD*pw(2,MOD-2)%MOD;
    ans=(ans*t)%MOD;

    cout<<ans;
    return 0;
}