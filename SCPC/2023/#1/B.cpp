#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")

// #define fileio() freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
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
const int MAX = 101010; // PLZ CHK!

void solve() {
    int N,D;
    cin>>N>>D;
    
    vector<int> L,R;
    int ans=0;
    for (int i=0; i<N; i++) {
        int x; cin>>x;
        if (x<0) L.pb(-x);
        else if (x>0) R.pb(x);
        else ans++;
    }

    sort(all(L)),sort(all(R));
    int l=sz(L), r=sz(R);
    
    for (int i=0; i<l; i++) {
        if (D-L[i]<0) break;
        int j=ub(all(R), D-2*L[i])-R.begin()-1;
        ans=max(ans, i+1+j+1);
    }

    for (int i=0; i<r; i++) {
        if (D-R[i]<0) break;
        int j=ub(all(L), D-2*R[i])-L.begin()-1;
        ans=max(ans, i+1+j+1);
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