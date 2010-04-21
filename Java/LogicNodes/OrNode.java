
public class OrNode extends LogicNode {
	LogicNode left;
	LogicNode right;
	    
	    public OrNode(LogicNode left0,LogicNode right0) {
		    left = left0;
		    right = right0;
	    }
	    public boolean value() {
		    return left.value() || right.value();
	    }
}
