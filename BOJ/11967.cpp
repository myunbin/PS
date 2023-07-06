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
const int MAX = 111; // PLZ CHK!

int main() {
    fio();
    int n,m;
    cin>>n>>m;

    vector<pii> a[MAX][MAX];
    for (int i=0; i<m; i++) {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        a[x1][y1].pb({x2,y2});
    }    

    int on[MAX][MAX]={0}, v[MAX][MAX]={0};
    queue<pii> q;

    on[1][1]=v[1][1]=1;
    q.push({1,1});

    while (!q.empty()) {
        auto [cx,cy]=q.front(); q.pop();

        for (auto [nx,ny]:a[cx][cy]) {
            if (!on[nx][ny]) {
                on[nx][ny]=1;
                for (int i=0; i<4; i++) {
                    int mx=nx+dx[i], my=ny+dy[i];
                    if (1<=mx&&mx<=n && 1<=my&&my<=n) {
                        if (!v[nx][ny] && v[mx][my]) {
                            v[nx][ny]=1;
                            q.push({nx,ny});
                            break;
                        }
                    }
                }
            }
        }

        for (int i=0; i<4; i++) {
            int nx=cx+dx[i], ny=cy+dy[i];
            if (1<=nx&&nx<=n && 1<=ny&&ny<=n) {
                if (!v[nx][ny] && on[nx][ny]) {
                    v[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    }

    int ans=0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            ans+=on[i][j];
        }
    }

    cout<<ans;
    return 0;
}