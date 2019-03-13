
#include "pokedex.h"

/************************************************************************
* FUNCTION GetInputFromFile
*----------------------------------------------------------------------
* 	 This function receives an empty Pokemon array and the input file name
* 	 	and then stores the information into an array
*
* 	 	example:
* 	 	1						 pokedex number
*		Bulbasaur			     pokemon name
*		Seed Pokemon			 pokemon species
*		Grass					 pokemon primary type
*		Poison					 pokemon seconary type
*		Bulbasaur can be seen... pokemon description
*		Overgrow                 pokemon ability
*		When HP is below ...	 pokemon ability description
*		Chlorophyll			     pokemon hidden abilitiy
*		When sunny, the ...	     pokemon hidden ability description
*		2						 number of pokemon abilities
*		None					 pokemon secondary ability
*		None					 pokemon secondary ability description
*		2 						 number of pokemon evolutions,
*		0 						 the condition if the pokemon is the second evo
*		1 						 the condition if the pokemon evolves through
*							     leveling up
*		0 						 the condition if the pokemon evolves through
*								 special conditions
*		16						 the evolution level of the pokemon
*		1						 the pokedex number of the first evolution
*		None				     the condtition to evolves to the second
*								 evolution
*		2					     the pokdex number of the second evolution
*		0						 the condition if the pokemon is the final evo
*		32					     the final evolution's level
*		None					 the condtition to evolves to the final
*							     evolution
*		3						 the final evolution pokedx number
*		0						 the condition if there is a branch evolution
*		0						 the pokedex number of the branch evolution
*
* 	 ==> returns an array with the stored information
*-----------------------------------------------------------------------
* PRE-CONDITIONS
*   The following need to have defined values
*     INPUT_FILE - the name of the input file
*   The following need to be defined but have no value
*     pokemonAr[AR_SIZE]
*
* POST-CONDITIONS
* 	==> Returns the Pokemon array
*************************************************************************/
void GetInputFromFile(pokemonInfo pokemonAr[AR_SIZE], //PROC - the pokemon array
					  const string &INPUT_FILE,       //PROC - the input file
                      	  	  	  	  	  	  	  	  //       name
					  const int    &REGION_MAX_INDEX) //PROC - the max pokemon
                                                      //       in that region
{
	static int pokdexIndex = 0;     //PROC - the position in the array

	ifstream fin;            		//IN   - the input file variable

	//Open the input file
	fin.open(INPUT_FILE.c_str());

	//While not at the end of the file and the index doesn't exceed the array
	while(!fin.eof() && pokdexIndex < REGION_MAX_INDEX)
	{
		fin >> pokemonAr[pokdexIndex].basic.pokedexNumber;
		fin.ignore(10000, '\n');
		getline(fin, pokemonAr[pokdexIndex].basic.name);
		getline(fin, pokemonAr[pokdexIndex].basic.species);
		getline(fin, pokemonAr[pokdexIndex].basic.typeOne);
		getline(fin, pokemonAr[pokdexIndex].basic.typeTwo);
		getline(fin, pokemonAr[pokdexIndex].basic.description);
		getline(fin, pokemonAr[pokdexIndex].basic.ability);
		getline(fin, pokemonAr[pokdexIndex].basic.abilityDes);
		getline(fin, pokemonAr[pokdexIndex].basic.hiddenAbility);
		getline(fin, pokemonAr[pokdexIndex].basic.hiddenAbDes);
		fin >> pokemonAr[pokdexIndex].advance.abilities;
		fin.ignore(1000, '\n');
		getline(fin, pokemonAr[pokdexIndex].advance.altAbility);
		getline(fin, pokemonAr[pokdexIndex].advance.altAbilityDes);
		fin >> pokemonAr[pokdexIndex].advance.evolutions;
		fin >> pokemonAr[pokdexIndex].advance.secEvo;
		fin >> pokemonAr[pokdexIndex].advance.evoThroughLvl;
		fin >> pokemonAr[pokdexIndex].advance.evoThroughCond;
		fin >> pokemonAr[pokdexIndex].advance.evoLvl;
		fin >> pokemonAr[pokdexIndex].advance.firstEvoNum;
		fin.ignore(1000, '\n');
		getline(fin, pokemonAr[pokdexIndex].advance.secEvoCondition);
		fin >> pokemonAr[pokdexIndex].advance.secEvoNum;
		fin >> pokemonAr[pokdexIndex].advance.finalEvo;
		fin >> pokemonAr[pokdexIndex].advance.finalEvoLvl;
		fin.ignore(1000, '\n');
		getline(fin, pokemonAr[pokdexIndex].advance.finalEvoCondition);
		fin >> pokemonAr[pokdexIndex].advance.finalEvoNum;
		fin >> pokemonAr[pokdexIndex].advance.branchEvo;
		fin >> pokemonAr[pokdexIndex].advance.branchEvoNumber;
		fin.ignore(1000, '\n');

		pokdexIndex++;
	}

	//Close the input file
	fin.close();
}
