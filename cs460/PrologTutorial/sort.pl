/*
sort.pl
Eric Brewer
12/13/10
Watts
CS460 - Programming Languages
Quicksort - 
*/

concat([],List,List).
concat([Element|List1],List2,[Element|List3]) :- concat(List1,List2,List3).

