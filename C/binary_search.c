/*binary_search.c : 2分探索の実装例を示すプログラム
 *事前に用意された配列arrayを探索対象とし，その中の特定の
 *keyを探索して,その位置(配列の添字)を返す．
 *
 *計算量などの比較のため，
 * ・線形探索
 * ・再帰処理を用いた2分探索
 *を実現する関数も実装する．
 */
#include <stdio.h>
#include <string.h>


int
linearSearch(char *array[], int array_length, char *key)
{
    int index;

    for (index = 0; index < array_length; index++) {
	printf("Compare %s with %s\n",key, array[index]);
	if (strcmp(key, array[index]) == 0) {   //探索キーを逐次比較していく
	    return index;
	}
    }
    return -1;
}

int
binarySearch(char *array[], int array_length, char *key)
{
    int left = 0;
    int right = array_length;

    while (left < right) {
	int middle = (left + right) / 2;
	int compare = strcmp(key, array[middle]);

	printf("Compare %s with %s\n", key, array[middle]);

	if (compare == 0) {          //keyとarray[middle]が等しい場合
	    return middle;
	} else if (compare < 0) {    //key < array[middle] の場合
	    right = middle;
	} else {                     //それ以外(key > array[middle]) の場合
	    left = middle + 1;
	}
    }
    return -1;
}

int
binarySearch_recursive(char *array[], int left, int right, char *key)
{
    if (right <= left) {    //探索キーが無い(右端が左端と等しいかそれ以上)場合
	return -1;
    } else {
	int middle = (left + right) / 2;
	int compare = strcmp(key, array[middle]);

	printf("Compare %s with %s\n", key, array[middle]);

	if (compare == 0) {   //探索キーが見つかった場合
	    return middle;
	} else if (compare < 0) {  //探索キーがmiddleより左側にある
	    return binarySearch_recursive(array, left, middle, key);
	} else {                   //探索キーがmiddleより右側にある
	    return binarySearch_recursive(array, middle+1, right, key);
	}
    }

}



int
main(int argc, char *argv[])
{
    char *sorted_data[26] = {
	"ALPHA","BRAVO","CHARLIE","DELTA","ECHO","FOXTROT","GOLF",
	"HOTEL","INDIA","JULIET","KILO","LIMA","MIKE","NOVEMBER",
	"OSCAR","PAPA","QUEBEC","ROMEO","SIERRA","TANGO","UNIFORM",
	"VICTOR","WHISKY","X-RAY","YANKEE","ZULU",
    };
    int index;


    printf("linear_search : \n");
    index = linearSearch(sorted_data, 26, "TANGO");
    printf("index = %d\n", index);
    printf("\n");

    printf("binary_search : \n");
    index = binarySearch(sorted_data, 26, "TANGO");
    printf("index = %d\n", index);
    printf("\n");

    printf("binary_search_recursive : \n");
    index = binarySearch_recursive(sorted_data, 0, 26, "TANGO");
    printf("index = %d\n", index);
    printf("\n");

    return 0;
}
