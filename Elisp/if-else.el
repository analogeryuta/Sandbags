;; if-else.el ... if-then-elseの確認

(defun if-else (hoge)
  "evaluate state..."
  (interactive "P")
  (if (< hoge 5) 
      (message "hoge is less than 5")   ;if節の条件が真の時
    (message "hoge is greater than 5")) ;条件が偽の時。else以下に相当
  )

(defun abs (num)
  "calcuration absolute number..."
  (if (< num 0) (- num) num))