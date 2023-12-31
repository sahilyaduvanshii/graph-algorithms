#include<bits/stdc++.h>
using namespace std;

class Edge{
  public:
  int source;
  int dest;
  int weight;
};

bool compare(Edge e1,Edge e2){
    return e1.weight<e2.weight;
}
int findParent(int v,int*parent){
    if(parent[v]==v) return v;
    return findParent(parent[v],parent);
}
void kruskals(Edge*input,int n,int E){
  sort(input,input+E,compare);
  Edge*output=new Edge[n-1];
  int*parent=new int[n];
  for(int i=0;i<n;i++){
    parent[i]=i;
  }
  int i=0,count=0;
  while(count!=n-1){
    Edge currentEdge=input[i];
    int sourceParent=findParent(currentEdge.source,parent);
    int destParent=findParent(currentEdge.dest,parent);
    if(sourceParent!=destParent){
        output[count++]=currentEdge;
        parent[sourceParent]=destParent;
    }
    i++;
  }
  for(int i=0;i<n-1;i++){
    cout<<output[i].source<<" ";
    cout<<output[i].dest<<" ";
    cout<<output[i].weight<<endl;

  }
}

int main()
{
    int n,e;
    cin>>n>>e;
    Edge*input=new Edge[e];
    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;
        input[i].source=s;
        input[i].dest=d;
        input[i].weight=w;
    }
    kruskals(input,n,e);

 return 0;
}
