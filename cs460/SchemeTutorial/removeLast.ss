(define (remove-last list0)
  (if (list? list0)
      (cond
       ((null? list0) '())
       ((null? (cdr list0)) '())
       (else (cons (car list0) (remove-last (cdr list0)))))
      "Error: Parameter must be a list."
))
