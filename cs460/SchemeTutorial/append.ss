(define (append list0 list1)
  (if (list? list0)
      (if (list? list1)
	  (cond
	   ((null? list0) list1)
	   (else (cons (car list0) (append (cdr list0) list1))))
	  "Error: Second parameter must be a list."
	  )
      "Error: First parameter must be a list."
))