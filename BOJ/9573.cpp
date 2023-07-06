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
const int MAX = 111; // PLZ CHK!

int main() {
    fio();
    int n;
    cin>>n;

    int a[3],b[3];
    for (int i=0; i<3; i++) cin>>a[i];
    for (int i=0; i<3; i++) cin>>b[i];

    int ans=0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            for (int k=1; k<=n; k++) {
                int mx1=0;
                mx1=max(mx1, min(abs(i-a[0]), n-abs(i-a[0])));
                mx1=max(mx1, min(abs(j-a[1]), n-abs(j-a[1])));
                mx1=max(mx1, min(abs(k-a[2]), n-abs(k-a[2])));

                int mx2=0;
                mx2=max(mx2, min(abs(i-b[0]), n-abs(i-b[0])));
                mx2=max(mx2, min(abs(j-b[1]), n-abs(j-b[1])));
                mx2=max(mx2, min(abs(k-b[2]), n-abs(k-b[2])));

                ans+=(mx1<=2||mx2<=2);
            }
        }
    }

    cout<<ans;
    return 0;
}