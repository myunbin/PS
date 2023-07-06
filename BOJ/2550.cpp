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
const int MAX = 10101; // PLZ CHK!

struct segtr{
    //0-indexed!
    vector<pii> tr;
    int n;
    void rst(int sz) {
        n=sz; tr.resize((n+1)<<1, {-1,-1});
    }

    void upd(int i, pii v) {
        tr[i+n] = max(tr[i+n], v); i+=n; //AWARE OF UPD POLICY!!
        for (i>>=1; i; i>>=1) tr[i] = max(tr[i<<1], tr[i<<1|1]);
    }

    pii qry(int l, int r) {
        pii ret = {0,-1};
        for (l+=n, r+=n; l<=r; l>>=1, r>>=1) {
            if (l&1) ret = max(ret, tr[l++]);
            if (~r&1) ret = max(ret, tr[r--]);
        }
        return ret;
    }
};

int main() {
    fio();
    int n;
    cin>>n;
    vector<pii> a(n);
    vector<int> p(n+1);
    for (int i=0; i<n; i++) {
        cin>>a[i].F;
        p[a[i].F]=i;
    }
    for (int i=0; i<n; i++) {
        int x; cin>>x;
        a[p[x]].S=i+1;
    }

    segtr seg; seg.rst(MAX);
    int d[MAX]={0}, pr[MAX]; fill(pr,pr+MAX,-1);

    for (int i=0; i<n; i++) {
        auto [mx,mxi]=seg.qry(0,a[i].S-1);
        d[i]=mx+1, pr[i]=mxi;
        seg.upd(a[i].S, {d[i],i});
    }
    
    pii ans={-1,0};
    for (int i=0; i<n; i++) {
        ans=max(ans, {d[i],i});
    }
    
    cout<<ans.F<<endl;
    vector<int> as;
    int cur=ans.S;
    while (1) {
        as.pb(a[cur].F);
        cur=pr[cur];
        if (cur<0) break;
    }
    sort(all(as));
    for (int x:as) cout<<x<<sp;
    return 0;
}