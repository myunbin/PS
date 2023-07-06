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
const int MAX = 1010101; // PLZ CHK!

ll f[MAX], d[MAX], ans[MAX];
vector<int> evs[MAX], eve[MAX];

int main() {
    fio();
    int n;
    cin>>n;
    
    f[0]=0, f[1]=1;
    for (int i=2; i<=n; i++) f[i]=(f[i-1]+f[i-2])%MOD;

    int m; cin>>m;
    for (int i=0; i<m; i++) {
        int s,e; cin>>s>>e;
        evs[s].pb(e-s+1), eve[e].pb(e-s+1);
    }

    for (int j=0; j<sz(evs[1]); j++) {
        d[1]+=f[1];
    }
    ans[1]=d[1];
    for (int j=0; j<sz(eve[1]); j++) {
        d[1]-=f[1];
    }

    for (int i=2; i<=n; i++) {
        d[i]=(d[i-1]+d[i-2])%MOD;
        
        for (int j=0; j<sz(evs[i]); j++) {
            d[i]=(d[i]+f[1])%MOD;
        }

        ans[i]=d[i];
        
        for (int j=0; j<sz(eve[i]); j++) {
            int l=eve[i][j];
            d[i]=(d[i]-f[l]+MOD)%MOD;
            d[i-1]=(d[i-1]-f[l-1]+MOD)%MOD;
        }
    }

    for (int i=1; i<=n; i++) cout<<ans[i]<<sp;
    return 0;
}