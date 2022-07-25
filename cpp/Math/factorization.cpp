vector<pair<long long, int>> factorization(long long n) {
    vector<pair<long long, int>> ans;
    
    for (long long p = 2; p*p <= n; p++) {
        if (n%p == 0) {
            int expoente = 0;
            
            while (n%p == 0) {
                n /= p;
                expoente++;
            }
            
            ans.push_back({p, expoente});
        }
    }
    
    if (n > 1) {
        ans.push_back({n, 1});
    }
    
    return ans;
}