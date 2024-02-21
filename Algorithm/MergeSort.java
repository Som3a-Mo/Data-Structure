import java.util.ArrayList;
import java.util.List;

public class Main {
    // Time complexity is O(n*log(n))
    // Space complexity is O(n)

    static void merge(int[]arr,int lower,int mid,int upper){
        List<Integer> list=new ArrayList<>();
        int left=lower;
        int right=mid+1;
        while(left<=mid&&right<=upper){
            if(arr[left]<=arr[right]){
                list.add(arr[left]);
                left++;
            }else{
                list.add(arr[right]);
                right++;
            }
        }
        while(left<=mid){
            list.add(arr[left]);
            left++;
        }
        while(right<=upper){
            list.add(arr[right]);
            right++;
        }
        for(int i=lower;i<=upper;i++){
            arr[i]= list.get(i - lower);
        }
    }
    static void mergeSort(int[]arr,int lower,int upper){
        if(lower==upper)return;
        int mid=(lower+upper)/2;
        mergeSort(arr,lower,mid);
        mergeSort(arr,mid+1,upper);
        merge(arr,lower,mid,upper);
    }

    public static void main(String[] args) {
        int []arr={1,5,8,97,4};

        mergeSort(arr,0,4); // will sort the array
        for(int i:arr){ // 1 4 5 8 97
            System.out.print(i+" ");
        }
    }
}