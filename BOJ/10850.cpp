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
const int MAX = 1000; // PLZ CHK!

int N,V[2*MAX+10],A[2*MAX+10],B[2*MAX+10];
vector<int> G[2*MAX+10];

int dfs(int cur) {
    V[cur]=1;
    for (int nxt:G[cur]) {
        if (B[nxt]==-1 || !V[B[nxt]]&&dfs(B[nxt])) {
            A[cur]=nxt;
            B[nxt]=cur;
            return 1;
        }
    }
    return 0;
}

int main() {
    fio();
    cin>>N;
    for (int i=0; i<N; i++) {
        int K; cin>>K;
        while (K--) {
            int x; cin>>x;
            G[i].pb(MAX+x);
        }
    }

    int M=0;
    fill(A,A+2*MAX+10,-1),fill(B,B+2*MAX+10,-1);

    for (int i=0; i<N; i++) {
        if (A[i]==-1) {
            fill(V,V+2*MAX+10,0);
            M+=dfs(i);
        }
    }

    cout<<N-M;
    return 0;
}