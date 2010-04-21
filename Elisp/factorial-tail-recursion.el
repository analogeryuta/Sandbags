;; factorial-tail-recursion.el ... 末尾再帰の例題
;; 状態変数を増やさないとtail-recursionにならないんだってさ。
;; n ... 階乗
;; i ... 計算途中の階乗の位置
;; p ... 計算途中の階乗の結果
(defun factorial-tail-recursion (n)
  (factorial-loop n 1 1))

(defun factorial-loop (n i p)
  (if (> i n) p
    (factorial-loop n (+ i 1) (* p i))))