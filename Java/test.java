import java.util.*;

public class test {
    public static void main(String[] args) {
	List<String> list = new ArrayList<String>();
	list.add("hoge");
	list.add("fuga");
	list.add("nohe");
	list.add("gubo");
	list.add("hanya");

	boolean flg=false;
	if (flg) {
	    System.out.println("true");
	} else {
	    System.out.println("false");
	}

	//拡張for文(for-each)
	for (Object name : list) {
	    System.out.println(name);
	}

	//従来通りのIterator
	Iterator it = list.iterator();
	while (it.hasNext()) {
	    System.out.println("ほげふがぐふぐふ\n");
	    System.out.println(it.next());
	}

    }



}