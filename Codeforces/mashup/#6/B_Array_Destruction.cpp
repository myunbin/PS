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
    int n; cin>>n;
    vector<int> a(2*n);
    map<int,int> v;
    for (int &x:a) cin>>x, v[x]++;
    sort(all(a));
    
    for (int i=0; i<2*n-1; i++) {
        int ix=a.back()+a[i];
        map<int,int> t=v;

        t[a.back()]--;
        if (t[a.back()]==0) t.erase(a.back());

        t[a[i]]--;
        if (t[a[i]]==0) t.erase(a[i]);

        vector<pii> ans; ans.pb({a.back(), a[i]});
        bool f=1;
        int x=a.back();
        while (!t.empty()) {
            auto it=t.end(); it--;
            int u=it->F, v=x-(it->F);
            
            t[u]--;
            if (t[u]==0) t.erase(u);

            if (t.find(v)==t.end()) {f=0; break;}

            t[v]--;
            if (t[v]==0) t.erase(v);
            ans.pb({u,v});
            x=u;
        }

        if (f) {
            cout<<"YES\n"<<ix<<endl;
            for (auto [u,v]:ans) cout<<u<<sp<<v<<endl;
            return;
        }
    }
    cout<<"NO\n";
}
int main() {
    fio();
    int tc;
    cin>>tc;
    while (tc--) solve();
    return 0;
}