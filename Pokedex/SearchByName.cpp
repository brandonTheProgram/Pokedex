
#include "pokedex.h"

/************************************************************************
* FUNCTION SearchByName
*----------------------------------------------------------------------
* 	 This function receives an the Pokemon array and asks the user what the name
* 	 	of the Pokemon they are searching for and if it is spelled correctly
* 	 	then it will output that information
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
void SearchByName(const pokemonInfo POKEMON_AR[AR_SIZE], //PROC - the pokemon
		  	  	  	  	  	  	  	  	  	  	  	     //       array
				  const Menu        &MENU_CHOICE,		 //PROC - the menu
				  	  	  	  	  	  	  	  	  	  	 //       choice
				  ofstream          &fout) 				 //OUT  - output file
{
	string pokemonName; //IN - the name of the Pokemon

	int index;          //PROC - the position in the array

	//INPUT - Get the name of the Pokemon
	cout << "\nWhat is the name of the Pokemon? ";
	getline(cin, pokemonName);

	//PROCESSING - Capitalize the first letter of the Pokemon's name
	pokemonName[0] = toupper(pokemonName[0]);

	//PROCESSING - Store the index of the found pokemon
	index = SearchPokedex(POKEMON_AR, pokemonName, 0, MENU_CHOICE);

	//If it is not found, output a message saying it wasn't
	if(index == AR_SIZE)
	{
		cout << "\nThe Pokemon was not found. Check your spelling.\n";
	}
	else
	{
		cout << endl;
		cout << POKEMON_AR[index].basic.name << " was found. Check the output "
			 << "file for the Pokemon\'s information";

		//OUTPUT - Print the pokemon's information
		DisplayPokemonInfo(POKEMON_AR, index, fout);
	}
}
