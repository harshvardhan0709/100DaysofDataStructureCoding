/*
    Time Complexity  =  O(Elog(V))
 
    1) Initialize distances of all vertices as infinite.

2) Create an empty priority_queue pq.  Every item
   of pq is a pair (weight, vertex). Weight (or 
   distance) is used used as first item  of pair
   as first item is by default used to compare
   two pairs

3) Insert source vertex into pq and make its
   distance as 0.

4) While either pq doesn't become empty
    a) Extract minimum distance vertex from pq. 
       Let the extracted vertex be u.
    b) Loop through all adjacent of u and do 
       following for every vertex v.

           // If there is a shorter path to v
           // through u. 
           If dist[v] > dist[u] + weight(u, v)

               (i) Update distance of v, i.e., do
                     dist[v] = dist[u] + weight(u, v)
               (ii) Insert v into the pq (Even if v is
                    already there)
               
5) Print distance array dist[] to print all shortest
   paths. 
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 0x3f3f3f3f

typedef pair<int,int> iPair;

void addEdge(vector<pair<int,int>> adj[],int u,int v,int wt){
    adj[u].push_back(make_pair(v,wt));
    adj[v].push_back(make_pair(u,wt));
}

void shortestPath(vector<pair<int,int>> adj[],int V,int src){
    priority_queue<iPair,vector<iPair>,greater<iPair>> pq;

    vector<int> dist(V,INF);

    pq.push(make_pair(0,src));
    dist[src] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        for(auto x : adj[u]){
            int v = x.first;
            int weight = x.second;

            if(dist[v] > dist[u]+weight){
                dist[v] = dist[u] +weight;
                pq.push(make_pair(dist[v],v));
            }
        }
    }

    cout<<"Vectex Distacne from source \n";
    for(int i =0;i < V; i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
}

int main(){
    int V = 9;
    vector<iPair> adj[V];
    addEdge(adj, 0, 1, 4); 
    addEdge(adj, 0, 7, 8); 
    addEdge(adj, 1, 2, 8); 
    addEdge(adj, 1, 7, 11); 
    addEdge(adj, 2, 3, 7); 
    addEdge(adj, 2, 8, 2); 
    addEdge(adj, 2, 5, 4); 
    addEdge(adj, 3, 4, 9); 
    addEdge(adj, 3, 5, 14); 
    addEdge(adj, 4, 5, 10); 
    addEdge(adj, 5, 6, 2); 
    addEdge(adj, 6, 7, 1); 
    addEdge(adj, 6, 8, 6); 
    addEdge(adj, 7, 8, 7);

    shortestPath(adj,V,0);
    return 0;
}