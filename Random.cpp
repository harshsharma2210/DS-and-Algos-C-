class Solution
{
public:
    int findMaxLen(string s)
    {
        // code here
        int count = 0;
        stack<int> st;
        bool flag = true;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            switch (ch)
            {
            case '(':
                st.push('(');
                break;
            case ')':
                if (st.top() == ')')
                {
                    count += 2;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
        }
        return count;
    }
};