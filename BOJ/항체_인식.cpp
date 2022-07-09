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
const int MAX = 33; // PLZ CHK!

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int n,m;
vector<vector<int>> a(MAX,vector<int>(MAX)), b(MAX,vector<int>(MAX));
bool v[MAX][MAX];

void dfs(vector<vector<int>> &t, vector<pii> &c, int x, int y) {
    c.pb({x,y});
    v[x][y]=1;
    for (int i=0; i<4; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if (nx<0||nx>=n||ny<0||ny>=m||v[nx][ny]) continue;
        if (t[x][y]==t[nx][ny]) dfs(t,c,nx,ny);
    }
}
int main() {
    fio();
    cin>>n>>m;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) cin>>a[i][j];
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) cin>>b[i][j];

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (!v[i][j]) {
                vector<pii> c;
                dfs(a,c,i,j);

                int aa=a[c[0].F][c[0].S];
                int bb=b[c[0].F][c[0].S];

                for (auto [x,y]:c) {
                    a[x][y]=bb;
                }

                bool ok=1;
                for (int x=0; x<n; x++) {
                    bool f=1;
                    for (int y=0; y<m; y++) {
                        if (a[x][y]!=b[x][y]) {
                            f=ok=0;
                            break;
                        }
                    }
                    if (!f) break;
                }

                if (ok) {
                    cout<<"YES\n";
                    return 0;
                }

                for (auto [x,y]:c) {
                    a[x][y]=aa;
                }
            }
        }
    }
    
    cout<<"NO\n";
    return 0;
}