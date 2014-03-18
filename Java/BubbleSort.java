
import java.util.Random;
import java.util.Scanner;

public class BubbleSort {

    /**
     * @param item[] 要素の入れ替えを行う配列
     * @param src 入れ換え元の添字
     * @param dsc 入れ換え先の添字
     * 配列内要素の入れ替えを行う
     */
    static void swap(int item[], int src, int dsc) {
	int tmp;
	tmp = item[src];
	item[src] = item[dsc];
	item[dsc] = tmp;
    }

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

	// 生成した配列にランダムな数値を代入し初期化
	for (int i = 0; i < number; i++) {
	    items[i] = rnd.nextInt(number);
	}

	System.out.println("print initialized items below:");
	for (Object obj : items) {
	    System.out.println(obj);
	}

	// 初期化した配列をソート
	for (int i = 0; i < number; i++) {
	    for (int j = 0; j < number-i-1; j++) {
		if (items[j]  > items[j+1]) {
		    swap(items, j, j+1);
		}
	    }
	}

	System.out.println("print sorted items below:");
	for (Object obj : items) {
	    System.out.println(obj);
	}
    }
}