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
const int MAX = 1010101; // PLZ CHK!

vector<ll> solve(ll a){
    vector<ll> ret;
    while (a%2==0) {
        ret.pb(2);
        a/=2;
    }
    for (ll i=3; i*i<=a; i+=2) {
        while (a%i==0) {
            ret.pb(i);
            a/=i;
        }
    }
    if (a>1) ret.pb(a);
    sort(all(ret), greater<>());
    return ret;
}
int main() {
    fio();
    ll a,b;
    cin>>a>>b;
    vector<ll> ra=solve(a), rb=solve(b);
    ll ans=1;
    for (int i=0; i<min(sz(ra), sz(rb)); i++) {
        if (ra[i]!=rb[i]) break;
        ans*=ra[i];
    }
    cout<<ans;
    return 0;
}