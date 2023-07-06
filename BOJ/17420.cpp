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

int main() {
    fio();
    int n;
    cin>>n;
    vector<pll> v(n);
    for (int i=0; i<n; i++) cin>>v[i].F;
    for (int i=0; i<n; i++) cin>>v[i].S;
    
    sort(all(v), [](pll a, pll b){
        if (a.S==b.S) return a.F<b.F;
        return a.S<b.S;
    });


    ll ans=0;
    for (int i=0; i<n; i++) {
        if (v[i].S>v[i].F) {
            ll t=(v[i].S-v[i].F+29)/30;
            ans+=t, v[i].F+=30ll*t;
        }
    }

    int p=0;
    ll mx=0;

    while (p<n) {
        ll nm=0;
        int l=p, r=p;
        while (r<n && v[l].S==v[r].S) r++;

        for (int i=l; i<r; i++) {
            if (mx>v[i].F) {
                ll t=(mx-v[i].F+29)/30;
                ans+=t, v[i].F+=30ll*t;
            }
            nm=max(nm, v[i].F);
        }
        mx=max(mx, nm);
        p=r;
    }

    cout<<ans;
    return 0;
}