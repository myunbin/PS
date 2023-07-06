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
const int MAX = 252525; // PLZ CHK!

int n,d[MAX],p[MAX][19];
vector<int> g[MAX];

void dfs(int cur, int prv) {
    for (int nxt:g[cur]) {
        if (nxt==prv) continue;
        d[nxt]=d[cur]+1;
        p[nxt][0]=cur;
        dfs(nxt,cur);
    }
}

void init() {
    for (int j = 1; j <= 18; j++) {
		for (int i = 1; i <= n; i++) {
			p[i][j] = p[p[i][j-1]][j-1];
		}
	}
}

int lca(int a, int b) {
    if (d[a]<d[b]) swap(a,b);
    int h=d[a]-d[b];
    
    bitset<20> bs(h);
    for (int i = 0; i < bs.size(); i++) 
        if (bs[i]) a = p[a][i];

    if (a==b) {
        return a;
    }

    for (int i=18; i>=0; i--) {
        if (p[a][i] && p[a][i]!=p[b][i])
            a=p[a][i], b=p[b][i];
    }
    
    return p[a][0];
}

int main() {
    fio();
    cin>>n;
    for (int i=0; i<n-1; i++) {
        int u,v; cin>>u>>v;
        g[u].pb(v), g[v].pb(u);
    }
    
    d[1]=0;
    dfs(1,0);
    init();

    int q; cin>>q;
    while (q--) {
        int op; cin>>op;
        if (op==1) {
            int i,j,k;
            cin>>i>>j>>k;
            
            int ik=lca(i,k), jk=lca(j,k);
            if (ik==k && jk==k) {
                int ij=lca(i,j);
                cout<<(ij!=k?"YES\n":"NO\n");
            }
            else if (ik==k && jk!=k) {
                cout<<"NO\n";
            }
            else if (ik!=k && jk==k) {
                cout<<"NO\n";
            }
            else {
                cout<<"YES\n";
            }
        }
        else {
            int i,j,k,l;
            cin>>i>>j>>k>>l;
            
            if (d[k]<d[l]) swap(k,l);
            
            int ik=lca(i,k), jk=lca(j,k);
            if (ik==k && jk==k) {
                cout<<"YES\n";
            }
            else if (ik==k && jk!=k) {
                cout<<"NO\n";
            }
            else if (ik!=k && jk==k) {
                cout<<"NO\n";
            }
            else {
                cout<<"YES\n";
            }
        }
    }

    return 0;
}