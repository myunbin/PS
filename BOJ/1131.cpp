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
const int MAX = 3.2*1e6; // PLZ CHK!

int A,B,K,V[MAX],D[MAX],F[MAX];
int pw(int x) {
    int ret=1;
    for (int i=0; i<K; i++) ret*=x;
    return ret;
}

int nv(int c) {
    int ret=0;
    while (c) {
        ret+=pw(c%10);
        c/=10;
    }
    return ret;
}

bool C[MAX];
void dfs(int cur) {
    V[cur]=1;
    D[cur]=cur;
    int nxt=nv(cur);

    if (cur==nxt) {
        C[cur]=1;
        F[cur]=1;
        return;
    }

    if (V[nxt]) {
        D[cur]=min(D[cur],D[nxt]);
        if (!F[nxt]) C[cur]=1;
        return;
    }

    dfs(nxt);
    D[cur]=min(D[cur],D[nxt]);
    F[cur]=1;
}

void dfs2(int cur) {
    V[cur]=1;
    int nxt=nv(cur);

    if (V[nxt]) {
        D[cur]=min(D[cur],D[nxt]);
        return;
    }

    dfs2(nxt);
    D[cur]=min(D[cur],D[nxt]);
}

int main() {
    fio();
    cin>>A>>B>>K;

    ll ans=0;
    for (int i=A; i<=B; i++) dfs(i);

    memset(V,0,sizeof V);
    for (int i=A; i<=B; i++) {
        // if (C[i]) cout<<i<<sp;
        if (C[i] && !V[i]) {
            int mn=D[i];
            for (int x=i; nv(x)!=i; x=nv(x)) mn=min(mn,D[x]), cout<<x<<sp;
            for (int x=i; nv(x)!=i; x=nv(x)) D[x]=mn,V[x]=1;
        }
    }

    // for (int i=A; i<=B; i++) {
    //     dfs2(i);
    //     ans+=D[i];
    // }
    
    // cout<<ans;
    return 0;
}