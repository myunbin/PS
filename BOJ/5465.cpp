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
const int MAX = 808; // PLZ CHK!

int N,M;
pii S,E;

char A[MAX][MAX];
int DB[MAX][MAX],V[MAX][MAX];

bool oob(int x, int y) { return (x<1||x>N||y<1||y>N||V[x][y]);}

bool ok(int t) {
    if (t>=DB[S.F][S.S]) return 0;

    memset(V,0,sizeof V);
    int D[MAX][MAX]={0};
    queue<pii> q;
    for (int i=0; i<MAX; i++) for (int j=0; j<MAX; j++) D[i][j]=-1;

    D[S.F][S.S]=0;
    V[S.F][S.S]=1;
    q.push(S);

    while (!q.empty()) {
        auto [cx,cy]=q.front(); q.pop();
        
        for (int i=0; i<4; i++) {
            int nx=cx+dx[i], ny=cy+dy[i];
            if (A[nx][ny]=='D') return 1;
            if (oob(nx,ny)||A[nx][ny]=='T'||A[nx][ny]=='D'||A[nx][ny]=='H'||t+(D[cx][cy]+1)/M>=DB[nx][ny]) continue;
            V[nx][ny]=1;
            D[nx][ny]=D[cx][cy]+1;
            q.push({nx,ny});
        }
    }
    return 0;
}

int main() {
    fio();
    for (int i=0; i<MAX; i++) for (int j=0; j<MAX; j++) DB[i][j]=-1;

    cin>>N>>M;
    
    queue<pii> q;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin>>A[i][j];
            if (A[i][j]=='M') S={i,j};
            if (A[i][j]=='D') E={i,j};
            if (A[i][j]=='H') {
                V[i][j]=1;
                DB[i][j]=0;
                q.push({i,j});
            }
        }
    }

    while (!q.empty()) {
        auto [cx,cy]=q.front(); q.pop();

        for (int i=0; i<4; i++) {
            int nx=cx+dx[i], ny=cy+dy[i];
            if (oob(nx,ny)||A[nx][ny]=='T'||A[nx][ny]=='D'||A[nx][ny]=='H') continue;

            V[nx][ny]=1;
            DB[nx][ny]=DB[cx][cy]+1;
            q.push({nx,ny});
        }
    }

    if (ok(0)==0) {
        cout<<-1;
        return 0;
    }

    int le=0, ri=N*N, ans=0;
    while (le<=ri) {
        int md=(le+ri)>>1;
        if (ok(md)) {
            ans=md;
            le=md+1;
        }
        else ri=md-1;
    }

    cout<<ans;
    return 0;
}