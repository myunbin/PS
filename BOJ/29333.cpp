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
const int MAX = 303030; // PLZ CHK!

struct edge {
    int v,d,id;
};

int N,M,S,E,ans[MAX],v[MAX];
vector<edge> G[MAX];

int main() {
    fio();
    cin>>N>>M>>S>>E;
    for (int i=0; i<M; i++) {
        int u,v; cin>>u>>v;
        G[u].pb({v,0,i});
        G[v].pb({u,1,i});
    }

    queue<int> q;
    q.push(S);
    v[S]=1;

    int prv[MAX];
    fill(prv,prv+MAX,-1);

    while (!q.empty()) {
        int cur=q.front(); q.pop();
        for (auto [nxt,dir,idx]:G[cur]) {
            if (v[nxt]) {
                continue;
            }
            prv[nxt]=cur;
            ans[idx]=dir;
            v[nxt]=1;
            q.push(nxt);
        }
    }

    if (!v[E]) {
        cout<<-1;
        return 0;
    }

    for (int cur=E; cur!=S; cur=prv[cur]) {
        for (auto [nxt,dir,idx]:G[cur]) {
            if (nxt==prv[cur]) continue;
            ans[idx]=dir;
        }
    }

    for (int i=0; i<M; i++) cout<<ans[i]<<sp;
    return 0;
}