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
const int MAX = 101010; // PLZ CHK!

void solve() {
    int n,k;
    cin>>n>>k;
    vector<pii> a(n);
    for (int i=0; i<n; i++) cin>>a[i].F, a[i].S=i+1;
    sort(all(a), greater<>());

    int mx=0, ai=1, aj=2, ax=0;
    for (int i=0; i<n-1; i++) {
        int x=a[i].F, y=a[i+1].F, sum=0, tx=0;
        for (int j=k-1; j>=0; j--) {
            if ((x&(1<<j)) == (y&(1<<j))) {
                sum+=(1<<j);
                if ((x&(1<<j))==0) tx+=(1<<j); 
            }
        }
        if (mx<sum) {
            mx=sum;
            ai=a[i].S, aj=a[i+1].S;
            ax=tx;
        }
    }

    cout<<ai<<sp<<aj<<sp<<ax<<endl;
}

int main() {
    fio();

    int t=1;
    cin>>t;
    while (t--) solve();

    return 0;
}