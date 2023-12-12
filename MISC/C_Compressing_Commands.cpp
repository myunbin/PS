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
const int MAX = 1010101; // PLZ CHK!

char a[MAX];
vector<int> G[MAX];
int N=1,D[MAX],L[MAX],E[MAX];

void dfs0(int cur) {
    if (sz(G[cur])==0) {
        // L[cur]=1;
        D[cur]=0;
        return;
    }

    for (int nxt:G[cur]) {
        dfs0(nxt);
        L[cur]+=L[nxt];
        D[cur]+=D[nxt]+L[nxt];
    }
}

void dfs1(int cur, int prv, int rt) {
    if (cur==rt) E[cur]=D[cur];
    else if (sz(G[cur])==0) E[cur]=INF;
    else E[cur]=E[prv]-2*L[cur]+L[1];

    for (int nxt:G[cur]) {
        dfs1(nxt,cur,rt);
    }
}

unordered_map<string,int> C[MAX];

int main() {
    fio();

    int n;
    cin>>n;

    for (int i=0; i<n; i++) {
        string l;
        cin>>l;
        int cur=1;
        for (int j=1,k=1; j<sz(l); j=k+1,k++) {
            while (k<sz(l) && l[k]!='/') k++;
            string sub=l.substr(j,k-j);
            if (C[cur].find(sub)==C[cur].end()) 
                C[cur][sub]=++N;
            cur=C[cur][sub];
        }
        L[cur]++;
    }

    for (int i=0; i<=N; i++) {
        // cout<<"====="<<i<<"====\n";
        for (auto [s,j]:C[i]) {
            // cout<<s<<sp<<j<<endl;
            G[i].pb(j);
        }
        // cout<<endl;
    }

    dfs0(1);
    dfs1(1,0,1);

    int ans=INF;
    for (int i=1; i<=N; i++) {
        ans=min(ans, E[i]);
    }

    cout<<ans;

    return 0;
}