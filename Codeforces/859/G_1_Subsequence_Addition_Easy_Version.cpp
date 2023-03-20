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
    int n;
    cin>>n;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) cin>>a[i];
    sort(all(a));

    if (a[1]!=1) {
        cout<<"NO\n";
        return;
    }

    vector<vector<int>> d(n+1, vector<int>(5050));
    d[0][0]=1;
    for (int i=1; i<=n; i++) {
        if (i>1 && !d[i-1][a[i]]) {
            cout<<"NO\n";
            return;
        }

        for (int j=1; j<=5000; j++) {
            d[i][j]=d[i-1][j];
            if (j-a[i]>=0) d[i][j]|=d[i-1][j-a[i]];
        }
    }
    // cout<<endl;
    cout<<"YES\n";
}
int main() {
    fio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}