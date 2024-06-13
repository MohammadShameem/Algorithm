#include <iostream>
#include <vector>
using namespace std;

void calcSubset(vector<int>& A, vector<vector<int> >& res,
                vector<int>& subset, int index)
{
    // Add the current subset to the result list
    res.push_back(subset);

    // Generate subsets by recursively including and
    // excluding elements
    for (int i = index; i < A.size(); i++) {
        // Include the current element in the subset
        subset.push_back(A[i]);

        // Recursively generate subsets with the current
        // element included
        calcSubset(A, res, subset, i + 1);

        // Exclude the current element from the subset
        // (backtracking)
        subset.pop_back();
    }
}

vector<vector<int> > subsets(vector<int>& A)
{
    vector<int> subset;
    vector<vector<int> > res;
    int index = 0;
    calcSubset(A, res, subset, index);
    return res;
}

// Function to find the subsets of the given array using bit manipulation
void findSubsets(int nums[], int n)
{
    // Loop through all possible subsets using bit manipulation
    for (int i = 0; i < (1 << n); i++) {

        // Loop through all elements of the input array
        for (int j = 0; j < n; j++) {

            // Check if the jth bit is set in the current subset
            if ((i & (1 << j)) != 0) {

                // If the jth bit is set, add the jth element to the subset
                cout << nums[j] << " ";
            }
        }

        cout << endl;
    }
}

// Driver code
int main()
{
    
    //vector<int> array = { 1, 2, 3 };
    //vector<vector<int> > res = subsets(array);

    // Print the generated subsets
    //for (int i = 0; i < res.size(); i++) {
    //    for (int j = 0; j < res[i].size(); j++)
        //cout << res[i][j] << " ";
        //cout << endl;
    //}

    int arr[] = { 1, 2, 3 }; //empty is another subset
    int n = sizeof(arr)/sizeof(arr[0]);
    findSubsets(arr, n);

    return 0;
}