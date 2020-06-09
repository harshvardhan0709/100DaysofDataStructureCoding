#include<iostream>
#include<list>

using namespace std;

struct Graph{
    int V;
    list<int> *adj;

    Graph(int V){
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int u,int v){
        adj[u].push_back(v);
    }

    bool isCyclic();

    bool isCyclicUtil(int v,bool visited[],bool *rs);

};

bool Graph::isCyclicUtil(int v,bool visited[],bool *recStack){

    if(visited[v] == false){
        visited[v] = true;
        recStack[v] = true;

        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); i++){
            if(!visited[*i] && isCyclicUtil(*i, visited, recStack))
                return true;
            else if(recStack[*i])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}

bool Graph::isCyclic(){
    bool *visited = new bool[V];
    bool *recStack = new bool[V];

    for(int i =0; i<V; i++){
        visited[i] = false;
        recStack[i] = false;
    }

    for(int i=0; i<V; i++){
        if(isCyclicUtil(i,visited,recStack))
            return true;
    }
    return false;
}

int main(){
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    if(g.isCyclic()) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle"; 
    return 0;
}