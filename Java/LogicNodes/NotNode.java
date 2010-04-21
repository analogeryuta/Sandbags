/*NotNode : 与えられた真理値の否定を出力するクラス。
 * LogicNodeを親クラスにもつ。
 * 
 */

public class NotNode extends LogicNode {
	public String name;
	public boolean value;
	
	public NotNode(String _name, boolean _value) {
		name = _name;
		value = _value;
	}

	public String name() {
		name = "not "+ name;
		return name;
	}

	public boolean value() {
		if (value == true) {
			return false;
		} else {
			return true;
		}
	
	}
}
