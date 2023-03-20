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

const ll MX=1000000000000000000;
int sz;
vector<ll> d;
void init() {
    d.pb(0), d.pb(2), d.pb(2);
    while (d.back()<MX) {
        int sz=sz(d);
        d.pb(d[sz-2]+d[sz-1]+2);
    }
    sz=sz(d)-1;
    d.pb(d[sz-1]+d[sz]+2);
}

void ans(ll n, ll k) {
    if (k==1) {
        cout<<'('<<endl;
        return;
    }
    if (k==d[n]) {
        cout<<')'<<endl;
        return;
    }

    if (1<k && k<=1+d[n-2]) ans(n-2, k-1);
    else ans(n-1, k-(1+d[n-2]));
}

void solve() {
    ll n,k;
    cin>>n>>k;
    if (n<=sz && d[n]<k) {
        cout<<0<<endl;
        return;
    }

    if (n>sz) {
        ll x=(n-sz)/2;
        n-=2*x, k-=x;
        if (k<=0) {
            cout<<'('<<endl;
            return;
        }
    }

    ans(n,k);
}

int main() {
    fio();
    init();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}