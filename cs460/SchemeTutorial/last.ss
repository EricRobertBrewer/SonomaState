(define (last list0)
  (if (list? list0)
      (cond
       ((null? list0) '())
       ((null? (cdr list0)) (car list0))
       (else (last (cdr list0))))
      list0
))