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

struct ed {
    int u,v,w;
};

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

int main() {
    fio();
    for (int i=0; i<MAX; i++) p[i]=i;

    int n,m;
    cin>>n>>m;
    vector<ed> e;
    int cnt=0,ans=0,sum=0;
    for (int i=0; i<m; i++) {
        int u,v,w,d;
        cin>>u>>v>>w>>d;
        sum+=w;

        cnt+=d;
        if (d) {
            mg(u,v);
            ans+=w;
        }
        else e.pb({u,v,w});
    }

    sort(all(e), [](ed a, ed b){
        return a.w>b.w;
    });

    for (auto [u,v,w]:e) {
        if (cnt<n-1 && mg(u,v)) {
            cnt++;
            ans+=w;
        }
    }

    cout<<sum-ans;
    return 0;
}