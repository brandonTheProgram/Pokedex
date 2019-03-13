
#include "pokedex.h"

/************************************************************************
* FUNCTION DisplayAbility
*----------------------------------------------------------------------
 * 	 This function receives the Pokemon array, the index for the pokemon, the
 * 	 	amount of abilities it has, and the output file variable. It then
 * 	 	prints the Pokemon's ability/abilities to the output file.
 * 	 ==> returns nothing - prints the Pokemon's ability/abilities
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in:
* 		POKEMON_AR  : The Pokemon array
* 		INDEX   	: The index in the pokemon array
* 		ABILITIES   : The amount of abilities the pokemon has
* 		fout        : The output file variarble
*
* POST-CONDITIONS
* 	==> Returns the types converted to an enum
*************************************************************************/
void DisplayAbility(const pokemonInfo POKEMON_AR[], //OUT  - the Pokemon array
					const int 		  &INDEX,		//PROC - the index
		            const int 		  &ABILITIES,	//PROC - the amount of
													//		 abilities
					ofstream  		  &fout)		//OUT  - the output file
{
	/**************************************************************************
	 * CONSTANTS
	 * ------------------------------------------------------------------------
	 * USED FOR COLUMN SIZES
	 * ------------------------------------------------------------------------
	 * LINE_SIZE  : the size for the line output
	 *************************************************************************/
	const int LINE_SIZE = 55;

	//PROCESSING - Based on how many abilities the pokemon has, print their info
	switch(ABILITIES)
	{
	case 1: fout << "Ability: " << POKEMON_AR[INDEX].basic.ability << endl
				 << endl;

			fout << POKEMON_AR[INDEX].basic.ability << ": "
				 << WordWrap(POKEMON_AR[INDEX].basic.abilityDes, LINE_SIZE)
				 << endl;

			break;

	case 2: fout << "Abilities: " << POKEMON_AR[INDEX].basic.ability << " - "
				 << POKEMON_AR[INDEX].basic.hiddenAbility
				 << " (Hidden Ability)" << endl << endl;

			fout << POKEMON_AR[INDEX].basic.ability << ": "
				 << WordWrap(POKEMON_AR[INDEX].basic.abilityDes, LINE_SIZE);

			fout << "\n\nHidden Ability\n\n";

			fout << POKEMON_AR[INDEX].basic.hiddenAbility << ": "
				 << WordWrap(POKEMON_AR[INDEX].basic.hiddenAbDes, LINE_SIZE)
				 << endl;

			break;

	case 3:	fout << "Abilities: " << POKEMON_AR[INDEX].basic.ability << " - "
				 << POKEMON_AR[INDEX].advance.altAbility << " - "
			 	 << POKEMON_AR[INDEX].basic.hiddenAbility
				 << " (Hidden Ability)" << endl << endl;

			fout << POKEMON_AR[INDEX].basic.ability << ": "
				 << WordWrap(POKEMON_AR[INDEX].basic.abilityDes, LINE_SIZE)
				 << endl
				 << endl;

			fout << POKEMON_AR[INDEX].advance.altAbility << ": "
				<< WordWrap(POKEMON_AR[INDEX].advance.altAbilityDes, LINE_SIZE);

			fout << "\n\nHidden Ability\n\n";

			fout << POKEMON_AR[INDEX].basic.hiddenAbility << ": "
				 << WordWrap(POKEMON_AR[INDEX].basic.hiddenAbDes, LINE_SIZE)
				 << endl;
	}
}
