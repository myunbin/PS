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
    
    int a[MAX]={0};
    for (int i=1; i<=n; i++) cin>>a[i];

    int l[30303]={0}, r[30303]={0};
    l[a[1]]++; for (int i=3; i<=n; i++) r[a[i]]++;

    int mx=*max_element(a+1, a+n+1);
    ll ans=0;
    for (int i=2; i<n; i++) {
        for (int j=1; j<=mx; j++) {
            int x=2*a[i]-j;
            if (x<0 || x>30000) continue;
            ans+=1ll*l[j]*r[2*a[i]-j];
        }
        r[a[i+1]]--;
        l[a[i]]++;
    }
    cout<<ans;
    return 0;
}