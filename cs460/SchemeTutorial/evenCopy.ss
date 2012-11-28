(define (even-copy list0)
  (if (list? list0)
      (cond
       ((null? list0) '())
       ((null? (cdr list0)) '())
       (else (cons (car (cdr list0)) (even-copy (cddr list0)))))
      "Error: Parameter must be a list."
))