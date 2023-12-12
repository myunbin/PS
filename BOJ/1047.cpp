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
const int MAX = 44; // PLZ CHK!

struct tree {
    int x,y,z;
};

int N;
vector<int> X,Y;
tree A[MAX];

int main() {
    fio();
    cin>>N;
    for (int i=0; i<N; i++) {
        cin>>A[i].x>>A[i].y>>A[i].z;
        X.pb(A[i].x), Y.pb(A[i].y);
    }

    cmprs(X),cmprs(Y);
    int sx=sz(X),sy=sz(Y);

    int ans=N-1;
    for (int i=0; i<sx; i++) {
        for (int j=i+1; j<sx; j++) {
            for (int k=0; k<sy; k++) {
                for (int l=k+1; l<sy; l++) {
                    int x1=X[i],x2=X[j],y1=Y[k],y2=Y[l];
                    int sum=0,cnt=0;
                    vector<tree> T;
                    for (int m=0; m<N; m++) {
                        if (x1<=A[m].x && A[m].x<=x2 && y1<=A[m].y && A[m].y<=y2) {
                            T.pb(A[m]);
                            continue;
                        }
                        sum+=A[m].z;
                        cnt++;
                    }

                    sort(all(T), [](tree a, tree b){
                        return a.z>b.z;
                    });

                    for (int m=0; m<sz(T) && sum<2*(x2-x1+y2-y1); m++) {
                        sum+=T[m].z;
                        cnt++;
                    }

                    if (sum>=2*(x2-x1+y2-y1)) ans=min(ans, cnt);
                }
            }
        }
    }
    cout<<ans;
    return 0;
}