

public class Main {
    // Time complexity is O(log(n))
    // Space complexity is O(1)
    static int binarySearch(int[]arr,int item){ // Binary search
        int l=0,r=arr.length-1;
        while(l<=r){
            int m=(l+r)/2;
            if(item==arr[m]){
                return m;
            }
            if (item > arr[m]) {
                l=m+1;
            }
            else {
                r=m-1;
            }

        }
        return -1;
    }

    public static void main(String[] args) {
        int []arr={1,4,5,8,97}; // binary search work with sorted array or sorted range
        int person=97;
        int pos=binarySearch(arr,person);// will return the index if the element is found or -1 if not
        System.out.println("Is founded on  : "+pos); // 3
    }
}
