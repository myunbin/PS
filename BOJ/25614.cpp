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
const int MAX = 101010; // PLZ CHK!

int n;
string m;
vector<int> p;
vector<vector<int>> c;

vector<int> vst;
void dfs(int cur) {
    vst[cur]=1;
    c.back().pb(cur);
    int nxt=p[cur];
    if (!vst[nxt]) dfs(nxt); 
}

int main() {
    fio();

    cin>>n>>m;
    p.resize(n+1), vst.resize(n+1);
    for (int i=1; i<=n; i++) cin>>p[i];

    unordered_set<int> sz;
    for (int i=1; i<=n; i++) {
        if (!vst[i]) {
            vector<int> t;
            c.pb(t);
            dfs(i);
            sz.insert(sz(c.back()));
        }
    }

    vector<int> sf;
    
    reverse(all(m));

    unordered_map<int,int> szm;
    for (int s:sz) {
        int md=0, mul=1;
        for (int i=0; i<sz(m); i++) {
            int x=m[i]-'0';
            md=(md+((x%s)*(mul%s))%s)%s;
            mul*=10;
            mul%=s;
        }
        szm[s]=md;
    }

    vector<int> ans(n+1);
    for (int i=0; i<sz(c); i++) {
        int s=sz(c[i]);
        int x=szm[s];

        for (int j=0; j<sz(c[i]); j++) {
            int y=c[i][j];
            ans[y]=c[i][(j+x)%s];
        }
    }
    
    for (int i=1; i<=n; i++) cout<<ans[i]<<sp;

    return 0;
}