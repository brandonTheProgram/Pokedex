
#include "pokedex.h"

/************************************************************************
* FUNCTION DisplayThreeEvo
*----------------------------------------------------------------------
* 	 This function receives the Pokemon array, the index  and the output file
* 	 	variable. This functions displays the Pokemon's evolution tree based on
* 	 	having only 3 evolutions.
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
void DisplayThreeEvo(const pokemonInfo POKEMON_AR[], //OUT  - the Pokemon array
					 const int         &INDEX,		 //PROC - the index
					 ofstream          &fout) 	     //OUT  - the output file
{
	int firstEvolutionIndex;	//PROC - The index of the first evolution
	int secondEvolutionIndex;	//PROC - The index of the second evolution
	int finalEvolutionIndex;	//PROC - The index of the final evolution

	//PROCESSING - Match the pokedex number with the index
	firstEvolutionIndex  = (POKEMON_AR[INDEX].advance.firstEvoNum - 1);
	secondEvolutionIndex = (POKEMON_AR[INDEX].advance.secEvoNum - 1);
	finalEvolutionIndex  = (POKEMON_AR[INDEX].advance.finalEvoNum - 1);

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
				fout << " into "
				     << POKEMON_AR[secondEvolutionIndex].basic.name
					 << "\nthen by "
					 << POKEMON_AR[INDEX].advance.finalEvoCondition
					 << " for "
					 << POKEMON_AR[finalEvolutionIndex].basic.name << ".";
			}
			//If the second evolution evolves through leveling and not condition
			else if(POKEMON_AR[secondEvolutionIndex].advance.evoThroughLvl
						== true &&
			        POKEMON_AR[secondEvolutionIndex].advance.evoThroughCond
					    == false)
			{
				fout << " into "
					 << POKEMON_AR[secondEvolutionIndex].basic.name << "\nthen "
					 << "by leveling up to level "
					 << POKEMON_AR[INDEX].advance.finalEvoLvl << " for "
					 << POKEMON_AR[finalEvolutionIndex].basic.name << ".";
			}
			//If the second evolution evolve through condition and not leveling
			else
			{
				fout << " into "
					 << POKEMON_AR[secondEvolutionIndex].basic.name
					 << "\nthen by "
					 << POKEMON_AR[INDEX].advance.finalEvoCondition
					 << " for "
					 << POKEMON_AR[finalEvolutionIndex].basic.name << ".";
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
				fout << " into "
				     << POKEMON_AR[secondEvolutionIndex].basic.name
					 << "\nthen by "
					 << POKEMON_AR[INDEX].advance.finalEvoCondition
					 << " for "
					 << POKEMON_AR[finalEvolutionIndex].basic.name << ".";
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
					 << POKEMON_AR[finalEvolutionIndex].basic.name << ".";
			}
			//If the second evolution evolve through condition and not leveling
			else
			{
				fout << " into "
					 << POKEMON_AR[secondEvolutionIndex].basic.name
					 << "\nthen by "
					 << POKEMON_AR[INDEX].advance.finalEvoCondition
					 << " for "
					 << POKEMON_AR[finalEvolutionIndex].basic.name << ".";
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
				fout << " into "
				     << POKEMON_AR[secondEvolutionIndex].basic.name
					 << "\nthen by "
					 << POKEMON_AR[INDEX].advance.finalEvoCondition
					 << " for "
					 << POKEMON_AR[finalEvolutionIndex].basic.name << ".";
			}
			//If the second evolution evolves through leveling and not condition
			else if(POKEMON_AR[secondEvolutionIndex].advance.evoThroughLvl
						== true &&
			        POKEMON_AR[secondEvolutionIndex].advance.evoThroughCond
					    == false)
			{
				fout << " into "
					 << POKEMON_AR[secondEvolutionIndex].basic.name
					 << "\nthen by "
					 << "leveling up to level "
					 << POKEMON_AR[INDEX].advance.finalEvoLvl << " for "
					 << POKEMON_AR[finalEvolutionIndex].basic.name << ".";
			}
			//If the second evolution evolve through condition and not leveling
			else
			{
				fout << " into "
					 << POKEMON_AR[secondEvolutionIndex].basic.name
					 << "\nthen by "
					 << POKEMON_AR[INDEX].advance.finalEvoCondition
					 << " for "
					 << POKEMON_AR[finalEvolutionIndex].basic.name << ".";
			}
		}
		else
		{
			fout << "\nERROR\n";
		}
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
				fout << " into "
				     << POKEMON_AR[INDEX].basic.name << "\nthen by "
					 << POKEMON_AR[INDEX].advance.finalEvoCondition
					 << " for "
					 << POKEMON_AR[finalEvolutionIndex].basic.name << ".";
			}
			//If the second evolution evolves through leveling and not condition
			else if(POKEMON_AR[INDEX].advance.evoThroughLvl
						== true &&
			        POKEMON_AR[INDEX].advance.evoThroughCond
					    == false)
			{
				fout << " into "
					 << POKEMON_AR[INDEX].basic.name << "\nthen by "
					 << "leveling up to level "
					 << POKEMON_AR[INDEX].advance.finalEvoLvl << " for "
					 << POKEMON_AR[finalEvolutionIndex].basic.name << ".";
			}
			//If the second evolution evolve through condition and not leveling
			else
			{
				fout << " into "
					 << POKEMON_AR[INDEX].basic.name << "\nthen by "
					 << POKEMON_AR[INDEX].advance.finalEvoCondition
					 << " for "
					 << POKEMON_AR[finalEvolutionIndex].basic.name << ".";
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
				fout << " into "
					 << POKEMON_AR[INDEX].basic.name << "\nthen by "
					 << POKEMON_AR[INDEX].advance.finalEvoCondition
					 << " for "
					 << POKEMON_AR[finalEvolutionIndex].basic.name << ".";
			}
			//If the second evolution evolves through leveling and not condition
			else if(POKEMON_AR[INDEX].advance.evoThroughLvl
						== true &&
					POKEMON_AR[INDEX].advance.evoThroughCond
						== false)
			{
				fout << " into " << POKEMON_AR[INDEX].basic.name << "\nthen by"
					 << " leveling up to level "
					 << POKEMON_AR[INDEX].advance.finalEvoLvl << " for "
					 << POKEMON_AR[finalEvolutionIndex].basic.name << ".";
			}
			//If the second evolution evolve through condition and not leveling
			else
			{
				fout << " into "
					 << POKEMON_AR[INDEX].basic.name << "\nthen by "
					 << POKEMON_AR[INDEX].advance.finalEvoCondition
					 << " for "
					 << POKEMON_AR[finalEvolutionIndex].basic.name << ".";
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
				fout << " into "
				     << POKEMON_AR[INDEX].basic.name << "\nthen by "
					 << POKEMON_AR[INDEX].advance.finalEvoCondition
					 << " for "
					 << POKEMON_AR[finalEvolutionIndex].basic.name << ".";
			}
			//If the second evolution evolves through leveling and not condition
			else if(POKEMON_AR[INDEX].advance.evoThroughLvl
						== true &&
			        POKEMON_AR[INDEX].advance.evoThroughCond
					    == false)
			{
				fout << " into "
					 << POKEMON_AR[INDEX].basic.name << "\nthen by "
					 << "leveling up to level "
					 << POKEMON_AR[INDEX].advance.finalEvoLvl << " for "
					 << POKEMON_AR[finalEvolutionIndex].basic.name << ".";
			}
			//If the second evolution evolve through condition and not leveling
			else
			{
				fout << " into "
					 << POKEMON_AR[INDEX].basic.name << "\nthen by "
					 << POKEMON_AR[INDEX].advance.finalEvoCondition
					 << " for "
					 << POKEMON_AR[finalEvolutionIndex].basic.name << ".";
			}
		}
		else
		{
			fout << "\nERROR\n";
		}
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
				fout << " into "
					 << POKEMON_AR[secondEvolutionIndex].basic.name
					 << "\nthen by "
					 << POKEMON_AR[secondEvolutionIndex].advance.finalEvoCondition
					 << " for "
					 << POKEMON_AR[INDEX].basic.name << ".";
			}
			//If the second evolution evolves through leveling and not condition
			else if(POKEMON_AR[secondEvolutionIndex].advance.evoThroughLvl
						== true &&
					POKEMON_AR[secondEvolutionIndex].advance.evoThroughCond
						== false)
			{
				fout << " into "
					 << POKEMON_AR[secondEvolutionIndex].basic.name << "\nthen"
					 << " by leveling up to level "
					 << POKEMON_AR[secondEvolutionIndex].advance.finalEvoLvl
					 << " for "
					 << POKEMON_AR[INDEX].basic.name << ".";
			}
			//If the second evolution evolve through condition and not leveling
			else
			{
				fout << " into "
					 << POKEMON_AR[secondEvolutionIndex].basic.name
					 << "\nthen by "
				<< POKEMON_AR[secondEvolutionIndex].advance.finalEvoCondition
					 << " for "
					 << POKEMON_AR[INDEX].basic.name << ".";
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
				fout << " into "
					 << POKEMON_AR[secondEvolutionIndex].basic.name
					 << "\nthen by "
				   << POKEMON_AR[secondEvolutionIndex].advance.finalEvoCondition
					 << " for "
					 << POKEMON_AR[INDEX].basic.name << ".";
			}
			//If the second evolution evolves through leveling and not condition
			else if(POKEMON_AR[secondEvolutionIndex].advance.evoThroughLvl
						== true &&
					POKEMON_AR[secondEvolutionIndex].advance.evoThroughCond
						== false)
			{
				fout << " into " << POKEMON_AR[secondEvolutionIndex].basic.name
					 << "\nthen by leveling up to level "
					 << POKEMON_AR[secondEvolutionIndex].advance.finalEvoLvl
					 << " for "
					 << POKEMON_AR[INDEX].basic.name << ".";
			}
			//If the second evolution evolve through condition and not leveling
			else
			{
				fout << " into "
					 << POKEMON_AR[secondEvolutionIndex].basic.name
					 << "\nthen by "
				<< POKEMON_AR[secondEvolutionIndex].advance.finalEvoCondition
					 << " for "
					 << POKEMON_AR[INDEX].basic.name << ".";
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
				fout << " into "
					 << POKEMON_AR[secondEvolutionIndex].basic.name
					 << "\nthen by "
				   << POKEMON_AR[secondEvolutionIndex].advance.finalEvoCondition
					 << " for "
					 << POKEMON_AR[INDEX].basic.name << ".";
			}
			//If the second evolution evolves through leveling and not condition
			else if(POKEMON_AR[secondEvolutionIndex].advance.evoThroughLvl
						== true &&
					POKEMON_AR[secondEvolutionIndex].advance.evoThroughCond
						== false)
			{
				fout << " into "
					 << POKEMON_AR[secondEvolutionIndex].basic.name
					 << "\nthen by leveling up to level "
					 << POKEMON_AR[secondEvolutionIndex].advance.finalEvoLvl
					 << " for "
					 << POKEMON_AR[INDEX].basic.name << ".";
			}
			//If the second evolution evolve through condition and not leveling
			else
			{
				fout << " into "
					 << POKEMON_AR[secondEvolutionIndex].basic.name
					 << "\nthen by "
				<< POKEMON_AR[secondEvolutionIndex].advance.finalEvoCondition
					 << " for "
					 << POKEMON_AR[INDEX].basic.name << ".";
			}
		}
		else
		{
			fout << "\nERROR\n";
		}
	}
}
