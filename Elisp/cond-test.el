(defun cond-test (hoge)
  "Condition test routins..."
  (interactive "P")
  (cond ((numberp hoge)
	 ;;"hoge"が数値だったら
	 (message "hoge is number...")
	 )
	((stringp hoge)
	 ;;"hoge"が文字列だったら
	 (message "hoge is string...")
	 ))
)

(defun triangle-using-cond (number)
  (cond ((<= number 0) 0) ;; 条件1
        ((= number 1) 1) ;; 条件2
        ((> number 1) ;; 条件3
         (+ number (triangle-using-cond (- number 1))))))

(defun print-triangle-num (number)
  "print triangle number..."
  (print (triangle-using-cond number)))

