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

int n,m;
int p[MAX];

int fd(int a) {
    if (a==p[a]) return a;
    return p[a]=fd(p[a]);
}

bool mg(int a, int b) {
    a=fd(a), b=fd(b);
    if (a==b) return 0;
    p[b]=a; return 1;
}

struct ed{
    int u,v;
    double pr;
};

int main() {
    fio();
    for (int i=0; i<MAX; i++) p[i]=i;

    cin>>n>>m;
    
    vector<ed> e(m);
    for (auto &[u,v,pr]:e) cin>>u>>v>>pr;
    sort(all(e), [](ed a, ed b){
        return a.pr>b.pr;
    });

    int q;
    cin>>q;
    typedef pair<int, double> pid;
    vector<pid> qry(q);
    for (int i=0; i<q; i++) {
        cin>>qry[i].S;
        qry[i].F=i;
    }  

    sort(all(qry), [](pid a, pid b){
        return a.S>b.S;
    });

    vector<int> ans(q);
    int cnt=n;
    int i=0;
    for (auto [idx, qpr]:qry) {
        while (i<m && e[i].pr>=qpr) {
            if (mg(e[i].u, e[i].v)) cnt--;
            i++;
        }
        ans[idx]=max(1,cnt);
    }

    for (int x:ans) cout<<x<<endl;
    return 0;
}