(defun concat-out (hoge fuga)
  "concatinate two string and output..."
  (interactive "P")
  (message "concat string : %s" (concat hoge fuga))
  )