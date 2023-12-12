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
const int MAX = 20202; // PLZ CHK!

int N,P[MAX],D[MAX],X[MAX];

int fd(int a) {
    if (a==P[a]) return a;
    int p=fd(P[a]);
    D[a]+=D[P[a]];
    P[a]=p;
    return p;
}

void mg(int a, int b) {
    P[a]=b;
    D[a]+=abs(a-b)%1000;
}

void solve() {
    for (int i=0; i<MAX; i++) P[i]=i,D[i]=0,X[i]=i;

    cin>>N;
    while (1) {
        char c; cin>>c;
        if (c=='O') break;
        if (c=='E') {
            int x; cin>>x; fd(x);
            cout<<D[x]<<endl;
        }
        if (c=='I') {
            int x,y; cin>>x>>y;
            mg(x,y);
        }
    }
}

int main() {
    fio();
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}