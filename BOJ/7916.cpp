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

typedef array<__int128,3> vecL;

int N;
vecL P[MAX];

vecL per(vecL a, vecL b) {
    auto [x1,y1,z1]=a; auto [x2,y2,z2]=b;
    __int128 x=y1*z2-z1*y2, y=-x1*z2+z1*x2, z=x1*y2-y1*x2;
    return vecL{x,y,z};
}

int in(vecL a, vecL b) {
    __int128 x=a[0]*b[0], y=a[1]*b[1], z=a[2]*b[2];
    if (x+y+z==0) return 1;
    return 0;
}

int main() {
    fio();
    cin>>N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<3; j++) {
            ll t; cin>>t;
            P[i][j]=t;
        }
    }

    vecL n;
    for (int i=2; i<N; i++) {
        vecL a={P[1][0]-P[0][0], P[1][1]-P[0][1], P[1][2]-P[0][2]};
        vecL b={P[i][0]-P[0][0], P[i][1]-P[0][1], P[i][2]-P[0][2]};
        n=per(a,b);

        if (n!=vecL{0,0,0}) break;
    }

    if (N<=3 || n==vecL{0,0,0}) {
        cout<<"TAK";
        return 0;
    }

    bool ans=1;
    for (int i=2; i<N; i++) {
        vecL a={P[i][0]-P[0][0], P[i][1]-P[0][1], P[i][2]-P[0][2]};
        ans&=in(n,a);
    }

    cout<<(ans?"TAK":"NIE");
    return 0;
}