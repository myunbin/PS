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
const int MAX = 505050; // PLZ CHK!

ll d[MAX];
pii g[MAX];
int s[MAX],in[MAX];

int main() {
    fio();
    ll n; int m;
    cin>>n>>m;
    
    for (int i=1; i<=m; i++) {
        char c; int l,r;
        cin>>c>>l>>r;
        s[i]=(c=='L');
        g[i].F=l, g[i].S=r;
        in[l]++, in[r]++;
    }

    d[1]=n;
    queue<int> q;
    for (int i=1; i<=m; i++) {
        if (!in[i]) {
            q.push(i);
        }
    }

    vector<int> ans(m+1);

    while (!q.empty()) {
        int cur=q.front(); q.pop();
        auto [le,ri]=g[cur];

        if (d[cur]%2) {
            ans[cur]=!s[cur];
            d[le]+=d[cur]/2+(s[cur]==1);
            d[ri]+=d[cur]/2+(s[cur]==0);
        }
        else {
            ans[cur]=s[cur];
            d[le]+=d[cur]/2;
            d[ri]+=d[cur]/2;
        }

        if (--in[le]==0) q.push(le);
        if (--in[ri]==0) q.push(ri);
    }

    for (int i=1; i<=m; i++) cout<<(ans[i]?'L':'R');
    return 0;
}