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
const int MAX = 505050; // PLZ CHK!

int N,Q,X[MAX];
set<int> S[MAX];

void mg(int a, int b) {
    int u=X[a], v=X[b];
    if (sz(S[u])<sz(S[v])) {
        for (int x:S[u]) S[v].insert(x);
        S[u].clear();
        X[a]=v, X[b]=u;
    }
    else {
        for (int x:S[v]) S[u].insert(x);
        S[v].clear();
        X[a]=u, X[b]=v;
    }
}

int main() {
    fio();
    for (int i=0; i<MAX; i++) X[i]=i;

    cin>>N>>Q;
    for (int i=1; i<=N; i++) {
        int n; cin>>n;
        while (n--) {
            int x; cin>>x;
            S[i].insert(x);
        }
    }

    while (Q--) {
        int x; cin>>x;
        if (x==1) {
            int a,b; cin>>a>>b;
            mg(a,b);
        }   
        else {
            int a; cin>>a;
            cout<<sz(S[X[a]])<<endl;
        }
    }

    return 0;
}