
#include "pokedex.h"

/************************************************************************
* FUNCTION ThreeEvoBranch
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
void TwoEvoBranch  (const pokemonInfo POKEMON_AR[], //OUT  - the Pokemon array
				    const int         &INDEX,       //PROC - the index
					ofstream          &fout)        //OUT  - the output file
{
	int firstEvolutionIndex;   //PROC - the index of the first evo
	int finalEvolutionIndex;   //PROC - the index of the final evo
	int branchEvolutionIndex;  //PROC - the index of the branch evo

	//PROCESSING - Store the index of the evolutions
	firstEvolutionIndex  = (POKEMON_AR[INDEX].advance.firstEvoNum     - 1);
	finalEvolutionIndex  = (POKEMON_AR[INDEX].advance.finalEvoNum     - 1);
	branchEvolutionIndex = (POKEMON_AR[INDEX].advance.branchEvoNumber - 1);

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
			 << POKEMON_AR[finalEvolutionIndex].basic.name << "\nor into "
			 << POKEMON_AR[branchEvolutionIndex].basic.name << " by ";

		//Display the branch evolution condition
		if(POKEMON_AR[branchEvolutionIndex].advance.evoThroughLvl  == true &&
		   POKEMON_AR[branchEvolutionIndex].advance.evoThroughCond == true	)
		{
			fout << POKEMON_AR[branchEvolutionIndex].advance.finalEvoCondition;
		}
		else if(POKEMON_AR[branchEvolutionIndex].advance.evoThroughLvl  == true
				&&
			   POKEMON_AR[branchEvolutionIndex].advance.evoThroughCond == false)
		{
			fout << "leveling up to level "
				 << POKEMON_AR[branchEvolutionIndex].advance.finalEvoLvl;
		}
		else if(POKEMON_AR[branchEvolutionIndex].advance.evoThroughCond == true
				&&
			   POKEMON_AR[branchEvolutionIndex].advance.evoThroughLvl  == false)
		{
			fout << POKEMON_AR[branchEvolutionIndex].advance.finalEvoCondition;
		}
		else
		{
			fout << "\nERROR\n";
		}

		fout << ".";
	}
	else
	{
		fout << POKEMON_AR[firstEvolutionIndex].basic.name
			 << " evolves by ";

		if(POKEMON_AR[finalEvolutionIndex].advance.evoThroughLvl  == true &&
		   POKEMON_AR[finalEvolutionIndex].advance.evoThroughCond == true	)
		{
			fout << POKEMON_AR[finalEvolutionIndex].advance.finalEvoCondition;
		}
		else if(POKEMON_AR[finalEvolutionIndex].advance.evoThroughLvl  == true
				&&
				POKEMON_AR[finalEvolutionIndex].advance.evoThroughCond == false)
		{
			fout << "leveling up to level "
				 << POKEMON_AR[finalEvolutionIndex].advance.finalEvoLvl;
		}
		else if(POKEMON_AR[finalEvolutionIndex].advance.evoThroughCond == true
				&&
				POKEMON_AR[finalEvolutionIndex].advance.evoThroughLvl  == false)
		{
			fout << POKEMON_AR[finalEvolutionIndex].advance.finalEvoCondition;
		}
		else
		{
			fout << "\nERROR\n";
		}

		fout << " into " << POKEMON_AR[finalEvolutionIndex].basic.name
			 << "\nor into "
			 << POKEMON_AR[branchEvolutionIndex].basic.name << " by ";

		//Display the branch evolution condition
		if(POKEMON_AR[branchEvolutionIndex].advance.evoThroughLvl  == true &&
		   POKEMON_AR[branchEvolutionIndex].advance.evoThroughCond == true	)
		{
			fout << POKEMON_AR[branchEvolutionIndex].advance.finalEvoCondition;
		}
		else if(POKEMON_AR[branchEvolutionIndex].advance.evoThroughLvl  == true
				&&
			   POKEMON_AR[branchEvolutionIndex].advance.evoThroughCond == false)
		{
			fout << "leveling up to level "
				 << POKEMON_AR[branchEvolutionIndex].advance.finalEvoLvl;
		}
		else if(POKEMON_AR[branchEvolutionIndex].advance.evoThroughCond == true
				&&
			   POKEMON_AR[branchEvolutionIndex].advance.evoThroughLvl  == false)
		{
			fout << POKEMON_AR[branchEvolutionIndex].advance.finalEvoCondition;
		}
		else
		{
			fout << "\nERROR\n";
		}

		fout << ".";
	}
}
