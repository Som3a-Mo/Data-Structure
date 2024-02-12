

public class Main {
    // Time complexity is O(n^2)
    // Space complexity is O(1)
    static void selectionSort(int[]arr){

        for(int i=0;i<arr.length-1;i++){
            int minIndex=i;
            for(int j=i+1;j<arr.length;j++){
                if(arr[minIndex]>arr[j]){
                    minIndex=j;
                }
            }
            int item=arr[i];
            arr[i]=arr[minIndex];
            arr[minIndex]=item;
        }
    }

    public static void main(String[] args) {
        int []arr={1,5,8,97,4};

        selectionSort(arr); // will sort the array

        for(int i:arr){ // 1 4 5 8 97
            System.out.print(i+" ");
        }
    }
}