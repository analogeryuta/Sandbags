import java.util.Random;
import java.util.Scanner;

/**
 * int型配列をソート対象として、マージソートを行うクラス。
 * とくにabstract classを作っているわけではない。が、もし使うとすれば
 * 
 * abstract class Sort { ...
 * 
 * と書けるかもしれない。ソートの操作を行うメソッド名は共通化させるとか。
 * @author analogeryuta(Yuta AKAMINE)
 * 
 */
public class MergeSort {
    /**
     * 配列内要素の入れ替えを行う
     * @param item[] 要素の入れ替えを行う配列
     * @param src 入れ換え元の添字
     * @param dsc 入れ換え先の添字
     */
    static void swap(int item[], int src, int dsc) {
	int tmp;
	tmp = item[src];
	item[src] = item[dsc];
	item[dsc] = tmp;
    }

    /**
     * ソートする配列要素を再帰処理でソート。要素数が奇数のデータはどうすればよろしい？
     * ソート対象の中間位置は mid = (left + right) / 2 で計算する。
     * @param item[] 要素の入れ替えを行う配列
     * @param left ソート対象の左端
     * @param right ソート対象の右端
     */
    static void sort(int[] items, int left, int right) {
	int mid = (left + right)/2;
	
	if (right - left <= 1) {
	    for (int i = left; i<=right; i++) {
		System.out.println("print divided element:"+items[i]);
	    }
	    System.out.println();
	    return;
	} else {
	    //配列の前半(左端のインデックス~中間)でソート
	    sort(items, left, mid);
	    //配列の後半(中間~右端のインデックス)でソート
	    sort(items, mid+1, right);
	    merge();
	    return;
	}
    }
    
    static void merge() {
	System.out.println("call merge");
	return;
    }
    
    static int[] generateItems(int number) {
	int[] items = new int[number];
	Random rnd = new Random();

	// 生成した配列にランダムな数値を代入し初期化
	for (int i = 0; i < number; i++) {
	    items[i] = rnd.nextInt(number);
	}
	
	return items;
    }

    public static void main(String[] args) {
	// TODO Auto-generated method stub
	int number;
	int[] items;
	
	Scanner stdio = new Scanner(System.in);

	System.out.print("Input: number of items :");
	number = stdio.nextInt();
	items = generateItems(number);

	System.out.println();

	System.out.println("print initialized items below:");
	for (Object obj : items) {
	    System.out.println(obj);
	}

	// 初期化した配列をソート
	/*
	  for (int i = 0; i < number; i++) {
	  for (int j = 0; j < number-i-1; j++) {
	  if (items[j]  > items[j+1]) {
	  swap(items, j, j+1);
	  }
	  }
	  }
	*/
	sort(items, 0, items.length-1);
	
	System.out.println("print sorted items below:");
	for (Object obj : items) {
	    System.out.println(obj);
	}
    }
}