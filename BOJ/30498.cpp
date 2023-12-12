#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast")
// #pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")

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

int N;
vector<int> G[MAX];
ll D[MAX][MAX],S[MAX];
// ll E[MAX][MAX];

void dfs(int cur) {
    S[cur]=1;
    for (int nxt:G[cur]) {
        dfs(nxt);
        S[cur]+=S[nxt];
    }

    vector<vector<ll>> E(sz(G[cur])+1,vector<ll>(S[cur]+1));

    D[cur][0]=D[cur][1]=1;
    int csz=sz(G[cur]);


    for (int i=0; i<csz; i++) E[i][0]=E[i][1]=1;
    for (int c=2; c<=S[cur]; c++) E[0][c]=D[G[cur][0]][c-1];

    if (csz==0) return;

    int sz=1+S[G[cur][0]];
    for (int i=1; i<csz; i++) {
        int j=G[cur][i];
        sz+=S[j];
        for (int c=2; c<=sz; c++) {
            E[i][c]=0;
            for (int x=1; x<=c; x++) {
                E[i][c]=(E[i][c]+E[i-1][x]*D[j][c-x]%MOD)%MOD;
            }
        }
    }
    
    for (int c=2; c<=S[cur]; c++) D[cur][c]=E[csz-1][c];
}

int main() {
    fio();
    cin>>N;
    for (int i=1; i<N; i++) {
        int p; cin>>p;
        G[p].pb(i);
    }

    dfs(0);

    for (int k=1; k<=N; k++) {
        ll ans=0;
        for (int i=0; i<N; i++) ans=(ans+D[i][k])%MOD;
        cout<<ans<<endl;
    }

    return 0;
}