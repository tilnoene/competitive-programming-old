vector<int> arr = {1, 2, 3};
int n = arr.size();

do { // 1,2,3; 1,3,2; 2,1,3; 2,3,1; 3,1,2; 3,2,1; 
    for (auto e : arr) {
        cout << e << ' ';
    }
    cout << '\n';
} while (next_permutation(arr.begin(), arr.begin() + n)); 