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
const int MAX = 2020; // PLZ CHK!

int N,M;
ll A[MAX][MAX],P[MAX][MAX],ans[MAX][MAX];

ll f(int x1, int y1, int x2, int y2) {
    x1=max(1,x1),y1=max(1,y1);
    return P[x2][y2]-P[x2][y1-1]-P[x1-1][y2]+P[x1-1][y1-1];
}

int main() {
    fio();
    cin>>N>>M;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin>>A[i][j];
            A[i][j]*=-1;
        }
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            int x=i+M/2, y=j+M/2;

            P[x][y]=P[x-1][y]+P[x][y-1]-P[x-1][y-1];
            ll t=f(x-M+1,y-M+1,x,y);
            ans[x][y]=max(0ll,A[i][j]-t);
            P[x][y]+=ans[x][y];
        }
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cout<<ans[i][j]<<sp;
        } cout<<endl;
    }

    return 0;
}   