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
const int MAX = 2020; // PLZ CHK!

int N,M,A[MAX][MAX];
int v[MAX][MAX],d[MAX][MAX];

int main() {
    fio();
    for (int i=0; i<MAX; i++) {
        for (int j=0; j<MAX; j++) d[i][j]=INF;
    }

    cin>>N>>M;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin>>A[i][j];
        }
    }

    A[1][1]=A[N][M]=A[0][0]=A[0][1]=A[1][0]=A[N][M+1]=A[N+1][M]=A[N+1][M+1]=-1;

    for (int j=2; j<=M+1; j++) A[0][j]=1;
    for (int j=0; j<=M-1; j++) A[N+1][j]=1;
    for (int i=2; i<=N+1; i++) A[i][0]=1;
    for (int i=0; i<=N-1; i++) A[i][M+1]=1;

    deque<pii> q;
    q.pb({2,0});
    v[2][0]=1;
    d[2][0]=0;

    int ans=2;
    while (!q.empty()) {
        auto [cx,cy]=q.front(); q.pop_front();
        if (cx==0 || cy==M+1) {
            ans=min(ans, d[cx][cy]);
            continue;
        }
        if (d[cx][cy]>=2) {
            break;
        }

        for (int i=0; i<8; i++) {
            int nx=cx+dx[i], ny=cy+dy[i];
            if (nx<0||nx>N+1||ny<0||ny>M+1||v[nx][ny]||A[nx][ny]==-1) continue;

            int c=(A[nx][ny]==0);
            if (d[nx][ny]>d[cx][cy]+c) {
                d[nx][ny]=d[cx][cy]+c;
                if (c==1) q.push_back({nx,ny});
                else q.push_front({nx,ny});
            }
        }
    }

    cout<<ans;
    
    return 0;
}