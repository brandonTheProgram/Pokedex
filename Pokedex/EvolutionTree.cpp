
#include "pokedex.h"

/************************************************************************
* FUNCTION DisplayTwoEvo
*----------------------------------------------------------------------
* 	 This function receives the Pokemon array, the index  and the output file
* 	 	variable. This functions calls other functions to display the
* 	 	evolutionary tree based on the amount of evolution
* 	 ==> returns nothing - It outputs the Pokemon's evolution tree
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in:
* 		POKEMON_AR  : The Pokemon array
* 		INDEX   	: The index in the pokemon array
* 		fout        : The output file variable
*
* POST-CONDITIONS
* 	==> Returns nothing - It outputs the Pokemon's evolution tree
*************************************************************************/
void EvolutionTree(const pokemonInfo POKEMON_AR[], //PROC - the Pokemon array
				   const int         &INDEX,	   //PROC - the index
				   ofstream          &fout) 	   //OUT  - the output file
{
	fout << "\nEvolutionary Chain:\n\n";

	//PROCESSING - If the pokemon has a branch evolution tree, then display that
	if(POKEMON_AR[INDEX].advance.branchEvo == true)
	{
		DisplayBranchEvo(POKEMON_AR, INDEX, fout);
	}
	else
	{
		//PROCESSING - If the pokemon has only one evolution, then display that
		if(POKEMON_AR[INDEX].advance.evolutions == 1)
		{
			DisplayTwoEvo(POKEMON_AR, INDEX, fout);
		}
		//PROCESSING - If the pokemon has only two evolution, then display that
		else
		{
			DisplayThreeEvo(POKEMON_AR, INDEX, fout);
		}
	}
}
