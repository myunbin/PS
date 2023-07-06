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
const int MAX = 1010; // PLZ CHK!

int a[MAX][MAX],v[MAX][MAX][2][5], d[MAX][MAX][2][5];

int main() {
    fio();

    // freopen("dream.in", "r", stdin);
    // freopen("dream.out", "w", stdout);

    int n,m;
    cin>>n>>m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>a[i][j];
        }
    }

    queue<array<int,4>> q;
    v[0][0][0][4]=1;
    q.push({0,0,0,4});

    while (!q.empty()) {
        auto [cx,cy,co,cd]=q.front(); q.pop();
        if (cx==n-1&&cy==m-1) {
            cout<<d[cx][cy][co][cd];
            return 0;
        }

        bool p=0;
        if (a[cx][cy]==4) {
            int nx=cx+dx[cd], ny=cy+dy[cd];
            int no=co, nd=cd;

            if (!(0<=nx&&nx<n && 0<=ny&&ny<m)) p=0;
            else if (a[nx][ny]==0) p=0;
            else if (a[nx][ny]==3 && co) p=0;
            else if (a[nx][ny]==1 && !v[nx][ny][no][nd]) {
                p=1;
                v[nx][ny][no][nd]=1;
                d[nx][ny][no][nd]=d[cx][cy][co][cd]+1;
                q.push({nx,ny,no,nd});
            }
            else if (a[nx][ny]==2 && !v[nx][ny][1][nd]) {
                p=1;
                v[nx][ny][1][nd]=1;
                d[nx][ny][1][nd]=d[cx][cy][co][cd]+1;
                q.push({nx,ny,1,nd});
            }
            else if (a[nx][ny]==3 && co && !v[nx][ny][1][nd]) {
                p=1;
                v[nx][ny][1][nd]=1;
                d[nx][ny][1][nd]=d[cx][cy][co][cd]+1;
                q.push({nx,ny,1,nd});
            }
            else if (a[nx][ny]==4 && !v[nx][ny][0][nd]) {
                p=1;
                v[nx][ny][0][nd]=1;
                d[nx][ny][0][nd]=d[cx][cy][co][cd]+1;
                q.push({nx,ny,0,nd});
            }
        }

        if (!p) {
            for (int i=0; i<4; i++) {
                int nx=cx+dx[i], ny=cy+dy[i];
                if (!(0<=nx&&nx<n && 0<=ny&&ny<m)) continue;
                int no=co, nd=i;
                
                if (a[nx][ny]==0) continue;
                else if (a[nx][ny]==1 && !v[nx][ny][no][nd]) {
                    v[nx][ny][no][nd]=1;
                    d[nx][ny][no][nd]=d[cx][cy][co][cd]+1;
                    q.push({nx,ny,no,nd});
                }
                else if (a[nx][ny]==2 && !v[nx][ny][1][nd]) {
                    v[nx][ny][1][nd]=1;
                    d[nx][ny][1][nd]=d[cx][cy][co][cd]+1;
                    q.push({nx,ny,1,nd});
                }
                else if (a[nx][ny]==3 && co && !v[nx][ny][1][nd]) {
                    v[nx][ny][1][nd]=1;
                    d[nx][ny][1][nd]=d[cx][cy][co][cd]+1;
                    q.push({nx,ny,1,nd});
                }
                else if (a[nx][ny]==4 && !v[nx][ny][0][nd]) {
                    v[nx][ny][0][nd]=1;
                    d[nx][ny][0][nd]=d[cx][cy][co][cd]+1;
                    q.push({nx,ny,0,nd});
                }
            }
        }
    }
    cout<<-1;
    return 0;
}