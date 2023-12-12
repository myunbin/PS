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
const int MAX = 101010; // PLZ CHK!

int N;
double A;
array<int,3> B[MAX];

int main() {
    fio();
    cin>>N>>A;
    for (int i=0; i<N; i++) {
        cin>>B[i][0]>>B[i][1]>>B[i][2];   
    }

    sort(B,B+N,[](auto a, auto b){
        return a[0]*a[0]+a[1]*a[1]<b[0]*b[0]+b[1]*b[1];
    });

    double ans=0.0, w=0, wd=0;
    for (int i=0; i<N; i++) {
        w+=1.0*B[i][2];
        wd+=1.0*B[i][2]*sqrt(B[i][0]*B[i][0]+B[i][1]*B[i][1]);

        double r=w/(2.0*A);
        double f=-A*r*r+r*w-wd;

        ans=max(ans, f);
    }

    cout<<fixed;
    cout.precision(10);
    cout<<ans;
    return 0;
}