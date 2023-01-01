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

bool ok(int x, int n, int m, vector<vector<int>> &a) {
    vector<vector<int>> p(n+1,vector<int>(m+1,0));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int t=(a[i][j]<x);
            p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+t;
        }
    }

    for (int i=1; i+x-1<=n; i++) {
        for (int j=1; j+x-1<=m; j++) {
            int x1=i, x2=i+x-1, y1=j, y2=j+x-1;
            int q=p[x2][y2]-p[x2][y1-1]-p[x1-1][y2]+p[x1-1][y1-1];
            if (q==0) return 1;
        }
    }
    return 0;
}
void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n+1,vector<int>(m+1,0));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin>>a[i][j];
        }
    }

    int le=1, ri=min(n,m);
    int ans=1;
    while (le<=ri) {
        int md=(le+ri)>>1;
        if (ok(md, n,m, a)) {
            ans=md;
            le=md+1;
        }
        else ri=md-1;
    }
    cout<<ans<<endl;
}
int main() {
    fio();
    int t;
    cin>>t;
    while (t--) solve();

    return 0;
}