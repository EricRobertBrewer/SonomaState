(define (letter-filter list0)
  (if (list? list0)
      (cond
       ((null? list0) '())
       (else (if (number? (car list0))
		 (cons (car list0) (letter-filter (cdr list0)))
		 (letter-filter (cdr list0)))))
      "Parameter must be a list."
))
