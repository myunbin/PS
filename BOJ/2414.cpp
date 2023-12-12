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
const int MAX = 55; // PLZ CHK!

int N,M,AH[MAX][MAX],AV[MAX][MAX];
char A[MAX][MAX];

template<typename FlowType, size_t _Sz, FlowType _Inf> struct Dinic {
    struct Edge { int v, dual; FlowType c; };
    int Level[_Sz], Work[_Sz];
    vector<Edge> G[_Sz];
    void clear() { for (int i = 0; i < _Sz; i++) G[i].clear(); }
    void AddEdge(int s, int e, FlowType x) {
        G[s].push_back({ e, (int)G[e].size(), x });
        G[e].push_back({ s, (int)G[s].size() - 1, 0 });
    }
    bool BFS(int S, int T) {
        memset(Level, 0, sizeof Level);
        queue<int> Q; Q.push(S); Level[S] = 1;
        while (Q.size()) {
            int v = Q.front(); Q.pop();
            for (const auto& i : G[v]) {
                if (!Level[i.v] && i.c) Q.push(i.v), Level[i.v] = Level[v] + 1;
            }
        }
        return Level[T];
    }
    FlowType DFS(int v, int T, FlowType tot) {
        if (v == T) return tot;
        for (int& _i = Work[v]; _i < G[v].size(); _i++) {
            Edge& i = G[v][_i];
            if (Level[i.v] != Level[v] + 1 || !i.c) continue;
            FlowType fl = DFS(i.v, T, min(tot, i.c));
            if (!fl) continue;
            i.c -= fl;
            G[i.v][i.dual].c += fl;
            return fl;
        }
        return 0;
    }
    FlowType MaxFlow(int S, int T) {
        FlowType ret = 0, tmp;
        while (BFS(S, T)) {
            memset(Work, 0, sizeof Work);
            while ((tmp = DFS(S, T, _Inf))) ret += tmp;
        }
        return ret;
    }
    tuple<FlowType, vector<int>, vector<int>, vector<pair<int, int>>> MinCut(int S, int T) {
        FlowType fl = MaxFlow(S, T);
        vector<int> a, b;
        vector<pair<int, int>> edges;
        const int Bias = 1e9;
        queue<int> Q; Q.push(S); Level[S] += Bias;
        while (Q.size()) {
            int v = Q.front(); Q.pop();
            for (const auto& i : G[v]) {
                if (!Level[i.v]) edges.emplace_back(v, i.v);
                else if (Level[i.v] < Bias) Q.push(i.v), Level[i.v] += Bias;
            }
        }
        for (int i = 0; i < _Sz; i++) {
            if (Level[i]) a.push_back(i);
            else b.push_back(i);
        }
        return make_tuple(fl, a, b, edges);
    }
};

int main() {
    fio();
    cin>>N>>M;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin>>A[i][j];
        }
    }

    int CH=0,CV=0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; ) {
            if (A[i][j]=='*') {
                CH++;
                while (j<=M && A[i][j]=='*') AH[i][j]=CH,j++;
            }
            else j++;
        }
    }

    for (int j=1; j<=M; j++) {
        for (int i=1; i<=N; ) {
            if (A[i][j]=='*') {
                CV++;
                while (i<=N && A[i][j]=='*') AV[i][j]=CV,i++;
            }
            else i++;
        }
    }
    
    Dinic<int,MAX*MAX,INF> D;

    int S=0,T=CH+CV+1;
    for (int i=1; i<=CH; i++) D.AddEdge(S,i,1);
    for (int i=1; i<=CV; i++) D.AddEdge(CH+i,T,1);
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            if (A[i][j]=='*') D.AddEdge(AH[i][j],CH+AV[i][j],1);
        }
    }

    cout<<D.MaxFlow(S,T);
    return 0;
}