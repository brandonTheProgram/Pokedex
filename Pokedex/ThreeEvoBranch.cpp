
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
void ThreeEvoBranch(const pokemonInfo POKEMON_AR[], //OUT  - the Pokemon array
				    const int         &INDEX,       //PROC - the index
					ofstream          &fout)        //OUT  - the output file
{
	int firstEvolutionIndex;	//PROC - the index of the first evo
	int secondEvolutionIndex;	//PROC - the index of the second evo
	int finalEvolutionIndex;	//PROC - the index of the final evo
	int branchEvolutionIndex;	//PROC - the index of the branch evo

	//PROCESSING - Store the index of the evolutions
	firstEvolutionIndex  = (POKEMON_AR[INDEX].advance.firstEvoNum     - 1);
	secondEvolutionIndex = (POKEMON_AR[INDEX].advance.secEvoNum       - 1);
	finalEvolutionIndex  = (POKEMON_AR[INDEX].advance.finalEvoNum     - 1);
	branchEvolutionIndex = (POKEMON_AR[INDEX].advance.branchEvoNumber - 1);

	//If the Pokemon is the first in the 3 chain
	if(POKEMON_AR[INDEX].advance.finalEvo != true &&
	   POKEMON_AR[INDEX].advance.secEvo   != true)
	{
		fout << POKEMON_AR[INDEX].basic.name << " evolves by ";

		//If the first evolution evolves through leveling and condition
		if(POKEMON_AR[INDEX].advance.evoThroughLvl  == true &&
		   POKEMON_AR[INDEX].advance.evoThroughCond == true	)
		{
			fout << POKEMON_AR[INDEX].advance.secEvoCondition;

			//If the second evolution evolves through leveling and condition
			if(POKEMON_AR[secondEvolutionIndex].advance.evoThroughLvl
					== true &&
			   POKEMON_AR[secondEvolutionIndex].advance.evoThroughCond
				   == true)
			{
				fout << " then evolves into "
				     << POKEMON_AR[secondEvolutionIndex].basic.name << "\nby "
					 << POKEMON_AR[INDEX].advance.finalEvoCondition
					 << " into "
					 << POKEMON_AR[finalEvolutionIndex].basic.name;
			}
			//If the second evolution evolves through leveling and not condition
			else if(POKEMON_AR[secondEvolutionIndex].advance.evoThroughLvl
						== true &&
			        POKEMON_AR[secondEvolutionIndex].advance.evoThroughCond
					    == false)
			{
				fout << " then evolves into "
					 << POKEMON_AR[secondEvolutionIndex].basic.name << "\nby "
					 << "leveling up to level "
					 << POKEMON_AR[INDEX].advance.finalEvoLvl << " then "
					 << POKEMON_AR[finalEvolutionIndex].basic.name;
			}
			//If the second evolution evolve through condition and not leveling
			else
			{
				fout << " into "
					 << POKEMON_AR[secondEvolutionIndex].basic.name << "\nthen "
					 << POKEMON_AR[INDEX].advance.finalEvoCondition
					 << " for "
					 << POKEMON_AR[finalEvolutionIndex].basic.name;
			}
		}

		//If the first evolution evolves through leveling and not condition
		else if(POKEMON_AR[INDEX].advance.evoThroughLvl  == true &&
				POKEMON_AR[INDEX].advance.evoThroughCond == false)
		{
			fout << "leveling up to level " << POKEMON_AR[INDEX].advance.evoLvl;

			//If the second evolution evolves through leveling and condition
			if(POKEMON_AR[secondEvolutionIndex].advance.evoThroughLvl
					== true &&
			   POKEMON_AR[secondEvolutionIndex].advance.evoThroughCond
				   == true)
			{
				fout << " then evolves into "
				     << POKEMON_AR[secondEvolutionIndex].basic.name << "\nby "
					 << POKEMON_AR[INDEX].advance.finalEvoCondition
					 << " then into "
					 << POKEMON_AR[finalEvolutionIndex].basic.name;
			}

			//If the second evolution evolves through leveling and not condition
			else if(POKEMON_AR[secondEvolutionIndex].advance.evoThroughLvl
						== true &&
			        POKEMON_AR[secondEvolutionIndex].advance.evoThroughCond
					    == false)
			{
				fout << " into "
					 << POKEMON_AR[secondEvolutionIndex].basic.name << "\nthen "
					 << "leveling up to level "
					 << POKEMON_AR[INDEX].advance.finalEvoLvl << " for "
					 << POKEMON_AR[finalEvolutionIndex].basic.name;
			}
			//If the second evolution evolve through condition and not leveling
			else
			{
				fout << " into "
					 << POKEMON_AR[secondEvolutionIndex].basic.name
					 << "\nthen by "
					 << POKEMON_AR[INDEX].advance.finalEvoCondition
					 << " for "
					 << POKEMON_AR[finalEvolutionIndex].basic.name;
			}
		}
		//If the first evolution evolves through condition and not leveling
		else if(POKEMON_AR[INDEX].advance.evoThroughCond == true  &&
				POKEMON_AR[INDEX].advance.evoThroughLvl  == false)
		{
			fout << POKEMON_AR[INDEX].advance.secEvoCondition;

			//If the second evolution evolves through leveling and condition
			if(POKEMON_AR[secondEvolutionIndex].advance.evoThroughLvl
					== true &&
			   POKEMON_AR[secondEvolutionIndex].advance.evoThroughCond
				   == true)
			{
				fout << " then evolves into "
				     << POKEMON_AR[secondEvolutionIndex].basic.name << "\nby "
					 << POKEMON_AR[INDEX].advance.finalEvoCondition
					 << " then into "
					 << POKEMON_AR[finalEvolutionIndex].basic.name;
			}
			//If the second evolution evolves through leveling and not condition
			else if(POKEMON_AR[secondEvolutionIndex].advance.evoThroughLvl
						== true &&
			        POKEMON_AR[secondEvolutionIndex].advance.evoThroughCond
					    == false)
			{
				fout << " then evolves into"
					 << POKEMON_AR[secondEvolutionIndex].basic.name << "\nby "
					 << "leveling up to level "
					 << POKEMON_AR[INDEX].advance.finalEvoLvl << " then into "
					 << POKEMON_AR[finalEvolutionIndex].basic.name;
			}
			//If the second evolution evolve through condition and not leveling
			else
			{
				fout << " then evolves into"
					 << POKEMON_AR[secondEvolutionIndex].basic.name << "\nby "
					 << POKEMON_AR[INDEX].advance.finalEvoCondition
					 << " then into "
					 << POKEMON_AR[finalEvolutionIndex].basic.name;
			}
		}
		else
		{
			fout << "\nERROR\n";
		}

		fout << "\nor into " << POKEMON_AR[branchEvolutionIndex].basic.name
			 << " by ";

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
	//Check if this is the second evolution
	else if(POKEMON_AR[INDEX].advance.secEvo == true)
	{
		fout << POKEMON_AR[firstEvolutionIndex].basic.name
			 << " evolves by ";

		//If the first evolution evolves through leveling and condition
		if(POKEMON_AR[firstEvolutionIndex].advance.evoThroughLvl  == true &&
		   POKEMON_AR[firstEvolutionIndex].advance.evoThroughCond == true	)
		{
			fout << POKEMON_AR[firstEvolutionIndex].advance.secEvoCondition;

			//If the second evolution evolves through leveling and condition
			if(POKEMON_AR[INDEX].advance.evoThroughLvl
					== true &&
			   POKEMON_AR[INDEX].advance.evoThroughCond
				   == true)
			{
				fout << " then evolves into "
				     << POKEMON_AR[INDEX].basic.name << "\nby "
					 << POKEMON_AR[INDEX].advance.finalEvoCondition
					 << " then into "
					 << POKEMON_AR[finalEvolutionIndex].basic.name;
			}
			//If the second evolution evolves through leveling and not condition
			else if(POKEMON_AR[INDEX].advance.evoThroughLvl
						== true &&
			        POKEMON_AR[INDEX].advance.evoThroughCond
					    == false)
			{
				fout << " then evolves into"
					 << POKEMON_AR[INDEX].basic.name << "\nby "
					 << "leveling up to level "
					 << POKEMON_AR[INDEX].advance.finalEvoLvl << " then into "
					 << POKEMON_AR[finalEvolutionIndex].basic.name;
			}
			//If the second evolution evolve through condition and not leveling
			else
			{
				fout << " then evolves into"
					 << POKEMON_AR[INDEX].basic.name << "\nby "
					 << POKEMON_AR[INDEX].advance.finalEvoCondition
					 << " then into "
					 << POKEMON_AR[finalEvolutionIndex].basic.name;
			}
		}
		//If the first evolution evolves through leveling and not condition
		else if(POKEMON_AR[firstEvolutionIndex].advance.evoThroughLvl  == true
			&&  POKEMON_AR[firstEvolutionIndex].advance.evoThroughCond == false)
		{
			fout << "leveling up to level "
				 << POKEMON_AR[firstEvolutionIndex].advance.evoLvl;

			//If the second evolution evolves through leveling and condition
			if(POKEMON_AR[INDEX].advance.evoThroughLvl
					== true &&
			   POKEMON_AR[INDEX].advance.evoThroughCond
				   == true)
			{
				fout << " then evolves into "
					 << POKEMON_AR[INDEX].basic.name << "\nby "
					 << POKEMON_AR[INDEX].advance.finalEvoCondition
					 << " then into "
					 << POKEMON_AR[finalEvolutionIndex].basic.name;
			}
			//If the second evolution evolves through leveling and not condition
			else if(POKEMON_AR[INDEX].advance.evoThroughLvl
						== true &&
					POKEMON_AR[INDEX].advance.evoThroughCond
						== false)
			{
				fout << " into " << POKEMON_AR[INDEX].basic.name << "\nthen "
					 << "leveling up to level "
					 << POKEMON_AR[INDEX].advance.finalEvoLvl << " for "
					 << POKEMON_AR[finalEvolutionIndex].basic.name;
			}
			//If the second evolution evolve through condition and not leveling
			else
			{
				fout << " into "
					 << POKEMON_AR[INDEX].basic.name << "\nthen by "
					 << POKEMON_AR[INDEX].advance.finalEvoCondition
					 << " for "
					 << POKEMON_AR[finalEvolutionIndex].basic.name;
			}
		}
		//If the first evolution evolves through condition and not leveling
		else if(POKEMON_AR[firstEvolutionIndex].advance.evoThroughCond == true
			&&	POKEMON_AR[firstEvolutionIndex].advance.evoThroughLvl  == false)
		{
			fout << POKEMON_AR[firstEvolutionIndex].advance.secEvoCondition;

			//If the second evolution evolves through leveling and condition
			if(POKEMON_AR[INDEX].advance.evoThroughLvl
					== true &&
			   POKEMON_AR[INDEX].advance.evoThroughCond
				   == true)
			{
				fout << " then evolves into "
				     << POKEMON_AR[INDEX].basic.name << "\nby "
					 << POKEMON_AR[INDEX].advance.finalEvoCondition
					 << " then into "
					 << POKEMON_AR[finalEvolutionIndex].basic.name;
			}
			//If the second evolution evolves through leveling and not condition
			else if(POKEMON_AR[INDEX].advance.evoThroughLvl
						== true &&
			        POKEMON_AR[INDEX].advance.evoThroughCond
					    == false)
			{
				fout << " then evolves into"
					 << POKEMON_AR[INDEX].basic.name << "\nby "
					 << "leveling up to level "
					 << POKEMON_AR[INDEX].advance.finalEvoLvl << " then into "
					 << POKEMON_AR[finalEvolutionIndex].basic.name;
			}
			//If the second evolution evolve through condition and not leveling
			else
			{
				fout << " then evolves into"
					 << POKEMON_AR[INDEX].basic.name << "\nby "
					 << POKEMON_AR[INDEX].advance.finalEvoCondition
					 << " then into "
					 << POKEMON_AR[finalEvolutionIndex].basic.name;
			}
		}
		else
		{
			fout << "\nERROR\n";
		}

		fout << "\nor into " << POKEMON_AR[branchEvolutionIndex].basic.name
			 << " by ";

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
	//The Pokemon must be the final evolution
	else
	{
		fout << POKEMON_AR[firstEvolutionIndex].basic.name
			 << " evolves by ";

		//If the first evolution evolves through leveling and condition
		if(POKEMON_AR[firstEvolutionIndex].advance.evoThroughLvl  == true &&
		   POKEMON_AR[firstEvolutionIndex].advance.evoThroughCond == true	)
		{
			fout << POKEMON_AR[firstEvolutionIndex].advance.secEvoCondition;

			//If the second evolution evolves through leveling and condition
			if(POKEMON_AR[secondEvolutionIndex].advance.evoThroughLvl
					== true &&
			   POKEMON_AR[secondEvolutionIndex].advance.evoThroughCond
				   == true)
			{
				fout << " then evolves into "
					 << POKEMON_AR[secondEvolutionIndex].basic.name << "\nby "
				   << POKEMON_AR[secondEvolutionIndex].advance.finalEvoCondition
					 << " then into "
					 << POKEMON_AR[INDEX].basic.name;
			}
			//If the second evolution evolves through leveling and not condition
			else if(POKEMON_AR[secondEvolutionIndex].advance.evoThroughLvl
						== true &&
					POKEMON_AR[secondEvolutionIndex].advance.evoThroughCond
						== false)
			{
				fout << " then evolves into"
					 << POKEMON_AR[secondEvolutionIndex].basic.name << "\nby "
					 << "leveling up to level "
					 << POKEMON_AR[secondEvolutionIndex].advance.finalEvoLvl
					 << " then into "
					 << POKEMON_AR[INDEX].basic.name;
			}
			//If the second evolution evolve through condition and not leveling
			else
			{
				fout << " into "
					 << POKEMON_AR[secondEvolutionIndex].basic.name
					 << "\nthen by "
				<< POKEMON_AR[secondEvolutionIndex].advance.finalEvoCondition
					 << " for "
					 << POKEMON_AR[INDEX].basic.name;
			}
		}
		//If the first evolution evolves through leveling and not condition
		else if(POKEMON_AR[firstEvolutionIndex].advance.evoThroughLvl  == true
			&&  POKEMON_AR[firstEvolutionIndex].advance.evoThroughCond == false)
		{
			fout << "leveling up to level "
				 << POKEMON_AR[firstEvolutionIndex].advance.evoLvl;

			//If the second evolution evolves through leveling and condition
			if(POKEMON_AR[secondEvolutionIndex].advance.evoThroughLvl
					== true &&
			   POKEMON_AR[secondEvolutionIndex].advance.evoThroughCond
				   == true)
			{
				fout << " then evolves into "
					 << POKEMON_AR[secondEvolutionIndex].basic.name << "\nby "
				   << POKEMON_AR[secondEvolutionIndex].advance.finalEvoCondition
					 << " then into "
					 << POKEMON_AR[INDEX].basic.name;
			}
			//If the second evolution evolves through leveling and not condition
			else if(POKEMON_AR[secondEvolutionIndex].advance.evoThroughLvl
						== true &&
					POKEMON_AR[secondEvolutionIndex].advance.evoThroughCond
						== false)
			{
				fout << " into " << POKEMON_AR[secondEvolutionIndex].basic.name
					 << "\nthen leveling up to level "
					 << POKEMON_AR[secondEvolutionIndex].advance.finalEvoLvl
					 << " for "
					 << POKEMON_AR[INDEX].basic.name;
			}
			//If the second evolution evolve through condition and not leveling
			else
			{
				fout << " into "
					 << POKEMON_AR[secondEvolutionIndex].basic.name
					 << "\nthen by "
				<< POKEMON_AR[secondEvolutionIndex].advance.finalEvoCondition
					 << " for "
					 << POKEMON_AR[finalEvolutionIndex].basic.name;
			}
		}
		//If the first evolution evolves through condition and not leveling
		else if(POKEMON_AR[firstEvolutionIndex].advance.evoThroughCond == true
			&&	POKEMON_AR[firstEvolutionIndex].advance.evoThroughLvl  == false)
		{
			fout << POKEMON_AR[firstEvolutionIndex].advance.secEvoCondition;

			//If the second evolution evolves through leveling and condition
			if(POKEMON_AR[secondEvolutionIndex].advance.evoThroughLvl
					== true &&
			   POKEMON_AR[secondEvolutionIndex].advance.evoThroughCond
				   == true)
			{
				fout << " then evolves into "
					 << POKEMON_AR[secondEvolutionIndex].basic.name << "\nby "
				   << POKEMON_AR[secondEvolutionIndex].advance.finalEvoCondition
					 << " then into "
					 << POKEMON_AR[INDEX].basic.name;
			}
			//If the second evolution evolves through leveling and not condition
			else if(POKEMON_AR[secondEvolutionIndex].advance.evoThroughLvl
						== true &&
					POKEMON_AR[secondEvolutionIndex].advance.evoThroughCond
						== false)
			{
				fout << " then evolves into"
					 << POKEMON_AR[secondEvolutionIndex].basic.name << "\nby "
					 << "leveling up to level "
					 << POKEMON_AR[secondEvolutionIndex].advance.finalEvoLvl
					 << " then into "
					 << POKEMON_AR[INDEX].basic.name;
			}
			//If the second evolution evolve through condition and not leveling
			else
			{
				fout << " then evolves into"
					 << POKEMON_AR[secondEvolutionIndex].basic.name << "\nby "
				<< POKEMON_AR[secondEvolutionIndex].advance.finalEvoCondition
					 << " then into "
					 << POKEMON_AR[INDEX].basic.name;
			}
		}
		else
		{
			fout << "\nERROR\n";
		}

		fout << "\nor into " << POKEMON_AR[branchEvolutionIndex].basic.name
					 << " by ";

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
