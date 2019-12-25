# Hello-World
Just Begin

class Solution {
public:
	int maxs=0;
	int res;
	int A[4]={0,1,0,-1};
	int B[4]={1,0,-1,0};
    int largestIsland(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++)
         for(int j=0;j<grid[i].size();j++)
         if(grid[i][j]==0)
         {
         	grid[i][j]=1;
         	res=0;
			DFS(i,j,grid);
			for(int k=0;k<grid.size();k++)
             for(int p=0;p<grid[i].size();p++)
			 if(grid[k][p]==8) grid[k][p]=1;	
			grid[i][j]=0;
		 }
		if(maxs==0) return grid.size()*grid[0].size();
		return maxs;
    }
    void DFS(int x,int y,vector<vector<int>>& grid)
    {
    	res++;
    	maxs=max(maxs,res);
        grid[x][y]=8;
    	for(int i=0;i<4;i++)
    	{
    		int sx=x+A[i];
			int sy=y+B[i]; 
			if(sx>=0&&sx<grid.size()&&sy>=0&&sy<grid[0].size()&&grid[sx][sy]==1)
			 DFS(sx,sy,grid);
		}
	}
};  
