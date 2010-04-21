;;append-to-buffer.el ... current bufferから一定範囲文字列をきりだし、指定したbuffer(の末尾)
;;                        copyする
(defun append-to-buffer (buffer start end)
  "Append to specified buffer the text of the region..."
  (interactive "BAppend to buffer: \nr")
  (let ((oldbuf (current-buffer)))
    (save-excursion
      (set-buffer (get-buffer-create buffer))
      (insert-buffer-substring oldbuf start end))))