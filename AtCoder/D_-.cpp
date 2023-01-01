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

int main() {
    fio();
    ll n,m;
    cin>>n>>m;
    vector<ll> x(n),y(m);
    for (ll &xx:x) cin>>xx;
    for (ll &yy:y) cin>>yy;
    
    vector<ll> a,b;
    for (int i=1; i<n; i++) a.pb(x[i]-x[i-1]);
    for (int i=1; i<m; i++) b.pb(y[i]-y[i-1]);

    n--, m--;
    ll t1=0, t2=0;
    for (ll i=0; i<n; i++) {
        ll t=((((i+1)*(n-i))%MOD)*a[i])%MOD;
        t1=(t1+t)%MOD;
    }
    for (ll i=0; i<m; i++) {
        ll t=((((i+1)*(m-i))%MOD)*b[i])%MOD;
        t2=(t2+t)%MOD;
    }
    cout<<(t1*t2)%MOD;
    return 0;
}