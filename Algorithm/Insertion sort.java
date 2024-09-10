
public class Main {
    // Time complexity is O(n^2)
    // Space complexity is O(1)

    static void insertionSort(int[]arr){
        for (int i=1;i<arr.length;i++){
            int element=arr[i];
            int j=i-1;
            while(j>-1&&arr[j]>element){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=element;
        }
    }

    public static void main(String[] args) {
        int []arr={1,5,8,97,46,8,9,7,2,3};
        insertionSort(arr); // will sort the array
        for(int i:arr){ // 1 2 3 5 7 8 8 9 46 97
            System.out.print(i+" ");
        }
    }
}