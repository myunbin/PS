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
const int MOD = 1e6+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 55; // PLZ CHK!

int n,m,c;
int a[MAX][MAX], d[MAX][MAX][MAX][MAX];

int main() {
    fio();

    cin>>n>>m>>c;
    for (int i=1; i<=c; i++) {
        int x,y; cin>>x>>y;
        a[x][y]=i;
    }

    if (a[1][1]) d[1][1][1][a[1][1]]=1;
    else d[1][1][0][0]=1;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (a[i][j]) {
                int z=a[i][j];
                for (int x=1; x<=c; x++) {
                    for (int y=0; y<z; y++) {
                        if (i>=2) d[i][j][x][z]=(d[i][j][x][z]+d[i-1][j][x-1][y])%MOD;
                        if (j>=2) d[i][j][x][z]=(d[i][j][x][z]+d[i][j-1][x-1][y])%MOD;
                    }
                }
            }
            else {
                for (int x=0; x<=c; x++) {
                    for (int y=0; y<=c; y++) {
                        if (i>=2) d[i][j][x][y]=(d[i][j][x][y]+d[i-1][j][x][y])%MOD;
                        if (j>=2) d[i][j][x][y]=(d[i][j][x][y]+d[i][j-1][x][y])%MOD;
                    }
                }
            }
        }
    }

    for (int i=0; i<=c; i++) {
        int ans=0;
        for (int j=0; j<=c; j++) {
            ans=(ans+d[n][m][i][j])%MOD;
        }
        cout<<ans<<sp;
    }
    
    return 0;
}