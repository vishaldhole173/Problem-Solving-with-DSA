/*
Trees are special kind of graphs,where all nodes are inter-connected with eachother & they are acyclic.
In graphs we have cylcles and nodes may or may not be inter-connected
Terminology of graph:-
1.Adjacent nodes: teo vertices having a direct edge
2. degree : number of edges going through the vertex
3. path : collection of edges through which you can go from ine point to another
4. connected graph : for every two vertices there is a path between them
   for 1 connected graph we have 1 connected componant
5. complete graph: every other vectex has edge with every other vertex

For a graph of n vertices:
min edges=0
min edges for connected graph=n-1
number of edges for complete graph : nC2 = n(n-1)/2 O(n*n)
*/

#include<iostream>
using namespace std;
void printDFS(int **edge,int n,int sv,bool* visited)
{
   cout<<sv<<endl;
   visited[sv]=true;
   for (int i = 0; i < n; i++)
   {
      if(i==sv)
      {
         continue;
      }
      if(edge[sv][i]==1)
      {
         if(visited[i])
         {
            continue;
         }
         printDFS(edge,n,i,visited);
      }
   }
   
}


int main()
{
   int n,e;
   int** edge=new int*[n];
   for (int i = 0; i < n; i++)
   {
      edge[i]=new int[n];
      for(int j=0;j<n;j++)
      {
         edge[i][j]=0;
      }
      
   }
   for (int i = 0; i < e; i++)
   {
      int f,s;
      cin>>f>>s;
      edge[f][s]=1;
      edge[s][f]=1;

   }
   bool *visited=new bool[n];
   for (int i = 0; i < n; i++)
   {
      visited[i]=false;
   }
   printDFS(edge,n,0,visited);
   delete[] visited;
   for (int i = 0; i < n; i++)
   {
      delete[] edge[i];
   }
   delete[] edge;
   
}