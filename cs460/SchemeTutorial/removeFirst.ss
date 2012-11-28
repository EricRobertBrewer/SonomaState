(define (remove-first list0)
  (if (list? list0)
      (if (null? list0)
	  "Error: List cannot be null."
	  (cdr list0))
      "Error: First parameter should be a list."
))
