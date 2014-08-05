/*Implementation of Breadth First Search*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define n 1000
vector <bool> vis;  // creating vector bool a spl kind of template
int matrix[n][n];
//structure node
struct node
{
	int x;		//value of node
	int len;	// gives position of node relative to root node
	node(int a,int b)
	{
		x=a;
		len=b;
	}
};

//bfs function
int bfs(int source,int target )
{
	vis=vector<bool>(n,false); // assign bool vector of length n as false
	queue <node> q;				// queue for operations
	node src=node(source,0);	//make intege value of souce as node and at zero distance from source
	if(source==target)
	return 0;	
	q.push(src);				//push source in queue
	vis[src.x]=true;			//make visited of that index as true
	cout<<q.size()<<"\n";
	while(!q.empty())
	{
		node curr=q.front();	//get current node
		cout<<q.size()<<"\n";
		q.pop();				//delete current node which is on top
		for(int j=0;j<n;++j)
		{
			if(!vis[j]&&matrix[curr.x][j])  // if we get an index which is not visited
			{
				
				q.push(node(j,curr.len+1));		//push current in queue
				vis[j]=true;				//make its visited true
				if(j==target)
				return(curr.len+1);			// if we get target we return its posititon
			}
		}
	}
	return -1;					// if all conditions fail
}
int main()
{
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			matrix[i][j]=0;
		}
	}
	matrix[1][2]=1;  //matrix formed from adjacency matrix
	matrix[1][3]=1;
	matrix[1][4]=1;
	matrix[2][1]=1;
	matrix[2][5]=1;
	matrix[2][6]=1;
	matrix[3][1]=1;
	matrix[3][7]=1;
	matrix[3][8]=1;
	matrix[4][1]=1;
	matrix[5][2]=1;
	matrix[6][2]=1;
	matrix[6][9]=1;
	matrix[6][10]=1;
	matrix[7][3]=1;
	matrix[8][3]=1;
	matrix[8][12]=1;
	matrix[9][6]=1;
	matrix[10][6]=1;
	matrix[10][11]=1;
	matrix[12][8]=1;
	matrix[11][10]=1;
	cout<<"ans:"<<bfs(1,12);
}
