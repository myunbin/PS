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
const int MAX = 5050; // PLZ CHK!

int N,K,C[MAX],R[MAX],d[MAX][MAX];
vector<int> G[MAX];

int main() {
    fio();
    cin>>N>>K;
    for (int i=1; i<=N; i++) cin>>C[i]>>R[i];
    for (int i=0; i<K; i++) {
        int u,v; cin>>u>>v;
        G[u].pb(v), G[v].pb(u);
    }

    fill(&d[0][0],&d[MAX-1][MAX],INF);

    typedef array<int,3> arr;
    priority_queue<arr,vector<arr>,greater<arr>> pq;

    d[1][R[1]]=C[1];
    pq.push({d[1][R[1]],1,R[1]});

    while (!pq.empty()) {
        auto [dst,cur,crd]=pq.top(); pq.pop();
        if (dst!=d[cur][crd]) continue;

        for (int nxt:G[cur]) {
            if (crd>0 && d[nxt][crd-1]>d[cur][crd]) {
                d[nxt][crd-1]=d[cur][crd];
                pq.push({d[nxt][crd-1],nxt,crd-1});
            }
            if (d[nxt][R[cur]-1]>d[cur][crd]+C[cur]) {
                d[nxt][R[cur]-1]=d[cur][crd]+C[cur];
                pq.push({d[nxt][R[cur]-1],nxt,R[cur]-1});
            }
        }
    }

    cout<<*min_element(d[N],d[N]+MAX);

    return 0;
}