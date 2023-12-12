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
const int MAX = 1010; // PLZ CHK!

int N,M;
string A[MAX];

int t[MAX][MAX],p[MAX*MAX];

int fd(int a) {
    if (a==p[a]) return a;
    return p[a]=fd(p[a]);
}

int mg(int a, int b) {
    a=fd(a), b=fd(b);
    if (a==b) return 0;
    p[b]=a; return 1;
}

int pr[MAX*MAX];
vector<int> G[MAX*MAX];

int ff(int i, int j) { return i*M+j; }
pii gg(int x) {return {x/M,x%M}; }

ll d[MAX*MAX];

void dfs(int cur) {
    d[cur]=1;    
    for (int nxt:G[cur]) {
        dfs(nxt);
        d[cur]=(d[cur]*d[nxt])%MOD;
    }
    d[cur]++;
}

int main() {
    fio();

    cin>>N>>M;
    for (int i=0; i<N; i++) cin>>A[i];

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            t[i][j]=i*M+j;
            p[t[i][j]]=t[i][j];
        }
    }

    fill(pr,pr+MAX*MAX,-1);
    for (int i=N-1; i>=0; i--) {
        for (int j=1; j<M; j++) {
            if (A[i][j]=='.' && A[i][j-1]=='.') mg(t[i][j], t[i][j-1]);
        }

        if (i==N-1) continue;
        for (int j=0; j<M; j++) {
            if (A[i][j]=='.' && A[i+1][j]=='.') {
                if (pr[fd(ff(i+1,j))]==-1) pr[fd(ff(i+1,j))]=ff(i,j);
                else mg(ff(i,j), pr[fd(ff(i+1,j))]);
            }
        }
    }

    set<pii> E;
    for (int i=0; i<N-1; i++) {
        for (int j=0; j<M; j++) {
            if (A[i][j]=='.' && A[i+1][j]=='.') {
                E.insert({fd(ff(i,j)), fd(ff(i+1,j))});
            }
        }
    }

    for (auto [u,v]:E) G[u].pb(v);
    
    ll ans=1;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (A[i][j]=='.' && p[ff(i,j)]==ff(i,j) && d[ff(i,j)]==0) {
                dfs(ff(i,j));
                ans=(ans*d[ff(i,j)])%MOD;
            }
        }
    }

    cout<<ans;
    return 0;
}