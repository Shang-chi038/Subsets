#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// A function to do the combination
void printSubsets(vector<int> sets, int n, int counter, vector<int> subset, int i, int index) {
    // index is the index of the data you want to begin with if not zero, data[] will be empty and it will just give us the memory address
    // And i controls which element of the set to pick or to start picking
    if (index == counter) {
        cout << "{ " ;
        for (int j = 0; j < counter; j++) {
            cout << subset[j] << " ";
        }
        cout << "}" << endl ;

        return;
    }
    
    if (i >= sets.size())
        return;

    // To add each member of the current size of subsets to the subset array
    subset.insert(subset.begin()+index, sets[i]);

    printSubsets(sets, n, counter, subset, (i + 1), (index + 1));

    printSubsets(sets, n, counter, subset, (i + 1), index);
}


int main() {
    int n, counter = 0;

    // cout << "Enter the length of your set (n): ";
    cout << "Enter the number of members of your set (n): ";
    cin >> n;

    // To take each element in the set
    vector<int> sets(n);
    cout << "Enter the memebers of the set: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter number"<< i+1 << ": " ;
        // To store each number into sets[]
        cin >> sets[i];
    }

    // Temporary array to store the current combination (subsets)
    vector<int> subset;

    cout << "\nAll the subset of sets numbers:\n";
    for (counter=0; counter<=n; counter++) { 
        printSubsets(sets, n, counter, subset, 0, 0);
    }

    return 0;
}
