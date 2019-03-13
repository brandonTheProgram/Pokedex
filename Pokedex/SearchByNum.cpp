
#include "pokedex.h"

/************************************************************************
* FUNCTION SearchByNum
*----------------------------------------------------------------------
* 	 This function receives an the Pokemon array and asks the user what number
* 	 	in the Pokedex that they are searching for and if it is within the max
* 	 	amount of Pokemon available(AR_SIZE) then it will output that
* 	 	 information
* 	 ==> returns nothing - Outputs Pokemon information
*-----------------------------------------------------------------------
* PRE-CONDITIONS
*   The following need to have defined values
*     POKEMON_AR[AR_SIZE] - the Pokemon array
*     MENU_CHOICE         - the choice from the menu
*     fout                - the output file's variable
*
* POST-CONDITIONS
* 	==> Returns nothing - Outputs Pokemon information
*************************************************************************/
void SearchByNum (const pokemonInfo POKEMON_AR[AR_SIZE], //PROC - the pokemon
		  	  	  	  	  	  	  	  	  	  	  	     //       array
				  const Menu        &MENU_CHOICE,		 //PROC - the menu
				  	  	  	  	  	  	  	  	  	  	 //       choice
				  ofstream          &fout) 				 //OUT  - output file
{

	int pokedexNumber;  //IN - the number of the pokemon that corresponds with
					    //     the Pokedex
	int index;

	bool   invalid;      //PROC       - the condition for invalid inputs
	bool   fail;         //PROC       - the condition for failed inputs

	string intString;   //PROC & OUT - the int converted to a string
	string errorMessage; //OUT        - the message when an error is encountered

	do
	{
		cout << "\nWhat is the number of the pokemon that you are "
			 <<	"looking for? ";
		cin  >> pokedexNumber;

		invalid = (pokedexNumber <= 0 || pokedexNumber > AR_SIZE);
		fail    = (cin.fail());

		if(invalid || fail)
		{
			//If input fail, then specify that a number should be entered
			if(fail)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\n**** Please input a NUMBER between 1 and "
					 << AR_SIZE << " ****\n\n";
			}
			//Output an error message
			else
			{
				intString = to_string(pokedexNumber);
				errorMessage = ("The number " + intString
											  + " is an invalid entry");
				cout << left << endl;
				cout << "**** " << setw(INVALID_COL) << (errorMessage)
					 << " ****";
				cout << "\n**** " << "Please input a number between 1 and "
					 << AR_SIZE << " ****\n\n";
				cout << right;
			}
		}

	}while(invalid || fail);

	index = SearchPokedex(POKEMON_AR, " ", pokedexNumber, MENU_CHOICE);

	cout << endl;
	cout << POKEMON_AR[index].basic.name << " was found. Check the output "
		 << "file for the Pokemon\'s information";

	//OUTPUT - Print the Pokemon's information
	DisplayPokemonInfo(POKEMON_AR, index, fout);

	cin.ignore(1000, '\n');

}
