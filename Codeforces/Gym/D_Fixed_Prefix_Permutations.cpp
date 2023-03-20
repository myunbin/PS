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
    vector<pair<vector<int>,int>> a;
    vector<vector<int>> b;
    for (int i=0; i<n; i++) {
        vector<int> x(m), y(m);
        for (int j=0; j<m; j++) {
            cin>>x[j]; --x[j];
            y[x[j]]=j;
        }
        a.pb({x,i}), b.pb(y);
    }
    sort(all(a)), sort(all(b));

    vector<int> ans(n);
    
    for (auto [v,i]:a) {
        int cnt=0;
        int pos=lb(all(b), v)-b.begin();
        if (pos<n) {
            for (int j=0; j<m; j++) {
                if (v[j]!=b[pos][j]) break;
                cnt++;
            }
            ans[i]=cnt;    
        }
        if (pos>0) {
            cnt=0;
            for (int j=0; j<m; j++) {
                if (v[j]!=b[pos-1][j]) break;
                cnt++;
            }
        }

        ans[i]=max(ans[i], cnt);
    }

    for (int x:ans) cout<<x<<sp;
    cout<<endl;
}

int main() {
    fio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}