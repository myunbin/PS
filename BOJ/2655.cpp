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
const int MAX = 111; // PLZ CHK!

struct ds{
    int id,s,h,w;
};
int main() {
    fio();
    int n;
    cin>>n;
    vector<ds> a;
    for (int i=1; i<=n; i++) {
        int x,y,z; cin>>x>>y>>z;
        a.pb({i,x,y,z});
    }

    sort(all(a), [](ds a, ds b){
        return a.s>b.s;
    });

    int d[MAX]={0}, p[MAX]={0};
    for (int i=0; i<n; i++) {
        d[i]=a[i].h;
        p[i]=i;
        for (int j=0; j<i; j++) {
            if (a[j].w<a[i].w) continue;

            if (d[i]<a[i].h+d[j]) {
                d[i]=a[i].h+d[j];
                p[i]=j;
            }
        }
    }

    int mx=0, idx;
    vector<int> ans;
    for (int i=0; i<n; i++) {
        if (mx<d[i]) {
            mx=d[i];
            idx=i;
        }
    }
    while (idx!=p[idx]) {
        ans.pb(a[idx].id);
        idx=p[idx];
    }
    ans.pb(a[idx].id);

    cout<<sz(ans)<<endl;
    for (int x:ans) cout<<x<<endl;
    
    return 0;
}