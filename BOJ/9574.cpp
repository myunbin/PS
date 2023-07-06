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
const int MAX = 40404; // PLZ CHK!

int main() {
    fio();
    int n,x,y,z;
    cin>>n>>x>>y>>z;

    vector<pii> a;
    vector<int> b;
    for (int i=0; i<n; i++) {
        int s,e; cin>>s>>e;
        a.pb({s,1}), a.pb({e,-1});
        b.pb(s), b.pb(e);
    }
    cmprs(b);
    sort(all(a));

    int d[MAX]={0};
    for (auto &[u,v]:a) {
        u=lb(all(b),u)-b.begin()+1;
        if (v==1) d[u]++;
        else d[u+1]--;
    }
    for (int i=1; i<MAX; i++) d[i]+=d[i-1];

    int dn=0, ans=0;
    for (auto [u,v]:a) {
        int t=y*d[u]+dn*z+(n-d[u]-dn)*x;
        ans=max(ans, t);
        if (v==-1) dn++;
    }

    cout<<ans;
    return 0;
}