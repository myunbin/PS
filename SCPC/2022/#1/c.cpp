#include <bits/stdc++.h>
using namespace std;
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
    int n; 
    cin>>n;
    vector<pll> v(n);
    for (auto &[x,y]:v) cin>>x>>y;
    if (n%2) {
        sort(all(v));
        int p=0;
        ll px,py; 
        while (p<n) {
            ll c=v[p].F;
            int cnt=0;
            while (p<n && v[p].F==c) p++, ++cnt;
            if (cnt%2) {
                px=c;
                break;
            }
        }

        sort(all(v),[](pll a, pll b){
            if (a.S==b.S) return a.F<b.F;
            return a.S<b.S;
        });

        p=0;
        while (p<n) {
            ll c=v[p].S;
            int cnt=0;
            while (p<n && v[p].S==c) p++, ++cnt;
            if (cnt%2) {
                py=c;
                break;
            }
        }
        
        for (int i=0; i<n; i++) {
            if (v[i].F==px && v[i].S==py) {
                p=i;
                break;
            }
        }
        v.erase(v.begin()+p);
        --n;
    }

    ll ans=0;
    sort(all(v));
    
    for (int i=0; i<n; i+=2) {
        ans+=v[i+1].S-v[i].S;
    }
    sort(all(v),[](pll a, pll b){
            if (a.S==b.S) return a.F<b.F;
            return a.S<b.S;
    });
    for (int i=0; i<n; i+=2) {
        ans+=v[i+1].F-v[i].F;
    }
    cout<<ans<<endl;
}

int main() {
    fio();
    int t;
    cin>>t;
    for (int i=1; i<=t; i++) {
        cout<<"Case #"<<i<<endl;
        solve();
    }
    return 0;
}