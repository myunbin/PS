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
const int MAX = 10101; // PLZ CHK!

int main() {
    fio();
    int n,m,k;
    cin>>n>>m>>k;

    vector<int> s(k);
    for (int &x:s) cin>>x;

    vector<pii> g[MAX];
    for (int i=0; i<m; i++) {
        int u,v,w; cin>>u>>v>>w;
        g[u].pb({v,w}), g[v].pb({u,w});
    }

    auto djk=[&](int st) {
        vector<int> d(n+1,INF);
        priority_queue<pii,vector<pii>,greater<pii>> pq;

        d[st]=0;
        pq.push({d[st], st});
        while (!pq.empty()) {
            auto [dst, cur]=pq.top(); pq.pop();
            if (dst!=d[cur]) continue;
            
            for (auto [nxt,cst]:g[cur]) {
                if (d[nxt]>d[cur]+cst) {
                    d[nxt]=d[cur]+cst;
                    pq.push({d[nxt],nxt});
                }
            }
        }

        return d;
    };

    vector<vector<int>> d;
    for (int i=0; i<k; i++) d.pb(djk(s[i]));

    vector<int> pi, iss(n+1,0);
    for (int i=0; i<k; i++) pi.pb(i), iss[s[i]]=1;

    int ans=INF;
    do {
        int sum=0;
        for (int i=0; i<k-1; i++) {
            sum+=d[pi[i]][s[pi[i+1]]];
        }
        for (int i=1; i<=n; i++) {
            if (iss[i]) continue;
            ans=min(ans, sum+d[pi[0]][i]+d[pi[k-1]][i]);
        }

    } while (next_permutation(all(pi)));

    cout<<ans;
    return 0;
}