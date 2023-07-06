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
const int MAX = 1000000; // PLZ CHK!

int mp[MAX];
map<int,int> cp, cnt[111];

void sv() {
    for (int i=2; i<MAX; i++) mp[i]=i;
    for (int i=4; i<MAX; i+=2) mp[i]=2;
    for (int i=3; i*i<MAX; i++) {
        if (mp[i]!=i) continue;
        for (int j=i*i; j<MAX; j+=i) mp[j]=i;
    }
}

void fct(int x, map<int,int> &m) {
    while (x != 1) {
        m[mp[x]]++;
        x/=mp[x];
    }
}

int main() {
    fio();
    sv();
    int n;
    cin>>n;

    for (int i=0; i<n; i++) {
        int x; cin>>x;
        fct(x,cp), fct(x,cnt[i]);                
    }

    int g=1, ans1=0, ans2=0;
    for (auto [pr,cc]:cp) {
        int d=cc/n;
        if (d==0) continue;
        
        for (int i=0; i<d; i++) g*=pr;
        for (int i=0; i<n; i++) {
            if (d>cnt[i][pr]) ans1+=(d-cnt[i][pr]);
            if (d<cnt[i][pr]) ans2+=(cnt[i][pr]-d);
        }
    }
    cout<<g<<sp<<ans1<<sp<<ans2;
    return 0;
}