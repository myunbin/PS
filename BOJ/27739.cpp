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
const int MAX = 2020; // PLZ CHK!

int main() {
    fio();
    int n,k;
    int d1[MAX]={0}, d2[MAX]={0}, a[MAX]={0};

    cin>>n>>k;
    for (int i=1; i<=n; i++) cin>>a[i];

    for (int i=1; i<=n; i++) {
        d1[i]=1;
        if (a[i-1]<a[i]) d1[i]=d1[i-1]+1;
    }
    for (int i=n; i>=1; i--) {
        d2[i]=1;
        if (a[i]<a[i+1]) d2[i]=d2[i+1]+1;
    }

    int ans=max(k, *max_element(d1+1, d1+n+1));
    for (int i=1; i+k-1<=n; i++) {
        int s=i, e=i+k-1;

        int t1=d2[e+1];
        for (int j=s; j<=e; j++) t1+=(a[j]<a[e+1]);
        ans=max(ans, t1);

        int t2=d1[s-1];
        for (int j=s; j<=e; j++) t2+=(a[s-1]<a[j]);
        ans=max(ans, t2);

        int mx=0, mn=MAX;
        for (int j=s; j<=e; j++) mx=max(mx, a[j]), mn=min(mn, a[j]);

        if (a[s-1]<mn && mx<a[e+1]) ans=max(ans, d2[e+1]+d1[s-1]+(e-s+1));
    }
    
    cout<<ans;
    return 0;
}