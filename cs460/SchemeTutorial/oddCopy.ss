(define (odd-copy list0)
  (if (list? list0)
      (cond
       ((null? list0) '())
       ((null? (cdr list0)) list0)
       (else (cons (car list0) (odd-copy (cddr list0)))))
      "Error: Paramter must be a list."
))
