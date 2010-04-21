;; 
;; insert-line-to-buffer.el ... 指定したバッファの、指定した行に、指定した文字列を挿入。
;; buf : 編集するバッファ
;; lineno : 編集するbufの行番号
;; str : lineno行目に挿入する文字列

(defun insert-line-to-buffer (buf lineno str)
  (let ((oldbuf (current-buffer)))
    (save-current-buffer
      (set-buffer (get-buffer-create buf))
      (goto-line lineno) ;;指定の行位置へ移動
      ;; 行頭から末尾までのテキストを削除
      (delete-region (progn (beginning-of-line) (point))
		     (progn (end-of-line) (point)))
      ;; 新しい行を挿入
      (insert str))))