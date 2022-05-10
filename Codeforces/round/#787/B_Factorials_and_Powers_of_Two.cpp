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

vector<ll> a;
void init() {
    ll c=1;
    for (ll i=2; c<=(ll)1e12; i++) a.pb(c), c*=i;
}

void solve() {
    ll n;
    cin>>n;
    int ans=INF;
    for (int i=0; i<(1<<14); i++) {
        ll s=0;
        for (int j=0; j<14; j++) {
            if (i&(1<<j)) {
                s+=a[j];
            }
        }

        if (n<s) continue;
        ans=min(ans,__builtin_popcountll(i)+__builtin_popcountll(n-s));
    }
    cout<<ans<<endl;
}
int main() {
    fio();
    init();
    int t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}