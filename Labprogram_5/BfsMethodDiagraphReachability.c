#include<stdio.h>
#define size 20
#define true 1
#define false 0

int queue[size],visit[20],rear=-1,front=0;
int n,s,adj[20][20],flag=0;

// 1) INSERT FUNCTION
void insertq(int v){
    queue[++rear]=v;
}

// 2) DELETE FUNCTION
int deleteq(){
return(queue[front++]);
}

// 3) EMPTY FUNCTION
int qempty(){
  if(rear<front)
    return 1;
  else
    return 0;
}

// 4) BREADTH FIRST SEARCH TECHNIQUE
void bfs(int v){
int w;
visit[v]=1;
insertq(v);
while(!qempty()){
    v=deleteq();
    for(w=1;w<=n;w++)
       if((adj[v][w]==1) && (visit[w]==0)){
              visit[w]=1;
              flag=1;
              printf("v%d\t",w);
              insertq(w);
       }
   }
}

// 5) MAIN FUNCTION
void main(){
    int v,w;
    printf("ENTER THE NO OF VERTICES : ");
    scanf("%d",&n);
    printf("ENTER THE ADJACENCY MATRIX : \n");
    for(v=1;v<=n;v++){
      for(w=1;w<=n;w++)
       scanf("%d",&adj[v][w]);
    }
    printf("=> ENTER THE START VERTEX : ");
    scanf("%d",&s);
    printf("=> REACHABILITY OF VERTEX : %d\n",s);
    for(v=1;v<=n;v++)
            visit[v]=0;
    bfs(s);
    if(flag==0){
      printf("=> NO PATH AVAILABLE \n");
    }
}

/* 1)  => VERTICES - 4 (NO PATH AVAILABILTY)
       => A.MATRIX
           0 1 0 0
           0 0 1 1 
           0 0 0 0
           1 0 1 0
       => START VERTEX - 3

    2) => VERTICES - 4 (PATH AVAILABILTY)
       =>  A.MATRIX
           0 1 0 0 
           0 0 1 1
           0 0 0 0
           1 0 1 0
       => START VERTEX - 4
*/