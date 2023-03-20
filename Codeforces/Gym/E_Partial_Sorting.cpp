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

// const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 3030303; // PLZ CHK!

ll fct[MAX], fiv[MAX], inv[MAX];
ll n, MOD;
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

ll add(ll a, ll b) {
    a%=MOD, b%=MOD;
    return (a+b)%MOD;
}

ll sub(ll a, ll b) {
    a%=MOD, b%=MOD;
    return (a-b+MOD)%MOD;
}

ll mul(ll a, ll b) {
    a%=MOD, b%=MOD;
    return (a*b)%MOD;
}

int main() {
    fio();

    cin>>n>>MOD;
    factinv();

    ll f0=1;
    ll f1=sub(mul(2, fct[2*n]), fct[n]);
    ll f2=mul(mul(mul(2, bico(2*n, n)), fct[n]), fct[2*n]);
    for (ll i=0; i<=n; i++) {
        ll x=mul(mul(bico(n,i), bico(n,i)), bico(n,i));
        ll t=mul(mul(mul(x, fct[i]), fct[n]), fct[2*n-i]);
        f2=sub(f2, t);
    }
    ll f3=fct[3*n];

    ll a1=mul(1,sub(f1, f0));
    ll a2=mul(2,sub(f2, f1));
    ll a3=mul(3,sub(f3, f2));

    cout<<add(a1, add(a2, a3));
    return 0;
}