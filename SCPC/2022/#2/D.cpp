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

bool ok(vector<vector<int>> &a, int r1, int r2, int c1, int c2) {
    int mn=INF, mx=-1;
    bool v[500]={0};
    for (int i=r1; i<=r2; i++) {
        for (int j=c1; j<=c2; j++) {
            mn=min(mn, a[i][j]), mx=max(mx, a[i][j]);
            v[a[i][j]]=1;
        }
    }
    for (int i=mn; i<=mx; i++) {
        if (!v[i]) {
            return 0;
        }
    }
    return 1;
}
void solve() {
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) cin>>a[i][j];
    }

    if (n>16) {
        cout<<0<<endl;
        return;
    }

    int ans=0;
    for (int r1=0; r1<n; r1++) {
        for (int r2=r1; r2<n; r2++) {
            for (int c1=0; c1<n; c1++) {
                for (int c2=c1; c2<n; c2++) {
                    ans+=ok(a, r1, r2, c1, c2);      
                }
            }
        }
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