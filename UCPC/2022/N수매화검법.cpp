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

struct P {
    ll x,y;
};

struct ST {
    P p1,p2;
    ll w;
};

int ccw(P p1, P p2, P p3){
	ll t1 = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	ll t2 = p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
	// t1-t2의 부호를 반환
	if(t1==t2) return 0;
	else return t1<t2 ? -1 : 1; 
}

inline bool id(P p1, P p2) {return (p1.x==p2.x && p1.y==p2.y);}

int main() {
    fio();
    int n;
    cin>>n;
    vector<ST> v(n);
    ll ans=0;
    for (auto &[s,e,w]:v) {
        cin>>s.x>>s.y>>e.x>>e.y>>w;
        ans+=w;
    }

    sort(all(v),[](ST a, ST b){
        return a.w<b.w;
    });

    for (int i=0; i<n; i++) {
        auto [s1,e1,w1]=v[i];
        for (int j=i+1; j<n; j++) {
            auto [s2,e2,w2]=v[j];
            int r1=ccw(s1,e1,s2)*ccw(s1,e1,e2);
            int r2=ccw(s2,e2,s1)*ccw(s2,e2,e1);
            if (r1==-1&&r2==-1) {
                ans+=w1;
            }
        }
    }
    
    cout<<ans;
    return 0;
}