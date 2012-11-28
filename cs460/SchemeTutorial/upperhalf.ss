(define (upperhalf list0)
  (if (list? list0)
      (cond
       ((null? (cdr list0)) '())
       (else (if (>= (car list0) (last list0))
		 (cons (car list0) (upperhalf (cdr list0)))
		 (upperhalf (cdr list0)))))
      list0
))