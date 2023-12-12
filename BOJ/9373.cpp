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

int N,p[MAX];
double W;

int fd(int a) {
    if (a==p[a]) return a;
    return p[a]=fd(p[a]);
}

int mg(int a, int b) {
    a=fd(a), b=fd(b);
    if (a==b) return 0;
    p[b]=a; return 1;
}

void solve() {
    for (int i=0; i<MAX; i++) p[i]=i;

    cin>>W>>N;
    const int S=N,E=N+1;

    vector<array<double,3>> C(N);
    for (auto &[x,y,r]:C) cin>>x>>y>>r;

    vector<tuple<double,int,int>> ed;
    ed.pb({W,S,E});
    for (int i=0; i<N; i++) {
        auto [ax,ay,ar]=C[i];
        ed.pb({max(0.0,ax-ar),S,i});
        ed.pb({max(0.0,W-ax-ar),E,i});

        for (int j=0; j<i; j++) {
            auto [bx,by,br]=C[j];
            double d=sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by))-ar-br;
            ed.pb({max(0.0,d),i,j});
        }
    }

    sort(all(ed), [](auto a, auto b){
        auto [aw,au,av]=a; auto [bw,bu,bv]=b;
        return aw<bw;
    });

    cout<<fixed;
    cout.precision(10);
    const double eps=1e-9;
    for (auto [w,u,v]:ed) {
        mg(u,v);
        if (fd(S)==fd(E)) {
            if (w<eps) cout<<0<<endl;
            else cout<<w/2.0<<endl;
            break;
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