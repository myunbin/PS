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
const int MAX = 555; // PLZ CHK!

int main() {
    fio();
    int n; ll k;
    cin>>n>>k;
    
    int a[MAX][MAX]={0}, v[MAX][MAX]={0};
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin>>a[i][j];
        }
    }
    
    pii cur={1,2};
    vector<int> ans;
    ans.pb(0), ans.pb(1), ans.pb(2);
    v[cur.F][cur.S]=1;

    ll x,y;
    while (1) {
        pii nxt={cur.S, a[cur.S][cur.F]};
        int nc=v[cur.F][cur.S]+1;
        if (v[nxt.F][nxt.S]) {
            x=v[nxt.F][nxt.S], y=nc-v[nxt.F][nxt.S];
            break;
        }
        ans.pb(a[cur.S][cur.F]);
        v[nxt.F][nxt.S]=nc;
        cur=nxt;
    }
    if (k<x) cout<<ans[k];
    else {
        k-=((k-x)/y)*y;
        cout<<ans[k];
    }
    return 0;
}