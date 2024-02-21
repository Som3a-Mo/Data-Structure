
public class Main {
    // Time complexity is O(n*log(n))
    // Space complexity is O(1)

    static int partitions(int[]arr,int lower,int upper){
        int pivot=arr[lower];
        int i=lower;
        int j=upper;
        while (i<j){
            while (arr[i]<=pivot&&i<upper)i++;
            while (arr[j]>pivot&&j>lower)j--;
            if(i<j){
                swap(arr,i,j);
            }
        }
        swap(arr,j,lower);
        return j;
    }

    static void swap(int[]arr,int i,int j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    static void quickSort(int[]arr,int lower,int upper){
        if(lower<upper){
            int partition=partitions(arr,lower,upper);
            quickSort(arr,lower,partition-1);
            quickSort(arr,partition+1,upper);
        }
    }

    public static void main(String[] args) {
        int []arr={1,5,8,97,46,8,9,7,2,3};

        quickSort(arr,0,9); // will sort the array
        for(int i:arr){ // 1 2 3 5 7 8 8 9 46 97 
            System.out.print(i+" ");
        }
    }
}