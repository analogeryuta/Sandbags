;; factorial.el ... 再帰処理の例題
(defun factorial (n)
  (if (= n 0)
      1
    (* n (factorial (- n 1)))))