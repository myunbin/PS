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

vector<pii> go(int x) {
    if (x==0) {
        vector<pii> ret;
        return ret;
    }
    if (x==1) {
        vector<pii> ret={{0,0}};
        return ret;
    }

    int c=0;
    while (x%2==0) x/=2, c++;
        
    int t=1, tc=0;
    while (t*3<=x) t*=3, tc++;

    vector<pii> ret=go(x-t);
    for (auto &[n,m]:ret) n+=c;
    ret.pb({c, tc});

    return ret;
}

void solve() {
    int x; cin>>x;
    vector<pii> ans=go(x);

    cout<<sz(ans)<<endl;
    for (auto [x,y]:ans) {
        // int n=1, m=1;
        // for (int i=0; i<x; i++) n*=2;
        // for (int i=0; i<y; i++) m*=3;
        // sum+=n*m;
        cout<<x<<sp<<y<<endl;
    }
}

int main() {
    fio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}