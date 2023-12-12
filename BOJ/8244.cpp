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
// const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 5050; // PLZ CHK!

int N,M,K;
short d[MAX][MAX][2];
vector<int> G[MAX];

const short INF=30000;

void bfs(int s) {
    queue<pii> q;
    d[s][s][0]=0;
    q.push({s,0});

    while (!q.empty()) {
        auto [cur,cpr]=q.front(); q.pop();
        int npr=cpr^1;
        for (int nxt:G[cur]) {
            if (d[s][nxt][npr]!=INF) continue;
            d[s][nxt][npr]=d[s][cur][cpr]+1;
            q.push({nxt,npr});
        }
    }
}

int main() {
    fio();
    fill_n(&d[0][0][0],MAX*MAX*2,INF);

    cin>>N>>M>>K;
    for (int i=0; i<M; i++) {
        int u,v; cin>>u>>v;
        G[u].pb(v), G[v].pb(u);
    }    

    for (int i=1; i<=N; i++) bfs(i);

    for (int i=0; i<K; i++) {
        int a,b,c; cin>>a>>b>>c;

        if (a==b && G[a].empty()) cout<<"NIE\n";
        else if ((int)d[a][b][c&1]==INF) cout<<"NIE\n";
        else if ((int)d[a][b][c&1]<=c) cout<<"TAK\n";
        else cout<<"NIE\n";
    }
    
    return 0;
}