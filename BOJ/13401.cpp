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
const int MAX = 202020; // PLZ CHK!

vector<pii> g1[MAX], g2[MAX];
int n,m,ans[MAX];

int main() {
    fio();
    cin>>n>>m;
    for (int i=0; i<m; i++) {
        int x,y; cin>>x>>y;
        g1[y+1].pb({x,1}), g2[y].pb({x,1});
    }
    
    for (int i=1; i<=n; i++) g1[i].pb({0,1}), g2[i].pb({0,1});
    
    for (int i=1; i<=n; i++) {
        sort(all(g1[i]));
        for (auto &[x,c]:g1[i]) {
            int idx=ub(all(g1[i-1]), make_pair(x,-1))-g1[i-1].begin()-1;
            if (idx<0) continue;

            c+=g1[i-1][idx].S;
        }
    }

    for (int i=n; i>=1; i--) {
        sort(all(g2[i]));
        for (auto &[x,c]:g2[i]) {
            int idx=ub(all(g2[i+1]), make_pair(x,-1))-g2[i+1].begin()-1;
            if (idx<0) continue;

            c+=g2[i+1][idx].S;
        }
    }

    for (int i=1; i<=n; i++) {
        int ans=0;
        cout<<g1[i].back().S+g2[i].back().S-1<<sp;
    }
    return 0;
}