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

int main() {
    fio();
    int n;
    cin>>n;
    multiset<pair<int,char>> m;
    for (int i=0; i<n; i++) {
        int x; char c;
        cin>>x>>c;
        m.insert({x,c});
    }
    vector<int> a(n);
    for (int &x:a) cin>>x;

    vector<char> ans(n);
    for (int i=0; i<n; i++) {
        vector<pair<char,int>> v;
        auto it=m.lb({a[i],0});
        for (auto j=it; j!=m.end(); j++) v.pb({j->S,j->F});
        sort(all(v));

        pair<char,int> p={'Z'+1,INF};
        for (int j=0; j<sz(v); j++) {
            auto [c,x]=v[j];
            
            int mxt=*max_element(a.begin()+i+1,a.end());
            auto cur=m.find({v[j].S,v[j].F});
            int mxc=0;
            for (auto k=m.begin(); k!=m.end(); k++) {
                if (k==cur) continue;
                mxc=max(mxc,k->F);
            }
            if (mxc>=mxt) {
                p={c,x};
                break;
            }
        }
        // cout<<p.F<<sp;
        auto dd=m.find({p.S,p.F});
        if (dd!=m.end()) m.erase(dd);
        else {
            cout<<-1;
            return 0;
        }
        ans[i]=p.F;
    }

    for (char c:ans) cout<<c;
    return 0;
}