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

struct cmp{
    bool operator() (pll a, pll b) {
        return a.F-a.S>b.F-b.S;
    }  
};

int main() {
    fio();
    int n,k; ll m;
    cin>>n>>k>>m;
    vector<pll> a(n);
    for (auto &[x,y]:a) cin>>x>>y;

    sort(all(a), [](pll x, pll y){
        if (x.S==y.S) return x.F<y.F;
        return x.S<y.S;
    });

    priority_queue<pll,vector<pll>,cmp> pq;
    ll cur=0;
    int ans=0;
    for (int i=0; i<k; i++) {
        if (cur+a[i].S<=m) {
            cur+=a[i].S;
            pq.push(a[i]);
            ans++;
        }
        else {
            cout<<ans;
            return 0;
        }
    }

    for (int i=k; i<n; i++) {
        auto [x,y]=pq.top();
        ll nxt1=cur-y+x+a[i].S;
        ll nxt2=cur+a[i].F;
        if (nxt1<nxt2) {
            if (nxt1>m) continue;
            cur=nxt1;
            ans++;
            pq.pop();
            pq.push(a[i]);
        }
        else {
            if (nxt2>m) continue;
            cur=nxt2;
            ans++;
        }
    }

    cout<<ans;
    return 0;
}