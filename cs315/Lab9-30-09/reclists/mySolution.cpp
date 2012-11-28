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
