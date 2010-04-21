;;; test-open-network.el ... tcp/ip接続を行う関数の例題
;;; yahooのトップページを取得してみる
(defun test-open-network ()
  "get file from http server"
  (interactive)
  (let ((buf (get-buffer-create "web conection"))
	(proc nil))
    (setq proc (open-network-stream "web-connection" buf "www.yahoo.co.jp" 80))
    (set-process-coding-system proc 'binary 'binary)
    (display-buffer buf)
    (process-send-string proc
			 (format (concat
				  "GET / HTTP/1.0\r\n"
				  "MIME-Version: 1.0\r\n"
				  "\r\n")))))