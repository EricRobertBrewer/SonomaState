(define (insert-last item0 list0)
  (if (list? list0)
      (cond
       ((null? list0) (cons item0 '()))
       (else (cons (car list0) (insert-last 'item0 (cdr list0)))))
      "Error: Second parameter must be a list."
))