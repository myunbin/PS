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
const int MAX = 55; // PLZ CHK!

int n;
pll a[MAX];

bool ok(ll m) {
    pll cur={-4ll*INF,4ll*INF};
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            auto [x1,y1]=a[i]; auto [x2,y2]=a[j];
            if (x1==x2) {
                if (abs(y1-y2)>m) return 0;
                continue;
            }

            ll t=m-abs(x1-x2);
            if (t<abs(y1-y2)) return 0;
            
            ll l=(ll)ceill((1.0*(y1+y2-t))/2.0), r=(ll)(floorl((1.0*(y1+y2+t))/2.0));
            if (l>r || cur.S<l || r<cur.F) return 0;

            cur.F=max(cur.F, l), cur.S=min(cur.S, r);
        }
    }
    
    return 1;
}

int main() {
    fio();

    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i].F>>a[i].S;

    ll le=0, ri=4ll*INF, ans=4ll*INF;
    while (le<=ri) {
        ll md=(le+ri)>>1;
        if (ok(md)) {
            ri=md-1;
            ans=md;
        }
        else le=md+1;
    }

    cout<<ans;
    return 0;
}