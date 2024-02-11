

public class Main {
    // Time complexity is O(n)
    // Space complexity is O(1)

    static int linearSearch(int []arr,int item){
        for(int i=0;i<arr.length;i++){
            if(arr[i]==item){
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int []arr={1,5,8,97,4};
        int person=8;
        int pos=linearSearch(arr,person);// will return the index if the element found or -1 if not
        System.out.println("Is founded on  : "+pos); // 2
    }
}