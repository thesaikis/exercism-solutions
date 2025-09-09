(defpackage :raindrops
  (:use :cl)
  (:export :convert))

(in-package :raindrops)

(defun convert (n)
  "Converts a number to a string of raindrop sounds."
  (let ((result ""))
       (when (zerop (mod n 3))
         (setf result (concatenate 'string result "Pling")))
       (when (zerop (mod n 5))
         (setf result (concatenate 'string result "Plang")))
       (when (zerop (mod n 7))
         (setf result (concatenate 'string result "Plong")))
       (if (string= result "")
           (format nil "~a" n)
           result)))
