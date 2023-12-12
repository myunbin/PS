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

int N,BA[MAX],FA[MAX];
array<int,3> B[MAX],F[MAX];
map<int,set<pii>> BM,FM;

int main() {
    fio();
    cin>>N;

    for (int i=1; i<=N; i++) cin>>B[i][0];
    for (int i=1; i<=N; i++) cin>>B[i][1], B[i][2]=i;

    for (int i=1; i<=N; i++) cin>>F[i][0];
    for (int i=1; i<=N; i++) cin>>F[i][1], F[i][2]=i;

    sort(B+1,B+N+1,[](auto a, auto b){
        return a[0]<b[0];
    });
    sort(F+1,F+N+1,[](auto a, auto b){
        return a[0]<b[0];
    });

    for (int i=1; i<=N; i++) {
        BM[B[i][0]].insert({B[i][1],B[i][2]});
        FM[F[i][0]].insert({F[i][1],F[i][2]});
    }
    // map[price] -> {height, index};
    
    for (int i=1; i<=N; i++) {
        int bp=B[i][0], fp=F[i][0];
        if (sz(BM[bp])<sz(FM[fp])) {
            auto [bh,bi]=*BM[bp].begin();
            BA[i]=bi;
            
            auto it=FM[fp].lb(pii{bh,-1});
            if (it==FM[fp].begin()) {
                cout<<"impossible";
                return 0;
            }
            
            auto [fh,fi]=*(--it);
            FA[i]=fi;

            BM[bp].erase(BM[bp].begin());
            FM[fp].erase(it);
        }
        else {
            auto [fh,fi]=*FM[fp].begin();
            FA[i]=fi;

            auto it=BM[bp].ub(pii{fh,INF});
            if (it==BM[bp].end()) {
                cout<<"impossible";
                return 0;
            }

            auto [bh,bi]=*it;
            BA[i]=bi;

            BM[bp].erase(it);
            FM[fp].erase(FM[fp].begin());
        }
    }

    for (int i=1; i<=N; i++) cout<<BA[i]<<sp; cout<<endl;
    for (int i=1; i<=N; i++) cout<<FA[i]<<sp;

    return 0;
}