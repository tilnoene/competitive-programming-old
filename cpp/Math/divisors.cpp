vector<long long> divisors(long long n) {
    vector<long long> ans;

    for (long long i = 1; i*i <= n; i++) {
        if (n%i == 0) {
            long long value = n/i;
            
            ans.push_back(i);
            if (value != i) {
                ans.push_back(value);
            }
        }
    }
    
    return ans;
}