import java.util.*;

public class DataCache {
	private final Map _map = new HashMap();
	private final Entry _head = new Entry(null);
	private final int _capacity;
	
	public DataCache(int capacity) {
		_capacity = capacity;
	}
	
	public Data getData(String name) {
		System.out.println("Getting " + name + "...");
		Entry entry = (Entry)_map.get(name);
		
		if (entry == null) {
			System.out.println("Cache miss!!");
			Data data = new Data(name);
			entry = new Entry(data);
			purge();
			_map.put(name, data);
		} else {
			System.out.println("Cache hit!");
		}
		access(entry);
		printCache();
		return entry.getData();
	}
	private void access(Entry entry) {
		entry.remove();
		entry.insertAfter(_head);
	}
	private void purge() {
		while (_capacity <= _map.size()) {
			Entry entry = _head.getPrevious();
			System.out.println(entry.getData().getName() + " is purged.");
			entry.remove();
			_map.remove(entry.getData().getName());
		}
	}
	private void printCache() {
		Entry entry = _head.getNext();
		System.out.print("Cache = [");
		while (entry != _head) {
			System.out.print(entry.getData().getName() + ", ");
			entry = entry.getNext();
		}
		System.out.println("]");
	}
}
