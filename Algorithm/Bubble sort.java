

public class Main {
    // Time complexity is O(n^2)
    // Space complexity is O(1)
    static void bubbleSort(int[]arr){
        boolean flag=true;
        for(int i=0;i<arr.length-1;i++){
            for(int j=0;j<arr.length-i-1;j++){
                if(arr[j]>arr[j+1]) {
                    int item = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = item;
                    flag=false;
                }
            }
            if(flag==true) {
                break;
            }
        }
    }

    public static void main(String[] args) {
        int []arr={1,5,8,97,4};

        bubbleSort(arr); // will sort the array

        for(int i:arr){ // 1 4 5 8 97
            System.out.print(i+" ");
        }
    }
}