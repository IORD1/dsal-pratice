
int hashing::hash_func(string s){
    int asscii = static_cast<int>(s[0]);
    return asscii%10;
}