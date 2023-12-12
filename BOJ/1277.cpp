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


const int dx[] = {1,-1,0,0,1,1,-1,-1};
const int dy[] = {0,0,1,-1,1,-1,1,-1};
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1010; // PLZ CHK!


typedef pair<int,double> pid;
typedef pair<double,int> pdi;

int N,W;
double M;
pll A[MAX];
vector<pid> G[MAX];
double D[MAX];

int main() {
    fio();
    cin>>N>>W>>M;
    for (int i=1; i<=N; i++) {
        cin>>A[i].F>>A[i].S;
    }

    for (int i=0; i<W; i++) {
        int u,v;
        cin>>u>>v;
        G[u].pb({v,0.0});
        G[v].pb({u,0.0});
    }
    
    const double eps=1e-9;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            double d=sqrt(1.0*(A[i].F-A[j].F)*(A[i].F-A[j].F)+1.0*(A[i].S-A[j].S)*(A[i].S-A[j].S));
            if (d>M+eps) continue;
            G[i].pb({j,d}), G[j].pb({i,d});
        }
    }

    priority_queue<pdi,vector<pdi>,greater<pdi>> pq;
    fill(D,D+MAX,1e18);

    D[1]=0.0;
    pq.push({D[1],1});

    while (!pq.empty()) {
        auto [dst,cur]=pq.top(); pq.pop();
        if (abs(dst-D[cur])>eps) continue;
        
        for (auto [nxt,cst]:G[cur]) {
            if (D[nxt]>D[cur]+cst+eps) {
                D[nxt]=D[cur]+cst;
                pq.push({D[nxt],nxt});
            }
        }
    }
    
    cout<<(ll)(D[N]*1000.0);
    
    return 0;
}