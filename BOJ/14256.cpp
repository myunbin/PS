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
const int MAX = 77777+1; // PLZ CHK!

int mp[MAX];
void sv() {
    for (int i=2; i<MAX; i++) mp[i]=i;
    for (int i=4; i<MAX; i+=2) mp[i]=2;
    for (int i=3; i*i<MAX; i++) {
        if (mp[i]!=i) continue;
        for (int j=i*i; j<MAX; j+=i) mp[j]=i;
    }
}

int fct(int x)
{
    map<int,int> ret; 
    while (x != 1) {
        ret[mp[x]]++;
        x = x / mp[x];
    }
    int res=1;
    for (auto [pr,cnt]:ret) {
        if (cnt&1) res*=pr;
    }
    return res;
}

int main() {
    fio();
    sv();

    int n,m;
    cin>>n>>m;
    
    vector<int> a(MAX), b(MAX);
    for (int i=1; i<=max(n,m); i++) {
        int x=fct(i);
        if (i<=n) a[x]++;
        if (i<=m) b[x]++;
    }
    
    ll ans=0;
    for (int i=1; i<=max(n,m); i++) {
        ans+=1ll*a[i]*b[i];
    }
    cout<<ans;
    return 0;
}