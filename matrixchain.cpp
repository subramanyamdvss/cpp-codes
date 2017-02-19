#include <bits/stdc++.h>
using namespace std;

typedef  long long lli;
typedef vector< long long int > vi;
typedef  double d;
typedef  pair<lli,pair<lli,lli> >  pipii;
#define bg begin()
#define rbg rbegin()
#define ren rend()
#define en end()
#define f first
#define s second
#define For(ii,aa,bb) for(lli ii=aa;ii<=bb;++ii)
#define Rof(ii,aa,bb) for(lli ii=aa;ii>=bb;--ii)
#define pb push_back
#define minf(a,b,c) min(min(a,b),c)
#define maxf(a,b,c) max(max(a,b),c)
#define mp make_pair
#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }

vector<string> split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c))
		v.emplace_back(x);
	return move(v);
}

void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
	cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
	err(++it, args...);
}
/// ********* debug template bt Bidhan Roy *********

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

#define deb(x) cerr << #x << " = " << x << endl;

void printm(lli i,lli j,lli n,lli ck[1000][1000]){
    if(i==j){
        cout<<"elem";
        return;
    } 
    cout<<"( ";
    printm(i,ck[i][j],n,ck);
    
    printm(ck[i][j]+1,j,n,ck);
    cout<<") ";    
}

lli matrixchain(lli n,lli p[],lli  ck[1000][1000]){
    
    lli S[n][n];
    For(i,1,n-1) S[i][i]=0;
    if(n==1) return S[1][1];
    For(l,2,n-1){
        For(i,1,n-l){
            lli mini=INT_MAX;
            lli cnt;
            For(k,i,i+l-2){
                if(S[i][k]+S[k+1][i+l-1]+p[i]*p[k+1]*p[i+l]>=mini) cnt=k;
                mini=min(mini,S[i][k]+S[k+1][i+l-1]+p[i]*p[k+1]*p[i+l]);
            }
            S[i][i+l-1]=mini;
            ck[i][i+l-1]=cnt;
        }
    }
    For(i,1,n-1) ck[i][i]=-1;
    
    return S[1][n-1];
}





int main(){
    lli n;
    cout<<"enter the value of n\n";
    cin>>n;
    lli p[n+1];
    cout<<" enter the values of dimensions:\n";
    For(i,1,n){
        cin>>p[i];
    }
    lli ck[1000][1000];
    cout<<matrixchain(n,p,ck)<<endl;
    printm(1,n-1,n,ck);
    // cout<<ck[1][n-1]<<endl;
    //printm(n,ck);

}




