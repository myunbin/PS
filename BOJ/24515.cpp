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

int N;
char A[MAX][MAX];
int d[MAX][MAX],B[MAX][MAX],v[MAX][MAX];

int main() {
    fio();

    for (int i=0; i<MAX; i++) for (int j=0; j<MAX; j++) d[i][j]=INF;

    cin>>N;
    for (int i=1; i<=N; i++) {
        string s; cin>>s;
        for (int j=1; j<=N; j++) {
            A[i][j]=s[j-1];
        }
    }

    for (int i=2; i<=N+1; i++) A[0][i]=A[i][0]='a';
    for (int i=0; i<=N-1; i++) A[i][N+1]=A[N+1][i]='a';
    A[0][0]=A[0][1]=A[1][0]=A[N][N+1]=A[N+1][N]=A[N+1][N+1]='.';

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (v[i][j]) continue;

            queue<pii> q;
            q.push({i,j});
            v[i][j]=1;
            int cnt=1;

            vector<pii> t;
            t.pb({i,j});
            while (!q.empty()) {
                auto [cx,cy]=q.front(); q.pop();
                for (int i=0; i<4; i++) {
                    int nx=cx+dx[i], ny=cy+dy[i];
                    if (nx<1 || nx>N || ny<1 || ny>N || v[nx][ny] || A[cx][cy]!=A[nx][ny]) continue;
                    cnt++;
                    v[nx][ny]=1;
                    q.push({nx,ny});
                    t.pb({nx,ny});
                }
            }

            for (auto [x,y]:t) {
                B[x][y]=cnt;
            }
        }
    }

    typedef array<int,3> arr;
    priority_queue<arr, vector<arr>, greater<arr>> pq;
    d[2][0]=0;
    pq.push({0,2,0});

    while (!pq.empty()) {
        auto [dst,cx,cy]=pq.top(); pq.pop();

        if (dst!=d[cx][cy]) continue;

        for (int i=0; i<8; i++) {
            int nx=cx+dx[i], ny=cy+dy[i];
            if (nx<0 || nx>N+1 || ny<0 || ny>N+1 || A[nx][ny]=='.') continue;

            int cst=((i<4&&A[cx][cy]==A[nx][ny])?0:B[nx][ny]);
            if (d[nx][ny]>d[cx][cy]+cst) {
                d[nx][ny]=d[cx][cy]+cst;
                pq.push({d[nx][ny], nx, ny});
            }
        }
    }

    int ans=INF;
    for (int i=2; i<=N+1; i++) ans=min(ans, d[0][i]);
    for (int i=0; i<=N-1; i++) ans=min(ans, d[i][N+1]);

    cout<<ans;

    return 0;
}