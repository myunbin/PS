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

int solve() {
    int n,m;
    cin>>n>>m;
    if (!n&&!m) return -1;

    vector<vector<int>> d(n+1,vector<int>(m+1));
    int ans=0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int x; cin>>x;
            if (x) d[i][j]=min({d[i-1][j], d[i][j-1], d[i-1][j-1]})+1;
            ans=max(ans, d[i][j]);
        }
    }
    return ans;
}
int main() {
    fio();
    while (1) {
        int r=solve();
        if (r<0) break;
        cout<<r<<endl;
    }
    return 0;
}