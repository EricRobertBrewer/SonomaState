(define (all-reverse list0)
  (if (list? list0)
      (cond
       ((null? list0) '())
       (else (append (all-reverse (cdr list0)) (cons (all-reverse (car list0)) '()))))
      list0
))