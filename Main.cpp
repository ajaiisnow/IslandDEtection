#include <iostream>
#include <vector>
using namespace std;

void detect_island_util(vector<vector<int>>& mat, int i, int j)
{
	if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size() || mat[i][j] != 1)
	{
		return;
	}
	
	mat[i][j] = 2;
	detect_island_util(mat, i - 1, j);
	detect_island_util(mat, i + 1, j);
	detect_island_util(mat, i, j - 1);
	detect_island_util(mat, i, j + 1); 
}


int detect_island( vector<vector<int>>& mat)
{
	int island = 0;
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[0].size(); j++)
		{
			if (mat[i][j] == 1)
			{
				detect_island_util(mat, i, j);
				island += 1;
			}
		}
	}
	
	return island;
}


int main(int argc, char** argv)
{
	vector<vector<int>> mat = { { 0,0,0,0,1} ,{1,1,0,0,1},{0,0,0,0,0},{0,1,0,0,1},{0,1,0,0,0} };
	cout << "Number of islands:" << detect_island(mat);
	return 0;
}
