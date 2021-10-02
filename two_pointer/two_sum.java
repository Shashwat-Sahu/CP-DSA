package two_pointer;

import java.util.*;

public class two_sum {
    public static void main(String args[]) {
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        int nums[]=new int[n];
        for(int i=0;i<n;i++)
        {
            nums[i]=scan.nextInt();
        }
        int target=scan.nextInt();
        two_sum obj=new two_sum();
        obj.twoSum(nums, target);
        scan.close();
    }
    public int[] twoSum(int[] nums, int target) {
        
        HashMap<Integer,Integer> map=new HashMap<>();
        for(int i=0;i<nums.length;i++)
        {
            if(map.containsKey(target-nums[i]))
                return new int[]{i,map.get(target-nums[i])};
            else
                map.put(nums[i],i);
        }
        return null;
    }
}