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
const int MAX = 20; // PLZ CHK!

int n;
string a[MAX];
set<string> b[MAX];

void go(int x, int y, string &s) {
    if (x+y==n-1) {
        b[x].insert(s);
        return;
    }

    if (x+1<n) {
        s.pb(a[x+1][y]);
        go(x+1,y,s);
        s.pop_back();
    }
    if (y+1<n) {
        s.pb(a[x][y+1]);
        go(x,y+1,s);
        s.pop_back();
    }
}

set<string> ans;
void go2(int x, int y, string &s) {
    if (x+y==n-1) {
        if (b[x].find(s)!=b[x].end()) ans.insert(s);
        return;
    }

    if (0<=x-1) {
        s.pb(a[x-1][y]);
        go2(x-1,y,s);
        s.pop_back();
    }
    if (0<=y-1) {
        s.pb(a[x][y-1]);
        go2(x,y-1,s);
        s.pop_back();
    }
}

int main() {
    fio();
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];

    string s;
    s.pb(a[0][0]);
    go(0,0,s);

    string t;
    t.pb(a[n-1][n-1]);
    go2(n-1,n-1,t);

    cout<<sz(ans);
    return 0;
}