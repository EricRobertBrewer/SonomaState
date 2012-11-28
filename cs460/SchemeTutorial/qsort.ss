(define (qsort list0)
  (if (list? list0)
      (cond
       ((null? list0) '())
       (else (append (append (qsort (lowerhalf list0)) (cons (last list0) '())) (qsort (upperhalf list0)))))
      list0
))