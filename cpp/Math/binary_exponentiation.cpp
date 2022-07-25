long long power(long long base, long long exp, long long m) {
    long long ans = 1;
    base %= m;
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            ans = ans * base % m;
        }
 
        base = base * base % m;
        exp /= 2;
    }
 
    return ans;
}