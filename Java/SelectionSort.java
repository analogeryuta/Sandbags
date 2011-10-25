
import java.util.Random;
import java.util.Scanner;

public class SelectionSort {

    /**
     * @param args
     */
    public static void main(String[] args) {
	// TODO Auto-generated method stub
	int number;
	int[] items;

	Random rnd = new Random();
	Scanner stdio = new Scanner(System.in);
	
	System.out.print("Input: number of items :");
	number = stdio.nextInt();
	
	System.out.println();
	
	items = new int[number];
	
	//生成した配列にランダムな数値を代入し初期化
	for (int i=0; i < number; i++) {
	    items[i] = rnd.nextInt(number);
	}
	
	System.out.println("print initialized items below:");
	for (Object obj : items) {
	    System.out.println(obj);
	}
	
	//初期化した配列をソート
	int min, tmp;
	for (int i=0; i<number - 1; i++) {
	    min = i;
	    for (int j=i+1; j<number; j++) {
		if (items[j]<items[min]) {
		    min = j;
		}
	    }
	    //要素の入れ替え
	    tmp = items[i];
	    items[i] = items[min];
	    items[min] = tmp;
	}
	
	System.out.println("print sorted items below:");
	for (Object obj : items) {
	    System.out.println(obj);
	}
	
    }

}
