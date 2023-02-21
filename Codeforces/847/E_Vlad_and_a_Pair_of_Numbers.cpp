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

void solve() {
    ll x;
    cin>>x;
    if (x&1) {
        cout<<-1<<endl;
        return;
    }
    ll y=(x>>1);
    ll a=0, b=0;
    for (ll i=0; i<30; i++) {
        if (!(x&(1<<i))) {
            if (y&(1<<i)) {
                a+=(1<<i);
                b+=(1<<i);
            }
        }
        else {
            if (y&(1<<i)) {
                cout<<-1<<endl;
                return;
            }
            a+=(1<<i);
        }
    }

    cout<<a<<sp<<b<<endl;
}
int main() {
    fio();
    int t;
    cin>>t;
    while (t--) solve();

    return 0;
}