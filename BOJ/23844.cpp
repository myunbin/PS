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

int N,K,d[MAX],s[MAX],p[MAX];
vector<int> G[MAX], H[MAX];

void dfs(int cur, int prv) {
    s[cur]=1;
    H[d[cur]].pb(cur);
    p[cur]=prv;

    for (int nxt:G[cur]) {
        if (nxt==prv) continue;
        d[nxt]=d[cur]+1;
        dfs(nxt, cur);
        s[cur]+=s[nxt];
    }
}

int main() {
    fio();
    cin>>N>>K;
    for (int i=0; i<N-1; i++) {
        int u,v; cin>>u>>v;
        G[u].pb(v), G[v].pb(u);
    }

    dfs(1,0);
    
    int mx=*max_element(d+1,d+N+1), ans=N;

    for (int i=mx; i>=0; i--) {
        sort(all(H[i]), [&](int a, int b){
            return s[a]<s[b];
        });

        // for (int x:H[i]) cout<<"("<<x<<sp<<s[x]<<")"<<sp; cout<<endl;

        for (int j=0; j<max(0,sz(H[i])-K); j++) {
            int x=H[i][j];
            ans-=s[x];
            s[x]=0;
        }
        
        for (int x:H[i]) s[p[x]]=1;
        for (int x:H[i]) s[p[x]]+=s[x];
    }

    cout<<s[1];
    return 0;
}