#include<bits/stdc++.h>
int main()
{

        int t;
        cin>>t;
        int k=1 ;
        while(t-->0){
            int N;
            cin>>N;
            int count=0 ;
            int arr[N];
            for(int i=0;i<N;i++){
                cin>>arr[i];
            }
            int maxi=0 ;
            for(int i=0;i<N;i++){
                
                if(i==0 && N>1){
                    maxi= arr[0];
                    if(arr[1]<arr[0]){
                        count++ ;
                    }
                    continue;
                }
                if(i==0 && N==1){
                    count++ ;
                    break ;
                }
                if(i==(N-1) && maxi<arr[i]){
                    count++ ;
                    break ;
                }
                if(arr[i]>maxi && arr[i]>arr[i+1]){
                    count++ ;
                     maxi= arr[i];
                }
                
            }
            cout<<"Case #"+k+":"+" "+count;
            k++;
        }
    
}