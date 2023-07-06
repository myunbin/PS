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

vector<int> g[MAX+1010];

int main() {
    fio();
    int n,k,m;
    cin>>n>>k>>m;
    
    
    for (int i=MAX; i<MAX+m; i++) {
        for (int j=0; j<k; j++) {
            int x; cin>>x;
            g[i].pb(x);
            g[x].pb(i);
        }
    }

    queue<int> q;
    int v[MAX+1010]={0}, d[MAX+1010];
    fill(d,d+MAX,INF);
    
    v[1]=1;
    d[1]=0;
    q.push(1);

    while (!q.empty()) {
        int cur=q.front(); q.pop();
        for (int nxt:g[cur]) {
            if (v[nxt]) continue;
            v[nxt]=1;
            d[nxt]=d[cur]+1;
            q.push(nxt);
        }
    }

    cout<<(d[n]==INF?-1:d[n]/2+1);
    return 0;
}