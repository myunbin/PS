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

int main() {
    fio();
    int n,s=0;
    int a[MAX]={0};
    bool d[MAX/2][MAX*450]={0};

    cin>>n;
    
    for (int i=1; i<=n; i++) cin>>a[i], s+=a[i];

    d[0][0]=1;
    for (int i=1; i<=n; i++) {
        for (int j=n/2; j>=0; j--) {
            for (int k=MAX*450-1; k>=a[i]; k--) { 
                d[j][k]|=d[j-1][k-a[i]];
            }
        }
    }

    int diff=INF;
    pii ans;
    for (int i=0; i<MAX*450; i++) {
        if (d[n/2][i]) {
            if (diff>abs(s-2*i)) {
                diff=abs(s-2*i);
                ans={min(i,s-i), max(i,s-i)};
            }
        }
    }
    cout<<ans.F<<sp<<ans.S;
    return 0;
}