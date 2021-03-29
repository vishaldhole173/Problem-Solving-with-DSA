// C++ program for the above approach 
#include<bits/stdc++.h>
using namespace std;

// Function to return the list of 
// minimum peak elements 
void minPeaks(vector<int>list) 
{
	
	// Length of original list 
	int n = list.size(); 
	
	// Initialize resultant list 
	vector<int>result;

	// Traverse each element of list 
	for(int i = 0; i < n; i++)
	{ 
		int min = INT_MAX;
		int index = -1; 

		// Length of original list after 
		// removing the peak element 
		int size = list.size(); 

		// Traverse new list after removal 
		// of previous min peak element 
		for(int j = 0; j < size; j++)
		{ 
			
			// Update min and index, 
			// if first element of 
			// list > next element 
			if (j == 0 && j + 1 < size)
			{ 
				if (list[j] > list[j + 1] && 
						min > list[j])
				{ 
					min = list[j]; 
					index = j; 
				} 
			} 

			else if (j == size - 1 && 
					j - 1 >= 0)
			{ 
				
				// Update min and index, 
				// if last elemnt of 
				// list > previous one 
				if (list[j] > list[j - 1] &&
						min > list[j])
				{ 
					min = list[j]; 
					index = j; 
				} 
			} 

			// Update min and index, if 
			// list has single element 
			else if (size == 1) 
			{ 
				min = list[j]; 
				index = j; 
			} 

			// Update min and index, 
			// if current element > 
			// adjacent elements 
			else if (list[j] > list[j - 1] && 
					list[j] > list[j + 1] && 
						min > list[j])
			{ 
				min = list[j]; 
				index = j; 
			} 
		} 

		// Remove current min peak 
		// element from list 
		list.erase(list.begin() + index); 

		// Insert min peak into 
		// resultant list 
		result.push_back(min); 
	} 
	
	// Print resultant list 
	cout << "[";
	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i] << ", ";
	}
	cout << "]";
} 

// Driver Code 
int main() 
{ 
	
	// Given array arr[] 
	vector<int> arr = { 2,7,8,5,1,6,3,9};

	// Function call 
	minPeaks(arr); 
}

