
#include "pokedex.h"

/************************************************************************
* FUNCTION FireWaterGrassDamage
*----------------------------------------------------------------------
* 	 This function receives two enumerated values that match the Pokemon's type
* 	 	and the empty array that will hold the damage that the pokemon will
* 	 	take. Based on the pokemon types of Fire, Water, and Grass,
* 	 	the damage will be assigned to the array.
*
* 	 ==> returns the damage taken array stored with the values
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be defined:
* 		damageTaken : The empty array to store the damage taken
*
* 	The following need to be passed in:
* 		TYPE_1	: The enumerated type matching the Pokemon's primary type
* 		TYPE_2  : The enumerated type matching the Pokemon's secondary type
*
* POST-CONDITIONS
* 	==> Returns the damage taken array stored with the values
*************************************************************************/
void FireWaterGrassDamage(const PokemonTypes &TYPE_1,     //PROC - the pokemon's
												          //       primary type
					      const PokemonTypes &TYPE_2,     //PROC - the pokemon's
						 	 	 	 	 	 	          //	  secondary type
					            float        damageTaken[]) //PROC - the damage
															//       array
{
	switch(TYPE_1)
	{
	case NORMAL:
	case FIGHTING:
	case FLYING:
	case POISON:
	case GROUND:
	case ROCK:
	case BUG:
	case GHOST:
	case STEEL:
	case FIRE: switch(TYPE_2)
				{
					case NORMAL: AssignDamageAr(damageTaken,
												1.0, 2.0, 1.0, 1.0, 2.0, 2.0,
												0.5, 0.0, 0.5, 0.5, 2.0, 0.5,
												1.0, 1.0, 0.5, 1.0, 1.0, 0.5);

								 break;
				case FIGHTING:	 AssignDamageAr(damageTaken,
												1.0, 1.0, 2.0, 1.0, 2.0, 1.0,
												0.25, 1.0, 0.5, 0.5, 2.0, 0.5,
												1.0, 2.0, 0.5, 1.0, 0.5, 1.0);

								 break;
				case FLYING: 	 AssignDamageAr(damageTaken,
												1.0, 0.5, 1.0, 1.0, 0.0, 4.0,
												0.25, 1.0, 0.5, 0.5, 2.0, 0.25,
												2.0, 1.0, 1.0, 1.0, 1.0, 0.5);

								 break;
				case POISON:	 AssignDamageAr(damageTaken,
												1.0, 0.5, 1.0, 0.5, 4.0, 2.0,
												0.25, 1.0, 0.5, 0.5, 2.0, 0.25,
												1.0, 2.0, 0.5, 1.0, 1.0, 0.25);

								 break;
				case GROUND:     AssignDamageAr(damageTaken,
												1.0, 1.0, 1.0, 0.5, 2.0, 1.0,
												0.5, 1.0, 0.5, 0.5, 4.0, 1.0,
												0.0, 1.0, 1.0, 1.0, 1.0, 0.5);

								 break;
				case ROCK:       AssignDamageAr(damageTaken,
												0.5, 2.0, 0.5, 0.5, 4.0, 2.0,
												0.5, 1.0, 1.0, 0.25, 4.0, 1.0,
												1.0, 1.0, 0.5, 1.0, 1.0, 0.5);

								 break;
				case BUG:        AssignDamageAr(damageTaken,
												1.0, 0.5, 2.0, 1.0, 1.0, 4.0,
												0.5, 1.0, 0.5, 1.0, 2.0, 0.25,
												1.0, 1.0, 0.5, 1.0, 1.0, 0.5);

								 break;
				case GHOST:		 AssignDamageAr(damageTaken,
												0.0, 0.0, 1.0, 0.5, 2.0, 2.0,
												0.25, 2.0, 0.5, 0.5, 2.0, 0.5,
												1.0, 1.0, 0.5, 1.0, 2.0, 0.5);

								 break;
				case STEEL:		 AssignDamageAr(damageTaken,
												0.5, 2.0, 0.5, 0.0, 4.0, 1.0,
												0.25, 1.0, 0.25, 1.0, 2.0, 0.25,
												1.0, 0.5, 0.25, 0.5, 1.0, 0.25);

								 break;
				case FIRE:		 AssignDamageAr(damageTaken,
												1.0, 1.0, 1.0, 1.0, 2.0, 2.0,
												0.5, 1.0, 0.5, 0.5, 2.0, 0.5,
												1.0, 1.0, 0.5, 1.0, 1.0, 0.5);

								 break;
				case WATER:      AssignDamageAr(damageTaken,
												1.0, 1.0, 1.0, 1.0, 2.0, 2.0,
												0.5, 1.0, 0.25, 0.25, 1.0, 1.0,
												2.0, 1.0, 0.25, 1.0, 1.0, 0.5);

								 break;
				case GRASS:		 AssignDamageAr(damageTaken,
												1.0, 1.0, 2.0, 2.0, 1.0, 2.0,
												1.0, 1.0, 0.5, 1.0, 1.0, 0.25,
												0.5, 1.0, 1.0, 1.0, 1.0, 0.5);

								 break;
				case ELECTRIC:   AssignDamageAr(damageTaken,
												1.0, 1.0, 0.5, 1.0, 4.0, 2.0,
												0.5, 1.0, 0.25, 0.5, 2.0, 0.5,
												0.5, 1.0, 0.5, 1.0, 1.0, 0.5);

								 break;
				case PSYCHIC:    AssignDamageAr(damageTaken,
												1.0, 0.5, 1.0, 1.0, 2.0, 2.0,
												1.0, 2.0, 0.5, 0.5, 2.0, 0.5,
												1.0, 0.5, 0.5, 1.0, 2.0, 0.5);

								 break;
				case ICE:        AssignDamageAr(damageTaken,
												1.0, 2.0, 1.0, 1.0, 2.0, 4.0,
												0.5, 1.0, 1.0, 1.0, 2.0, 0.5,
												1.0, 1.0, 0.25, 1.0, 1.0, 0.5);

								 break;
				case DRAGON:	 AssignDamageAr(damageTaken,
												1.0, 1.0, 1.0, 1.0, 2.0, 2.0,
												0.5, 1.0, 0.5, 0.25, 1.0, 0.25,
												0.5, 1.0, 1.0, 2.0, 1.0, 1.0);

								 break;
				case DARK:		 AssignDamageAr(damageTaken,
												1.0, 2.0, 1.0, 1.0, 2.0, 2.0,
												1.0, 0.5, 0.5, 0.5, 2.0, 0.5,
												1.0, 0.0, 0.5, 1.0, 0.5, 1.0);

								 break;
				case FAIRY:      AssignDamageAr(damageTaken,
												1.0, 0.5, 1.0, 2.0, 2.0, 2.0,
												0.25, 1.0, 1.0, 0.5, 2.0, 0.5,
												1.0, 1.0, 0.5, 0.0, 0.5, 0.5);

								 break;
				}
				break;

	case WATER: switch(TYPE_2)
					{
					case NORMAL: AssignDamageAr(damageTaken,
												1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
												1.0, 0.0, 0.5, 0.5, 0.5, 2.0,
												2.0, 1.0, 0.5, 1.0, 1.0, 1.0);

								 break;
				case FIGHTING: 	 AssignDamageAr(damageTaken,
												1.0, 1.0, 2.0, 1.0, 1.0, 0.5,
												0.5, 1.0, 0.5, 0.5, 0.5, 2.0,
												2.0, 2.0, 0.5, 1.0, 0.5, 2.0);

								 break;
				case FLYING: 	 AssignDamageAr(damageTaken,
												1.0, 0.5, 1.0, 1.0, 0.0, 2.0,
												0.5, 1.0, 0.5, 0.5, 0.5, 1.0,
												4.0, 1.0, 1.0, 1.0, 1.0, 1.0);

								 break;
				case POISON:	 AssignDamageAr(damageTaken,
												1.0, 0.5, 1.0, 0.5, 2.0, 1.0,
												0.5, 1.0, 0.5, 0.5, 0.5, 1.0,
												2.0, 2.0, 0.5, 1.0, 1.0, 0.5);

								 break;
				case GROUND:     AssignDamageAr(damageTaken,
												1.0, 1.0, 1.0, 0.5, 1.0, 0.5,
												1.0, 1.0, 0.5, 0.5, 1.0, 4.0,
												0.0, 1.0, 1.0, 1.0, 1.0, 1.0);

								 break;
				case ROCK:       AssignDamageAr(damageTaken,
												0.5, 2.0, 0.5, 0.5, 2.0, 1.0,
												1.0, 1.0, 1.0, 0.25, 1.0, 4.0,
												2.0, 1.0, 0.5, 1.0, 1.0, 1.0);

								 break;
				case BUG:        AssignDamageAr(damageTaken,
												1.0, 0.5, 2.0, 1.0, 0.5, 2.0,
												1.0, 1.0, 0.5, 1.0, 0.5, 1.0,
												2.0, 1.0, 0.5, 1.0, 1.0, 1.0);

								 break;
				case GHOST:		 AssignDamageAr(damageTaken,
												0.0, 0.0, 1.0, 0.5, 1.0, 1.0,
												0.5, 2.0, 0.5, 0.5, 0.5, 2.0,
												2.0, 1.0, 0.5, 1.0, 2.0, 1.0);

								 break;
				case STEEL:		 AssignDamageAr(damageTaken,
												0.5, 2.0, 0.5, 1.0, 2.0, 0.5,
												0.5, 1.0, 1.0, 1.0, 0.5, 1.0,
												2.0, 0.5, 1.0, 0.5, 1.0, 0.5);

								 break;
				case FIRE:		 AssignDamageAr(damageTaken,
												1.0, 1.0, 1.0, 1.0, 2.0, 2.0,
												0.5, 1.0, 0.25, 0.25, 1.0, 1.0,
												2.0, 1.0, 0.25, 1.0, 1.0, 0.5);

								 break;
				case WATER:      AssignDamageAr(damageTaken,
												1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
												1.0, 1.0, 0.5, 0.5, 0.5, 2.0,
												2.0, 1.0, 0.5, 1.0, 1.0, 1.0);

								 break;
				case GRASS:		 AssignDamageAr(damageTaken,
												1.0, 1.0, 2.0, 2.0, 0.5, 1.0,
												2.0, 1.0, 0.5, 1.0, 0.25, 1.0,
												1.0, 1.0, 1.0, 1.0, 1.0, 1.0);

								 break;
				case ELECTRIC:   AssignDamageAr(damageTaken,
												1.0, 1.0, 0.5, 1.0, 2.0, 1.0,
												1.0, 1.0, 0.25, 0.5, 0.5, 2.0,
												1.0, 1.0, 0.5, 1.0, 1.0, 1.0);

								 break;
				case PSYCHIC:    AssignDamageAr(damageTaken,
												1.0, 0.5, 1.0, 1.0, 1.0, 1.0,
												2.0, 2.0, 0.5, 0.5, 0.5, 2.0,
												2.0, 0.5, 0.5, 1.0, 1.0, 1.0);

								 break;
				case ICE:        AssignDamageAr(damageTaken,
												1.0, 2.0, 1.0, 1.0, 1.0, 2.0,
												1.0, 1.0, 1.0, 1.0, 0.5, 2.0,
												2.0, 1.0, 0.25, 1.0, 1.0, 1.0);

								 break;
				case DRAGON:	 AssignDamageAr(damageTaken,
												1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
												1.0, 1.0, 0.5, 0.25, 0.25, 1.0,
												1.0, 1.0, 1.0, 2.0, 1.0, 2.0);

								 break;
				case DARK:		 AssignDamageAr(damageTaken,
												1.0, 2.0, 1.0, 1.0, 1.0, 1.0,
												2.0, 0.5, 0.5, 0.5, 0.5, 2.0,
												2.0, 0.0, 0.5, 1.0, 0.5, 2.0);

								 break;
				case FAIRY:      AssignDamageAr(damageTaken,
												1.0, 0.5, 1.0, 2.0, 1.0, 1.0,
												0.5, 1.0, 1.0, 0.5, 0.5, 2.0,
												2.0, 1.0, 0.5, 0.0, 0.5, 1.0);

								 break;
					}
					break;
		case GRASS: switch(TYPE_2)
					{
					case NORMAL: AssignDamageAr(damageTaken,
												1.0, 2.0, 2.0, 2.0, 0.5, 1.0,
												2.0, 0.0, 1.0, 2.0, 0.5, 0.5,
												0.5, 1.0, 2.0, 1.0, 1.0, 1.0);

								 break;
				case FIGHTING: 	 AssignDamageAr(damageTaken,
												1.0, 1.0, 4.0, 2.0, 0.5, 0.5,
												1.0, 1.0, 1.0, 2.0, 0.5, 0.5,
												0.5, 2.0, 2.0, 1.0, 0.5, 2.0);

								 break;
				case FLYING: 	 AssignDamageAr(damageTaken,
												1.0, 0.5, 2.0, 2.0, 0.0, 2.0,
												1.0, 1.0, 1.0, 2.0, 0.5, 0.25,
												1.0, 1.0, 4.0, 1.0, 1.0, 1.0);

								 break;
				case POISON:	 AssignDamageAr(damageTaken,
												1.0, 0.5, 2.0, 1.0, 1.0, 1.0,
												1.0, 1.0, 1.0, 2.0, 0.5, 0.25,
												0.5, 2.0, 2.0, 1.0, 1.0, 0.5);

								 break;
				case GROUND:     AssignDamageAr(damageTaken,
												1.0, 1.0, 2.0, 1.0, 0.5, 0.5,
												2.0, 1.0, 1.0, 2.0, 1.0, 1.0,
												0.0, 1.0, 4.0, 1.0, 1.0, 1.0);

								 break;
				case ROCK:       AssignDamageAr(damageTaken,
												0.5, 2.0, 1.0, 1.0, 1.0, 1.0,
												2.0, 1.0, 2.0, 1.0, 1.0, 1.0,
												0.5, 1.0, 2.0, 1.0, 1.0, 1.0);

								 break;
				case BUG:        AssignDamageAr(damageTaken,
												1.0, 0.5, 4.0, 2.0, 0.25, 2.0,
												2.0, 1.0, 1.0, 4.0, 0.5, 0.25,
												0.5, 1.0, 2.0, 1.0, 1.0, 1.0);

								 break;
				case GHOST:		 AssignDamageAr(damageTaken,
												0.0, 0.0, 2.0, 1.0, 0.5, 1.0,
												1.0, 2.0, 1.0, 2.0, 0.5, 0.5,
												0.5, 1.0, 2.0, 1.0, 2.0, 1.0);

								 break;
				case STEEL:		 AssignDamageAr(damageTaken,
												0.5, 2.0, 1.0, 0.0, 1.0, 0.5,
												1.0, 1.0, 0.5, 4.0, 0.5, 0.25,
												0.5, 0.5, 1.0, 0.5, 1.0, 0.5);

								 break;
				case FIRE:		 AssignDamageAr(damageTaken,
												1.0, 1.0, 2.0, 2.0, 1.0, 2.0,
												1.0, 1.0, 0.5, 1.0, 1.0, 0.25,
												0.5, 1.0, 1.0, 1.0, 1.0, 0.5);

								 break;
				case WATER:      AssignDamageAr(damageTaken,
												1.0, 1.0, 2.0, 2.0, 0.5, 1.0,
												2.0, 1.0, 0.5, 1.0, 0.25, 1.0,
												1.0, 1.0, 1.0, 1.0, 1.0, 1.0);

								 break;
				case GRASS:		 AssignDamageAr(damageTaken,
												1.0, 1.0, 2.0, 2.0, 0.5, 1.0,
												2.0, 1.0, 1.0, 2.0, 0.5, 0.5,
												0.5, 1.0, 2.0, 1.0, 1.0, 1.0);

								 break;
				case ELECTRIC:   AssignDamageAr(damageTaken,
												1.0, 1.0, 1.0, 2.0, 1.0, 1.0,
												2.0, 1.0, 0.5, 2.0, 0.5, 0.5,
												0.25, 1.0, 2.0, 1.0, 1.0, 1.0);

								 break;
				case PSYCHIC:    AssignDamageAr(damageTaken,
												1.0, 0.5, 2.0, 2.0, 0.5, 1.0,
												4.0, 2.0, 1.0, 2.0, 0.5, 0.5,
												0.5, 0.5, 2.0, 1.0, 2.0, 1.0);

								 break;
				case ICE:        AssignDamageAr(damageTaken,
												1.0, 2.0, 2.0, 2.0, 0.5, 2.0,
												2.0, 1.0, 2.0, 4.0, 0.5, 0.5,
												0.5, 1.0, 1.0, 1.0, 1.0, 1.0);

								 break;
				case DRAGON:	 AssignDamageAr(damageTaken,
												1.0, 1.0, 2.0, 2.0, 0.5, 1.0,
												2.0, 1.0, 1.0, 1.0, 0.25, 0.25,
												0.25, 1.0, 4.0, 2.0, 1.0, 2.0);

								 break;
				case DARK:		 AssignDamageAr(damageTaken,
												1.0, 2.0, 2.0, 2.0, 0.5, 1.0,
												4.0, 0.5, 1.0, 2.0, 0.5, 0.5,
												0.5, 0.0, 2.0, 1.0, 0.5, 2.0);

								 break;
				case FAIRY:      AssignDamageAr(damageTaken,
												1.0, 0.5, 2.0, 4.0, 0.5, 1.0,
												1.0, 1.0, 2.0, 2.0, 0.5, 0.5,
												0.5, 1.0, 2.0, 0.0, 0.5, 1.0);

								 break;
					}
					break;
	case ELECTRIC:
	case PSYCHIC:
	case ICE:
	case DRAGON:
	case DARK:
	case FAIRY:	break;
	}
}
