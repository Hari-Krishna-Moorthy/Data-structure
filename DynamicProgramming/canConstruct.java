import java.util.HashMap;
import java.util.LinkedHashMap;

public class CanConstruct {
	
	public static HashMap<String, Boolean> memo = new LinkedHashMap<String, Boolean>();
	public static boolean canConstruct(String target, String[] words) {
		if(memo.containsKey(target)) return memo.get(target);
		if(target.length()==0) return true;
		for(String item:words) {
			
			if(target.startsWith(item)) {
				boolean result = canConstruct(target.replaceFirst(item, ""), words);
				memo.put(target.replace(item, ""), result);
				if(result) return result;
			} 
		}
		
		return false;
	}
	

	public static void main(String[] args) {
		System.out.println(canConstruct("abcdef" , new String[] {"ab", "abc", "cd", "def", "abcd"}));
		System.out.println(canConstruct("skateboard", new String[] {"bo", "rd", "ate", "t", "ska", "sk", 
				"boar"}));
		System.out.println(canConstruct("enterapotentpot", new String[] {"a", "p", "ent", "enter", "ot",
				"o", "t"}));
		System.out.println(canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee", new String[] {
				"e", "ee", "eee", "eeee", "eeeee", "eeeeee",}));
		
	}

}
