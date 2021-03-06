# klondike-patterns

## Introduction
 
###### Project belonging to the Master in Software Craftmanship, in which we apply the knowledge of software analysis and design. To do this, an mvc-based application must be created in which the SOLID principles and the Clean Code guide must be used, in addition to using Gamma design patterns (or suitable adaptations thereof) in C ++.

## MVC - Model-View-Controller
	
## Model
[![model](/resources/Model-Released.png)](https://raw.githubusercontent.com/MarcoCaballero/klondike-patterns/master/resources/Model-Released.png)

### Patterns
 - Builder (BoardBuilder)
 - Singleton (FrenchDeckUtils)
 - Fachade (Game)

###  Relevant principles
 - SO**L**ID - >Liskov substitution
	
	> If Deck, Tableau and Foundation inherits from CardList then we should assure that the 	
	preconditions of derived classes are equal or weaker than those of Base. This can not be 	
	guaranteed for the `push()` and `pushlist()` methods where in cardlist it is possible to insert 
	any letter but in the derivatives not.
	
 	- Before:
 [![model](/resources/Model-PreLiskov.png)](https://github.com/MarcoCaballero/klondike-patterns/tree/master/resources/Model-PreLiskov.png)
 	- After:
	[![model](/resources/Model-Released.png)](https://github.com/MarcoCaballero/klondike-patterns/tree/master/resources/Model-Released.png)
	
	
## Controller
[![model](/resources/Controller.png)](https://raw.githubusercontent.com/MarcoCaballero/klondike-patterns/master/resources/Controller.png)

### Patterns
 - Builder (LogicBuilder)
 - Visitor (GameControllerVisitor, GameController and deriveds, and implements view)

###  Relevant principles
 - DRY (Don't repeat yourself)
	
	> In order for all game controllers to have a common code, a base class must be created, called `GameController`, to which everyone will extend, thus avoiding repetition of the code.
	
- SOLI**D** -> DIP (Dependency inversion)
	
	> To avoid cycles in the implementation of the **visitor** **pattern** , **dependency inversion** is applied on `GameController` and its derivatives and `KlondikeView` adding an interface called `GameControllerVisitor`.
	
		
- Double Dispatch

	> For the implementation of the ** visitor ** ** pattern *, ** double ** ** dispatch ** must be applied between the corresponding implementation of the `GameControllerVisitor` and  `KlondieView`.
	
		
## View
[![model](/resources/View.png)](https://raw.githubusercontent.com/MarcoCaballero/klondike-patterns/master/resources/View.png)

### Patterns
 - Singleton `Multitone` (KlondikeRegistry, KlondikeView and deriveds)
 - Singleton (IOUtils)
 - Visitor (KlondikeView, KlondikeViewConsole implements GameControllerVisitor from controller model)
 - Command (CommandDispatcher, Command and deriveds)
 - Template method (Command and deriveds)
 - Fachade (CommandDispatcher)

###  Relevant principles
 - DRY (Don't repeat yourself)
	
	> In order for all command to have a common algorithm but implementing its own part, a base class must be created, called `Command`, to which everyone will inherit, thus avoiding repetition of the algorithm structure (Template method) .
	
- Double Dispatch

	> For the implementation of the ** visitor ** ** pattern *, ** double ** ** dispatch ** must be applied between `KlondieView` and the corresponding implementation of the `GameControllerVisitor`
	
## MVC DIAGRAM

[![model](/resources/Klondike.png)](https://raw.githubusercontent.com/MarcoCaballero/klondike-patterns/master/resources/Klondike.png)	
