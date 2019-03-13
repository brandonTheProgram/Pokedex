
#include "pokedex.h"

/************************************************************************
* FUNCTION AssignDamageAr
*----------------------------------------------------------------------
* 	 This function receives an empty array that will hold the the damage that
* 	 	the pokemon will take and the different amounts of damage that the
* 	 	pokemon will take based the different types and will assign the
* 	 	corresponding damage into the array.
* 	 ==> returns the damage taken array stored with the values
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be defined:
* 		damageTaken : The empty array to store the damage taken
*
* 	The following need to be passed in:
* 		NORMAL_DMG	: The damage that would be taken by a normal type move
* 		FIGHT_DMG	: The damage that would be taken by a fighting type move
*       FLY_DMG		: The damage that would be taken by a flying type move
*       POI_DMG		: The damage that would be taken by a poison type move
*       GRD_DMG		: The damage that would be taken by a ground type move
*       ROCK_DMG	: The damage that would be taken by a rock type move
*       BUG_DMG		: The damage that would be taken by a bug type move
*       GHOST_DMG	: The damage that would be taken by a ghost type move
*       STEEL_DMG	: The damage that would be taken by a steel type move
*       FIRE_DMG	: The damage that would be taken by a fire type move
*       WATER_DMG	: The damage that would be taken by a water type move
*       GRASS_DMG	: The damage that would be taken by a grass type move
*       ELEC_DMG	: The damage that would be taken by a electric type move
*       PSY_DMG		: The damage that would be taken by a psychic type move
*       ICE_DMG		: The damage that would be taken by a ice type move
*       DRGN_DMG	: The damage that would be taken by a dragon type move
*       DARK_DMG	: The damage that would be taken by a dark type move
*       FAIRY_DMG	: The damage that would be taken by a fairy type move
*
* POST-CONDITIONS
* 	==> Returns the damage taken array stored with the values
*************************************************************************/
void AssignDamageAr(      float damageTaken[], //PROC - the damage array
					const float NORMAL_DMG,    //PROC - the damage taken from
											   //       normal type moves
					const float FIGHT_DMG,	   //PROC - the damage taken from
					   	   	   	   	   	   	   //       fighting type moves
					const float FLY_DMG,       //PROC - the damage taken from
					   	   	   	   	   	   	   //       flying type moves
					const float POI_DMG,       //PROC - the damage taken from
					   	   	   	   	   	   	   //       poison type moves
					const float GRD_DMG,       //PROC - the damage taken from
					   	   	   	   	   	   	   //       ground type moves
					const float ROCK_DMG,      //PROC - the damage taken from
					   	   	   	   	   	   	   //       rock type moves
					const float BUG_DMG,       //PROC - the damage taken from
					   	   	   	   	   	   	   //       bug type moves
					const float GHOST_DMG,     //PROC - the damage taken from
					   	   	   	   	   	   	   //       ghost type moves
					const float STEEL_DMG,     //PROC - the damage taken from
					   	   	   	   	   	   	   //       steel type moves
					const float FIRE_DMG,      //PROC - the damage taken from
					   	   	   	   	   	   	   //       fire type moves
					const float WATER_DMG,     //PROC - the damage taken from
					   	   	   	   	   	   	   //       water type moves
					const float GRASS_DMG,     //PROC - the damage taken from
					   	   	   	   	   	   	   //       grass type moves
					const float ELEC_DMG,      //PROC - the damage taken from
					   	   	   	   	   	   	   //       electric type moves
					const float PSY_DMG,       //PROC - the damage taken from
					   	   	   	   	   	   	   //       psychic type moves
					const float ICE_DMG,       //PROC - the damage taken from
					   	   	   	   	   	   	   //       ice type moves
					const float DRGN_DMG,      //PROC - the damage taken from
					   	   	   	   	   	   	   //       dragon type moves
					const float DARK_DMG,      //PROC - the damage taken from
					   	   	   	   	   	   	   //       dark type moves
					const float FAIRY_DMG)     //PROC - the damage taken from
											   //       fairy type moves
{
	 damageTaken[NORMAL]   = NORMAL_DMG;
	 damageTaken[FIGHTING] = FIGHT_DMG;
	 damageTaken[FLYING]   = FLY_DMG;
	 damageTaken[POISON]   = POI_DMG;
	 damageTaken[GROUND]   = GRD_DMG;
	 damageTaken[ROCK]     = ROCK_DMG;
	 damageTaken[BUG]      = BUG_DMG;
	 damageTaken[GHOST]    = GHOST_DMG;
	 damageTaken[STEEL]    = STEEL_DMG;
	 damageTaken[FIRE]     = FIRE_DMG;
	 damageTaken[WATER]    = WATER_DMG;
	 damageTaken[GRASS]    = GRASS_DMG;
	 damageTaken[ELECTRIC] = ELEC_DMG;
	 damageTaken[PSYCHIC]  = PSY_DMG;
	 damageTaken[ICE]      = ICE_DMG;
	 damageTaken[DRAGON]   = DRGN_DMG;
	 damageTaken[DARK]     = DARK_DMG;
	 damageTaken[FAIRY]    = FAIRY_DMG;
}
