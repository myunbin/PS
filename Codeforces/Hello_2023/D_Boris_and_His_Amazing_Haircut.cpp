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
const int MAX = 202020; // PLZ CHK!

int p[MAX];
int fd(int a) {
    if (p[a]==a) return a;
    return p[a]=fd(p[a]);
}

bool mg(int a, int b) {
    a=fd(a), b=fd(b);
    if (a==b) return 0;
    p[b]=a;
    return 1;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    set<pii> rb;
    set<int> bb;
    for (int i=0; i<n; i++) cin>>a[i];
    for (int i=0; i<n; i++) {
        cin>>b[i];
        rb.insert({b[i], i});
        bb.insert(b[i]);
    }

    int m;
    cin>>m;
    vector<int> r(m);
    map<int,int> rz;
    for (int &x:r) cin>>x, rz[x]++;

    for (int i=0; i<n; i++) {
        if (a[i]<b[i]) {
            cout<<"NO\n";
            return;
        }
    }

    vector<int> chk(n,0);
    auto it=rb.begin();
    int cur=0;
    for (auto [x,cnt]:rz) {
        if (bb.find(x)==bb.end()) continue;
        
        vector<int> cut;
        while (it!=rb.end() && it->F<=x) {
            auto [bi,i]=*it;
            if (bi==x) cut.pb(i);

            bool ok1=0, ok2=0;
            p[i]=i;
            if (i>0 && p[i-1]>=0) mg(i, i-1), ok1=1;
            if (i<n-1 && p[i+1]>=0) mg(i, i+1), ok2=1;
            
            if (ok1 && ok2) cur--;
            else if (!ok1 && !ok2) cur++;
            
            it++;
        }
        
        set<int> cpt;
        for (int ci:cut) cpt.insert(fd(ci));

        if (sz(cpt)>cnt) {
            cout<<"NO\n";
            return;
        }

        for (int ci:cut) chk[ci]=1;
    }

    for (int i=0; i<n; i++) {
        if (!chk[i] && a[i]!=b[i]) {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";

    for (int i=0; i<n; i++) p[i]=-1;
}
int main() {
    fio();
    memset(p,-1,sizeof p);
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}