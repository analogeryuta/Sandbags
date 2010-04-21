;; combination.el ... 組み合わせの計算を行う
;; 最初に定義したやつは除算の桁落ちのせいでダメダメだ...
(defun combination (n k)
  (if (= k 0) 1
      (* (/ n k) (combination (- n 1) (- k 1)))))

(defun C (n k)
  (if (= k 0) 1
    (if (= n k) 1
      (+ (C (- n 1) (- k 1)) (C (- n 1) k)))))