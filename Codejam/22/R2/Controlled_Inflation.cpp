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
    int n,p;
    cin>>n>>p;

    vector<vector<ll>> x(n+1,vector<ll>(p));
    for (int i=1; i<=n; i++) {
        for (int j=0; j<p; j++) {
            cin>>x[i][j];
        }
    }
    for (int i=0; i<=n; i++) sort(all(x[i]));
    
    vector<vector<ll>> d(n+1, vector<ll>(2));
    for (int i=1; i<=n; i++) {
        ll mx=x[i][p-1],mn=x[i][0];
        ll lmx=x[i-1][p-1], lmn=x[i-1][0];
        d[i][0]=min(d[i-1][0]+abs(lmx-mn), d[i-1][1]+abs(lmn-mn))+mx-mn;
        d[i][1]=min(d[i-1][0]+abs(lmx-mx), d[i-1][1]+abs(lmn-mx))+mx-mn;
    }
    cout<<min(d[n][0],d[n][1])<<endl;
}
int main() {
    fio();
    int t;
    cin>>t;
    for (int i=1; i<=t; i++) {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}