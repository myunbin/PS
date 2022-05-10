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
const int MAX = 222; // PLZ CHK!

ll dp[MAX][MAX][MAX];
vector<int> x,y,z;
int r,g,b;
ll go(int i, int j, int k) {
    if (r-i+g-j+b-k==1) return 0;
    ll &ret=dp[i][j][k];
    if (ret!=-1) return ret;

    ret=0;
    if (i<r && j<g) ret=max(ret,x[i]*y[j]+go(i+1,j+1,k));
    if (j<g && k<b) ret=max(ret,y[j]*z[k]+go(i,j+1,k+1));
    if (i<r && k<b) ret=max(ret,x[i]*z[k]+go(i+1,j,k+1));
    return ret;
}
void solve() {
    memset(dp,-1,sizeof dp);
    
    cin>>r>>g>>b;
    x.resize(r),y.resize(g),z.resize(b);
    for (int &a:x) cin>>a; sort(all(x),greater<>());
    for (int &a:y) cin>>a; sort(all(y),greater<>());
    for (int &a:z) cin>>a; sort(all(z),greater<>());

    cout<<go(0,0,0)<<endl;
}
int main() {
    fio();
    int tc=1;
    // cin>>tc;
    while (tc--) solve();
    return 0;
}