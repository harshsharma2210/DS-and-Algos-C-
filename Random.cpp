class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int i = 0, j = 0, counter, tn = p.size(), n = s.size();
        vector<int> l;
        unordered_map<char, int> tm;
        unordered_map<char, int> m;
        //intitalise the target map first for further references
        for (int k = 0; k < p.size(); k++)
        {
            tm[p[k]]++;
            m[p[k]]++;
        }
        counter = tm.size();
        while (j < n)
        {
            if (tm[s[j]] > 0)
            {
                m[s[j]]--;
                if (m[s[j]] == 0)
                {
                    counter--;
                }
            }

            if ((j - i + 1) < tn)
            {
                j++;
            }
            else if ((j - i + 1) == tn)
            {
                if (counter == 0)
                {
                    l.push_back(i);
                }
                if (tm[s[i]] > 0)
                {
                    m[s[i]]++;
                    if (m[s[i]] == 1)
                    {
                        counter++;
                    }
                }

                i++;
                j++;
            }
        }
        return l;
    }
};