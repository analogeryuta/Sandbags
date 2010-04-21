
public class MainApp {
    public static void main(String[] args) {
	SimpleThread st= new SimpleThread();
	st.setReserveCount(15);
	st.start();
    }
}