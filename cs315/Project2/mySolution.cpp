#include "reclists.hpp"
#include "mySolution.hpp"

list append( list p, list q )
{
     if( is_null( p ) ) return q;
     return cons( car(p), append( cdr(p), q ));
}

list reverse( list p )
{
     if( is_null(p) || atom(p) ) return p;
     return append( reverse( cdr(p) ), cons(car(p), null() )) ;
}


int equal(list p, list q){
  if(is_null(p) && is_null(q))
    return 1;
  if(is_null(p) || is_null(q))
    return 0;
  if(!atom(car(p)) || !atom(car(q)))
    return equal(car(p), car(q)) && equal(cdr(p), cdr(q));
  return eq(car(p), car(q)) && equal(cdr(p), cdr(q));
}

list total_reverse(list p){
  if(is_null(p) || atom(p))
    return p;
  return append( total_reverse( cdr(p) ), cons( total_reverse( car(p) ), null() ) );
}

int is_lat(list p){
  if(is_null(p))
    return 1;
  return atom(car(p)) && is_lat(cdr(p));
}

list flat(list p){
  if(is_null(p))
    return p;
  if(!atom(car(p)))
    return append( flat( car(p) ), flat( cdr(p) ) );
  return cons(car(p), flat(cdr(p)));
}

int member(list p, list q){
  if(is_null(q))
    return 0;
  if(!atom(car(q)))
    return member(p, car(q)) || member(p, cdr(q));
  return eq(p, car(q)) || member(p, cdr(q));
}

list last(list p){
  if(is_null(cdr(p)))
    return car(p);
  return last(cdr(p));
}

list shape(list p){
  return p;
}

list list_pair(list p, list q){
  if(is_null(p) || is_null(q))
    return p;
  return cons( cons( car(p), cons( car(q), null() ) ), 
	       list_pair( cdr(p), cdr(q) ) );
}

list firsts(list p){
  if(is_null(p))
    return p;
  return cons( car( car(p) ), firsts( cdr(p) ) );
}

int two_the_same(list p, list q){
  if(!is_lat(p) || !is_lat(q))
    return two_the_same(flat(p), flat(q));
  if(is_null(p) || is_null(q))
    return 0;
  return member(car(p), q) || two_the_same(cdr(p), q);
}

list intersection(list p, list q){
  if(is_null(p))
    return p;
  if( member( car(p), q ) )
    return cons( car(p), intersection( cdr(p), q ) );
  return intersection( cdr(p), q );
}

list list_union(list p, list q){
  if(is_null(q))
    return p;
  if(is_null(p))
    return q;
  if( !member( car(p), q ) )
    return cons( car(p), list_union( cdr(p), q ) );
  return list_union( cdr(p), q );
}
