
#include "pokedex.h"

/************************************************************************
* FUNCTION SpecialBranchEvo
*----------------------------------------------------------------------
 * 	 This function receives the Pokemon array, the index  and the output file
 * 	 	variable. This functions displays the Pokemon's special branch evolution
 * 	 	tree based for pokemon with more than 3 evolutions
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
void SpecialBranchEvo(const pokemonInfo POKEMON_AR[], //OUT  - the Pokemon array
													  //       array
					  const int         &INDEX,       //PROC - the index
					  ofstream          &fout)        //OUT  - the output file
{
	/**************************************************************************
	 * CONSTANTS
	 * ------------------------------------------------------------------------
	 * USED FOR MAX/MIN
	 * ------------------------------------------------------------------------
	 * MAX_EEVEELUTIONS : The max size of the eveelutions
	 * TYROUGE_EVOS     : The amount of evolutions in the Tyrogue family
	 * WURMPLE_EVOS     : The amount of evolutions in the wurmple family
	 * ------------------------------------------------------------------------
	 * USED FOR SPECIFED VALUES
	 * ------------------------------------------------------------------------
	 * WURPLE_EVOLUTIONS[]  - the pokedex numbers for the Wurmple family
	 * TYROGUE_EVOLUTIONS[] - the pokedex numbers for the Tyrogue family
	 * EEVEELUTIONS[]       - the pokedex numbers for the eeveelutions
	 *************************************************************************/

	const int MAX_EEVEELUTIONS = 8;
	const int TYROUGE_EVOS     = 3;
	const int WURMPLE_EVOS     = 4;

	const int WURPLE_EVOLUTIONS[WURMPLE_EVOS] =
	{
			266, 267, 268, 269
	};

	const int TYROGUE_EVOLUTIONS[TYROUGE_EVOS] =
	{
		106, 107, 237
	};
	const int EEVEELUTIONS[MAX_EEVEELUTIONS] =
	{
		134, 135, 136, 196, 197, 470, 471, 700
	};

	int index;				//PROC - The index in the array
	int eveelutionNumber;   //PROC - the index in the eevelutions
	int tyrogueEvoNumber;   //PROC - the index in the Tyrogue family
	int wurmpleEvoNumber;   //PROC - the index in the Wurmple family

	//Check if the Pokemon is part of the Wurmple family
	if(POKEMON_AR[INDEX].basic.pokedexNumber == 265 ||
	   POKEMON_AR[INDEX].basic.pokedexNumber == 266 ||
	   POKEMON_AR[INDEX].basic.pokedexNumber == 267 ||
	   POKEMON_AR[INDEX].basic.pokedexNumber == 268 ||
	   POKEMON_AR[INDEX].basic.pokedexNumber == 269)
	{
		fout << "Wurmple - first evolution\n\n";

		for(index = 0; index < WURMPLE_EVOS; index++)
		{
			wurmpleEvoNumber = (WURPLE_EVOLUTIONS[index] - 1);

			if(POKEMON_AR[wurmpleEvoNumber].advance.secEvo == true)
			{
				fout << POKEMON_AR[wurmpleEvoNumber].basic.name << " by "
					 << POKEMON_AR[wurmpleEvoNumber].advance.secEvoCondition
					 << " then leveling up to "
					 << POKEMON_AR[wurmpleEvoNumber].advance.evoLvl << " for "
					 << POKEMON_AR[wurmpleEvoNumber + 1].basic.name << ".\n\n";
			}
		}
	}

	//Check if the Pokemon is part of the Tyrouge family
	else if(POKEMON_AR[INDEX].basic.pokedexNumber == 236 ||
	        POKEMON_AR[INDEX].basic.pokedexNumber == 106 ||
		    POKEMON_AR[INDEX].basic.pokedexNumber == 107 ||
		    POKEMON_AR[INDEX].basic.pokedexNumber == 237)
	{
		if(POKEMON_AR[INDEX].basic.pokedexNumber != 236)
		{
			fout << "Tyrogue - first evolution\n\n";
		}

		for(index = 0; index < TYROUGE_EVOS; index++)
		{
			tyrogueEvoNumber = (TYROGUE_EVOLUTIONS[index] - 1);

			if(POKEMON_AR[tyrogueEvoNumber].advance.evoThroughCond == true &&
			   POKEMON_AR[tyrogueEvoNumber].advance.evoThroughLvl  == true)
			{
				fout << POKEMON_AR[tyrogueEvoNumber].basic.name
					 << " evolves by "
					 << POKEMON_AR[tyrogueEvoNumber].advance.finalEvoCondition
					 << ".\n";
			}
			else if(POKEMON_AR[tyrogueEvoNumber].advance.evoThroughCond == true
					&&
				   POKEMON_AR[tyrogueEvoNumber].advance.evoThroughLvl  == false)
			{
				fout << POKEMON_AR[tyrogueEvoNumber].basic.name
					 << " evolves through "
					 << POKEMON_AR[tyrogueEvoNumber].advance.finalEvoCondition
					 << ".\n";
			}
			else if(POKEMON_AR[tyrogueEvoNumber].advance.evoThroughCond == false
					&&
					POKEMON_AR[tyrogueEvoNumber].advance.evoThroughLvl  == true)
			{
				fout << POKEMON_AR[tyrogueEvoNumber].basic.name
					 << " evolves through leveling up to "
					 << POKEMON_AR[tyrogueEvoNumber].advance.evoLvl << ".\n";
			}
			fout << endl;
		}
	}
	//The Pokemon is part of the Eevee family
	else
	{
		if(POKEMON_AR[INDEX].basic.pokedexNumber != 133)
		{
			fout << "Eevee - first evolution\n\n";
		}

		for(index = 0; index < MAX_EEVEELUTIONS; index++)
		{
			eveelutionNumber = (EEVEELUTIONS[index] - 1);

			if(POKEMON_AR[eveelutionNumber].advance.evoThroughCond == true &&
			   POKEMON_AR[eveelutionNumber].advance.evoThroughLvl  == true)
			{
				fout << POKEMON_AR[eveelutionNumber].basic.name
					 << " evolves by "
					 << POKEMON_AR[eveelutionNumber].advance.finalEvoCondition
					 << ".\n";
			}
			else if(POKEMON_AR[eveelutionNumber].advance.evoThroughCond == true
					&&
				   POKEMON_AR[eveelutionNumber].advance.evoThroughLvl  == false)
			{
				fout << POKEMON_AR[eveelutionNumber].basic.name
					 << " evolves through "
					 << POKEMON_AR[eveelutionNumber].advance.finalEvoCondition
					 << ".\n";
			}
			else if(POKEMON_AR[eveelutionNumber].advance.evoThroughCond == false
					&&
					POKEMON_AR[eveelutionNumber].advance.evoThroughLvl  == true)
			{
				fout << POKEMON_AR[eveelutionNumber].basic.name
					 << " evolves through leveling up to "
					 << POKEMON_AR[eveelutionNumber].advance.evoLvl << ".\n";
			}

			fout << endl;
		}
	}
}
