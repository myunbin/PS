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
const int MAX = 202020; // PLZ CHK!

int N,M,P,R[MAX],B[MAX],DN[MAX],DM[MAX],F[MAX];
vector<int> G[MAX];
vector<vector<int>> SCC;

int cnt=1;
vector<int> S;
void dfs(int cur) {
    DN[cur]=DM[cur]=cnt++;
    S.pb(cur);

    for (int nxt:G[cur]) {
        if (!DN[nxt]) {
            dfs(nxt);
            DM[cur]=min(DM[cur],DM[nxt]);
        }
        else if (!F[nxt]) DM[cur]=min(DM[cur],DN[nxt]);
    }

    if (DM[cur]==DN[cur]) {
        vector<int> scc;
        while (1) {
            int t=S.back(); S.pop_back();
            scc.pb(t);
            F[t]=1;
            if (t==cur) break;
        }
        SCC.pb(scc);
    }
}

int main() {
    fio();
    cin>>N>>M;
    for (int i=0; i<M; i++) {
        int u,v; cin>>u>>v;
        G[u].pb(v);
    }

    cin>>P;
    for (int i=0; i<P; i++) {
        int x; cin>>x;
        R[x]=1;
    }
    for (int i=0; i<P; i++) {
        int x; cin>>x;
        B[x]=1;
    }

    for (int i=1; i<=N; i++) {
        if (!DN[i]) dfs(i);
    }

    for (auto v:SCC) {
        int r=0,b=0;
        for (int x:v) {
            if (R[x]) r++;
            if (B[x]) b++;
        }
        if (r!=b) {
            cout<<"NO";
            return 0;
        }
    }

    cout<<"YES";
    return 0;
}