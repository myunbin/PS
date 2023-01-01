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
const int MAX = 100001; // PLZ CHK!

ll k;
vector<ll> s;
vector<bool> c(MAX, 0);
int n;

ll get(int i, ll x, ll y) {
    if (i==n || x*s[i]>y) return 0;
    return (y/(x*s[i]))-get(i+1, x*s[i], y)+get(i+1, x, y);   
}

int main() {
    fio();
    
    for (ll i=2; i<MAX; i++) {
        if (c[i]) continue;
        s.pb(i*i);
        for (ll j=i+i; j<MAX; j+=i) c[i]=1;
    }

    for (ll x:s) cout<<x<<sp;
    cout<<endl;

    int n=sz(s);

    cin>>k;
    
    ll l=0, r=1ll*(2e9);
    ll ans=r;
    while (l<=r) {
        ll m=(l+r)>>1;
        ll ok=m-get(0, 1, m);
        if (ok>=k) {
            ans=m;
            r=m-1;
        }
        else l=m+1;
    }
    cout<<ans;
    return 0;
}