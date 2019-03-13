
#include "pokedex.h"

/************************************************************************
* FUNCTION DisplayDamage
*----------------------------------------------------------------------
* 	 This function receives the Pokemon array, the index  and the output file
* 	 	variable. This functions displays the Pokemon's damage that the would
* 	 	receive in battle
* 	 ==> returns nothing - It outputs the Pokemon's damage that they would
* 	 					   recieve in battle.
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in:
* 		POKEMON_AR  : The Pokemon array
* 		INDEX   	: The index in the pokemon array
* 		fout        : The output file variable
*
* POST-CONDITIONS
* 	==> Returns nothing - It outputs the Pokemon's damage that they would
* 						  recieve in battle.
*************************************************************************/
void DisplayDamage(const pokemonInfo POKEMON_AR[], //OUT  - the Pokemon array
		   	       const int         &INDEX,	   //PROC - the index
		           ofstream          &fout) 	   //OUT  - the output file
{
	/**************************************************************************
	 * CONSTANTS
	 * ------------------------------------------------------------------------
	 * USED FOR MAX/MIN
	 * ------------------------------------------------------------------------
	 * MAX_TYPES  : The max size of pokemon types
	 * ------------------------------------------------------------------------
	 * USED FOR COLUMN SIZES
	 * ------------------------------------------------------------------------
	 * TYPE_COL : The size of the Pokemon type column
	 * ------------------------------------------------------------------------
	 * USED FOR SPECIFIED VALUES
	 * ------------------------------------------------------------------------
	 * TYPES : The pokemon types available
	 *************************************************************************/
	const int MAX_TYPES = 18;
	const int TYPE_COL  = 10;

	const string TYPES[MAX_TYPES] =
	{
		"NORMAL",
		"FIGHTING",
		"FLYING",
		"POISON",
		"GROUND",
		"ROCK",
		"BUG",
		"GHOST",
		"STEEL",
		"FIRE",
		"WATER",
		"GRASS",
		"ELETRIC",
		"PSYCHIC",
		"ICE",
		"DRAGON",
		"DARK",
		"FAIRY"
	};

	int index;							  //PROC - The index in the array

	float damageTaken[MAX_TYPES] = {0.0}; //PROC - The array of damage
										  //       the pokemon will take

	PokemonTypes type1;					  //PROC - the enum of the pokemon's
										  //	   primary type
	PokemonTypes type2;					  //PROC - the enum of the pokemon's
										  //       seconary type

	//PROCESSING - Convert the pokemon's types into enumerated values
	ConvertTypeToEnum(type1, type2, POKEMON_AR[INDEX].basic.typeOne,
			          POKEMON_AR[INDEX].basic.typeTwo);

	//PROCESSING - Calculate the damage that the pokemon would take based on
	//			   their given types
	CalcDamageTaken(type1, type2, damageTaken);

	fout << "\nDamage Taken:\n";

	fout << left;

	//OUTPUT - Print the damage the pokemon would take
	for(index = NORMAL; index < MAX_TYPES; index++)
	{
		fout << setw(TYPE_COL) << TYPES[index] << ": *"
			 << damageTaken[index] << endl;
	}

	fout << right;
}
