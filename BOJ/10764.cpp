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

const int dx[] = {1,-1,0,0,1,1,-1,-1};
const int dy[] = {0,0,1,-1,1,-1,1,-1};
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010; // PLZ CHK!

int main() {
    fio();
    int n,m;
    cin>>n>>m;
    
    string a[55];
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }
    
    map<vector<char>,int> cnt;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            for (int k=0; k<8; k++) {
                vector<char> t;
                for (int l=0; l<3; l++) {
                    int x=i+l*dx[k], y=j+l*dy[k];
                    if (0<=x&&x<n && 0<=y&&y<m) t.pb(a[x][y]);
                }
                if (sz(t)==3) cnt[t]++;
            }
        }
    }
    
    int ans=0;
    for (auto [v,x]:cnt) {
        if (v[0]!=v[1] && v[1]==v[2] && v[0]!='M' && v[1]!='O') ans=max(ans, x);
    }
    cout<<ans;

    return 0;
}