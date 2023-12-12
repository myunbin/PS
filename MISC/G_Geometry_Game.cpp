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

pll A[4];
ll B[4];

int main() {
    fio();
    for (int i=0; i<4; i++) cin>>A[i].F>>A[i].S;
    for (int i=0; i<4; i++) 
        B[i]=(A[i].F-A[(i+1)%4].F)*(A[i].F-A[(i+1)%4].F)+(A[i].S-A[(i+1)%4].S)*(A[i].S-A[(i+1)%4].S);

    sort(B,B+4);
    if (B[0]==B[1] && B[1]==B[2] && B[2]==B[3]) {
        if ((A[0].F-A[1].F)*(A[2].F-A[1].F)+(A[0].S-A[1].S)*(A[2].S-A[1].S)==0) cout<<"square";
        else cout<<"rhombus";
    }
    else if (B[0]==B[1] && B[2]==B[3]) {
        if ((A[0].F-A[1].F)*(A[2].F-A[1].F)+(A[0].S-A[1].S)*(A[2].S-A[1].S)==0 && A[1].F-A[0].F+A[3].F-A[2].F==0 && A[1].S-A[0].S+A[3].S-A[2].S==0) cout<<"rectangle";
        else if (A[1].F-A[0].F+A[3].F-A[2].F==0 && A[1].S-A[0].S+A[3].S-A[2].S==0) cout<<"parallelogram";
        else cout<<"kite";
    }
    else if ((A[1].S-A[0].S)*(A[3].F-A[2].F)==(A[3].S-A[2].S)*(A[1].F-A[0].F)){
        cout<<"trapezium";
    }
    else if ((A[3].S-A[0].S)*(A[2].F-A[1].F)==(A[2].S-A[1].S)*(A[3].F-A[0].F)) {
        cout<<"trapezium";
    }
    else cout<<"none";

    return 0;
}