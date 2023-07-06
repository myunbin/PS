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

const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010; // PLZ CHK!

int n,m,v;
vector<int> g[1010];
bool vst[1010];

void dfs(int cur) {
    vst[cur]=1;
    cout<<cur<<' ';
    for (int i=0; i<g[cur].size(); i++) {
        int nxt=g[cur][i];
        if (vst[nxt]) continue;
        dfs(nxt);
    }
}

void bfs() {
    memset(vst, 0, sizeof vst);
    queue<int> q;
    q.push(v);
    vst[v]=1;

    while (!q.empty()) {
        int cur=q.front();
        q.pop();
        cout<<cur<<' ';
        for (int i=0; i<g[cur].size(); i++) {
            int nxt=g[cur][i];
            if (vst[nxt]) continue;
            q.push(nxt);
            vst[nxt]=1;
        }
    }
}

int main() {
    fio();
    cin>>n>>m>>v;
    for (int i=0; i<m; i++) {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i=1; i<=n; i++) {
        sort(g[i].begin(), g[i].end());
    }

    dfs(v);
    cout<<endl;
    bfs();

    return 0;
}