
public class MainApp {
	/*
	 *
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new MainApp().run();
	}
	private void run() {
		DataCache cache = new DataCache(3);
		String[] name = {
			"j03002",
			"freddie",
			"S_A",
			"j03001",
			"gongo",
			"j03043",
			"snake",
			"david",
		};
		for (int i = 0; i < name.length; i++) {
			Data data = cache.getData(name[i]);
			System.out.println(data.getContent());
			System.out.println();
		}
	}

}
