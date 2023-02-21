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

const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 200000; // PLZ CHK!

int main() {
    fio();
    int n;
    ll x,y;
    cin>>n>>x>>y;
    vector<ll> p(MAX*2+10), a(n);
    for (ll &k:a) {
        cin>>k;
        p[k]++;
    }

    for (int i=1; i<=MAX; i++) p[i]+=p[i-1];
    
    vector<ll> d(MAX+1);
    for (int i=200000; i>=0; i--) {
        d[i]=d[i+x]+(y*((p[200000]-p[i+x-1]+p[i+x]-p[i]+MOD)%MOD))%MOD;
        d[i]%=MOD;
    }

    ll ans=0;
    for (ll k:a) ans+=d[k], ans%=MOD;

    cout<<ans<<sp<<d[a[0]];


    return 0;
}