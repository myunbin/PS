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

int n, ans;
vector<pii> a;
int to[20];


void go(vector<int> b) {
    bool ok=1;
    for (int i=0; i<n; i++) {
        if (!b[i]) {
            ok=0;
            break;
        }
    }

    if (ok) {
        vector<vector<int>> ed(n/2+1);
        for (int i=0; i<n; i++) ed[b[i]].pb(i);

        vector<int> w(n);
        for (int i=1; i<=n/2; i++) {
            int u=ed[i][0], v=ed[i][1];
            w[u]=v, w[v]=u;
        }

        for (int i=0; i<n; i++) {
            int cur=i;
            for (int j=0; j<n; j++) {
                cur=w[cur];
                cur=to[cur];
                if (cur==-1) break;
            }
            if (cur!=-1) {
                ans++;
                return;
            }
        }
        return;
    }
    
    int nxt=*max_element(all(b))+1;
    int f,s;
    for (int i=0; i<n; i++) {
        if (!b[i]) {
            f=i;
            b[i]=nxt;
            break;
        }
    }

    for (int i=f+1; i<n; i++) {
        if (!b[i]) {
            b[i]=nxt;
            go(b);
            b[i]=0;
        }
    }
}

int main() {
    fio();
    fill(to, to+20, -1);

    cin>>n;
    a.resize(n);
    
    map<int,vector<pii>> m;
    for (int i=0; i<n; i++) {
        cin>>a[i].F>>a[i].S;
        m[a[i].S].pb({a[i].F,i});
    }
    
    for (auto [y,v]:m) {
        int s=sz(v);
        sort(all(v));
        for (int i=0; i<s-1; i++) {
            to[v[i].S]=v[i+1].S;
        }
    }

    vector<int> t(n,0);
    go(t);

    cout<<ans;
    return 0;
}