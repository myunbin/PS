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

int N,M,D[MAX];
pii E[MAX];
vector<int> G[MAX];

int P[MAX],S[MAX];
int fd(int a) {
    if (a==P[a]) return a;
    return P[a]=fd(P[a]);
}

int mg(int a, int b) {
    a=fd(a), b=fd(b);
    if (a==b) return 0;
    S[a]+=S[b], S[b]=0;
    P[b]=a;

    return 1;
}

int main() {
    fio();
    cin>>N>>M;
    for (int i=0; i<M; i++) {
        int u,v; cin>>u>>v;
        E[i]={u,v};
        G[u].pb(v), G[v].pb(u);
        D[u]++,D[v]++;
    }

    set<pii> s;
    for (int i=1; i<=N; i++) s.insert({D[i],i});

    vector<pii> a;
    vector<int> del(N+1,0);
    while (sz(s)) {
        auto [deg,cur]=*s.begin();
        a.pb({deg,cur});

        del[cur]=1;
        for (int nxt:G[cur]) {
            if (!del[nxt]) {
                s.erase({D[nxt],nxt});
                D[nxt]--;
                s.insert({D[nxt],nxt});
            }
        }
        s.erase({D[cur],cur});
    }

    reverse(all(a));
    for (int i=0; i<MAX; i++) P[i]=i, S[i]=1;

    ll ans=0;
    for (auto [deg,cur]:a) {
        del[cur]=0;
        for (int nxt:G[cur]) {
            if (!del[nxt]) {
                mg(cur,nxt);
                int t=fd(cur);
                ans=max(ans, 1ll*deg*S[t]);
            }
        }
    }

    cout<<ans;
    return 0;
}