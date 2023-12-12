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
const int MAX = 105; // PLZ CHK!

int N,M,S1,S2,S3,T1,T2,T3;
ll D[MAX][MAX][MAX],E[MAX][MAX];

ll go(int i, int j, int k) {
    if (i==T1 && j==T2 && k==T3) return 0;
    if (i>T1 || j>T2 || k>T3) return -LINF;
    if (i==S2||i==S3||j==S1||j==S3||k==S1||k==S2) return -LINF;

    ll &ret=D[i][j][k];
    if (ret!=-1) return ret;

    ret=-LINF;
    int mx=max({i,j,k})+1;
    for (int l=mx; l<=N; l++) {
        if (E[i][l]>-1) ret=max(ret, E[i][l]+go(l,j,k));
        if (E[j][l]>-1) ret=max(ret, E[j][l]+go(i,l,k));
        if (E[k][l]>-1) ret=max(ret, E[k][l]+go(i,j,l));
    }
    
    return ret;
}

void solve() {
    memset(D,-1,sizeof D);
    memset(E,-1,sizeof E);
    cin>>N>>M>>S1>>S2>>S3>>T1>>T2>>T3;

    E[0][S1]=E[0][S2]=E[0][S3]=0;
    for (int i=0; i<M; i++) {
        int u,v,w; cin>>u>>v>>w;
        E[u][v]=w;
    }

    cout<<max(0ll, go(0,0,0))<<endl;
}

int main() {
    fio();
    int T;
    cin>>T;
    while (T--) solve();

    return 0;
}