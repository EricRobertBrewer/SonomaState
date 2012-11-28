(define (list-copy list0)
  (if (list? list0)
      (cond
       ((null? list0) '())
       (else (cons (car list0) (list-copy (cdr list0)))))
      "Error: Parameter must be a list."
))
