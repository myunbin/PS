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

// const int dx[] = {1,-1,0,0,1,1,-1,-1};
// const int dy[] = {0,0,1,-1,1,-1,1,-1};
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1010; // PLZ CHK!

int N,M,K;
string I;
char A[MAX][MAX],B[MAX][MAX];
int D[MAX][MAX],V[MAX][MAX];

//NWSE
const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};

bool oob(int x, int y) {
    return (x<1||x>N||y<1||y>M);
}

int main() {
    fio();
    memset(D,-1,sizeof D);

    pii st;
    cin>>M>>N;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin>>A[i][j];
            B[i][j]=A[i][j];

            if (A[i][j]=='S') st={i,j};
        }
    }
    cin>>I;
    K=sz(I);

    queue<pii> q;
    V[st.F][st.S]=1;
    D[st.F][st.S]=0;
    q.push(st);

    while (!q.empty()) {
        auto [cx,cy]=q.front(); q.pop();
        
        for (int i=0; i<4; i++) {
            int nx=cx+dx[i], ny=cy+dy[i];
            if (oob(nx,ny) || V[nx][ny] || A[nx][ny]=='#') continue;

            V[nx][ny]=1;
            D[nx][ny]=D[cx][cy]+1;
            q.push({nx,ny});
        }
    }

    memset(V,0,sizeof V);
    V[st.F][st.S]=1;
    q.push(st);
    while (!q.empty()) {
        auto [cx,cy]=q.front(); q.pop();
        int cd=D[cx][cy];

        if (cd==K) {
            B[cx][cy]='!';
            continue;
        }

        for (int i=0; i<4; i++) {
            if (I[cd]=='N' && i==0) continue;
            if (I[cd]=='W' && i==1) continue;
            if (I[cd]=='S' && i==2) continue;
            if (I[cd]=='E' && i==3) continue;

            int nx=cx+dx[i], ny=cy+dy[i];
            if (oob(nx,ny) || V[nx][ny] || A[nx][ny]=='#' || D[nx][ny]!=D[cx][cy]+1) continue;

            V[nx][ny]=1;
            q.push({nx,ny});
        }
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cout<<B[i][j];
        } cout<<endl;
    }
    return 0;
}