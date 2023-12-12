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

int N,M;
vector<int> G[MAX],S;
vector<vector<int>> SCC;
int f[MAX],dn[MAX],mn[MAX],sn[MAX],ssz,cnt;

void dfs(int cur) {
    dn[cur]=mn[cur]=cnt++;
    S.pb(cur);

    for (int nxt:G[cur]) {
        if (!dn[nxt]) {
            dfs(nxt);
            mn[cur]=min(mn[cur],mn[nxt]);
        }
        else if (!f[nxt]) mn[cur]=min(mn[cur],dn[nxt]);
    }
    
    if (mn[cur]==dn[cur]) {
        vector<int> cs;
        while (1) {
            int t=S.back(); S.pop_back();
            cs.pb(t);
            f[t]=1, sn[t]=ssz;
            if (t==cur) break;
        }
        ssz++;
        SCC.pb(cs);
    }
}

void init() {
    fill(f,f+MAX,0), fill(dn,dn+MAX,0);
    fill(mn,mn+MAX,0), fill(sn,sn+MAX,0);
    ssz=0, cnt=1;

    for (int i=0; i<MAX; i++) G[i].clear(); S.clear();
    for (auto &V:SCC) V.clear(); SCC.clear();
}

int opp(int x) {return x^1;}

bool solve() {
    cin>>N>>M;
    if (N==0 && M==0) return 0;
    init();

    for (int i=0; i<N; i++) {
        int u,v;
        cin>>u>>v;
        
        u=(u>0?2*u-2:opp(-2*u-2));
        v=(v>0?2*v-2:opp(-2*v-2));

        G[opp(u)].pb(v), G[opp(v)].pb(u);
    }

    for (int i=0; i<2*M; i++) if (!dn[i]) dfs(i);

    bool ok=1;
    for (int i=0; i<2*M; i+=2) {
        if (sn[i]==sn[opp(i)]) {
            ok=0;
            break;
        }
    }

    cout<<ok<<endl;
    return 1;
}

int main() {
    fio();
    while (solve());
    return 0;
}