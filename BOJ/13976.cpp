#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("boards.txt");ofstream file_out("boards.txt")
#define f first
#define s second
//#define double long double
#define db double
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
const int MOD = 1e9+7;
const ll LMOD = 1e9+7; // PLZ check
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 5;
int sz=2;
struct mat {
	ll m[MAXN][MAXN] = {0};
	mat operator * (mat x) const {
		mat ret;
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				for (int k = 0; k < sz; k++) {
					ret.m[i][j] += (m[i][k]*x.m[k][j])%LMOD;
					ret.m[i][j] = (ret.m[i][j]+LMOD)%LMOD;
				}
			}
		}
		return ret;
	}
};

mat id;
mat go(mat a, ll m) {
	if (m == 0) return id;
	if (m%2 == 1) return a*go(a, m-1);
	mat t = go(a, m>>1); return t*t;
}

int main() {
	fio();

    for (int i=0; i<sz; i++) id.m[i][i]=1;

    ll n;
    cin>>n;
    
    if (n&1) {
        cout<<0;
        return 0;
    }

    mat k; 
    k.m[0][0]=4, k.m[0][1]=-1;
    k.m[1][0]=1, k.m[1][1]=0;

    mat i;
    i.m[0][0]=3;
    i.m[1][0]=1;
    
    mat r=go(k, (n-2)/2)*i;
    cout<<r.m[0][0]%LMOD;
	return 0;
}