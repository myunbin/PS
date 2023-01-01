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

int n,k;
vector<int> a;

bool ok(int x) {
    unordered_map<int,int> mp1, mp2;
    for (int i=0; i<n; i++) mp2[a[i]]++;
    
    for (int i=0; i<x; i++) {
        mp1[a[i]]++;
        if (--mp2[a[i]]==0) mp2.erase(a[i]);    
        if (sz(mp1)==k && sz(mp2)==k) return 1;
    }

    for (int i=1; i<=n-x; i++) {
        mp1[a[i+x-1]]++;
        if (--mp2[a[i+x-1]]==0) mp2.erase(a[i+x-1]);

        if (--mp1[a[i-1]]==0) mp1.erase(a[i-1]);
        mp2[a[i-1]]++;

        if (sz(mp1)==k && sz(mp2)==k) return 1;
    }
    return 0;
}
int main() {
    fio();
    cin>>n>>k;
    a.resize(n);
    for (int &x:a) cin>>x;
    
    int l=k, r=n-k;
    int ans=0;
    while (l<=r) {
        int m=(l+r)>>1;
        if (ok(m)) {
            ans=m;
            r=m-1;
        }
        else l=m+1;
    }
    cout<<ans;
    return 0;
}