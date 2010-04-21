/* Data.java : 扱うデータ（キー、値）を定義したもの
 * 
 */

public class Data {
	private final String _name;
	private final String _content;
	public Data(String name) {
		System.out.println("Reading " + name + "...");
		_name = name;
		slowly();
		_content = "(Content of " + name + ")";
	}
	public String getName() {
		return _name;
	}
	public String getContent() {
		return _content;
	}
	private void slowly() {
		try {
			Thread.sleep(1000);
		} catch (InterruptedException ignore) {
		}
	}
}
