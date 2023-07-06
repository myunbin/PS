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

const int MOD = 9901;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 15; // PLZ CHK!

int n,m;
int d[MAX][1<<MAX];


void gen(int idx, int cur, int nxt, vector<int> &res) {
    if (idx==m) {
        res.pb(nxt);
        return;
    }
    if (cur&(1<<idx)) {
        gen(idx+1,cur,nxt,res);
        return;
    }
    
    gen(idx+1, cur, nxt|(1<<idx), res);
    if (idx+1<m && !(cur&(1<<(idx+1)))) gen(idx+2, cur, nxt, res);
}

int go(int i, int s) {
    if (i==n) {
        if (s==0) return 1;
        return 0;
    }

    int &ret=d[i][s];
    if (ret!=-1) return ret;
    
    ret=0;
    vector<int> res;
    gen(0,s,0,res);
    for (int t:res) ret=(ret+go(i+1,t))%MOD;

    return ret;
}

int main() {
    fio();
    memset(d,-1,sizeof d);
    cin>>n>>m;
    cout<<go(0,0);
    return 0;
}