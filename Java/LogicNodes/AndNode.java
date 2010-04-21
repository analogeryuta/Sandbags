
public class AndNode extends LogicNode {
	 LogicNode left;
	 LogicNode right;
	    
	    public AndNode(LogicNode left0,LogicNode right0) {
		    left = left0;
		    right = right0;
	    }
	    public boolean value() {
		    return left.value() && right.value();
	    }
}
