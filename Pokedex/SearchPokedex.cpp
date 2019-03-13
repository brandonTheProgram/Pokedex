
#include "pokedex.h"

/************************************************************************
* FUNCTION SearchPokedex
*----------------------------------------------------------------------
* 	 This function receives the Pokemon array, name, number, and menu choice to
* 	 	search through the pokedex to return the index of the specified pokemon
* 	 ==> returns the index of the found pokemon
*-----------------------------------------------------------------------
* PRE-CONDITIONS
*   The following need to have defined values
*     POKEMON_AR[AR_SIZE] - the Pokemon array
*     NAME                - the name of the pokemon being searched for
*     POKEDEX_NUMBER      - the number of the pokemon being searched for
*     MENU_CHOICE         - the choice from the menu
*
* POST-CONDITIONS
* 	==> Returns the index of the found pokemon
*************************************************************************/
int SearchPokedex(const pokemonInfo POKEMON_AR[AR_SIZE], //PROC - the pokemon
														 //       array
				  const string &NAME,					 //PROC - the name of
				  	  	  	  	  	  	  	  	  	     //       the pokemon
				  const int    &POKEDEX_NUMBER,		     //PROC - the number of
				  	  	  	  	  	  	  	  	  	     //       the pokemon
				  const Menu   &MENU_CHOICE)		     //PROC - the menu
														 //       choice
{
	int index;		//PROC - the index in the array
	int endRegion;	//PROC - the last number in the region's dex

	bool found;		//PROC - the condition if the pokemon was found

	//PROCESSING - Initialize the values
	index = 0;
	found = false;

	if(POKEDEX_NUMBER <= KANTO_DEX)
	{
		endRegion = KANTO_DEX;
	}
	else if(POKEDEX_NUMBER <= JOHTO_DEX)
	{
		index     = KANTO_DEX;
		endRegion = JOHTO_DEX;
	}
	else if(POKEDEX_NUMBER <= HOENN_DEX)
	{
		index     = JOHTO_DEX;
		endRegion = HOENN_DEX;
	}
	else if(POKEDEX_NUMBER <= SINNOH_DEX)
	{
		index     = HOENN_DEX;
		endRegion = SINNOH_DEX;
	}
	else if(POKEDEX_NUMBER <= UNOVA_DEX)
	{
		index     = SINNOH_DEX;
		endRegion = UNOVA_DEX;
	}
	else if(POKEDEX_NUMBER <= KALOS_DEX)
	{
		index     = UNOVA_DEX;
		endRegion = KALOS_DEX;
	}
	else
	{
		index     = KALOS_DEX;
		endRegion = ALOLA_DEX;
	}

	switch(MENU_CHOICE)
	{
	case SEARCH_NAME:  while(!found && index < AR_SIZE)
					   {
							if (NAME == POKEMON_AR[index].basic.name)
							{
								found = true;
							}
							else
							{
								index++;
							}
						}
						break;

	case SEARCH_NUM:	while(!found && index < endRegion)
					    {
							if (POKEDEX_NUMBER ==
								POKEMON_AR[index].basic.pokedexNumber)
							{
								found = true;
								index = (POKEDEX_NUMBER - 1);
							}
							else
							{
								index++;
							}
						 }
						 break;

	case EXIT:
	case TYPE_EFFECTIVNESS_CHART:
	case END:
	case SURPRISE:               cout << "\nERROR\n";
	}

	return index;
}
