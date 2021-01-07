#include<iostream>
#include<stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define INFINIT 9999
#define max 14
void dijkstra(int G[max][max],int n,int startnode);
int v;
int Trans_type[max][max]={{0,3,1,0,2,0,3,4,0,1,2,2,4},
                          {3,0,2,0,3,0,0,0,0,0,0,0,0},
                          {1,2,0,0,0,0,2,0,0,0,0,0,0},
                          {0,0,0,0,3,0,0,0,0,0,0,0,2},
                          {2,3,0,3,0,0,0,0,0,0,0,0,2},
                          {0,0,0,0,0,0,0,0,2,3,4,0,0},
                          {3,0,1,0,0,0,0,3,0,3,0,0,0},
                          {4,0,0,0,0,0,3,0,4,4,0,0,0},
                          {0,0,0,0,0,2,0,4,0,3,3,0,0},
                          {1,0,0,0,0,3,3,4,3,0,0,0,0},
                          {2,0,0,0,0,4,0,4,2,0,0,4,0},
                          {2,0,0,0,0,0,0,0,0,0,4,0,3},
                          {4,0,0,2,2,0,0,0,0,0,0,3,0}};
char ride_on[4][15] = {"cng", "direct_bus", "local_bus", "train"};
char city[14][15] = {"dhaka", "narayanganj", "munshiganj", "chittagong","chadpur","mymensingh","savar","tongi","gazipur","kaliakair","narshindi","rcomilla","feni"};
int main() {
    printf("****Welcome to Low Cost Travel***\n");
    int lb;
    printf("Please Select the Time\n");
    printf("6:00 A.M to 11:59 P.M == press 1\n");
    printf("12:00 A.M to 5:59 A.M == press 0\n");
    scanf("%d",&lb);
    if(lb==0)
    {
        printf("----Notice:sorry no local bus is available----\n\n");
    }
   int G[max][max]={{0,30*lb,400,0,140,0,80*lb,20,0,300,200,160,150},
                    {30*lb,0,60,0,50*lb,0,0,0,0,0,0,0,0},
                    {400,60,0,0,0,0,300,0,0,0,0,0,0},
                    {0,0,0,0,250*lb,0,0,0,0,0,0,0,200},
                    {140,50*lb,0,250*lb,0,0,0,0,0,0,0,0,100},
                    {0,0,0,0,0,0,0,0,50,100*lb,120,0,0},
                    {80*lb,0,300,0,0,0,0,50*lb,0,100,0,0,0},
                    {20,0,0,0,0,0,50*lb,0,30,50,0,0,0},
                    {0,0,0,0,0,50,0,30,0,30*lb,100,0,0},
                    {300,0,0,0,0,100*lb,100*lb,50,30*lb,0,0,0,0},
                    {200,0,0,0,0,120,0,50,100,0,0,100,0},
                    {160,0,0,0,0,0,0,0,0,0,100,0,50*lb},
                    {150,0,0,200,100,0,0,0,0,0,0,50*lb,0}};

   int n=13;
   int u; //source node
   printf("\nList of the Station\n");
   printf(" 0=Dhaka\n");
   printf(" 1=Narayanganj\n");
   printf(" 2=Munshiganj\n");
   printf(" 3=Chittagong\n");
   printf(" 4=Chadpur\n");
   printf(" 5=Mymensingh\n");
   printf(" 6=Savar\n");
   printf(" 7=Tongi\n");
   printf(" 8=Gazipur\n");
   printf(" 9=Kaliakair\n");
   printf(" 10=Narshindi\n");
   printf(" 11=Comilla\n");
   printf(" 12=Feni\n\n");


   printf("**Enter Source**\n");
   scanf("%d",&u);

    printf("**Enter destination**\n");
   scanf("%d",&v);
   dijkstra(G,n,u);
   return 0;
}
void dijkstra(int G[max][max],int n,int startnode) {
   int cost[max][max],distance[max],pred[max];
   int visited[max],count,mindistance,nextnode,i,j;
   for(i=0;i<n;i++)
      for(j=0;j<n;j++)
   if(G[i][j]==0)
      cost[i][j]=INFINIT;
   else
      cost[i][j]=G[i][j];
   for(i=0;i<n;i++) {
      distance[i]=cost[startnode][i];
      pred[i]=startnode;
      visited[i]=0;
   }
   distance[startnode]=0;
   visited[startnode]=1;
   count=1;
   while(count<n-1) {
      mindistance=INFINIT;
      for(i=0;i<n;i++)
         if(distance[i]<mindistance&&!visited[i]) {
         mindistance=distance[i];
         nextnode=i;
      }
      visited[nextnode]=1;
      for(i=0;i<n;i++)
         if(!visited[i])
      if(mindistance+cost[nextnode][i]<distance[i]) {
         distance[i]=mindistance+cost[nextnode][i];
         pred[i]=nextnode;
      }
      count++;
   }
   for(i=0;i<n;i++)

   if(i==v)//destination node 4
    {
   if(i!=startnode) {

      printf("Your source is %s and destination is %s \n",city[startnode],city[i]);
      printf(" RESULT: Minimum cost of your journey is %d TK\n",distance[i]);
       printf(" PLease follow the path from the bottom \n");

      j=i;
      do {
         int k=j;
         j=pred[j];

          printf(" Go %s to %s",city[j],city[k]);
          printf(",cost is %d taka ,use %s \n ",G[k][j],ride_on[Trans_type[k][j]-1]);

      }while(j!=startnode);
   }

   }
}

