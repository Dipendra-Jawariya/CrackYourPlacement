//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    //Function to calculate the maximum area of a rectangle
    //in a histogram
    int mhist(int row[], int m1) {
    
        stack<int> result; //create a stack to store the indices
    
        int top_val; //variable to store the value at the top of the stack
    
        int max_area = 0; //initialize max_area to 0
    
        int area = 0; //initialize area to 0
        int i = 0; //initialize i to 0
        for (i = 0; i < m1;) {
    
            //if the stack is empty or the current element is larger
            //than or equal to the element at the top of the stack, 
            //push the index onto the stack and move to the next element
            if (result.empty() || row[result.top()] <= row[i])
                result.push(i++);
    
            else {
                top_val = row[result.top()]; //get the value at the top of the stack
                result.pop(); //pop the element from the stack
                area = top_val * i; //calculate the area with the popped element
    
                //if the stack is not empty, calculate the area
                //using the current index minus the index at the top of the stack
                if (!result.empty()) area = top_val * (i - result.top() - 1);
    
                max_area = max(area, max_area); //update the maximum area
            }
        }
    
        //calculate the area for any remaining elements in the stack
        while (!result.empty()) {
            top_val = row[result.top()]; //get the value at the top of the stack
            result.pop(); //pop the element from the stack
            area = top_val * i; //calculate the area with the popped element
    
            //if the stack is not empty, calculate the area
            //using the current index minus the index at the top of the stack
            if (!result.empty()) area = top_val * (i - result.top() - 1);
    
            max_area = max(area, max_area); //update the maximum area
        }
        return max_area; //return the maximum area
    }
    
    //Function to calculate the maximum area of a rectangle
    //in the given matrix.
    int kewl(int M[MAX][MAX], int n, int m) {
        int res = mhist(M[0], m); //initialize res with the maximum area of the first row
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
    
                //if the current element is non-zero,
                //update it with the sum of the current element
                //and the element above it
                if (M[i][j]) M[i][j] += M[i - 1][j];
            }
            res = max(res, mhist(M[i], m)); //calculate the maximum area for the current row and update res
        }
        return res; //return the maximum area
    }
    
    //Function to calculate the maximum area of a rectangle
    //in the given matrix.
    int maxArea(int M[MAX][MAX], int n, int m) {
        return kewl(M, n, m); //call the helper function to find the maximum area
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends