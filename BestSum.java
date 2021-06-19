import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.List;

class BestSum {
//	public static ArrayList<Integer> bestSum(int sum, Integer[] arr) {
//		
//		if(memo.containsKey(sum)) return memo.get(sum);
//		
//		if(sum==0) return new ArrayList<Integer>();
//		if(sum<0) return null;
//
//		ArrayList<Integer> shortestCombination = null;
//
//		for(Integer item : arr) {
//			int remainder = sum - item;
//			ArrayList<Integer>  remainderCombination = bestSum(remainder, arr);
//
//			if(remainderCombination != null) {
//				ArrayList<Integer> combination = new ArrayList<Integer>(remainderCombination);
//				combination.add(item);
//				if(shortestCombination==null||combination.size()<shortestCombination.size()) {
//					shortestCombination = combination;
//				}
//				
//			}
//		}
//		return shortestCombination;
//	}
	
	public static HashMap<Integer, List> memo = new LinkedHashMap<Integer, List>(); 
	public static List<Integer> bestSum(int sum, Integer[] arr) {
		
		
		if(memo.containsKey(sum)) return memo.get(sum);
		
		if(sum==0) return new ArrayList<Integer>();
		if(sum<0) return null;

		List<Integer> shortestCombination = null;
		
		for(Integer item : arr) {
			int remainder = sum - item;
			List<Integer>  remainderCombination = bestSum(remainder, arr);

			if(remainderCombination != null) {
				List<Integer> combination = new ArrayList<Integer>(remainderCombination);
				combination.add(item);
				if(shortestCombination==null||combination.size()<shortestCombination.size()) {
					shortestCombination = combination;
				}
				
			}
		}
		memo.put(sum, shortestCombination);
		return shortestCombination;
	}

	public static void main(String... args) {
		System.out.println(bestSum(7, new Integer[] {5, 3, 4, 7})); // [7]
		System.out.println(bestSum(8, new Integer[] {2, 3, 5,}));
		System.out.println(bestSum(8, new Integer[] {1, 4, 5}));
		System.out.println(bestSum(100, new Integer[] {5, 3, 4, 25}));

	}
}