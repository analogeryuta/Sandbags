;; flatten.el ... 入れ子になっているリストの要素を全てフラットにする

(defun flatten (item)
  (cond ((null item) item)
	((listp item)
	 (append (flatten (car item)) (flatten (cdr item))))
	(t (list item))))