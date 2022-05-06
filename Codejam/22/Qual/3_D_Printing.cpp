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
    int a[3][4];
    for (int i=0; i<3; i++) {
        for (int j=0; j<4; j++) cin>>a[i][j];
    }

    int sum=0, m[4];
    for (int j=0; j<4; j++) {
        int mn=INF;
        for (int i=0; i<3; i++) {
            mn=min(mn,a[i][j]);
        }
        sum+=mn;
        m[j]=mn;
    }

    if (sum<1000000) cout<<"IMPOSSIBLE\n";
    else {
        int x=1000000;
        for (int i=0; i<4; i++) {
            if (x-m[i]>=0) cout<<m[i]<<sp, x-=m[i];
            else cout<<x<<sp, x=0;
        }
        cout<<endl;
    }
}
int main() {
    fio();
    int tc; 
    cin>>tc;
    for (int i=1; i<=tc; i++) {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}