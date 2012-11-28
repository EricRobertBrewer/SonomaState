(define (insert-first list0 list1)
  (if (list? list1)
      (cons list0 list1)
      "Error: Second parameter should be a list."
))
