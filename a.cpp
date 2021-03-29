#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int array[4][4];
    cout<<"enter elements of array";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; i < 4; j++)
        {
            cin>>array[i][j];
        }
        
    }
    int startRow = 0;
int endRow = sizeof(array) - 1;
int startCol = 0;
int endCol = sizeof(array[0]) - 1;
  vector<int> result = {};
while (startCol<=endCol && startRow<=endRow)
{
    for (int  col=startCol; col <= endCol; col++)
    {
        result.push_back(array[startRow][col]);
    }
    for (int row = startRow+1; row <= endRow; row++)
    {
        result.push_back(array[row][endCol]);
    }
    for(int col=endCol-1;col>=startCol;col--)
    {
        if(startCol==endCol)
        {
            break;
        }
        else
        {
            result.push_back(array[endRow][col]);
        }
        
    }
    for(int row=endRow-1;row>startRow;row--)
    {
        result.push_back(array[row][startCol]);
    }
    startCol++;
    startRow++;
    endCol--;
    endRow--;
}

for (int i = 0; i < result.size(); i++)
    {
        cout<<result[i]<<" ";
    }
  return 0;      
}











// using namespace std;
 // O(n) time | O(n) space - where n is the total number of eleme
// vector<int> spiralTraverse(vector<vector<int>> array) {
// if (array.size() == 0)
// return {};
// vector<int> result = {};
// int startRow = 0;
// int endRow = array.size() - 1;
// int startCol = 0;
// int endCol = array[0].size() - 1;
// while (startRow <= endRow && startCol <= endCol) {
// for (int col = startCol; col <= endCol; col++) {
// result.push_back(array[startRow][col]);
// }
// for (int row = startRow + 1; row <= endRow; row++) {
// result.push_back(array[row][endCol]);
// }
// for (int col = endCol - 1; col >= startCol; col--) {
// if (startRow == endRow)
// break;
// result.push_back(array[endRow][col]);
// }
// for (int row = endRow - 1; row > startRow; row--) {
// if (startCol == endCol)
// break;