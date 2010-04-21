;;
;; queue.el : 構造体とリストの生成による、キューの実装
;;

;;common-lispパッケージを使う
(even-while-compile (require 'cl))

;;構造体の定義
;; (defstruct NAME (SLOT) (SLOT SLOT-OPTS) ...)
;; NAME:構造体の名前
;; SLOT:構造体のメンバ
;; SLOT-OPTS:メンバの初期値(?)
;;
;;  各メンバを参照する時は、
;;  (if (NAME-SLOT queue) ...
;;  
(defstruct Queue (front nil) (rear nil))

;;リスト（キュー）を一つ作る
(defvar local-queue nil
  "local queue list...")

;;キューリストへの挿入
(defun enqueue (queue item)
  (let ((new-cell (list item)))
    (if (Queue-front queue)
        ;; 最終セルを書き換える
        (setf (cdr (Queue-rear queue)) new-cell)
      ;; キューは空の状態
      (setf (Queue-front queue) new-cell))
    (setf (Queue-rear queue) new-cell)))

;;キューリストからの削除
(defun dequeue (queue)
  (if (Queue-front queue)
      (prog1
          (pop (Queue-front queue))
        (unless (Queue-front queue)
          ;; queue is empty
          (setf (Queue-rear queue) nil)))))

;;キューを全消去する
(defun dequeue-all (queue)
  "clean queue"
  (while (Queue-front queue)
    (dequeue queue)))

;;キューのテストルーチン
(defun queue-test (list item)
)