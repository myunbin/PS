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
const int MAX = 55; // PLZ CHK!

int main() {
    fio();
    int n,m;
    cin>>n>>m;
    char a[MAX][MAX];
    for (int i=1; i<=n; i++) {
        string s; cin>>s;
        for (int j=1; j<=m; j++) a[i][j]=s[j-1];
    }

    int b[MAX][MAX]={0};

    auto ok1=[&](int x, int y) {
        if (a[x][y]!='.') return 0;
        if (y-1==0 || a[x][y-1]=='#') {
            if (y+2<=m && a[x][y+1]=='.' && a[x][y+2]=='.') return 1;
        }
        return 0;
    };

    auto ok2=[&](int x, int y) {
        if (a[x][y]!='.') return 0;
        if (x-1==0 || a[x-1][y]=='#') {
            if (x+2<=n && a[x+1][y]=='.' && a[x+2][y]=='.') return 1;
        }
        return 0;
    };

    vector<pii> ans;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (ok1(i,j) || ok2(i,j)) ans.pb({i,j});
        }
    }

    cout<<sz(ans)<<endl;
    for (auto [x,y]:ans) cout<<x<<sp<<y<<endl;
    return 0;
}