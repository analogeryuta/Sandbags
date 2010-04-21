/**
 * @author freddie
 * LogicNodesのテスト。ここのmainメソッドからテスト開始。
 */
public class LogicNodeTest {
	static public void main(String args[]) {
	    LogicNode a = new VariableNode("a",true);
	    LogicNode b = new VariableNode("b",false);
	    LogicNode e = new AndNode(a,b);
	    
	    System.out.println(e.value());
	    
	    a = new VariableNode("a",true);
	    b = new VariableNode("b",false);
	    e = new OrNode(a,b);

	    System.out.println(e.value());
	    
	    LogicNode test = new NotNode("T",true);
	    LogicNode test2 = new NotNode("F",false);
	    
	    System.out.println(test.name() + ":" + test.value());
	    System.out.println(test2.name() + ":" + test2.value());
    }
	
	static public void main2(int k) {
		if (k==-1) {
			System.out.println(k);
		}
	}
}
