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

int N,M,dn[MAX],mn[MAX],c,isa[MAX];
vector<int> G[MAX];
vector<pii> S;
vector<vector<int>> B;

void dfs(int cur, int prv) {
    dn[cur]=mn[cur]=c++;

    int ch=0;
    for (int nxt:G[cur]) {
        if (nxt==prv) continue;
        
        if (dn[cur]>dn[nxt]) S.pb({cur,nxt});

        if (dn[nxt]>0) mn[cur]=min(mn[cur],dn[nxt]);
        else {
            ch++;
            dfs(nxt,cur);
            mn[cur]=min(mn[cur],mn[nxt]);
            if (mn[nxt]>=dn[cur]) {
                if (prv) isa[cur]=1;

                vector<int> bcc;
                while (!S.empty() && S.back()!=pii(cur,nxt)) {
                    bcc.pb(S.back().F), bcc.pb(S.back().S);
                    S.pop_back();
                }
                bcc.pb(S.back().F), bcc.pb(S.back().S); S.pop_back();

                cmprs(bcc);
                B.pb(bcc);
            }
        }
    }

    if (!prv && ch>1) isa[cur]=1;
}

bool solve(int T) {
    cin>>M;
    if (M==0) return 0;

    N=0,c=1; S.clear();
    for (int i=0; i<MAX; i++) dn[i]=mn[i]=isa[i]=0, G[i].clear();
    for (auto &v:B) v.clear(); B.clear();

    for (int i=0; i<M; i++) {
        int u,v; cin>>u>>v;
        G[u].pb(v),G[v].pb(u);
        N=max(N,u), N=max(N,v);
    }

    for (int i=1; i<=N; i++) {
        if (dn[i]==0) dfs(i,0);
    }

    ll ans=1,res=0;
    for (auto &b:B) {
        int a=0;
        for (int x:b) {
            if (isa[x]) a++;
        }
        if (a==1) res++, ans*=1ll*(sz(b)-1);
    }

    cout<<"Case "<<T<<": ";
    if (res) cout<<res<<sp<<ans<<endl;
    else cout<<2<<sp<<1ll*N*(N-1)/2<<endl;

    return 1;
}

int main() {
    fio();
    for (int i=1; solve(i); i++);
    return 0;
}