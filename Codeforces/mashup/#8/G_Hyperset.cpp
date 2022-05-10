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
    int n,k;
    cin>>n>>k;
    vector<string> v(n);
    for (string &x:v) cin>>x;
    sort(all(v));

    int ans=0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            string x=v[i], y=v[j], z;
            for (int t=0; t<k; t++) {
                if (x[t]==y[t]) z.pb(x[t]);
                else {
                    if (x[t]=='S'&&y[t]=='E' || x[t]=='E'&&y[t]=='S') z.pb('T');
                    else if (x[t]=='S'&&y[t]=='T' || x[t]=='T'&&y[t]=='S') z.pb('E');
                    else if (x[t]=='E'&&y[t]=='T' || x[t]=='T'&&y[t]=='E') z.pb('S');
                }
            }
            auto ii=lb(all(v),z);
            if (*ii==z) ++ans;
        }
    }   
    cout<<ans/3;
}
int main() {
    fio();
    int t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}