(define (lowerhalf list0)
  (if (list? list0)
      (cond
       ((null? list0) '())
       (else (if (< (car list0) (last list0))
		 (cons (car list0) (lowerhalf (cdr list0)))
		 (lowerhalf (cdr list0)))))
      list0
))