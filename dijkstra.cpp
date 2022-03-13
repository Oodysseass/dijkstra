#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

#define MAXN 100005
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f

typedef pair<int,int> pii;

vector< pii > graph[MAXN];
int N,u;
int x,y,aiai;

void Dijkstra_kakos () {
	int i, minim, pick, j, neib, apostasi;
	int dist[MAXN], visited[MAXN];
	
	for ( i=1; i<=N; ++i ) {
		dist[i] = INF;
		visited[i] = 0;
	}
	dist[1] = 0;
	
	for ( i=1; i<=N; ++i ) {
		//Dialego kombo
		minim = INF;
		for ( j=1; j<=N; ++j ) {
			if ( visited[j] == 0 && dist[j] < minim ) {
				minim = dist[j];
				pick = j;
			}
		}
		visited[pick] = 1;
		
		//Beltiono apostaseis geitonon
		for ( j=0; j<graph[pick].size() ; ++j ) {
			neib = graph[pick][j].X;
			apostasi = graph[pick][j].Y;
			if ( dist[ neib ] > dist[ pick ] + apostasi ) {
				dist[neib] = dist[pick] + apostasi;
			}
		}
	}
	
	for ( i=1; i<=N; ++i ) {
		printf ( "%d %d\n", i, dist[i] );
	}
}
/*
//Input d[i][j]
//Complexity O(N^3)
void FloydWarshall() {
	int i, j, k;

	//Den xehnao, prota i epanalipsi me K, allios einai lathos
	for ( k=1; k<=N; ++i ) {
		for ( i=1; i<=N; ++i ) {
			for ( j=1; j<=N; ++j ) {
				if ( d[i][j] > d[i][k] + d[k][j] ) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
}
//Output d[i][j]

*/



void Dijkstra_t (int my) {
	set< pii > dist;
	int d[MAXN];

	int i, pick, neib, apostasi;
	
	for ( i=1; i<=N; ++i ) {
		d[i] = INF;
	}
	d[my] = 0;
	
	for (int i=1; i<=N; ++i ) {
		dist.insert( mp( d[i], i ) ); //prota d[i] kai meta i oste na taxinomithei me apostasi
	}
	
	while ( !dist.empty() ) { //idio me for(i=1; i<=N; ++i)
		//Dialego kombo
		pick = (*dist.begin()).Y;
		dist.erase ( dist.begin() );
		
		//Beltiono apostaseis geitonon
		for ( i=0; i<graph[pick].size() ; ++i ) {
			neib = graph[pick][i].X;
			apostasi = graph[pick][i].Y;
			if ( d[ neib ] > d[ pick ] + apostasi ) {
				dist.erase ( dist.find ( mp ( d[neib], neib) ) ); //moni allagi auti kai i epomeni
				d[neib] = d[pick] + apostasi;
				dist.insert ( mp ( d[neib], neib ) ); //auti einai i epomeni (!)
			}
		}
	}
	int tso=0;
	printf ( "----------------------\n" );
		for (int i=1; i<=N; ++i ) {
			if(d[i]==INF){}
			else if(i==my){}
			else{
				tso++;	
			}
		}
		printf("Connections: %d\n",tso);
		printf ( "----------------------\n" );
}


void connection (int my,int y) {
	set< pii > dist;
	int d[MAXN];

	int i, pick, neib, apostasi;
	
	for ( i=1; i<=N; ++i ) {
		d[i] = INF;
	}
	d[my] = 0;
	
	for (int i=1; i<=N; ++i ) {
		dist.insert( mp( d[i], i ) ); //prota d[i] kai meta i oste na taxinomithei me apostasi
	}
	
	while ( !dist.empty() ) { //idio me for(i=1; i<=N; ++i)
		//Dialego kombo
		pick = (*dist.begin()).Y;
		dist.erase ( dist.begin() );
		
		//Beltiono apostaseis geitonon
		for ( i=0; i<graph[pick].size() ; ++i ) {
			neib = graph[pick][i].X;
			apostasi = graph[pick][i].Y;
			if ( d[ neib ] > d[ pick ] + apostasi ) {
				dist.erase ( dist.find ( mp ( d[neib], neib) ) ); //moni allagi auti kai i epomeni
				d[neib] = d[pick] + apostasi;
				dist.insert ( mp ( d[neib], neib ) ); //auti einai i epomeni (!)
			}
		}
	}
	printf ( "----------------------\n" );
			
			if(d[y]==INF){printf("%d-->%d :There is no way\n",my,y);}
			else{
				printf("%d-->%d :There is a connection\n",my,y);
				}
	printf ( "----------------------\n" );
}
int mosa=0,mosk,moss=MAXN,most;

void Ece (int my) {
	set< pii > dist;
	int d[MAXN];

	int i, pick, neib, apostasi;

	for(int fo=1;fo<=N;fo++){
	 my=fo;
	for ( i=1; i<=N; ++i ) {
		d[i] = INF;
	}
	d[my] = 0;
	
	for (int i=1; i<=N; ++i ) {
		dist.insert( mp( d[i], i ) ); //prota d[i] kai meta i oste na taxinomithei me apostasi
	}
	
	while ( !dist.empty() ) { //idio me for(i=1; i<=N; ++i)
		//Dialego kombo
		pick = (*dist.begin()).Y;
		dist.erase ( dist.begin() );
		
		//Beltiono apostaseis geitonon
		for ( i=0; i<graph[pick].size() ; ++i ) {
			neib = graph[pick][i].X;
			apostasi = graph[pick][i].Y;
			if ( d[ neib ] > d[ pick ] + apostasi ) {
				dist.erase ( dist.find ( mp ( d[neib], neib) ) ); //moni allagi auti kai i epomeni
				d[neib] = d[pick] + apostasi;
				dist.insert ( mp ( d[neib], neib ) ); //auti einai i epomeni (!)
			}
		}
	}
	for (int i=1; i<=N; ++i ) {
			
			if(d[i]==INF){}
			else if(i==my){}
			else{
				if(mosa<d[i]){
					mosa=d[i];
					mosk=my;
					//printf("mpika %d\n",my);
				}
				}

	
	}

	if(moss>mosa){
					moss=mosa;
					most=mosk;
					//printf("mpika 22   %d  %d\n",my,moss);
					mosa=0;
				}
				
	}

}



void Dijkstra_1 (int my) {
	set< pii > dist;
	int d[MAXN];

	int i, pick, neib, apostasi;

	for(int fo=1;fo<=N;fo++){
	 my=fo;
	for ( i=1; i<=N; ++i ) {
		d[i] = INF;
	}
	d[my] = 0;
	
	for (int i=1; i<=N; ++i ) {
		dist.insert( mp( d[i], i ) ); //prota d[i] kai meta i oste na taxinomithei me apostasi
	}
	
	while ( !dist.empty() ) { //idio me for(i=1; i<=N; ++i)
		//Dialego kombo
		pick = (*dist.begin()).Y;
		dist.erase ( dist.begin() );
		
		//Beltiono apostaseis geitonon
		for ( i=0; i<graph[pick].size() ; ++i ) {
			neib = graph[pick][i].X;
			apostasi = graph[pick][i].Y;
			if ( d[ neib ] > d[ pick ] + apostasi ) {
				dist.erase ( dist.find ( mp ( d[neib], neib) ) ); //moni allagi auti kai i epomeni
				d[neib] = d[pick] + apostasi;
				dist.insert ( mp ( d[neib], neib ) ); //auti einai i epomeni (!)
			}
		}
	}
	for (int i=1; i<=N; ++i ) {
			
			if(d[i]==INF){printf("%d-->%d :There is no way\n",my,i);}
			else if(i==my){}
			else{
				printf ( "%d-->%d distance: %d\n", my, i, d[i] );
				}
	
	}
	}
}


void Dijkstra_2 (int my,int y) {
	set< pii > dist;
	int d[MAXN];

	int i, pick, neib, apostasi;
	
	for ( i=1; i<=N; ++i ) {
		d[i] = INF;
	}
	d[my] = 0;
	
	for (int i=1; i<=N; ++i ) {
		dist.insert( mp( d[i], i ) ); //prota d[i] kai meta i oste na taxinomithei me apostasi
	}
	
	while ( !dist.empty() ) { //idio me for(i=1; i<=N; ++i)
		//Dialego kombo
		pick = (*dist.begin()).Y;
		dist.erase ( dist.begin() );
		
		//Beltiono apostaseis geitonon
		for ( i=0; i<graph[pick].size() ; ++i ) {
			neib = graph[pick][i].X;
			apostasi = graph[pick][i].Y;
			if ( d[ neib ] > d[ pick ] + apostasi ) {
				dist.erase ( dist.find ( mp ( d[neib], neib) ) ); //moni allagi auti kai i epomeni
				d[neib] = d[pick] + apostasi;
				dist.insert ( mp ( d[neib], neib ) ); //auti einai i epomeni (!)
			}
		}
	}
	printf ( "----------------------\n" );
			
			if(d[y]==INF){printf("%d-->%d :There is no way\n",my,y);}
			else if(y==my){}
			else{
				printf ( "%d-->%d distance: %d\n", my, y, d[y] );
				}
	printf ( "----------------------\n" );
}



void Dijkstra_3 (int my) {
	set< pii > dist;
	int d[MAXN];

	int i, pick, neib, apostasi;
	
	for ( i=1; i<=N; ++i ) {
		d[i] = INF;
	}
	d[my] = 0;
	
	for (int i=1; i<=N; ++i ) {
		dist.insert( mp( d[i], i ) ); //prota d[i] kai meta i oste na taxinomithei me apostasi
	}
	
	while ( !dist.empty() ) { //idio me for(i=1; i<=N; ++i)
		//Dialego kombo
		pick = (*dist.begin()).Y;
		dist.erase ( dist.begin() );
		
		//Beltiono apostaseis geitonon
		for ( i=0; i<graph[pick].size() ; ++i ) {
			neib = graph[pick][i].X;
			apostasi = graph[pick][i].Y;
			if ( d[ neib ] > d[ pick ] + apostasi ) {
				dist.erase ( dist.find ( mp ( d[neib], neib) ) ); //moni allagi auti kai i epomeni
				d[neib] = d[pick] + apostasi;
				dist.insert ( mp ( d[neib], neib ) ); //auti einai i epomeni (!)
			}
		}
	}
	printf ( "----------------------\n" );
		for (int i=1; i<=N; ++i ) {
			if(d[i]==INF){printf("%d-->%d :There is no way\n",my,i);}
			else if(i==my){}
			else{
				printf ( "%d-->%d distance: %d\n", my, i, d[i] );
			}
		}
		printf ( "----------------------\n" );
}

void Read() {
	int i, a, b, d, M;
	printf("Nodes:");
	scanf ( "%d", &N);
	printf("Edges:");
	scanf ( "%d",&M );

	for ( i=1; i<=M; ++i ) {
		printf("From, To, Weight:");
		scanf ( "%d %d %d", &a, &b, &d );
		graph[a].pb ( mp (b,d) );
		graph[b].pb ( mp (a,d) );
	}
}

int main() {
	printf("\n\n                        Welcome to our Graph program  ");

while(1){
	printf("\n\n1.Shortest Path\n2.Εccentricity\n3.Connection\n4.Exit\n");
	scanf("%d",&u);
	if(u==4){return 0;}
	printf("Form Graph:\n");

	Read();
	
	if(u==1){
		printf("\n1.All distances\n2.Distance from x to y\n3.Distance from x to all\n");
		scanf("%d", &aiai);
		if(aiai==3){
			printf("x=");
			scanf("%d", &x);
			Dijkstra_3(x);
		}
		if(aiai==2){
			printf("x=");
			scanf("%d", &x);
			printf("y=");
			scanf("%d", &y);
			Dijkstra_2(x,y);
		}
		if(aiai==1){
			Dijkstra_1(x);
		}
	}
	else if(u==2){
		Ece(x);
		printf("\nThe most central node is:%d\n", most);
	}
	else if(u==3){
		printf("\n1.Connection x with y\n2.Connections from x\n");
		scanf("%d", &aiai);
		if(aiai==1){
			printf("x=");
			scanf("%d", &x);
			printf("y=");
			scanf("%d", &y);	
			connection(x,y);
		}
		if(aiai==2){
			printf("x=");
			scanf("%d", &x);
			Dijkstra_t(x);
		}
		
	}
}	
	//Dijkstra_kakos();
	//Dijkstra();
	return 0;
}
