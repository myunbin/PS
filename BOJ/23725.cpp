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
const int MAX = 55; // PLZ CHK!

int N,B[MAX],D[2][MAX*MAX/2][MAX*MAX/2],ans,sum;

void solve() {
    cin>>N;

    if (N==0) exit(0);

    memset(B,0,sizeof B);
    memset(D,0,sizeof D);
    ans=0, sum=0;

    for (int i=1; i<=N; i++) {
        cin>>B[i];
        sum+=B[i];
    }

    D[0][0][0]=1;
    for (int i=1; i<=N; i++) {
        for (int x=0; x<=sum/2; x++) {
            for (int y=0; y<=sum/2; y++) {
                D[i%2][x][y]=D[(i-1)%2][x][y];
                if (x-B[i]>=0) D[i%2][x][y]|=D[(i-1)%2][x-B[i]][y];
                if (y-B[i]>=0) D[i%2][x][y]|=D[(i-1)%2][x][y-B[i]];

                if (D[i%2][x][y]) {
                    ans=max(ans, min(x,min(y,sum-x-y)));
                }
            }
        }
    }
    
    cout<<ans<<endl;
}

int main() {
    fio();
    while (1) solve();
    return 0;
}