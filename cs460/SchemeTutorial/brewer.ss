; brewer.ss
; Eric Brewer
; 10/5/10
; Watts
; CS460 - Programming Languages
; Scheme Tutorial

(define (insert-first list0 list1)
  (if (list? list1)
      (cons list0 list1)
      "Error: Second parameter should be a list."
))

(define (remove-first list0)
  (if (list? list0)
      (if (null? list0)
          "Error: List cannot be null."
          (cdr list0))
      "Error: First parameter should be a list."
))

(define (list-copy list0)
  (if (list? list0)
      (cond
       ((null? list0) '())
       (else (cons (car list0) (list-copy (cdr list0)))))
      "Error: Parameter must be a list."
))

(define (odd-copy list0)
  (if (list? list0)
      (cond
       ((null? list0) '())
       ((null? (cdr list0)) list0)
       (else (cons (car list0) (odd-copy (cddr list0)))))
      "Error: Paramter must be a list."
))

(define (even-copy list0)
  (if (list? list0)
      (cond
       ((null? list0) '())
       ((null? (cdr list0)) '())
       (else (cons (car (cdr list0)) (even-copy (cddr list0)))))
      "Error: Parameter must be a list."
))

(define (insert-last item0 list0)
  (if (list? list0)
      (cond
       ((null? list0) (cons item0 '()))
       (else (cons (car list0) (insert-last 'item0 (cdr list0)))))
      "Error: Second parameter must be a list."
))

(define (remove-last list0)
  (if (list? list0)
      (cond
       ((null? list0) '())
       ((null? (cdr list0)) '())
       (else (cons (car list0) (remove-last (cdr list0)))))
      "Error: Parameter must be a list."
))

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

(define (list-reverse list0)
  (if (list? list0)
      (cond
       ((null? list0) '())
       (else (append (list-reverse (cdr list0)) (cons (car list0) '()))))
      list0
))

(define (all-reverse list0)
  (if (list? list0)
      (cond
       ((null? list0) '())
       (else (append (all-reverse (cdr list0)) (cons (all-reverse (car list0)) '()))))
      list0
))

; last is defined simply to be used as a pivot in the quicksort function
(define (last list0)
  (if (list? list0)
      (cond
       ((null? list0) '())
       ((null? (cdr list0)) (car list0))
       (else (last (cdr list0))))
      list0
))

; lowerhalf returns numbers in the list that are less than the pivot
(define (lowerhalf list0)
  (if (list? list0)
      (cond
       ((null? list0) '())
       (else (if (< (car list0) (last list0))
                 (cons (car list0) (lowerhalf (cdr list0)))
                 (lowerhalf (cdr list0)))))
      list0
))

; similarly, returns numbers greater than the pivot
(define (upperhalf list0)
  (if (list? list0)
      (cond
       ((null? (cdr list0)) '())
       (else (if (>= (car list0) (last list0))
                 (cons (car list0) (upperhalf (cdr list0)))
                 (upperhalf (cdr list0)))))
      list0
))

(define (quicksort list0)
  (qsort (letter-filter list0))
)

; returns the list with alphabetic characters tossed out - used in quicksort
(define (letter-filter list0)
  (if (list? list0)
      (cond
       ((null? list0) '())
       (else (if (number? (car list0))
                 (cons (car list0) (letter-filter (cdr list0)))
                 (letter-filter (cdr list0)))))
      "Error: Parameter must be a list."
))

; assumes only numeric values in a list and therefore should not be used in a guile prompt
(define (qsort list0)
  (if (list? list0)
      (cond
       ((null? list0) '())
       (else (append (append (qsort (lowerhalf list0)) (cons (last list0) '())) (qsort (upperhalf list0)))))
      list0
))
