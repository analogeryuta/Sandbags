/*Entry.java : キャッシュデータのデータ構造を定義する。
 * ここで扱うデータは双方向リストでつながっており、Entryはデータ間の
 * つながり、データ間の移動、データの取得を提供するクラスである。
 */

public class Entry {
	private Entry _previous;
	private Entry _next;
	private final Data _data;
	
	public Entry(Data data) {
		_previous = this;
		_next = this;
		_data = data;
	}
	
	public Entry getPrevious() {
		return _previous;
	}
	public Entry getNext() {
		return _next;
	}
	public Data getData() {
		return _data;
	}
	public void remove() {
		_next._previous = _previous;
		_previous._next = _next;
		_next = this;
	}
	public void insertAfter(Entry entry) {
		_next = entry._next;
		_next._previous = this;
		entry._next = this;
		_previous = entry;
	}
	
}
