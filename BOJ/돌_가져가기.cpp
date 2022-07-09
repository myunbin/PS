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
    int n; string s;
    cin>>n>>s;
    vector<int> v(n);
    for (int &x:v) cin>>x;

    int p=0;
    vector<int> a;
    while (p<n) {
        char c=s[p];
        int mx=v[p];
        while (p<n && c==s[p]) mx=max(mx, v[p]), p++;
        a.pb(mx);
    }
    
    n=sz(a);
    if (n<=2) {
        cout<<0<<endl;
        return 0;
    }

    sort(a.begin()+1, a.end()-1, greater<>());
    ll ans=0;
    
    int x=(n-1)/2;
    p=1;
    while (p<n && x--) ans+=1ll*a[p++];

    cout<<ans;
    return 0;
}