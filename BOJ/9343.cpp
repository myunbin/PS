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

const int dx[] = {1,-1,0,0,1,1,-1,-1};
const int dy[] = {0,0,1,-1,1,-1,1,-1};
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 2020202; // PLZ CHK!

ll fct[MAX], fiv[MAX], inv[MAX];
void factinv() {
    fct[0] = fct[1] = inv[0] = inv[1] = fiv[0] = fiv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fct[i] = (fct[i-1]*i)%MOD;
        inv[i] = MOD-(MOD/i)*inv[MOD%i]%MOD;
        fiv[i] = (fiv[i-1]*inv[i])%MOD;
    }
}

ll bico(int n, int k) {
    if (n < k) return 0;
	return (fct[n]*(fiv[k]*fiv[n-k]%MOD)%MOD)%MOD;
}

ll pw(ll a, ll b) {
    if (b==0) return 1;
    if (b%2) return a*pw(a,b-1)%MOD;
    ll r=pw(a,b/2)%MOD; return r*r%MOD;
}

int main() {
    fio();
    factinv();

    int t; cin>>t;
    while (t--) {
        ll n; cin>>n;
        ll ans=bico(2*n, n)*pw(n+1,MOD-2)%MOD;
        cout<<ans<<endl;
    }

    return 0;
}