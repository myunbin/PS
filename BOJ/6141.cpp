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
const int MAX = 1010; // PLZ CHK!

int l,p;
double f[MAX];
typedef tuple<int,int,double> tid;
vector<tid> e;

const double eps=1e-8;

bool ok(double k) {
    vector<tid> te;
    for (auto [u,v,w]:e) {
        te.pb({u,v,w-k*f[u]});
    }

    double d[MAX]; fill(d,d+MAX,1e9);
    for (int i=1; i<=l; i++) {
        for (auto [u,v,w]:te) {
            if (d[v]-(d[u]+w)>eps) {
                d[v]=d[u]+w;
                if (i==l) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    fio();
    cin>>l>>p;
    for (int i=1; i<=l; i++) cin>>f[i];
    e.resize(p);
    for (auto &[u,v,w]:e) cin>>u>>v>>w;
    
    double le=0.0, ri=2e6, ans=ri;
    while (eps<ri-le) {
        double md=(le+ri)/2.0;
        if (ok(md)) {
            ri=md;
            ans=1/md;
        }
        else le=md;
    }
    cout<<fixed;
    cout.precision(2);

    cout<<ans;
    return 0;
}