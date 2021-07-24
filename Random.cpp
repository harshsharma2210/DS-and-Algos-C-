#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'number_of_ways' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY waterDistributed
 *  2. INTEGER maximumDifference
 */

int number_of_ways(vector<int> waterDistributed, int maximumDifference) {
    int sumOfArray=0;
    int n=waterDistributed.size();
    for(int i=0;i<n;i++)
    {
        sumOfArray+=waterDistributed[i];;
    }
    if((sumOfArray+maximumDifference)%2!=0)
    {
        return 0;
    }
    else
    {
        return number_of_ways(waterDistributed,(sumOfArray+maximumDifference)/2);
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string waterDistributed_count_temp;
    getline(cin, waterDistributed_count_temp);

    int waterDistributed_count = stoi(ltrim(rtrim(waterDistributed_count_temp)));

    vector<int> waterDistributed(waterDistributed_count);

    for (int i = 0; i < waterDistributed_count; i++) {
        string waterDistributed_item_temp;
        getline(cin, waterDistributed_item_temp);

        int waterDistributed_item = stoi(ltrim(rtrim(waterDistributed_item_temp)));

        waterDistributed[i] = waterDistributed_item;
    }

    string maximumDifference_temp;
    getline(cin, maximumDifference_temp);

    int maximumDifference = stoi(ltrim(rtrim(maximumDifference_temp)));

    int result = number_of_ways(waterDistributed, maximumDifference);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
