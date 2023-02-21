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
const ll LINF = 3000000000;
const int MAX = 101010; // PLZ CHK!

ll up(ll l, ll a) {
    ll le=0, ri=LINF;
    ll ret=0;
    while (le<=ri) {
        ll md=(le+ri)>>1;
        ll t=md*l+md*(md-1)/2;
        if (t<=a) {
            le=md+1;
            ret=md;
        }
        else ri=md-1;
    }
    return ret;
}

int n; ll m;
vector<ll> l, a, mx;

bool ok(ll x) {
    ll k=0;
    for (int i=0; i<n; i++) {
        k+=max(0ll,x-mx[i]);
    }
    return (k<=m);
}

int main() {
    fio();
    
    cin>>n>>m;
    l.resize(n), a.resize(n), mx.resize(n);

    for (ll &x:l) cin>>x;
    for (ll &x:a) cin>>x;

    for (int i=0; i<n; i++) mx[i]=l[i]+up(l[i], a[i]);
    
    ll le=0, ri=*max_element(all(mx))+m+1;
    ll ans=-1;
    while (le<=ri) {
        ll md=(le+ri)>>1;
        if (ok(md)) {
            le=md+1;
            ans=md;
        }
        else ri=md-1;
    }

    cout<<ans;

    return 0;
}