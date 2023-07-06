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
const int MAX = 50505; // PLZ CHK!

struct ev {
    int t,e,y,i;
    bool operator < (const ev &o) const {
        if (t==o.t) return e<o.e;
        return t<o.t;
    }
};

int main() {
    fio();
    int n;
    cin>>n;
    
    vector<ev> a;
    for (int i=0; i<n; i++) {
        int x,y,r;
        cin>>x>>y>>r;
        int s=(-x-1)*r, e=-x*r;
        a.pb({s,1,y,i}), a.pb({e,-1,y,i});
    }
    sort(all(a));

    int ok[MAX]={0};
    set<int> cur;
    priority_queue<pii,vector<pii>,greater<pii>> pq; //y,i

    int p=0;
    while (p<2*n) {
        int np=p;
        while (np<2*n && a[p].t==a[np].t) {
            if (a[np].e==1) {
                pq.push({a[np].y, a[np].i});
                cur.insert(a[np].i);
            }
            else cur.erase(a[np].i);
            np++;
        }

        while (!pq.empty() && cur.find(pq.top().S)==cur.end()) pq.pop();
        if (!pq.empty()) ok[pq.top().S]=1;

        p=np;
    }

    int ans=0;
    for (int i=0; i<n; i++) ans+=ok[i];

    cout<<ans;
    return 0;
}