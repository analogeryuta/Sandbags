;; hash.el ... 連想配列(hash)の例題. redit-client-sm.elから拝借...

(setq key-list '(one two three four five six seven eight nine ten))
(setq val-list '(1 2 3 4 5 6 7 8 9 10))

;;hash tableを生成
(defvar htable-hoge (make-hash-table))

;;hash tableにキーと値を登録
(defun put-htable-hoge (key val)
  (setf (gethash key htable-hoge) val))

;;hash tableから値を取得
(defun get-htable-hoge (key)
  (gethash key htable-hoge))

;;hash tableから値を削除
(defun rm-htable-hoge (key)
  (rmhash key htable-hoge))

(defun hash-test ()
  )