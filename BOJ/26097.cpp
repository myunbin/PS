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
const int MAX = 1010; // PLZ CHK!

int main() {
    fio();
    int n,m;
    cin>>n>>m;
    int a[MAX][MAX];

    set<pii> v0, v1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin>>a[i][j];
            if (a[i][j]) v1.insert({i,j});
            else v0.insert({i,j});
        }
    }
    if (sz(v0)&1 || sz(v1)&1) {
        cout<<-1;
        return 0;
    }

    bool ok=0;
    pair<pii, pii> st;
    for (int i=1; i<n; i++) {
        for (int j=1; j<m; j++) {
            if (!ok && a[i][j]==a[i+1][j]) {
                ok=1;
                st={{i,j}, {i+1,j}};
                if (a[i][j]) v1.erase({i,j}), v1.erase({i+1,j});
                else v0.erase({i,j}), v0.erase({i+1,j});
            }
            if (!ok && a[i][j]==a[i][j+1]) {
                ok=1;
                st={{i,j}, {i,j+1}};
                if (a[i][j]) v1.erase({i,j}), v1.erase({i,j+1});
                else v0.erase({i,j}), v0.erase({i,j+1});
            }
        }
    }
    
    if (!ok) {
        cout<<-1;
        return 0;
    }
    cout<<1<<endl;
    cout<<st.F.F<<sp<<st.F.S<<sp<<st.S.F<<sp<<st.S.S<<endl;
    
    bool e=1;
    for (auto [x,y]:v0) {
        cout<<x<<sp<<y;
        if (e) cout<<sp;
        else cout<<endl;
        e^=1;
    }
    e=1;
    for (auto [x,y]:v1) {
        cout<<x<<sp<<y;
        if (e) cout<<sp;
        else cout<<endl;
        e^=1;
    }
    return 0;
}