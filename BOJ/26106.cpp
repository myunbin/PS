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
const int MAX = 101010; // PLZ CHK!

typedef array<ll,3> arr;

int N,M,K,S,T;
vector<pll> G[MAX];
map<int,ll> D[MAX];
set<arr> F;

int main() {
    fio();
    
    cin>>M>>N>>K>>S>>T;
    for (int i=0; i<M; i++) {
        int u,v,w; cin>>u>>v>>w;
        G[u].pb({v,w});
    }
    for (int i=0; i<K; i++) {
        ll u,v,w; cin>>u>>v>>w;
        F.insert({u,v,w});
    }

    priority_queue<arr,vector<arr>,greater<arr>> pq;
    
    D[S][-1]=0;
    pq.push({D[S][-1],S,-1});

    while (!pq.empty()) {
        auto [dst,cur,prv]=pq.top(); pq.pop();
        if (dst!=D[cur][prv]) continue;
        
        for (auto [nxt,cst]:G[cur]) {
            if (F.find({prv,cur,nxt})!=F.end()) continue;
            if (D[nxt].find(cur)==D[nxt].end() || D[nxt][cur]>D[cur][prv]+cst) {
                D[nxt][cur]=D[cur][prv]+cst;
                pq.push({D[nxt][cur],nxt,cur});
            }
        }
    }

    ll ans=LINF;
    for (auto [prv,dst]:D[T]) {
        ans=min(ans,dst);
    }

    cout<<(ans==LINF?-1:ans);
    return 0;
}