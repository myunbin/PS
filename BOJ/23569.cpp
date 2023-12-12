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

int N,M,V[MAX],C[MAX],E[MAX][MAX],d[MAX][2*MAX];
vector<int> G[MAX],A;

void dfs(int cur, int &c1, int &c2) {
    if (C[cur]==0) c1++;
    else c2++;

    V[cur]=1;
    for (int nxt:G[cur]) {
        if (V[nxt]) {
            if (C[nxt]==C[cur]) {
                cout<<-1;
                exit(0);
            }
            continue;
        }
        C[nxt]=!C[cur];
        dfs(nxt, c1, c2);
    }
}

int main() {
    fio();
    cin>>N>>M;
    
    for (int i=0; i<M; i++) {
        int u,v; cin>>u>>v;
        E[u][v]=E[v][u]=1;
    }

    for (int i=1; i<=N; i++) {
        for (int j=i+1; j<=N; j++) {
            if (!E[i][j]) {
                G[i].pb(j);
                G[j].pb(i);
            }
        }
    }

    A.pb(0);
    for (int i=1; i<=N; i++) {
        if (!V[i]) {
            int a=0,b=0;
            dfs(i,a,b);
            A.pb(abs(a-b));
        }
    }

    int K=sz(A)-1;

    const int bs=1000;

    d[0][bs]=1;
    for (int i=1; i<=K; i++) {
        for (int j=-N; j<=N; j++) {
            if (bs+j-A[i]>=0 && d[i-1][bs+j-A[i]]) d[i][bs+j]=1;
            if (bs+j+A[i]<2*MAX && d[i-1][bs+j+A[i]]) d[i][bs+j]=1;   
        }
    }
    
    int ans=2*N;
    for (int j=-N; j<=N; j++) {
        if (d[K][bs+j]) ans=min(ans, abs(j));
    }

    cout<<ans;
    return 0;
}