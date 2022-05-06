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
const int MAX = 1010; // PLZ CHK!

int n,k;
int nxt[MAX], ii[MAX], sz[MAX], p[MAX];
pii mm[MAX];
vector<int> g[MAX];
bool v[MAX],f[MAX];
vector<vector<int>> cy;

void cmp(int cur, int idx) {
    v[cur]=1;
    ii[cur]=idx;
    sz[idx]++;
    for (int nxt:g[cur]) {
        if (v[nxt]) continue;
        cmp(nxt,idx);
    }
}
void dfs(int cur) {
    v[cur]=1;
    if (v[nxt[cur]]) {
        if (!f[nxt[cur]]) {
            vector<int> t;
            for (int i=cur;; i=p[i]) {
                t.pb(i);
                mm[ii[cur]].F++;
                if (i==nxt[cur]) break;
            }
            cy.pb(t);
        }
    }
    else {
        p[nxt[cur]]=cur;
        dfs(nxt[cur]);
    }
    f[cur]=1;
}
int main() {
    fio();
    cin>>n>>k;
    for (int i=1; i<=n; i++) {
        int x; cin>>x;
        nxt[i]=x;
        g[i].pb(x), g[x].pb(i);
    }

    int c=1;
    for (int i=1; i<=n; i++) {
        if (!v[i]) cmp(i,c++);
    }
    memset(v,0,sizeof v);
    
    for (int i=1; i<=n; i++) {
        if (!v[i]) dfs(i);
    } 
    
    for (int i=1; i<c; i++) mm[i].S=sz[i];

    int d[MAX][MAX]={0};
    d[0][0]=1;
    for (int i=1; i<c; i++) {
        for (int j=MAX-1; j>=0; j--) d[i][j]=d[i-1][j];
        for (int j=mm[i].F; j<=mm[i].S; j++) {
            for (int k=MAX-1; k>=j; k--) {
                d[i][k]|=d[i-1][k-j];
            }
        }
    }

    for (int i=k; i>=0; i--){ 
        if (d[c-1][i]) {
            cout<<i;
            break;
        }
    }
    return 0;
}