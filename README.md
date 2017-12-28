# klondike-patterns

## Introduction
 
###### Project belonging to the master in craftmanship software, in which we apply the knowledge of software analysis and design. To do this, an mvc-based application must be created in which the SOLID principles and the Clean Code guide must be used, in addition to using Gamma design patterns (or suitable adaptations thereof) in C ++.

## MVC - Model-View-Controller
	
## Model
[![model](/resources/Model-Released.png)](https://github.com/MarcoCaballero/klondike-patterns/tree/master/resources/Model-Released.png)

### Patterns
 - Builder (BoardBuilder)
 - Singleton (FrenchDeckUtils)

###  Relevant principles
 - Liskov substitution
	
	> If Deck, Tableau and Foundation inherits from CardList then we should assure that the 	
	> preconditions of derived classes are equal or weaker than those of Base. This can not be 	
	> guaranteed for the push()and pushlist () methods where in cardlist it is possible to insert 	> any letter but in the derivatives not.
	
 	- Before:
 [![model](/resources/Model-PreLiskov.png)](https://github.com/MarcoCaballero/klondike-patterns/tree/master/resources/Model-PreLiskov.png)
 	- After:
	[![model](/resources/Model-Released.png)](https://github.com/MarcoCaballero/klondike-patterns/tree/master/resources/Model-Released.png)
	
	
