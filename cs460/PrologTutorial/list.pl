/************************************************************************
brewer.pl
Sonoma State University
CS 460 - Fall 2010 - Watts
Programming Languages
Tutorial - Prolog Lists
Documented and Modified by: Eric Brewer
Date: 11/22/10
************************************************************************/

is_first(Element,[Element|_]).

/* Both of the following use simple recursion. They call the same function
     using the cdr of the list. */
is_last(Element,[Element]).
is_last(Element,[_|Tail]) :- is_last(Element,Tail).

is_in(Element,[Element|_]).
is_in(Element,[_|Tail]) :- is_in(Element,Tail).

/* Now these two use that simple recursion with implicit incrementation. Effectively
     the same as C's  return 1+how_long( list ); */
how_long(0,[]).
how_long(1,[_]).
how_long(N,[_|Tail]) :- how_long(M,Tail),
			N is M+1.

place(Element,[Element|_],1).
place(Element,[_|Tail],N) :- place(Element,Tail,M),
			     M > 0,
			     N is M+1.

/* The | operator allows for exactly this sort of method. */
insert_first(Element,List,[Element|List]).

insert_last( Element, [], [Element] ).
insert_last( Element, [Head|Tail], N ) :- insert_last( Element, Tail, M ),
                                          insert_first( Head, M, N ).

/* First here is the base case. Then we just call the same function passing
     the cdr of the list. */
remove_first([],[]).
remove_first([_|Tail],Tail).

remove_last( [_], [] ).
remove_last( [Head|Tail], N ) :- remove_last( Tail, M ),
                                 insert_first( Head, M, N ).

/* Here's the tricky. The key is that the variable Element refers to the
     same thing. */
concat([],List,List).
concat([Element|List1],List2,[Element|List3]) :- concat(List1,List2,List3).

switch( [], [] ).
switch( [Head|List], N ) :- switch( List, M ),
                            concat( M, [Head], N ).

/* Quicksort - in ascending order 
WARNING: The answer will be spit out many times: 8 times for an array of size 6,
  16 times for an array of size 10...
Sorts correctly */
quicksort( [], [] ).
quicksort( [Element], [Element] ).
quicksort( [Head|Tail], SortedList ) :- quick_split( Head, Tail, L, H ),
                                        quicksort( L, SL ),
                                        quicksort( H, SH ),
                                        concat( SL, [Head|SH], SortedList ).

quick_split( _Car, [], [], [] ).
quick_split( Car, [Head|Cdr], Low, High ) :- quick_split( Car, Cdr, Low, H ),
                                             Head > Car,
                                             insert_first( Head, H, High ).
quick_split( Car, [Head|Cdr], Low, High ) :- quick_split( Car, Cdr, L, High ),
                                             Car > Head,
                                             insert_first( Head, L, Low ).
