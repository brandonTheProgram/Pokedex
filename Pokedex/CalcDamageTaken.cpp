
#include "pokedex.h"

/************************************************************************
* FUNCTION CalcDamageTaken
*----------------------------------------------------------------------
* 	 This function receives two enumerated values that match the Pokemon's type
* 	 	and the empty array that will hold the damage that the pokemon will
* 	 	take. Based on the pokemon's types, the damage will be assigned to
* 	 	the array.
*
* 	 ==> returns the damage taken array stored with the values
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be defined:
* 		damageTaken : The empty array to store the damage taken
*
* 	The following need to be passed in:
* 		TYPE_1	: The enumerated type matching the Pokemon's primary type
* 		TYPE_2   : The enumerated type matching the Pokemon's secondary type
*
* POST-CONDITIONS
* 	==> Returns the damage taken array stored with the values
*************************************************************************/
void CalcDamageTaken(const PokemonTypes &TYPE_1, 	  //PROC - the pokemon's
													  //       primary type
					 const PokemonTypes &TYPE_2,  	  //PROC - the pokemon's
								 	 	 	 	 	  //		 secondary type
					 float        	    damageTaken[]) //PROC - the damage array
{
	//PROCESSING - Based on the Pokemon's types, assign the damage that the
	//  		   Pokemon would take if they were attacked
	switch(TYPE_1)
	{
	case NORMAL:
	case FIGHTING:  //PROCESSING - Calculate the damage taken for
					//             the given types
	case FLYING:	NormFightFlyDamage(TYPE_1, TYPE_2, damageTaken);
					break;
	case POISON:
	case GROUND:	//PROCESSING - Calculate the damage taken for
					//             the given types
	case ROCK:		PoiGrndRockDamage(TYPE_1, TYPE_2, damageTaken);
					break;
	case BUG:
	case GHOST:		//PROCESSING - Calculate the damage taken for
					//             the given types
	case STEEL:		BugGhostSteelDamage(TYPE_1, TYPE_2, damageTaken);
					break;
	case FIRE:
	case WATER:		//PROCESSING - Calculate the damage taken for
					//             the given types
	case GRASS:		FireWaterGrassDamage(TYPE_1, TYPE_2, damageTaken);
					break;
	case ELECTRIC:
	case PSYCHIC:	//PROCESSING - Calculate the damage taken for
					//             the given types
	case ICE:       ElecPsyIceDamage(TYPE_1, TYPE_2, damageTaken);
					break;
	case DRAGON:
	case DARK:		//PROCESSING - Calculate the damage taken for
					//             the given types
	case FAIRY:		DragDarkFairyDamage(TYPE_1, TYPE_2, damageTaken);
					break;
	}
}
