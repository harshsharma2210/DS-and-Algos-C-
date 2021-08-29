int jumps = 0, farthest = 0, currEnd = 0;
    for(int i=0;i<n-1;i++)
    {
        farthest = max(farthest, i + arr[i]);
        if(farthest >= n-1)
            return 1 + jumps;
        
        if(i == farthest)
            return -1;
        
        if(i == currEnd)
        {
            jumps++;
            currEnd = farthest;
        }
    }
    return jumps;