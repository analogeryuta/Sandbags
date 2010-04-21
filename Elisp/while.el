;; while.el ... whileループの動作確認

(setq words '(solid liquid solidus))

;;whileループを使ったリストの表示
(defun print-elements-of-listf (list)
  "print each element of LIST on a line of its own."
  (while list
    (print (car list))
    (setq list (cdr list))))

;;whileループを使ったカウンタの増加
(defun inc-counter-in-while-loop ()
  "increment counter"
  (let ((count 0))
    (while (< count 10)
      (print count)
      (setq count (+ count 1)))))