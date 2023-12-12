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
const int MAX = 101010; // PLZ CHK!

int N,M,Q;
array<int,3> E[MAX];
pii qry[MAX], ans[MAX];
int p[MAX], le[MAX], ri[MAX], sz[MAX];

int fd(int a) {
    if (a==p[a]) return a;
    return p[a]=fd(p[a]);
}

int mg(int a, int b) {
    a=fd(a), b=fd(b);
    if (a==b) return 0;

    sz[a]+=sz[b], sz[b]=0;
    p[b]=a;
    return 1;
}

vector<int> C[MAX];

int main() {
    fio();

    cin>>N>>M;
    for (int i=0; i<M; i++) {
        cin>>E[i][0]>>E[i][1]>>E[i][2];
    }
    sort(E,E+M, [](auto a, auto b){
        return a[2]<b[2];
    });

    
    cin>>Q;
    for (int i=0; i<Q; i++) {
        cin>>qry[i].F>>qry[i].S;
        ans[i]={INF,INF};
    }

    fill(le,le+MAX,1), fill(ri,ri+MAX,M);
    while (1) {
        for (int i=1; i<=M; i++) C[i].clear();
        bool ok=0;

        for (int i=0; i<Q; i++) {
            if (le[i]<=ri[i]) {
                ok=1;
                int md=(le[i]+ri[i])>>1;
                C[md].pb(i);
            }
        }  
        if (!ok) break;

        for (int i=1; i<=N; i++) p[i]=i, sz[i]=1;

        for (int i=1; i<=M; i++) {
            auto [u,v,w]=E[i-1];
            mg(u,v);
            for (int j:C[i]) {
                auto [x,y]=qry[j];
                x=fd(x), y=fd(y);
                if (x==y) {
                    ans[j]={w,sz[x]};
                    ri[j]=i-1;
                }
                else le[j]=i+1;
            }
        }
    }

    for (int i=0; i<Q; i++) {
        if (ans[i].F==INF) cout<<-1<<endl;
        else cout<<ans[i].F<<sp<<ans[i].S<<endl;
    }

    return 0;
}