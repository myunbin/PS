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

struct pt {
    int p,x,y;
};

int main() {
    fio();
    int n;
    cin>>n;
    vector<pt> v;
    pii t;
    for (int i=0; i<n+1; i++) {
        int x,y; cin>>x>>y;
        v.pb({(i==n),x,y});
        if (i==n) t={x,y};
    }    

    sort(all(v),[](pt a, pt b){
        return a.x<b.x;
    });

    set<int> s;
    bool ll=0, lh=0, rl=0, rh=0;
    
    int i=0, f=0;
    while (i<=n) {
        vector<int> yy;
        int cy=v[i].y;
        while (i<=n && cy==v[i].y) {
            if (v[i].p) {
                auto it1=s.lb(v[i].y);
                if (it1!=s.begin()) ll=1;
                auto it2=s.ub(v[i].y);
                if (it2!=s.end()) lh=1;
            }
            yy.pb(v[i].y); i++;
        }
        for (int y:yy) s.insert(y);
    }
    return 0;
}