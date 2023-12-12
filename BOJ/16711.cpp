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

int N,M;
ll A[MAX][MAX];

int main() {
    fio();
    cin>>N>>M;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) cin>>A[i][j];
    }

    ll s=0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            if ((i+j)&1) s+=A[i][j];
            else s-=A[i][j];
        }
    }
    if (s) {
        cout<<-1;
        return 0;
    }

    vector<array<ll,5>> ans;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<M; j++) {
            ll t=1ll*(j-1)*1e6;
            ans.pb({i,j,i,j+1,t});
            A[i][j]+=t;
            A[i][j+1]+=t;
        }
        if (i<N) {
            ll t=1ll*i*1e9;
            ans.pb({i,M,i+1,M,t});
            A[i][M]+=t;
            A[i+1][M]+=t;
        }
    }
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<M; j++) {
            ans.pb({i,j,i,j+1,-A[i][j]});
            A[i][j+1]-=A[i][j];
            A[i][j]=0;
        }
    }

    for (int i=1; i<N; i++) {
        ans.pb({i,M,i+1,M,-A[i][M]});
        A[i+1][M]-=A[i][M];
        A[i][M]=0;
    }

    cout<<sz(ans)<<endl;
    for (auto [a,b,c,d,e]:ans)
        cout<<a<<sp<<b<<sp<<c<<sp<<d<<sp<<e<<endl;

    return 0;
}