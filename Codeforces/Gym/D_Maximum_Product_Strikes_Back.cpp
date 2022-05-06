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

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for (int &x:a) cin>>x;

    vector<vector<int>> v;
    vector<pii> ii;
    int p=0;
    while (p<n) {
        vector<int> t;
        pii idx={p,p-1};
        while (p<n && a[p]!=0) t.pb(a[p]), p++, idx.S++;
        p++;
        if (!t.empty()) v.pb(t), ii.pb(idx);
    }
    pair<int,pair<int,int>> ans={0, {0,-1}}; //num of 2, index of ii
    for (int i=0; i<sz(v); i++) {
        auto k=v[i];

        int c2=0,m=0;
        for (int x:k) {
            if (abs(x)==2) c2++;
            if (x<0) m++;
        }
        
        if (m%2==0) {
            ans=max(ans,{c2,ii[i]});
            continue;
        }
        
        int f=0,b=0;
        int cf=c2, cb=c2;
        for (int j=0; j<sz(k); j++) {
            f++;
            if (abs(k[j])==2) cf--;
            if (k[j]<0) break;
        }
        for (int j=sz(k)-1; j>=0; j--) {
            b++;
            if (abs(k[j])==2) cb--;
            if (k[j]<0) break;
        }
        
        if (cf>cb) {
            ans=max(ans,{cf,{ii[i].F+f,ii[i].S}});
        }
        else {
            ans=max(ans,{cb,{ii[i].F,ii[i].S-b}});
        }
    }

    cout<<ans.S.F<<sp<<n-1-ans.S.S<<endl;
}
int main() {
    fio();
    int tc;
    cin>>tc;
    while (tc--) solve();
    return 0;
}