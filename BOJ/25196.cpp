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

pll isp(pll a, pll b) {
    return {max(a.F,b.F), min(a.S,b.S)};
}

ll lc;

ll solve(vector<ll> &a, vector<ll> &b, vector<ll> &c) {
    pll ca={a[1],a[2]};
    ll ans=LINF;

    while (ca.F<=lc) {
        ll bk=(ca.F-b[1]+b[0]-1)/b[0];
        pll cb[]={{b[1]+bk*b[0], b[2]+bk*b[0]}, 
        {b[1]+(bk-1)*b[0], b[2]+(bk-1)*b[0]}, {b[1]+(bk+1)*b[0], b[2]+(bk+1)*b[0]}
        };

        ll ck=(ca.F-c[1]+c[0]-1)/c[0];
        pll cc[]={{c[1]+ck*c[0], c[2]+ck*c[0]}, 
        {c[1]+(ck-1)*c[0], c[2]+(ck-1)*c[0]}, {c[1]+(ck+1)*c[0], c[2]+(ck+1)*c[0]}
        };

        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                pll res=isp(ca, cb[i]); res=isp(res, cc[j]);
                if (0<=res.F && res.F<=res.S) ans=min(ans, res.F);
            }
        }

        if (ans<LINF) return ans;
        
        ca={ca.F+a[0], ca.S+a[0]};
    }

    return ans;
}
int main() {
    fio();
    vector<ll> a(3),b(3),c(3);
    for (int i=0; i<3; i++) cin>>a[i];
    for (int i=0; i<3; i++) cin>>b[i];
    for (int i=0; i<3; i++) cin>>c[i];

    ll l=a[0]*b[0]/gcd(a[0],b[0]);
    lc=l*c[0]/gcd(l,c[0]);

    ll ans=LINF;
    ans=min(ans, solve(a,b,c));
    ans=min(ans, solve(b,a,c));
    ans=min(ans, solve(c,a,b));

    cout<<(ans==LINF?-1:ans);
    return 0;
}