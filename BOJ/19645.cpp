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

const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 51; // PLZ CHK!

int main() {
    fio();
    int n;
    cin>>n;
    int a[MAX]={0};
    for (int i=1; i<=n; i++) cin>>a[i];

    bool d[MAX][MAX*MAX][MAX*MAX]={0};
    d[0][0][0]=1;
    int sum=0, ans=0;
    for (int i=1; i<=n; i++) {
        sum+=a[i];
        for (int x=0; x<=sum; x++) {
            for (int y=0; y<=sum; y++) {
                d[i][x][y]=d[i-1][x][y];
                if (x-a[i]>=0) d[i][x][y]|=d[i-1][x-a[i]][y];
                if (y-a[i]>=0) d[i][x][y]|=d[i-1][x][y-a[i]];
                
                int t=sum-(x+y);
                if (d[i][x][y] && t<=x && t<=y) ans=max(ans,t);
            }
        }
    }
    cout<<ans;
    return 0;
}