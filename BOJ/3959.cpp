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

double j,p,H,L;

double h(double x) {
    if (x<0) return H;
    if (0<=x && x<L/2.0) return H*(1.0-2.0*(x/L)*(x/L));
    if (L/2.0<=x && x<L) return 2.0*H*(x/L-1.0)*(x/L-1.0);
    return 0.0;
}

double hp(double x) {
    if (x<0) return 0.0;
    if (0<=x && x<L/2.0) return -4.0*H*x/(L*L);
    if (L/2.0<=x && x<L) return 4.0*H/L*(x/L-1.0);
    return 0.0;
}

const double G=9.81;
const double eps=1e-9;
const double pi=acos(-1);

double f(double x) {
    double v0=sqrt(2.0*G*j);
    return -G/2.0*(x/v0)*(x/v0)+H+p;
}

double fp(double x) {
    double v0=sqrt(2.0*G*j);
    return -G*x/(v0*v0);
}

void solve() {
    cin>>j>>p>>H>>L;
    
    double le=0.0, ri=1e9, X=0.0;
    while (abs(le-ri)>eps) {
        double md=(le+ri)/2.0;
        if (f(md)-h(md)>eps) {
            X=md;
            le=md;
        }
        else ri=md;
    }

    double K=G*(H+p+j);
    double Y=f(X);

    double V=sqrt(2.0*(K-G*Y));
    double FP=fp(X), HP=hp(X);
    double A=acos((1.0+FP*HP)/(sqrt((1.0+FP*FP)*(1.0+HP*HP))))*180.0/pi;

    cout<<fixed; cout.precision(10);
    cout<<X<<sp<<V<<sp<<A<<endl;
}

int main() {
    fio();
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}