#include<bits/stdc++.h>
using namespace std;
#define dd double
#define ll long long int
#define pb push_back
#define light ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define t_pair pair<ll,pair<ll,ll>>
#define I INT_MAX

class Edge{
	public:
		int u;
		int v;
		int wt;
		Edge(){
			
		}
		Edge(int x, int y, int z){
			u = x;
			v = y;
			wt = z;
		}
};
bool EdgeComparator(Edge a, Edge b){
	return a.wt < b.wt;
}

/* This is for ForestSet Representation */

/* Here, I'm using array of v(numbers of vertices) elements as a DS for 
   Forest representation.In this representation representative element 
   will have -ve value and abs value of that -ve value will gives the 
   count of total numbers of elements present under the respective 
   representative element.
*/   
class ForestSet{
	private:
		int size;
		int *S;
	public:
		ForestSet(int x){
			size = x;
			S = new int[x];
		}
		
		void makeSet();
		int find_set(int x);
		void union_set(int x, int y);
};

/* Here I'm not passing any arguments in the makeSet because here
   we are considering vertices are 0, 1, 2 ...... , n-1.
   But In other case, we can simply pass argument as a vertex and
   call makeSet fn for every vertex.
*/
void ForestSet::makeSet(){
	int i;
	// Assigning all the set as -1 meaning that all 
	// are the parent of itself having 1 element.
	for(i=0;i<size;i++){
		S[i] = -1;
	}
}

int ForestSet::find_set(int x){
	if(!(x>=0 && x<size)){
		return -1;
	}
	
	if(S[x] <= 0){
		return x;
	}else{
		// Code for path compression
		return (S[x] = find_set(S[x]));
	}
}

void ForestSet::union_set(int x, int y){
	if((x == y) && x != -1){
		return;
	}
	
	if(S[x] < S[y]){
		// Size(no of elements of given representative element) of x set 
		// is greater so set x will be representative element
		S[x] += S[y];
		S[y] = x;
	}else{
		// Size(no of elements of given representative element) of y set
		// is greater so set y will be representative element
		S[y] += S[x];
		S[x] = y;
	}
}
/*  Upto Here !!!  */

//------------------------------------------------------------------------------------------------------------------------//


/* This is for ListSet Representation */

class Node;
// This class is used for storing details of the representstive element
// of each set
class Set{
	public:
		int sz; // this will store total numbers of element in the given set
		Node *head;
		Node *tail;
		Set(){
			sz = 0;
			head = NULL;
			tail = NULL;
		}
};

// This class is used for storing all the element of a set
class Node{
	public:
		int data;
		Node *next;
		Set *repPtr; // this is pointer to the representative element
		Node(){
			
		}
		Node(int x){
			data = x;
			next = NULL;
			repPtr = NULL;
		}
};

class LinkedListSet{
	private:
		int size;
		Node **sets;
	public:
		LinkedListSet(int n){
			size = n;
			sets = new Node*[n];
		}
		void makeSet();
		Set* find_set(int x);
		void union_set(Set *set1, Set *set2);
};

/* Here I'm not passing any arguments in the makeSet because here
   we are considering vertices as 0, 1, 2 ...... , n-1.
   But In other case, we can simply pass argument as a vertex and
   call makeSet fn for every vertex.
*/
void LinkedListSet::makeSet(){
	for(int i=0;i<size;i++){
		Set *s = new Set();
		s->head = new Node(i);
		s->tail = s->head;
		s->sz = 1;
		sets[i] = s->head;
		s->head->repPtr = s;
	}
}

Set* LinkedListSet::find_set(int x){
	if(!(x>=0 && x<size)){
		return NULL;
	}
	
	return (sets[x]->repPtr); // We are simply returning the address of representative element
}

void LinkedListSet::union_set(Set *set1, Set *set2){
	if((set1 == set2) && !set1){
		return;
	}
	
	Node *p;
	// If condition is for making choice of selecting representative
	// element having greater size
	if((set1->sz) > (set2->sz)){
		(set1->tail)->next = set2->head;
		set1->tail = set2->tail;
		set1->sz += set2->sz;
		
		p = set2->head;
		while(p != NULL){
			p->repPtr = set1;
			p = p->next;
		}
		
		delete set2;
	}else{
		(set2->tail)->next = set1->head;
		set2->tail = set1->tail;
		set2->sz += set1->sz;
		
		p = set1->head;
		while(p != NULL){
			p->repPtr = set2;
			p = p->next;
		}
		
		delete set1;
	}
	
}
/*  Upto Here !!!  */

//------------------------------------------------------------------------------------------------------------------------//

int KruskalAlgo(int n, int e, Edge *edges, int path[][3]){
	
	
	//Uncomment the below two lines(one at a time) for each type of representation.
	
	//ForestSet st(n);
	LinkedListSet st(n);
	
	st.makeSet();
	
	sort(edges, edges+e, EdgeComparator);
	
	int u, v, w, j=0, sum = 0;
	for(int i=0;i<e;i++){
		u = edges[i].u;
		v = edges[i].v;
		w = edges[i].wt;
		
		// This condition will check that whether both vertex(i.e u(src) and v(des))
		// belongs to same set or not. This condition will be true when both doesn't 
		// belongs to the same set.
		if((st.find_set(u) != st.find_set(v))){
			
			path[j][0] = u;
			path[j][1] = v;
			path[j++][2] = w;
	
			st.union_set(st.find_set(u), st.find_set(v));
			
			sum += w;
		}
	}
	
	return sum;	
}

int main()
{
	freopen("inputf.txt", "r", stdin);
	//freopen("outputf.txt", "w", stdout);
	
	//	light;

	ll t;
	cin>>t;
	while(t-- > 0){
		int n, e;
		cin>>n>>e;
		
		Edge *edges = new Edge[e];
			
		int a, b, w, i=0;
		while(i<e){
			cin>>a>>b>>w;
			edges[i++] = Edge(a, b, w);
		}
		
		// This is used for storing the answer
		int mst_path[n-1][3];
		
		int cost = KruskalAlgo(n, e, edges, mst_path);
		
		cout<<"Minimum cost of the MST is "<<cost<<"\n";	
		
		// I have represeted MST by displaying all the solution edges
		// which will be getting used for minimum cost spanning tree. 
		cout<<"Paths of the MST are \n";
		for(int i=0;i<n-1;i++){
			cout<<mst_path[i][0]<<" --> "<<mst_path[i][1]<<" == "<<mst_path[i][2]<<"\n";
		}
		
		cout<<endl;
	}
	return 0;
}

