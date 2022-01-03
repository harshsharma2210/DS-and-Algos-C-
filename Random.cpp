class Solution
{
public:
    int wordBreak(string A, vector<string> &B){

        bool recursion(string a, vector<string> b, int n, int m){
            if (n == 0) return true;
    if (m == 0)
        return false;
    if (a == b[m - 1])
        return true;
    if (a[n - 1] == a[m - 1])
        return recursion(a.substr(0, n - 1), b, n - 1, m - 1) || recursion(a, b, n, m - 1);
    else
        return recursion(a, b, n, m - 1) || recursion(a, b, n - 1, m);
}

int
wordBreak(string A, vector<string> &B)
{
    // code here
    // reverse(A.begin(),A.end());
    if (recursion(A, B, A.size(), B.size()))
        return 1;
    return 0;
}
}
;