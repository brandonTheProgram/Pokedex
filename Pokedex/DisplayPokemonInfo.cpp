
#include "pokedex.h"

/************************************************************************
* FUNCTION DisplayPokemonInfo
*----------------------------------------------------------------------
* 	 This function receives the Pokemon array, the index  and the output file
* 	 	variable. This functions displays the Pokemon's information
* 	 ==> returns nothing - It outputs the Pokemon's information
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in:
* 		POKEMON_AR  : The Pokemon array
* 		INDEX   	: The index in the pokemon array
* 		fout        : The output file variable
*
* POST-CONDITIONS
* 	==> Returns nothing - It outputs the Pokemon's information
*************************************************************************/
void DisplayPokemonInfo(const pokemonInfo POKEMON_AR[], //OUT  - the Pokemon
														//       array
						const int         &INDEX,       //PROC - the index
						ofstream          &fout)        //OUT  - the output file
{
	/**************************************************************************
	 * CONSTANTS
	 * ------------------------------------------------------------------------
	 * USED FOR COLUMN SIZES
	 * ------------------------------------------------------------------------
	 * LINE_SIZE : The size of the page
	 *************************************************************************/
	const int LINE_SIZE = 75;

	fout << "***************************************************************\n";

	fout << POKEMON_AR[INDEX].basic.name << " #" << setw(3)
		 << POKEMON_AR[INDEX].basic.pokedexNumber;

	fout << endl << endl;

	fout << "Species: " << POKEMON_AR[INDEX].basic.species << "\nType(s): ";

	//OUTPUT - If the pokemon has two different types, display both of them
	if(POKEMON_AR[INDEX].basic.typeOne != POKEMON_AR[INDEX].basic.typeTwo)
	{
		fout << POKEMON_AR[INDEX].basic.typeOne << " and "
			 << POKEMON_AR[INDEX].basic.typeTwo << endl << endl;
	}
	else
	{
		fout << POKEMON_AR[INDEX].basic.typeOne << endl << endl;
	}

	//OUTPUT - Print the pokemon's description in neat paragraph formation
	fout << WordWrap(POKEMON_AR[INDEX].basic.description, LINE_SIZE)
		 << endl << endl;

	fout << "**********************************"
			"*****************************\n";

	//OUTPUT - Display the Pokemon's abilities
	DisplayAbility(POKEMON_AR, INDEX, POKEMON_AR[INDEX].advance.abilities,
						fout);

	fout << "***************************************************************\n";

	///OUTPUT - Display the pokemon's damage
	DisplayDamage(POKEMON_AR, INDEX, fout);

	//If there is more than one evolution, then display the evolution tree
	if(POKEMON_AR[INDEX].advance.evolutions > 0)
	{
		EvolutionTree(POKEMON_AR, INDEX, fout);
	}

	fout << "\n*******************************************"
			"********************\n\n";
	fout << right;
}
