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
const int MAX = 3030; // PLZ CHK!

int N,M,K,D[MAX];
vector<pii> G[MAX];

int main() {
    fio();
    cin>>N>>M>>K;
    for (int i=0; i<M; i++) {
        int u,v,w; cin>>u>>v>>w;
        G[u].pb({v,w}), G[v].pb({u,w});
    }

    fill(D,D+MAX,INF);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for (int i=0; i<K; i++) {
        int x; cin>>x;
        D[x]=0;
        pq.push({D[x],x});
    }

    while (!pq.empty()) {
        auto [dst,cur]=pq.top(); pq.pop();
        if (dst!=D[cur]) continue;

        for (auto [nxt,cst]:G[cur]) {
            if (D[nxt]>D[cur]+cst) {
                D[nxt]=D[cur]+cst;
                pq.push({D[nxt],nxt});
            }
        }
    }

    double ans=0;
    for (int i=1; i<=N; i++) {
        for (auto [j,c]:G[i]) {
            ans=max(ans, 1.0*(D[i]+D[j]+c)/2.0);
        }
    }

    cout<<(int)(ans+0.5);
    return 0;
}