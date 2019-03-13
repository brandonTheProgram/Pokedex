
#include "pokedex.h"

/************************************************************************
* FUNCTION DisplayTwoEvo
*----------------------------------------------------------------------
* 	 This function receives the Pokemon array, the index  and the output file
* 	 	variable. This functions displays the Pokemon's evolution tree based on
* 	 	having only 2 evolutions.
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
void DisplayTwoEvo(const pokemonInfo POKEMON_AR[], //OUT  - the Pokemon array
				   const int         &INDEX,	   //PROC - the index
				         ofstream    &fout) 	   //OUT  - the output file
{
	int firstEvolutionIndex;	//PROC - The index of the first evolution
	int finalEvolutionIndex;	//PROC - The index of the final evolution

	//PROCESSING - Match the pokedex number with the index
	firstEvolutionIndex = (POKEMON_AR[INDEX].advance.firstEvoNum - 1);
	finalEvolutionIndex = (POKEMON_AR[INDEX].advance.finalEvoNum - 1);

	//PROCESSING - If the pokemon is the first evolution
	if(POKEMON_AR[INDEX].advance.finalEvo != true)
	{
		fout << POKEMON_AR[INDEX].basic.name << " evolves by ";

		if(POKEMON_AR[INDEX].advance.evoThroughLvl  == true &&
		   POKEMON_AR[INDEX].advance.evoThroughCond == true	)
		{
			fout << POKEMON_AR[INDEX].advance.finalEvoCondition;
		}
		else if(POKEMON_AR[INDEX].advance.evoThroughLvl  == true &&
				POKEMON_AR[INDEX].advance.evoThroughCond == false)
		{
			fout << "leveling up to level " << POKEMON_AR[INDEX].advance.evoLvl;
		}
		else if(POKEMON_AR[INDEX].advance.evoThroughCond == true  &&
				POKEMON_AR[INDEX].advance.evoThroughLvl  == false)
		{
			fout << POKEMON_AR[INDEX].advance.finalEvoCondition;
		}
		else
		{
			fout << "\nERROR\n";
		}

		fout << " into "
			 << POKEMON_AR[finalEvolutionIndex].basic.name << ".";
	}
	//PROCESSING - If the pokemon is the final evolution
	else
	{
		fout << POKEMON_AR[firstEvolutionIndex].basic.name
			 << " evolves by ";

		if(POKEMON_AR[INDEX].advance.evoThroughLvl  == true &&
		   POKEMON_AR[INDEX].advance.evoThroughCond == true	)
		{
			fout << POKEMON_AR[INDEX].advance.finalEvoCondition;
		}
		else if(POKEMON_AR[INDEX].advance.evoThroughLvl  == true &&
				POKEMON_AR[INDEX].advance.evoThroughCond == false)
		{
			fout << "leveling up to level "
				 << POKEMON_AR[INDEX].advance.finalEvoLvl;
		}
		else if(POKEMON_AR[INDEX].advance.evoThroughCond == true  &&
				POKEMON_AR[INDEX].advance.evoThroughLvl  == false)
		{
			fout << POKEMON_AR[INDEX].advance.finalEvoCondition;
		}
		else
		{
			fout << "\nERROR\n";
		}

		fout << " into " << POKEMON_AR[INDEX].basic.name << ".";
	}
}
