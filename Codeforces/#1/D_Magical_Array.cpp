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
    int n,m;
    cin>>n>>m;
    vector<vector<ll>> a(n,vector<ll>(m+1)), p(n,vector<ll>(m+1));
    for (int i=0; i<n; i++) {
        for (int j=1; j<=m; j++) {
            cin>>a[i][j];
            p[i][j]=p[i][j-1]+a[i][j];
        }
    }
    
    vector<ll> s(n);
    for (int i=0; i<n; i++) {
        for (int j=1; j<=m; j++) s[i]+=p[i][j];
    }

    ll ansi=-1, ans=-1;
    for (int i=1; i<n-1; i++) {
        vector<ll> t={s[i-1], s[i], s[i+1]};
        if (t[0]==t[1] && t[1]==t[2]) continue;
        if (t[0]!=t[1] && t[0]!=t[2]) ansi=i, ans=t[1]-t[0];
        else if (t[1]!=t[0] && t[1]!=t[2]) ansi=i+1, ans=t[0]-t[1];
        else if (t[2]!=t[0] && t[2]!=t[1]) ansi=i+2, ans=t[0]-t[2];
        break;
    }
    cout<<ansi<<sp<<ans<<endl;
}
int main() {
    fio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}