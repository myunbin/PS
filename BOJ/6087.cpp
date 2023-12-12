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

int N,M;
char A[MAX][MAX];
int D[MAX][MAX][5];
vector<pii> SE;

bool oob(int x, int y) {
    return (x<1||x>N||y<1||y>M||A[x][y]=='*');
}

int main() {
    fio();

    for (int i=0; i<MAX; i++) for (int j=0; j<MAX; j++) for (int k=0; k<5; k++) D[i][j][k]=INF;

    cin>>M>>N;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin>>A[i][j];
            if (A[i][j]=='C') SE.pb({i,j});
        }
    }

    pii s=SE[0],e=SE[1];
    deque<array<int,3>> q;
    q.push_back({s.F,s.S,4});
    D[s.F][s.S][4]=0;

    int ans=INF;
    while (!q.empty()) {
        auto [cx,cy,cd]=q.front(); q.pop_front();

        if (e==pii(cx,cy)) {
            ans=min(ans, D[cx][cy][cd]);
        }

        for (int i=0; i<4; i++) {
            int nx=cx+dx[i], ny=cy+dy[i], nd=i;
            if (oob(nx,ny)) continue;

            int c=(cd==nd?0:1);
            if (D[nx][ny][nd]>D[cx][cy][cd]+c) {
                D[nx][ny][nd]=D[cx][cy][cd]+c;
                if (c==1) q.push_back({nx,ny,nd});
                else q.push_front({nx,ny,nd});
            }
        }
    }

    cout<<ans-1;
    return 0;
}