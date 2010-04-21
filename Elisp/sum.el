;;sum-test.el : summationのテスト。なんでこう書ける?
(defun sum (&rest x) "summation of integer"
  (let ((f 0))
    (while (not (null x))
      (setq f (+ f (car x)))
      (setq x (cdr x)))
    f))