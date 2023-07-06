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

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n+1);
    vector<vector<int>> dv(n+1);
    for (int i=1; i<=n; i++) {
        cin>>a[i];
        for (int j=1; j*j<=a[i]; j++) {
            if (a[i]%j==0) {
                dv[i].pb(j);
                if (j*j!=a[i]) dv[i].pb(a[i]/j);
            }
        }
        dv[i].pb(0);
        sort(all(dv[i]));
    }

    vector<vector<ll>> d(n+1, vector<ll>(250));
    vector<ll> p(250);
    for (int i=1; i<sz(dv[1]); i++) {
        d[1][i]=1;
        p[i]=(p[i-1]+d[1][i])%MOD;
    }

    for (int i=2; i<=n; i++) {
        for (int j=1; j<sz(dv[i]); j++) {
            int l=ub(all(dv[i-1]), dv[i][j])-dv[i-1].begin();
            d[i][j]=p[l-1];
        }
        for (int j=1; j<sz(dv[i]); j++) p[j]=(p[j-1]+d[i][j])%MOD;
    }

    cout<<p[sz(dv[n])-1]<<endl;
}

int main() {
    fio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}