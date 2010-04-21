;;; let-asta.el ... let* の記述を確認よー

(defun hoge ()
  (let* ((a 3) (b (+ a 4))) ;;; VARLISTの前の要素で初期化した変数を、次の変数の初期化に使える
    (print b)))