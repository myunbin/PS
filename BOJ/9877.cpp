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
const int MAX = 505; // PLZ CHK!

struct DD{
    ll x; pii a,b;
    bool operator < (DD o) const {
        return x<o.x;
    }
};

int N,M,T;
ll A[MAX][MAX], le[MAX*MAX], ri[MAX*MAX], ans[MAX*MAX];
vector<pii> qry;
vector<DD> E;
pii p[MAX][MAX];
int s[MAX][MAX];
map<ll,vector<int>> C;

pii fd(pii a) {
    auto [x,y]=a;
    if (p[x][y]==a) return a;
    return p[x][y]=fd(p[x][y]);    
}

int mg(pii a, pii b) {
    a=fd(a), b=fd(b);
    if (a==b) return 0;

    auto [ax,ay]=a; auto [bx,by]=b;
    s[ax][ay]+=s[bx][by], s[bx][by]=0;
    p[bx][by]=a;
    
    return 1;
}



int main() {
    fio();
    cin>>N>>M>>T;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin>>A[i][j];
        }
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            int x; cin>>x;
            if (x) qry.pb({i,j});
        }
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            if (i+1<=N) E.pb({abs(A[i][j]-A[i+1][j]), {i,j}, {i+1,j}});
            if (j+1<=M) E.pb({abs(A[i][j]-A[i][j+1]), {i,j}, {i,j+1}});
        }
    }
    sort(all(E));

    int Q=sz(qry);
    fill(le,le+MAX*MAX,0), fill(ri,ri+MAX*MAX,INF);

    while (1) {
    // for (int o=0;o<5;o++) {
        for (auto &[x,v]:C) v.clear(); C.clear();
        bool ok=0;

        for (int i=0; i<Q; i++) {
            if (le[i]<=ri[i]) {
                ok=1;
                ll md=(le[i]+ri[i])>>1ll;
                C[md].pb(i);
            }
        }

        if (!ok) break;

        for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) p[i][j]={i,j}, s[i][j]=1;

        int i=0,sz=sz(E);
        for (auto [d,v]:C) {
            while (i<sz && E[i].x<=d) {
                mg(E[i].a, E[i].b);
                i++;
            }

            for (int j:v) {
                pii t=qry[j];
                t=fd(t);
                auto [x,y]=t;

                if (s[x][y]>=T) {
                    ans[j]=d;
                    ri[j]=d-1;
                }
                else le[j]=d+1;
            }
        }
    }

    ll res=0;
    for (int i=0; i<Q; i++) {
        res+=ans[i];
    }

    cout<<res;
    return 0;
}