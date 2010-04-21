;; progn-test.el ... prognの動作確認
(defun progn-test(x y)
  (progn
    (message "add x y : %d" (+ x y))
    (message "sub x y : %d" (- x y))
    (message "mltply x y : %d" (* x y))
    (message "div x y : %d" (/ x y))))