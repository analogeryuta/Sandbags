;; equal-check.el ... eq, eql, equalの確認

(setq three 3)
(setq three-flt 3.0)


(setq hoge '(a i u e o))
(setq hoge2 '(a i u e o))
(setq aho '(a i u e o))


(defun check-eq (obj1 obj2)
  (if (eq obj1 obj2) (print "T") (print "F")))

(defun check-eql (obj1 obj2)
  (if (eql obj1 obj2) (print "T") (print "F")))

(defun check-equal (obj1 obj2)
  (if (equal obj1 obj2) (print "T") (print "F")))