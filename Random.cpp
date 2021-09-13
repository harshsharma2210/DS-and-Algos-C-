class NoOfRotation{
    public int fun(int arr[]){
        int start=0;
        int end=arr.length-1;
        while (start<=end){
            int mid=start+(end-start)/2;
            int next=(mid+1)%arr.length;
            int previous=(mid+arr.length-1)%arr.length;
            if(arr[mid]<=arr[next] && arr[mid]<=arr[previous]){
                return mid;
            }
            else {
                if(arr[mid]>=arr[start] && arr[mid]<=arr[end]){ return start; }
                else if(arr[mid]>=arr[start]){start=mid+1;}
                else if(arr[mid]<=arr[end]){end=mid-1;}
            }
        }
        return -1;
//        System.out.println("No of rotation is : "+(arr.length-returned value)%arr.length);
//        no of rotation=(arr.length-returned value)%arr.length;
    }
  }
