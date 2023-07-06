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
const int MAX = 202020; // PLZ CHK!

int n,a[MAX],b[MAX],c[MAX*2],d[MAX];
int f[MAX*2];

int main() {
    fio();
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    for (int i=0; i<n; i++) cin>>b[i];
    sort(a,a+n), sort(b,b+n);

    const int CL=360000;
    for (int i=0; i<n; i++) {
        c[i]=(a[(i+1)%n]-a[i]+CL)%CL, c[i+n]=c[i];
        d[i]=(b[(i+1)%n]-b[i]+CL)%CL;
    }

    // for (int i=0; i<n; i++) cout<<c[i]<<sp; cout<<endl;
    // for (int i=0; i<n; i++) cout<<d[i]<<sp; cout<<endl;

    for (int i=1,j=0; i<MAX; i++) {
        while (j && d[i]!=d[j]) j=f[j-1];
        if (d[i]==d[j]) f[i]=(++j);
    }

    for (int i=0,j=0; i<2*n; i++) {
        while (j && c[i]!=d[j]) j=f[j-1];
        if (c[i]==d[j]) {
            if (j==n-1) {
                cout<<"possible";
                return 0;
            }
            else j++;
        }
    }

    cout<<"impossible";
    return 0;
}