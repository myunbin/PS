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
const int MAX = 16; // PLZ CHK!

int n,a[MAX];
int d[81][81]={0};

int f(int b, int s) {
    int cnt;
    if (s) cnt=__builtin_popcount(b);
    else cnt=n-__builtin_popcount(b);

    memset(d,0,sizeof d);
    d[0][0]=1;

    int ret=0;
    for (int i=0; i<n; i++) {
        bool ok=b&(1<<i);
        if (ok==s) {
            for (int x=cnt*5; x>=0; x--) {
                for (int y=cnt*5; y>=0; y--) {
                    // if (x-a[i]<0 && y-a[i]<0) continue;
                    if (x-a[i]>=0) d[x][y]|=d[x-a[i]][y];
                    if (y-a[i]>=0) d[x][y]|=d[x][y-a[i]];
                    if (x && x==y && d[x][y]) ret=max(ret, x);
                }
            }   
        }
    }

    return ret;
}

int main() {
    fio();
    
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];

    int ans=0;
    for (int i=0; i<(1<<n); i++) {
        int c=__builtin_popcount(i);
        if (c<2 || n-c<2) continue;

        int s1=0, s2=0;
        for (int j=0; j<n; j++) {
            if (i&(1<<j)) s1++;
            else s2++;
        }
        if (s1>s2) continue;

        int mx1=f(i,1), mx2=f(i,0);
        ans=max(ans, mx1*mx2);
    }

    cout<<(!ans?-1:ans);
    return 0;
}