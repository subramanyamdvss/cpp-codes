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


class Adjlistnode{
public:
	lli num;
	Adjlistnode *next;

};


class Adjlist{
public:
	Adjlistnode* head;
};


class Graph{
public:
	lli V;
	lli E;
	Adjlist* array;
	void initi(lli x){
		array=(Adjlist*) malloc(x*sizeof(Adjlist));
		error(x-1);
		For(i,0,x-1){
			array[i].head=NULL ;
		}
		V=x;
		E=0;

	}
	void insertvertex(Adjlistnode* head,lli numb){
		//Adjlistnode* nd=(Adjlistnode* ) malloc(sizeof(Adjlistnode));
		Adjlistnode* nd;
		nd=(Adjlistnode*)malloc(sizeof(Adjlistnode));
		nd->num=numb;
		nd->next=NULL;
		//nd->num=numb;
		if(head==NULL){
			head=nd;
		}
		else{
			nd->next=head->next;
			head=nd;
		}

	}
	void addedge(lli src,lli dest){
		insertvertex(array[src-1].head,dest);
		E++;
	}
	void printgraph(){
		For(i,0,V-1){
			Adjlistnode* hdn=array[i].head;
			cout<<i+1<<"	";
			while(hdn->next){
				cout<<" --> "<<hdn->num;
				hdn=hdn->next;
			}
			cout<<endl;
		}
	}

};

int main()
{
	lli x;
	cin>>x;
	error(x);
	Graph g;
	g.initi(x);
	For(i,1,3){
		g.addedge(i,i+1);
		g.addedge(i,i+2);
	}
	g.addedge(4,1);
	g.addedge(4,2);
	g.printgraph();
}


