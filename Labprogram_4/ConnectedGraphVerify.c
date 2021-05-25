#include<stdio.h>
#include<stdlib.h>

int a[10][10],vis[10],n,count;
// 1) APPROACH BY DFS METHOD
void dfs(int v){
int i;
vis[v]=1;
count=count+1;
printf("%d,",v);
for(i=1;i<=n;i++){
if(a[v][i]==1 && vis[i]==0)
  dfs(i);
}
}

// 2) MAIN FUNCTION
void main(){
int i,j,src;
printf("enter number of vertices\n");
scanf("%d",&n);
printf("enter adjacency matrix\n");
for(i=1;i<=n;i++){
for(j=1;j<=n;j++){
scanf("%d", &a[i][j]);
}
}
for(i=1;i<=n;i++)
 vis[i]=0;
printf("enter source vertex\n");
scanf("%d",&src);
printf("-->Nodes reachable from vertex : \n %d",src);
dfs(src);
if(count==n){
    printf("\n-->Graph is connected\n");
}
else{
    printf("-->Graph is not connected");
}
}

/*
1) CONNECTED GRAPH (ADJACENCY MATRIX)
0 0 1 1 1,   0 0 0 1 1, 1 0 0 1 0,  1 1 1 0 0,  1 1 0 0 0

2) DISCONNECTED GRAPH (ADJACENCY MATRIX)
0 1 0 0 0 0,  1 0 0 1 1 0, 0 0 0 1 1 0, 0 1 1 0 0 0, 0 1 1 0 0 0, 0 0 0 0 0 0
*/