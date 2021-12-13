class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        int i = 0, j = 0;
        unordered_map<char, int> mp;
        for (auto a : p)
        {
            mp[a]++;
        }
        int count = mp.size();
        int k = p.length();
        while (j < s.length())
        {
            if (mp[s[j]])
            {
                mp[s[j]]--;
                if (mp[s[j]] == 0)
                {
                    count--;
                }
                cout << s[j] << " ";
            }

            if (j - i + 1 < k)
            {
                j++;
            }
            else if (j - i + 1 == k)
            {
                if (count == 0)
                {
                    ans.push_back(i);
                }
                if (mp[s[i]])
                {
                    mp[s[i]]++;
                    if (mp[s[i]] == 1)
                        count++;
                }
                i++;
                j++;
            }
        }

        return ans;
    }
};