public class GetExecTime {
    public static void main(String[] args) {
	long startTime;
	long endTime;

	startTime = System.currentTimeMillis();
        for (int i = 0; i < 100000; i++) {
            int j = i * i;
        }
	endTime = System.currentTimeMillis();

        System.out.printf("exection time : %.3f ms", endTime - startTime);
    }
}