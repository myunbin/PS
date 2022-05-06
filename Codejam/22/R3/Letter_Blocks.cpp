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

string dfs(int cur, vector<vector<int>> &g, vector<string> &s) {
    string ret=s[cur];
    for (int nxt:g[cur]) {
        ret+=dfs(nxt, g, s);
    }
    return ret;
}
void solve() {
    int n;
    cin>>n;
    vector<string> s,tt;
    vector<int> xx(30,0);
    for (int i=0; i<n; i++) {
        string x; cin>>x;
        bool f=1;
        for (int j=0; j<sz(x)-1; j++) {
            if (x[j]!=x[j+1]) {
                f=0;
                s.pb(x);
                break;
            }
        }
        if (f) {
            xx[x[0]-'A']+=sz(x);
        }
    }

    for (string &x:s) {
        if (xx[x[0]-'A']) {
            for (int i=0; i<xx[x[0]-'A']; i++) {
                x=x[0]+x;
            }
            xx[x[0]-'A']=0;
        }
        if (xx[x.back()-'A']) {
            for (int i=0; i<xx[x.back()-'A']; i++) {
                x=x+x.back();
            }
            xx[x.back()-'A']=0;
        }
    }

    int sz=sz(s);
    vector<vector<int>> g(sz);
    vector<int> ind(sz);
    for (int i=0; i<sz; i++) {
        for (int j=0; j<sz; j++) {
            if (i==j) continue;
            if (s[i].back()==s[j][0]) {
                g[i].pb(j);
                ind[j]++;
            }
        }
    }

    vector<int> q;
    for (int i=0; i<sz; i++) {
        if (!ind[i]) {
            q.pb(i);
        }
    }

    string ans;
    for (int x:q) {
        ans+=dfs(x,g,s);
    }    
    if (sz(ans)==0) {
        cout<<"IMPOSSIBLE\n";
        return;
    }
    for (int i=0; i<30; i++) {
        if (xx[i]) {
            for (int j=0; j<xx[i]; j++) {
                ans+=i+'A';
            }
        }
    }

    int p=0;
    vector<int> vv(30,0);
    while (p<sz(ans)) {
        char c=ans[p];
        if (vv[c-'A']) {
            cout<<"IMPOSSIBLE\n";
            return;
        }
        vv[c-'A']=1;
        while (p<sz(ans) && c==ans[p]) {
            p++;
        }
    }
    cout<<ans<<endl;
}

int main() {
    fio();
    int t;
    cin>>t;
    for (int i=1; i<=t; i++) {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}