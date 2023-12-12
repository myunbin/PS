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
const int MAX = 15151; // PLZ CHK!
const int MAXM=1515;

int N,M;
int A[MAX][MAXM];

int main() {
    fio();
    scanf("%d %d",&N,&M);
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%1d",&A[i][j]);
        }
    }

    vector<pii> P;
    for (int j=0; j<M; j++) P.pb({0,j});

    int ans=0;
    for (int i=0; i<N; i++) {
        vector<pii> NP;
        vector<int> z(M,0);
        for (int j=0; j<M; j++) {
            if (A[i][j]=='0') NP.pb({0,j}),z[j]=1;
        }
        for (int j=0; j<M; j++) {
            if (z[P[j].S]) continue;
            NP.pb({P[j].F+1,P[j].S});
        }
        
        P.clear();
        P=NP;
        for (int j=M-1,k=1; j>=0; j--,k++) {
            ans=max(ans, P[j].F*k);
        }
    }

    printf("%d",ans);
    return 0;
}