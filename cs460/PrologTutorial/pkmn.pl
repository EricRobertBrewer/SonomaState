/* 
pkmn.pl
Eric Brewer
11/22/10
Watts
CS460 - Programming Languages
Pokemnon database - 
*/

type( charmander, fire ).
type( squirtle, water ).
type( bulbasaur, grass ).
type( bulbasaur, poison ).
type( koffing, poison ).
type( dratini, dragon ).
type( meowth, normal ).
type( pidgey, flying ).
type( pidgey, normal ).
type( mewtwo, psychic ).
type( onix, rock ).
type( onix, ground ).
type( mankey, fighting ).
type( pikachu, electric ).

legend( mewtwo ).

supereffective( X, Y ) :- type( X, fire ), type( Y, grass ).
supereffective( X, Y ) :- type( X, grass ), type( Y, water ).
supereffective( X, Y ) :- type( X, water ), type( Y, fire ).
supereffective( X, Y ) :- type( X, psychic ), type( Y, poison ).
supereffective( X, Y ) :- type( X, psychic ), type( Y, fighting ).
supereffective( X, Y ) :- type( X, poison ), type( Y, grass ).
supereffective( X, Y ) :- type( X, fighting ), type( Y, rock ).

uneffective( X, Y ) :- type( X, ground ), type( Y, flying ).
uneffective( X, Y ) :- type( X, electric ), type( Y, ground ).
