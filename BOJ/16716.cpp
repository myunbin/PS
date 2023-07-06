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
vector<pii> a, b(2);
vector<pii> t1, t2;

int bt(vector<int> &v, int st) {
    vector<pii> res;
    if (st==1) for (int idx:v) res.pb(t1[idx]);
    else for (int idx:v) res.pb(t2[idx]);
    cmprs(res);
    return sz(res);
}


int main() {
    fio();
    int n;
    cin>>n;
    a.resize(n);

    for (auto &[x,y]:a) cin>>x>>y;
    for (auto &[x,y]:b) cin>>x>>y;
    
    for (auto [x,y]:a) {
        pii tan1={y-b[0].S, x-b[0].F};
        int g1=gcd(abs(tan1.F), abs(tan1.S));
        tan1.F/=g1, tan1.S/=g1;
        t1.pb(tan1);

        pii tan2={y-b[1].S, x-b[1].F};
        int g2=gcd(abs(tan2.F), abs(tan2.S));
        tan2.F/=g2, tan2.S/=g2;
        t2.pb(tan2);
    }
    
    pii ans={INF,INF};
    for (int i=0; i<(1<<n); i++) {
        vector<int> f,s;
        for (int j=0; j<n; j++) {
            if (i&(1<<j)) f.pb(j);
            else s.pb(j);
        }

        pii t={bt(f,1)+bt(s,2), (sz(s)>0)};
        ans=min(ans, t);
    }

    cout<<ans.F<<sp<<ans.S;
    return 0;
}