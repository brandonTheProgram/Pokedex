
#include "pokedex.h"

/************************************************************************
* FUNCTION CalcDamageTaken
*----------------------------------------------------------------------
 * 	 This function receives the Pokemon's empty enum types and the Pokemon's
 * 	 	actual type values and stores the type values in the enum types and
 * 	 	returns them.
 * 	 ==> returns the types converted to an enum
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be defined:
* 		typeOne : The enumerated type matching the Pokemon's primary type
* 		typeTwo : The enumerated type matching the Pokemon's secondary type
*
* 	The following need to be passed in:
* 		MAIN_TYPE  : The Pokemon's primary type
* 		ALT_TYPE   : The Pokemon's secondary type
*
* POST-CONDITIONS
* 	==> Returns the types converted to an enum
*************************************************************************/
void ConvertTypeToEnum(PokemonTypes &typeOne,   //PROC - the enum of the first
												//       type
					   PokemonTypes &typeTwo,   //PROC - the enum of the second
												//       type
					   const string &MAIN_TYPE, //PROC - the string of the first
												//       type
					   const string &ALT_TYPE)  //PROC - the string of the first
												//       type
{
	//Convert the first type
	if(MAIN_TYPE == "Normal")
	{
		typeOne = NORMAL;
	}
	else if(MAIN_TYPE == "Fighting")
	{
		typeOne = FIGHTING;
	}
	else if(MAIN_TYPE == "Flying")
	{
		typeOne = FLYING;
	}
	else if(MAIN_TYPE == "Poison")
	{
		typeOne = POISON;
	}
	else if(MAIN_TYPE == "Ground")
	{
		typeOne = GROUND;
	}
	else if(MAIN_TYPE == "Rock")
	{
		typeOne = ROCK;
	}
	else if(MAIN_TYPE == "Bug")
	{
		typeOne = BUG;
	}
	else if(MAIN_TYPE == "Ghost")
	{
		typeOne = GHOST;
	}
	else if(MAIN_TYPE == "Steel")
	{
		typeOne = STEEL;
	}
	else if(MAIN_TYPE == "Fire")
	{
		typeOne = FIRE;
	}
	else if(MAIN_TYPE == "Water")
	{
		typeOne = WATER;
	}
	else if(MAIN_TYPE == "Grass")
	{
		typeOne = GRASS;
	}
	else if(MAIN_TYPE == "Electric")
	{
		typeOne = ELECTRIC;
	}
	else if(MAIN_TYPE == "Psychic")
	{
		typeOne = PSYCHIC;
	}
	else if(MAIN_TYPE == "Ice")
	{
		typeOne = ICE;
	}
	else if(MAIN_TYPE == "Dragon")
	{
		typeOne = DRAGON;
	}
	else if(MAIN_TYPE == "Dark")
	{
		typeOne = DARK;
	}
	else if(MAIN_TYPE == "Fairy")
	{
		typeOne = FAIRY;
	}

	//Convert the second Type
	if(ALT_TYPE == "Normal")
	{
		typeTwo = NORMAL;
	}
	else if(ALT_TYPE == "Fighting")
	{
		typeTwo = FIGHTING;
	}
	else if(ALT_TYPE == "Flying")
	{
		typeTwo = FLYING;
	}
	else if(ALT_TYPE == "Poison")
	{
		typeTwo = POISON;
	}
	else if(ALT_TYPE == "Ground")
	{
		typeTwo = GROUND;
	}
	else if(ALT_TYPE == "Rock")
	{
		typeTwo = ROCK;
	}
	else if(ALT_TYPE == "Bug")
	{
		typeTwo = BUG;
	}
	else if(ALT_TYPE == "Ghost")
	{
		typeTwo = GHOST;
	}
	else if(ALT_TYPE == "Steel")
	{
		typeTwo = STEEL;
	}
	else if(ALT_TYPE == "Fire")
	{
		typeTwo = FIRE;
	}
	else if(ALT_TYPE == "Water")
	{
		typeTwo = WATER;
	}
	else if(ALT_TYPE == "Grass")
	{
		typeTwo = GRASS;
	}
	else if(ALT_TYPE == "Electric")
	{
		typeTwo = ELECTRIC;
	}
	else if(ALT_TYPE == "Psychic")
	{
		typeTwo = PSYCHIC;
	}
	else if(ALT_TYPE == "Ice")
	{
		typeTwo = ICE;
	}
	else if(ALT_TYPE == "Dragon")
	{
		typeTwo = DRAGON;
	}
	else if(ALT_TYPE == "Dark")
	{
		typeTwo = DARK;
	}
	else if(ALT_TYPE == "Fairy")
	{
		typeTwo = FAIRY;
	}
}
