;; length-defun.el ... length関数を自分で実装してみる。

;;再帰を使わない書き方(なんか違う...)
(defun length-defun (str)
  "refine length command... "
  (let ((tmp str) (cnt 0))
    (while tmp
      (setq tmp (cdr tmp))
      (setq cnt (+ cnt 1)))
      (print cnt)))

;;再帰を使った書き方(普通?の再帰)
(defun length-defun-recursion (str)
  (if (null str) 0
    (+ 1 (length-defun-recursion (cdr str)))))

;;再帰を使った書き方(末尾再帰(tail recursion?))
(defun length-defun-tail-recursion (str)
  (length-loop str 0))

(defun length-loop (str cnt)
  (if (null str) cnt
    (length-loop (cdr str) (+ cnt 1))))