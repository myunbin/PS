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
const int MAX = 4040; // PLZ CHK!

vector<pil> g[MAX];
ll d1[MAX], d2[MAX][2];
int n,m;

typedef tuple<ll,int,int> tli;
typedef pair<ll,int> pli;

void djk1() {
    fill(d1, d1+MAX, LINF);
    d1[1]=0;
    priority_queue<pli,vector<pli>,greater<pli>> pq;
    pq.push({d1[1],1});

    while (!pq.empty()) {
        auto [dst,cur]=pq.top(); pq.pop();
        if (dst!=d1[cur]) continue;

        for (auto [nxt, cst]:g[cur]) {
            if (d1[nxt]>d1[cur]+cst) {
                d1[nxt]=d1[cur]+cst;
                pq.push({d1[nxt],nxt});
            }
        }
    }
}

void djk2() {
    for (int i=0; i<MAX; i++) for (int j=0; j<2; j++) d2[i][j]=LINF;
    d2[1][0]=0;

    priority_queue<tli,vector<tli>,greater<tli>> pq;
    pq.push({d2[1][0], 1, 0});
    while (!pq.empty()) {
        auto [dst, cur, curs]=pq.top(); pq.pop();
        if (dst!=d2[cur][curs]) continue;

        for (auto [nxt,cst]:g[cur]) {
            int nxts=!curs;
            if (d2[nxt][nxts]>d2[cur][curs]+(curs?cst*2:cst/2)) {
                d2[nxt][nxts]=d2[cur][curs]+(curs?cst*2:cst/2);
                pq.push({d2[nxt][nxts], nxt, nxts});
            }
        }
    }
}

int main() {
    fio();
    cin>>n>>m;
    for (int i=0; i<m; i++) {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].pb({v,2*w});
        g[v].pb({u,2*w});
    }

    djk1();
    djk2();

    int ans=0;
    for (int i=2; i<=n; i++) {
        if (d1[i]<min(d2[i][0], d2[i][1])) ans++;
    }

    cout<<ans;
    return 0;
}