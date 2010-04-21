
public class VariableNode extends LogicNode {
	    public String name;
	    public boolean value;
	    
	    public VariableNode(String _name, boolean _value) {
		    name = _name;
		    value = _value;
	    }
	    public String name() {
		    return name;
	    }
	    public boolean value() {
		    return value;
	    }
}
