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

int N,M,A[MAX][MAX],P[MAX];
vector<int> G[MAX];

int fd(int a) {
    if (a==P[a]) return a;
    return P[a]=fd(P[a]);
}

int mg(int a, int b) {
    a=fd(a), b=fd(b);
    if (a==b) return 0;
    P[b]=a; return 1;
}

int main() {
    fio();
    for (int i=0; i<MAX; i++) P[i]=i;

    cin>>N;
    while (1) {
        int u,v; cin>>u>>v;
        if (u==-1 && v==-1) break;

        A[u][v]=A[v][u]=1;
        M++;
    }

    if (M==N*(N-1)/2) {
        cout<<1<<endl;
        for (int i=1; i<=N; i++) cout<<i<<sp; cout<<-1<<endl;
        cout<<-1<<endl;
        return 0;
    }

    for (int i=1; i<=N; i++) {
        vector<int> op;
        for (int j=1; j<=N; j++) {
            if (i==j || A[i][j]) continue;
            op.pb(j);
        }
        for (int j=1; j<sz(op); j++) {
            mg(op[j-1],op[j]);
        }
    }

    int cnt=0;
    for (int i=1; i<=N; i++) {
        if (P[i]==i) cnt++;
    }

    if (cnt!=2) {
        cout<<-1;
        return 0;
    }

    int p=fd(1),q;
    for (int i=1; i<=N; i++) {
        if (fd(i)!=fd(1)) {
            q=fd(i);
            break;
        }
    }

    vector<int> a,b;
    for (int i=1; i<=N; i++) {
        if (fd(i)==p) a.pb(i);
        else b.pb(i);
    }

    for (int x:a) {
        for (int y:a) {
            if (x==y || A[x][y]) continue;
            cout<<-1;
            return 0;
        }
    }
    for (int x:b) {
        for (int y:b) {
            if (x==y || A[x][y]) continue;
            cout<<-1;
            return 0;
        }
    }

    cout<<1<<endl;
    for (int x:a) cout<<x<<sp; cout<<-1<<endl;
    for (int x:b) cout<<x<<sp; cout<<-1<<endl;
    return 0;
}