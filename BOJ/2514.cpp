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

int M,K,A[10][10],B[10][10];
char ans[10][10];

int main() {
    fio();
    cin>>M>>K;
    for (int i=1; i<=8; i++) {
        for (int j=1; j<=8; j++) {
            cin>>A[i][j];
            A[i][j]-=M;
            B[i][j]=A[i][j];
        }
    }

    for (int i=1; i<=8; i++) {
        for (int j=1; j<=8; j++) {
            int sum=0;
            for (int k=1; k<=8; k++) sum+=A[i][k];
            for (int k=1; k<=8; k++) sum+=A[k][j];
            sum-=A[i][j];
            
            if (sum%2==0) {
                ans[i][j]='.';
            }
            else {
                for (int k=1; k<=8; k++) B[i][k]+=1;
                for (int k=1; k<=8; k++) B[k][j]+=1;
                B[i][j]-=1;
            }
        }
    }

    for (int i=1; i<=8; i++) {
        for (int j=1; j<=8; j++) {
            if (ans[i][j]=='.') cout<<ans[i][j]<<sp;
            else {
                int sum=0;
                for (int k=1; k<=8; k++) sum+=B[i][k];
                for (int k=1; k<=8; k++) sum+=B[k][j];
                sum-=B[i][j];

                if (sum%4==0) cout<<'-'<<sp;
                else cout<<'+'<<sp;
            }
        } cout<<endl;
    }
    
    
    return 0;
}