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

int solve() {
    int n; cin>>n;
    if (n==0) return -1;

    vector<vector<int>> p(n+1,vector<int>(2*n+1));

    for (int i=1; i<=n; i++) {
        for (int j=n-(i-1); j<=n+(i-1); j++) {
            int x; cin>>x;
            p[i][j]=p[i][j-1]+x;
        }
    }

    int ans=-INF;
    for (int i=1; i<=n; i++) {
        for (int j=n-i+1; j<=n+i-1; j+=2) {
            int sum=0;
            for (int k=i, sz=0; k<=n; k++, sz++) { //[k][j-sz, j+sz]
                sum+=p[k][j+sz]-p[k][j-sz-1];
                ans=max(ans, sum);
            }
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=n-(i-2); j<=n+(i-2); j+=2) {
            int sum=0;
            for (int k=i, sz=0; k>=1; k--, sz++) {
                if (j-sz<n-k+1 || j+sz>n+k-1) break;
                sum+=p[k][j+sz]-p[k][j-sz-1];
                ans=max(ans, sum);
            }
        }
    }
    return ans;
}

int main() {
    fio();
    for (int i=1;; i++) {
        int ans=solve();
        if (ans==-1) break;
        cout<<i<<". "<<ans<<endl;
    }
    return 0;
}