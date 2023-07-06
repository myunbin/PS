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
const int MAX = 1010; // PLZ CHK!

vector<int> g[MAX];
int dp[MAX];

int main() {
    fio();
    int n,e;
    cin>>n>>e;
    
    vector<pii> q(n+1);
    for (int i=1; i<=n; i++) {
        int d; q[i].F=i;
        cin>>q[i].S>>d;
        while (d--) {
            int x; cin>>x;
            g[i].pb(x);
        }
    }
    sort(all(q), [](pii a, pii b){
        return a.S>b.S;
    });

    int ans=0;
    fill(dp,dp+MAX,-INF);

    
    for (auto [s,x]:q) {
        queue<int> qu;
        vector<int> v(n+1,0), d(n+1,0);
        v[s]=1; qu.push(s);
        
        while (!qu.empty()) {
            int cur=qu.front(); qu.pop();
            for (int nxt:g[cur]) {
                if (v[nxt]) continue;
                v[nxt]=1;
                d[nxt]=d[cur]+1;
                qu.push(nxt);
            }
        }

        dp[s]=x;
        for (int i=1; i<=n; i++) {
            if (i==s || !v[i]) continue;
            dp[s]=max(dp[s], dp[i]+x-e*d[i]);
        }
        ans=max(ans, dp[s]);
    }
       
    cout<<ans;
    
    return 0;
}