// **********************************************************************************************************************
// TASK		: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column is set to 0  
// Space	: O(1)
// Time		: O(M*N)
// Author	: Piotr Rżysko
// **********************************************************************************************************************

#include <iostream>
#include <vector>

using namespace std;

#define PB push_back

void setZeros(vector<vector<int> > & matrix)
{
	if(!matrix.empty()){
		int M = matrix.size(), N = matrix[0].size();
		int rowWithTempArray = -1, columnWithTempArray = -1, column = 0, row = 0;
		
		// Check if matrix contains any 0s
		while(row < M && rowWithTempArray < 0){
			while(column < N && rowWithTempArray < 0){
				if(!matrix[row][column]){
					rowWithTempArray = row;
					columnWithTempArray = column;
				}
				column++;
			}
			row++;
			column = 0;
		}
		// Matrix hasn't any 0s, so there are nothing to change 	
		if(rowWithTempArray < 0 && columnWithTempArray < 0) 
			return;

		for(int i = 0; i < M; i++){
			for(int j = 0; j < N; j++){
				if(!matrix[i][j]){
					matrix[rowWithTempArray][j] = 0;
					matrix[i][columnWithTempArray] = 0;
				}
			}
		}
	
		for(int i = 0; i < M; i++){
			// Skip row with temp array
			if(i != rowWithTempArray){
				for(int j = 0; j < N; j++){
					// Skip column with temp array
					if(j != columnWithTempArray){
						if(!matrix[rowWithTempArray][j] || !matrix[i][columnWithTempArray])
							matrix[i][j] = 0;
					}
				}
			}
		}
		
		for(int j = 0; j < N; j++){
			matrix[rowWithTempArray][j] = 0;
		}
		for(int i = 0; i < M; i++){
			matrix[i][columnWithTempArray] = 0;
		}
	}
}

void printVectorOfVector(const vector<vector<int> > & matrix)
{
	for(vector<vector<int> >::const_iterator row_it = matrix.begin(); row_it != matrix.end(); row_it++){
			for(vector<int>::const_iterator col_it = row_it->begin(); col_it != row_it->end(); col_it++)
				cout << *col_it << " ";
			cout << endl;
	}
}


int main()
{
	// Test
	vector<vector<int> > matrix;
	vector<int> row;
	row.PB(1); row.PB(0); row.PB(3);
	matrix.PB(row);
	row.clear();
	row.PB(1); row.PB(5); row.PB(1);
	matrix.PB(row);
	row.clear();
	row.PB(0); row.PB(6); row.PB(1);
	matrix.PB(row);
	row.clear();
	row.PB(7); row.PB(0); row.PB(1);
	matrix.PB(row);
	row.clear();
	
	printVectorOfVector(matrix);
	cout << endl;
	setZeros(matrix);
	printVectorOfVector(matrix);

	return 0;
}
