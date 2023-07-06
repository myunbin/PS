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
const int MAX = 2020; // PLZ CHK!

struct evt{
    int x,y1,y2,s;
    bool operator < (const evt& o) const {
        return x<o.x;
    } 
};

int main() {
    fio();
    int n;
    cin>>n;
    vector<evt> ev;
    vector<int> y;
    for (int i=0; i<n; i++) {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        y.pb(y1), y.pb(y2);
        ev.pb({x1,y2,y1,1}), ev.pb({x2,y2,y1,-1});
    }
    sort(all(ev)), cmprs(y);
    for (auto &[x,y1,y2,s]:ev) {
        y1=lb(all(y),y1)-y.begin();
        y2=lb(all(y),y2)-y.begin();
    }

    ll ans=0, lst=0;
    for (int i=0; i<2*n; i++) {
        vector<int> d(sz(y)+1,0);
        for (int j=0; j<i; j++) d[ev[j].y1]+=ev[j].s, d[ev[j].y2]-=ev[j].s;
        for (int j=1; j<sz(d); j++) d[j]+=d[j-1];

        for (int j=0; j<sz(d);) {
            int le=j, ri=j;
            while (ri<sz(d) && d[ri]>0) ri++;
            if (le<ri) {
                ans+=1ll*(ev[i].x-lst)*1ll*(y[ri]-y[le]);
            }
            j=ri+1;
        }

        lst=ev[i].x;
    }
    cout<<ans;
    return 0;
}