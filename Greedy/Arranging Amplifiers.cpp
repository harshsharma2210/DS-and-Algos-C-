// Given below code is for ARRANGE spoj or Arrange Amplifiers spoj.

// This question is based on greedy approach.

// Main idea is  a^b < b^a (if a>b and not valid for a=3 and b=3) , so place all the amplifiers with higher amplification first . If there is amplifier with amplification 1 the place all these amplifier first.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int array[n], count1 = 0, count = 0, input, j = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &input);
            if (input == 1)
                count1++;
            else
            {
                array[j++] = input;
                count++;
            }
        }
        sort(array, array + count);
        for (int i = 0; i < count1; i++)
            printf("1 ");
        if (count == 2 && array[0] == 2 && array[1] == 3)
            cout << 2 << " " << 3;
        else
        {
            for (int i = count - 1; i >= 0; i--)
                printf("%d ", array[i]);
        }
        cout << endl;
    }
    return 0;
}