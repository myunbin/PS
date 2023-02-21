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

struct dt {
    char t;
    int v;
};

int main() {
    fio();
    int n;
    cin>>n;
    vector<dt> a(n), b(n);
    for (int i=0; i<n; i++) {
        string s; cin>>s;
        a[i].t=s[0];
        a[i].v=stoi(s.substr(1));
        b[i]=a[i];
    }

    int r[30]={0};
    r['B'-'A']=1, r['S'-'A']=2, r['G'-'A']=3, r['P'-'A']=4, r['D'-'A']=5;
    sort(all(b), [&](dt a, dt b){
        auto [at,av]=a; auto [bt,bv]=b;
        if (r[at-'A']==r[bt-'A']) return av>bv;
        return r[at-'A']<r[bt-'A'];
    });

    vector<dt> ans;
    for (int i=0; i<n; i++) {
        if (a[i].t!=b[i].t || a[i].v!=b[i].v) ans.pb(b[i]);
    }

    cout<<(ans.empty()?"OK":"KO")<<endl;
    if (!ans.empty()) {
        for (auto [x,y]:ans) cout<<x<<y<<sp;
    }
    return 0;
}