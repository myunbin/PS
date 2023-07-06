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

string s;
int r;

vector<int> ans(3);

void go(string cur, vector<int> cr, vector<int> pr) {
    if (sz(cur)==2) {
        int cnt=0;
        for (int i=1; i<=r; i++) if (cr[i]!=-1) cnt++;
        ans[cnt]++;
        return;
    }

    int sz=sz(cur);
    vector<int> nr(r+1,-1), cp(sz);
    vector<vector<int>> np(sz);
    for (int i=1; i<=r; i++) {
        if (cr[i]==-1) continue;
        cp[cr[i]]=i;
    }
    
    if (cp[0]) np[1].pb(cp[0]);
    if (cp[sz-2]) np[sz-3].pb(cp[sz-2]);
    if (cp[sz-1]) np[sz-2].pb(cp[sz-1]);
    for (int i=1; i<sz-2; i++) {
        if (!cp[i]) continue;
        if (cur[i]=='W') np[i-1].pb(cp[i]);
        if (cur[i]=='B') np[i+1].pb(cp[i]);
        if (cur[i]=='R') {
            if (pr[cp[i]]==-1) np[i-1].pb(cp[i]);
            else np[pr[i]].pb(cp[i]);
        }
    }
    
    for (int i=0; i<sz; i++) {
        if (sz(np[i])==1) {
            nr[np[i][0]]=i;
        }
    }

    cur.pop_back();
    go(cur, nr, pr);
}

int main() {
    fio();
    cin>>s>>r;

    int n=sz(s);
    vector<int> pos(n,0);
    for (int i=0; i<r; i++) pos[i]=1;

    int mo=0;
    do {
        vector<int> cr(r+1), pr(r+1,-1);
        int x=1;
        for (int i=0; i<n; i++) {
            if (pos[i]) {
                cr[x++]=i;
            }
        }
        go(s,cr,pr);
        mo++;
    } while (prev_permutation(all(pos)));

    cout<<fixed; cout.precision(15);
    double res=(1.0*ans[1]+2.0*ans[2])/(1.0*mo);
    cout<<res;

    return 0;
}