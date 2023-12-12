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
const int MAX = 303; // PLZ CHK!
const int MAXD = MAX/60+5;

int N,M,A[MAX][MAX];
ll B[MAX][MAX][4][MAXD];

const int R=2,L=3,U=1,D=0;

bool ok(int x1, int y1, int d) {
    int x2=x1+d-1, y2=y1+d-1;
    for (int i=0; i<(d/60); i++) {
        if (B[x1][y1][R][i]!=B[x2][y2][L][i]) return 0;
        if (B[x1][y1][D][i]!=B[x2][y2][U][i]) return 0;
    }
    for (int i=0; i<(d%60); i++) {
        if ((B[x1][y1][R][d/60]&(1ll<<i))!=(B[x2][y2][L][d/60]&(1ll<<i))) return 0;
        if ((B[x1][y1][D][d/60]&(1ll<<i))!=(B[x2][y2][U][d/60]&(1ll<<i))) return 0;
    }
    return 1;
}

int main() {
    fio();
    cin>>N>>M;
    for (int i=1; i<=N; i++) {
        string a; cin>>a;
        for (int j=1; j<=M; j++) {
            A[i][j]=a[j-1]-'0';
        }
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            for (int k=0; k<4; k++) {
                for (int x=i,y=j,z=0; 1<=x&&x<=N && 1<=y&&y<=M; x+=dx[k],y+=dy[k],z++) {
                    if (A[x][y]) B[i][j][k][z/60]+=(1ll<<(z%60));
                }
            }
        }
    }

    int ans=1;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            for (int k=0; 1<=i-k&&i+k<=N&&1<=j-k&&j+k<=M; k++) {
                if (ok(i-k,j-k,2*k+1)) {
                    ans=max(ans,2*k+1);
                }
                else break;
            }
            for (int k=0; 1<=i-k&&i+k+1<=N&&1<=j-k&&j+k+1<=M; k++) {
                if (ok(i-k,j-k,2*k+2)) {
                    ans=max(ans,2*k+2);
                }
                else break;
            }
        }
    }

    cout<<ans;

    return 0;
}