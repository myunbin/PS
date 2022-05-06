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
const int MAX = 555; // PLZ CHK!

int main() {
    fio();
    int n, a[MAX][MAX];
    cin>>n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) cin>>a[i][j];
    }

    int cy[MAX]={0};
    vector<vector<int>> c;
    for (int i=1; i<=n; i++) {
        bool f=1;
        if (cy[i]) continue;
        for (int j=1; j<=n; j++) {
            if (a[i][j] && f) {
                for (int k=1; k<=n; k++) {
                    if (a[i][k]!=a[j][k]) {f=0; break;}
                }
            }
        }
        if (f) {
            vector<int> t;
            for (int j=1; j<=n; j++) {
                if (a[i][j] && !cy[j]) cy[j]=1, t.pb(j);
            }
            if (!t.empty()) c.pb(t);
        }
    }

    ll ans=1;
    for (auto v:c) {
        ll fct=1;
        for (int i=1; i<=sz(v)-1; i++) fct=(fct*i)%MOD;
        ans=(ans*fct)%MOD;
    }

    for (int i=1; i<=n; i++) {
        int nc=0, ic=0;
        for (int j=1; j<=n; j++) {
            if (a[i][j] && !cy[j]) nc++;
            if (a[i][j] && cy[j]) ic++;
        }
        if (nc==1) ans=(ans*ic)%MOD;
    }

    cout<<ans;
    return 0;
}