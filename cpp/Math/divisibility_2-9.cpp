int ctoi(char c){
    return int(c)-48;
}

bool div2(string num) {
    return ctoi(num.back()) % 2 == 0;
}

bool div3(string num) {
    int sum = 0;
    
    for (auto c : num)
        sum += ctoi(c);
    
    return sum % 3 == 0;
}

bool div4(string num) {
    if (num.length() == 1) {
        if (stoi(num) % 4 == 0)
            return true;
        return false;
    }
    
    string tmp = to_string(ctoi(num[num.length()-2])) + to_string(ctoi(num[num.length()-1]));
    return stoi(tmp) % 4 == 0;
}

bool div5(string num) {
    return (num.back() == '5' or num.back() == '0');
}

bool div6(string num) {
    return (div2(num) && div3(num));
}

bool div7(string num) {
    return stoll(num) % 7 == 0;
}

bool div8(string num) {
    if (num.length() < 3) {
        if (stoi(num) % 8 == 0)
            return true;
        return false;
    }
    
    string tmp = to_string(ctoi(num[num.length()-3])) + to_string(ctoi(num[num.length()-2])) + to_string(ctoi(num[num.length()-1]));
    return stoi(tmp) % 8 == 0;
}

bool div9(string num) {
    int sum = 0;
    
    for (auto c : num)
        sum += ctoi(c);
    
    return sum % 9 == 0;
}