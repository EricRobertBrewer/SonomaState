(define (list-reverse list0)
  (if (list? list0)
      (cond
       ((null? list0) '())
       (else (append (list-reverse (cdr list0)) (cons (car list0) '()))))
      list0
))