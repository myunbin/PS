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

int main() {
    fio();
    int n; 
    pll g;
    cin>>n>>g.F>>g.S;

    vector<pll> a(n);
    for (auto &[x,y]:a) cin>>x>>y;
    
    int h=(n>>1), oh=n-h;
    map<pll, map<ll,int>> m1;
    for (int i=0; i<(1<<h); i++) {
        pll cur={0,0};
        int k1=0;
        for (int j=0; j<h; j++) {
            if (i&(1<<j)) {
                cur={cur.F+a[j].F, cur.S+a[j].S};
                k1++;
            }
        }
        m1[cur][k1]++;
    }

    vector<ll> ans(n+1);
    for (int i=0; i<(1<<oh); i++) {
        pll cur={0,0};
        ll k2=0;
        for (int j=h; j<n; j++) {
            if (i&(1<<(j-h))) {
                cur={cur.F+a[j].F, cur.S+a[j].S};
                k2++;
            }
        }

        if (m1.find({g.F-cur.F, g.S-cur.S})!=m1.end()) {
            for (auto [k1,cnt]:m1[{g.F-cur.F, g.S-cur.S}]) {
                ans[k1+k2]+=cnt;
            }
        }
    }
    for (int i=1; i<=n; i++) cout<<ans[i]<<endl;
    return 0;
}