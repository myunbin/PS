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

struct pt{
    ll x,y1,y2,s;
};

int main() {
    fio();
    int n;
    cin>>n;

    vector<pt> a;
    for (int i=0; i<n; i++) {
        double x,y,w,h;
        cin>>x>>y>>w>>h;
        ll x1,x2,y1,y2;
        x*=10, y*=10, w*=10, h*=10;
        x1=(ll)x, x2=x1+(ll)w, y1=(ll)y, y2=y1+(ll)h;
        a.pb({x1,y1,y2,1});
        a.pb({x2,y1,y2,-1});
    }
    sort(all(a),[](pt a, pt b){
        return a.x<b.x;
    });

    int xl=0;
    ll ans=0;
    ll on[20202]={0};
    for (int i=0; i<2*n; i++) {
        ll cnt=0;
        for (int j=0; j<20202; j++) cnt+=(on[j]>0);
        ans+=cnt*(a[i].x-xl);

        for (int j=a[i].y1; j<a[i].y2; j++) on[j]+=a[i].s;
        xl=a[i].x;
    }
    
    if (ans%100==0) cout<<(ans/100);
    else {
        double res=(double)ans/100.0;
        cout.precision(2);
        cout<<fixed;
        cout<<res;
    }
    return 0;
}