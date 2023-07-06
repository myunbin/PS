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
const int MAX = 50505; // PLZ CHK!

typedef pair<int,double> pid;

map<pii,int> m;
vector<pid> g[MAX];

int main() {
    fio();
    int n,f;
    cin>>n>>f;

    int cnt=1;
    m[{0,0}]=cnt++;
    for (int i=0; i<n; i++) {
        int x,y;
        cin>>x>>y;
        m[{x,y}]=cnt++;
    }
    
    for (auto [p,u]:m) {
        auto [x,y]=p;
        for (int dx=-2; dx<=2; dx++) {
            for (int dy=-2; dy<=2; dy++) {
                if (dx==0 && dy==0) continue;

                if (m.find({x+dx, y+dy})!=m.end()) {
                    int v=m[{x+dx, y+dy}];
                    double d=sqrt(1.0*dx*dx+1.0*dy*dy);
                    g[u].pb({v,d});
                }
            }
        }
    }

    vector<double> d(MAX,1.0*INF);
    priority_queue<pdi,vector<pdi>,greater<pdi>> pq;

    d[1]=0.0;
    pq.push({d[1],1});

    const double eps=1e-9;
    while (!pq.empty()) {
        auto [dst,cur]=pq.top(); pq.pop();
        if (abs(dst-d[cur])>eps) continue;

        for (auto [nxt,cst]:g[cur]) {
            if (d[nxt]-d[cur]-cst>eps) {
                d[nxt]=d[cur]+cst;
                pq.push({d[nxt], nxt});
            }
        }
    }

    double ans=1.0*INF;
    for (auto [p,idx]:m) {
        auto [x,y]=p;
        if (y==f && ans-d[idx]>eps) ans=d[idx];
    }

    if (abs(ans-1.0*INF)<eps) cout<<-1;
    else cout<<(int)(ans+0.5);
    return 0;
}