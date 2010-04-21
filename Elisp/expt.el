;; expt.el ... 再帰を用い、冪乗を計算する。

(defun expt_n (m n)
  "exponentiation"
  (if (= n 0) 1
    (* (expt_n m (- n 1)) m)))