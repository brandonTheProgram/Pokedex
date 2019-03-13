
#include "pokedex.h"

/************************************************************************
* FUNCTION DisplayBranchEvo
*----------------------------------------------------------------------
 * 	 This function receives the Pokemon array, the index for the pokemon, and '
 * 	 	the output file variable. It then prints out the evolution tree for
 * 	 	pokemon that have special branch evolutions
 * 	 ==> returns nothing - It outputs the Pokemon's branch evolution tree
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in:
* 		POKEMON_AR  : The Pokemon array
* 		INDEX   	: The index in the pokemon array
* 		fout        : The output file variable
*
* POST-CONDITIONS
* 	==> Returns nothing - It outputs the Pokemon's branch evolution tree
*************************************************************************/
void DisplayBranchEvo(const pokemonInfo POKEMON_AR[], //OUT  - the Pokemon array
				      const int         &INDEX,		  //PROC - the index
					  ofstream          &fout)	   	  //OUT  - the output file
{
	/**************************************************************************
	 * CONSTANTS
	 * ------------------------------------------------------------------------
	 * USED FOR MAX/MIN
	 * ------------------------------------------------------------------------
	 * SPECIAL_BRANCHES  : The max size of special branch pokemons
	 * ------------------------------------------------------------------------
	 * USED FOR SPECIFIED VALUES
	 * ------------------------------------------------------------------------
	 * SPECIAL_BRANCHE_EVOS : The pokedex numbers of pokemon with special
	 * 						  branch evolutions
	 *************************************************************************/
	const int SPECIAL_BRANCHES = 18;

	const int SPECIAL_BRANCHE_EVOS[SPECIAL_BRANCHES] =
	{
		106, 107, 133, 134, 135, 136, 196, 197,
		236, 237, 265, 266, 267, 268, 269, 470,
		471, 700
	};

	int index;				//PROC - The index in the array

	bool specialBranchs;	//PROC - The condition if the pokemon is special

	//PROCESSING - Initialize the values
	index = 0;
	specialBranchs = false;

	//PROCESSING - Loop through to find if the specificed pokemon has a unique
	//			   branch evolutions
	while(index < SPECIAL_BRANCHES && !specialBranchs)
	{
		if(POKEMON_AR[INDEX].basic.pokedexNumber == SPECIAL_BRANCHE_EVOS[index])
		{
			SpecialBranchEvo(POKEMON_AR, INDEX, fout);
			specialBranchs = true;
		}
		index++;
	}

	//PROCESSING - If the pokemon is not a special branch evo, then print the
	//			   evo branch for that pokemon
	if(specialBranchs == false)
	{
		if(POKEMON_AR[INDEX].advance.evolutions == 1)
		{
			//PROCESSING - Pokemon with only 2 normal evolutions and
			//			   1 branch evo
			TwoEvoBranch(POKEMON_AR, INDEX, fout);
		}
		else
		{
			//PROCESSING - Pokemon with only 3 normal evolutions and
			//		       1 branch evo
			ThreeEvoBranch(POKEMON_AR, INDEX, fout);
		}
	}
}
