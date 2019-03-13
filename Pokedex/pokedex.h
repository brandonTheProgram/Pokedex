/*
 * pokedex.h
 *
 *  Created on: July 25, 2018
 *      Author: Brandon
 */

#ifndef POKEDEX_H_
#define POKEDEX_H_

#include <iostream>       /** cout, cin                 **/
#include <iomanip>        /** setprecision, fixed       **/
#include <string>		  /** string					**/
#include <cctype>         /** toupper                   **/
#include <fstream>        /** fout                      **/
#include <cstdlib>        /** srand, rand               **/
#include <time.h>         /** time                      **/
using namespace std;

struct basicInfo
{
	int    pokedexNumber;
	string name;
	string species;
	string typeOne;     //Primary Type
	string typeTwo;     //Secondary Type
	string description;
	string ability;
	string abilityDes;
	string hiddenAbility;
	string hiddenAbDes;
};

struct advanceInfo
{
	int    abilities;       //Amount of abilities
	string altAbility;
	string altAbilityDes;
	int    evolutions;      //Amount of evolutions
	bool   secEvo;			//If the Pokemon is the second evolution

	bool   evoThroughLvl;   // If the pokemon does not evolve through lvl, then
	                        // just output the condition
	bool   evoThroughCond;  // If the pokemon does not evolve through condition,
	                        //then just output the level
	int    evoLvl;
	int    firstEvoNum;
	string secEvoCondition;
	int    secEvoNum;
	bool   finalEvo;        //If the Pokemon is the last evolution
	int    finalEvoLvl;
	string finalEvoCondition;
	int    finalEvoNum;
	bool   branchEvo;       //If the Pokemon has a branch evolution
	int    branchEvoNumber; //The location of the branch evo pokemon
};

//The struct that represent the information that a Pokemon would have
struct pokemonInfo
{
	basicInfo   basic;
	advanceInfo advance;
};

enum Menu
{
	EXIT,
	SEARCH_NAME,
	SEARCH_NUM,
	TYPE_EFFECTIVNESS_CHART,
	SURPRISE,
	END
};

//The enumerated type that represent the available Pokemon types
enum PokemonTypes
{
	NORMAL,
	FIGHTING,
	FLYING,
	POISON,
	GROUND,
	ROCK,
	BUG,
	GHOST,
	STEEL,
	FIRE,
	WATER,
	GRASS,
	ELECTRIC,
	PSYCHIC,
	ICE,
	DRAGON,
	DARK,
	FAIRY
};

/**************************************************************************
 * CONSTANTS
 * ------------------------------------------------------------------------
 * USED FOR SIZE OF ARRAY
 * ------------------------------------------------------------------------
 * AR_SIZE    : the maximum size of the array
 * ------------------------------------------------------------------------
 * USED FOR MAX/MIN VALUES
 * ------------------------------------------------------------------------
 * KANTO_DEX    : the maximum size of the Kanto pokedex
 * JOHTO_DEX    : the maximum size of the Johto pokedex
 * HOENN_DEX    : the maximum size of the Hoenn pokedex
 * SINNOH_DEX   : the maximum size of the Sinnoh pokedex
 * UNOVA_DEX    : the maximum size of the Unova pokedex
 * KALOS_DEX    : the maximum size of the Kalos pokedex
 * ALOLA_DEX    : the maximum size of the Alola pokedex
 * ------------------------------------------------------------------------
 * USED FOR COLUMN SIZE
 * ------------------------------------------------------------------------
 * INVALID_COL : the size of the column to display the invalid message
 *************************************************************************/
const int AR_SIZE      = 807;
const int KANTO_DEX    = 151;
const int JOHTO_DEX    = 251;
const int HOENN_DEX    = 386;
const int SINNOH_DEX   = 493;
const int UNOVA_DEX    = 649;
const int KALOS_DEX    = 721;
const int ALOLA_DEX    = 807;
const int INVALID_COL  = 30;

/******************************************************************************
 * GetInputFromFile
 * 	 This function receives an empty Pokemon array and the input file name
 * 	 	and then stores the information into an array
 * 	 ==> returns an array with the stored information
 *****************************************************************************/
void GetInputFromFile(pokemonInfo pokemonAr[AR_SIZE], //PROC - the pokemon array
					  const string &INPUT_FILE,       //PROC - the input file
                      	  	  	  	  	  	  	  	  //       name
					  const int    &REGION_MAX_INDEX);//PROC - the max pokemon
                                                      //       in that region

/******************************************************************************
 * GetAndCheckMenu
 * 	 This function receives nothing and returns a valid input option from the
 * 	 	menu for what function the Pokedex will do
 * 	 ==> returns the user choice for what the Pokedex will do
 *****************************************************************************/
Menu GetAndCheckMenu();

/******************************************************************************
 * SearchByNum
 * 	 This function receives the Pokemon array, the menu choice, and the output
 * 	 	file variable. It gets and checks a Pokedex Number that the user would
 * 	 	like to search for. It tell the user that the Pokemon was found and
 * 	 	returns nothing.
 * 	 ==> returns nothing - It tell the user that the Pokemon was found.
 *****************************************************************************/
void SearchByNum(const pokemonInfo POKEMON_AR[AR_SIZE], //PROC - the pokemon
	  	  	  	  	     	 	 	 	 	 	 	 	//       array
				 const Menu        &MENU_CHOICE,         //PROC - the menu choice
				 ofstream          &fout);              //OUT  - output file

/******************************************************************************
 * SearchByName
 * 	 This function receives the Pokemon array, the menu choice, and the output
 * 	 	file variable. It then gets the name that pertains to the Pokemon in
 * 	 	the Pokedex and checks if it is spelled correctly and tells the user
 * 	 	if the Pokemon was found or not.
 * 	 ==> returns nothing - It tells the user if the Pokemon was found or not
 *****************************************************************************/
void SearchByName(const pokemonInfo POKEMON_AR[AR_SIZE], //PROC - the pokemon
		  	  	  	  	  	  	  	  	  	  	  	     //       array
				  const Menu        &MENU_CHOICE,		 //PROC - the menu
				  	  	  	  	  	  	  	  	  	  	 //       choice
				  ofstream          &fout);				 //OUT  - output file

/******************************************************************************
 * SearchPokedex
 * 	 This function receives the Pokemon array, the name of the Pokemon, the
 * 	 	Pokedex number and the menu choice. It returns the index of the found
 * 	 	Pokemon if it was found or the AR_SIZE if it was not found.
 * 	 ==> returns the index of the found Pokemon
 *****************************************************************************/
int SearchPokedex(const pokemonInfo POKEMON_AR[AR_SIZE], //PROC - the pokemon
														 //       array
				  const string &NAME,					 //PROC - the name of
				  	  	  	  	  	  	  	  	  	     //       the pokemon
				  const int    &POKEDEX_NUMBER,		     //PROC - the number of
				  	  	  	  	  	  	  	  	  	     //       the pokemon
				  const Menu   &MENU_CHOICE);		     //PROC - the menu
														 //       choice

/******************************************************************************
 * TypeEffectivenessChart
 * 	 This function receives the output file variable. It then outputs the type
 * 	 	effectiveness chart to the file.
 * 	 ==> returns nothing - It outputs the type effectiveness chart
 *****************************************************************************/
void TypeEffectivenessChart(ofstream &fout); //OUT - the output file

/******************************************************************************
 * DisplayPokemonInfo
 * 	 This function receives the Pokemon array, the index, and the output file
 * 	 	variable. This functions displays the Pokemon's information to the
 * 	 	output file.
 * 	 ==> returns nothing - It outputs the Pokemon's information
 *****************************************************************************/
void DisplayPokemonInfo(const pokemonInfo POKEMON_AR[], //OUT  - the Pokemon
														//       array
						const int         &INDEX,       //PROC - the index
						ofstream          &fout);       //OUT  - the output file

/******************************************************************************
 * WordWrap
 * 	 This function receives a sentence and the width of each line. It then
 * 	 	returns the sentence as a paragraph according to the line width.
 * 	 ==> returns the sentence wrapped as a paragraph
 *****************************************************************************/
string WordWrap(const string &SENTENCE,    //PROC - the sentence
		        const int    &LINE_WIDTH); //PROC - the width of each line

/******************************************************************************
 * DisplayAbility
 * 	 This function receives the Pokemon array, the index, the amount of
 * 	 	abilities, and the output file variable. This functions displays the
 * 	 	Pokemon's ability information to the output file.
 * 	 ==> returns nothing - It outputs the Pokemon's ability information
 *****************************************************************************/
void DisplayAbility(const pokemonInfo POKEMON_AR[], //OUT  - the Pokemon array
					const int &INDEX,				//PROC - the index
		            const int &ABILITIES,			//PROC - the amount of
													//	     abilities
					ofstream  &fout);				//OUT  - the output file

/******************************************************************************
 * EvolutionTree
 * 	 This function receives the Pokemon array, the index  and the output file
 * 	 	variable. This functions displays the Pokemon's evolution tree based on
 * 	 	how many evolutions the Pokemon has.
 * 	 ==> returns nothing - It outputs the Pokemon's evolution tree
 *****************************************************************************/
void EvolutionTree(const pokemonInfo POKEMON_AR[], //PROC - the Pokemon array
				   const int         &INDEX,	   //PROC - the index
				   ofstream          &fout);	   //OUT  - the output file

/******************************************************************************
 * DisplayTwoEvo
 * 	 This function receives the Pokemon array, the index  and the output file
 * 	 	variable. This functions displays the Pokemon's evolution tree based on
 * 	 	having only two evolutions.
 * 	 ==> returns nothing - It outputs the Pokemon's evolution tree
 *****************************************************************************/
void DisplayTwoEvo(const pokemonInfo POKEMON_AR[], //OUT  - the Pokemon array
				   const int         &INDEX,	   //PROC - the index
				   ofstream          &fout);	   //OUT  - the output file

/******************************************************************************
 * DisplayThreeEvo
 * 	 This function receives the Pokemon array, the index  and the output file
 * 	 	variable. This functions displays the Pokemon's evolution tree based on
 * 	 	having only 3 evolutions.
 * 	 ==> returns nothing - It outputs the Pokemon's evolution tree
 *****************************************************************************/
void DisplayThreeEvo(const pokemonInfo POKEMON_AR[], //OUT  - the Pokemon array
					 const int         &INDEX,		 //PROC - the index
					 ofstream          &fout);	     //OUT  - the output file

/******************************************************************************
 * DisplayBranchEvo
 * 	 This function receives the Pokemon array, the index for the pokemon, and '
 * 	 	the output file variable. It then prints out the evolution tree for
 * 	 	pokemon that have special branch evolutions
 * 	 ==> returns nothing - It outputs the Pokemon's branch evolution tree
 *****************************************************************************/
void DisplayBranchEvo(const pokemonInfo POKEMON_AR[], //OUT  - the Pokemon array
				      const int         &INDEX,		  //PROC - the index
					  ofstream          &fout);	   	  //OUT  - the output file

/******************************************************************************
 * TwoEvoBranch
 * 	 This function receives the Pokemon array, the index for the pokemon, and '
 * 	 	the output file variable. It then prints out the evolution tree for
 * 	 	pokemon that have special branch evolutions with two evolutions
 * 	 ==> returns nothing - It outputs the Pokemon's branch evolution tree
 *****************************************************************************/
void TwoEvoBranch(const pokemonInfo POKEMON_AR[],
		   	   	  const int         &INDEX,
				        ofstream    &fout);

/******************************************************************************
 * ThreeEvoBranch
 * 	 This function receives the Pokemon array, the index for the pokemon, and '
 * 	 	the output file variable. It then prints out the evolution tree for
 * 	 	pokemon that have special branch evolutions with three evolutions
 * 	 ==> returns nothing - It outputs the Pokemon's branch evolution tree
 *****************************************************************************/
void ThreeEvoBranch(const pokemonInfo POKEMON_AR[], //OUT  - the pokemon array
		   	   	    const int         &INDEX,		//PROC - the index
				          ofstream    &fout);		//OUT  - the output file

/******************************************************************************
 * SpecialBranchEvo
 * 	 This function receives the Pokemon array, the index  and the output file
 * 	 	variable. This functions displays the Pokemon's special branch evolution
 * 	 	tree based for pokemon with more than 3 evolutions
 * 	 ==> returns nothing - It outputs the Pokemon's evolution tree
 *****************************************************************************/
void SpecialBranchEvo(const pokemonInfo POKEMON_AR[],  //PROC - the Pokemon
													   //       array
		   	   	      const int         &INDEX,		   //PROC - the index
				      ofstream          &fout);	       //OUT  - the output file

/******************************************************************************
 * DisplayDamage
 * 	 This function receives the Pokemon array, the index  and the output file
 * 	 	variable. This functions displays the Pokemon's damage that the would
 * 	 	receive in battle
 * 	 ==> returns nothing - It outputs the Pokemon's damage that they would
 * 	 					   recieve in battle.
 *****************************************************************************/
void DisplayDamage(const pokemonInfo POKEMON_AR[], //OUT  - the Pokemon array
		   	       const int         &INDEX,	   //PROC - the index
		           ofstream          &fout);	   //OUT  - the output file

/******************************************************************************
 * ConvertTypeToEnum
 * 	 This function receives the Pokemon's empty enum types and the Pokemon's
 * 	 	actual type values and stores the type values in the enum types and
 * 	 	returns them.
 * 	 ==> returns the types converted to an enum
 *****************************************************************************/
void ConvertTypeToEnum(PokemonTypes &typeOne,   //PROC - the enum of the first
											    //       type
					   PokemonTypes &typeTwo,   //PROC - the enum of the second
						  	  	  	  	  	    //       type
					   const string &MAIN_TYPE, //PROC - the string of the first
						  	  	  	  	  	    //       type
					   const string &ALT_TYPE); //PROC - the string of the first
											    //       type

/******************************************************************************
 * CalcDamageTaken
 * 	 This function receives the Pokemon's enum types and the empty float array
 * 	 	of damage they would take. It calculates which damage should be stored
 * 	 	in the float array based on the enums and returns the array.
 * 	 ==> returns the damage array
 *****************************************************************************/
void CalcDamageTaken(const PokemonTypes &TYPE_1, 	   //PROC - the pokemon's
													   //       primary type
					 const PokemonTypes &TYPE_2,  	   //PROC - the pokemon's
								 	 	 	 	 	   //		 secondary type
					 float        	    damageTaken[]);//PROC - the damage array

/******************************************************************************
 * NormFightFlyDamage
 * 	 This function receives the Pokemon's enum types and the empty float array
 * 	 	of damage they would take. It calculates which damage should be stored
 * 	 	in the float array based on the enums and returns the array.
 * 	 ==> returns the damage array
 *****************************************************************************/
void NormFightFlyDamage(const PokemonTypes &TYPE_1, //PROC - the pokemon's
													//       primary type
						const PokemonTypes &TYPE_2, //PROC - the pokemon's
						 	 	 	 	 	 	 	//		 secondary type
						float        damageTaken[]);//PROC - the damage array

/******************************************************************************
 * PoiGrndRockDamage
 * 	 This function receives the Pokemon's enum types and the empty float array
 * 	 	of damage they would take. It calculates which damage should be stored
 * 	 	in the float array based on the enums and returns the array.
 * 	 ==> returns the damage array
 *****************************************************************************/
void PoiGrndRockDamage(const PokemonTypes &TYPE_1, //PROC - the pokemon's
													//      primary type
					   const PokemonTypes &TYPE_2, //PROC - the pokemon's
						 	 	 	 	 	 	   //		secondary type
					   float        damageTaken[]);//PROC - the damage array

/******************************************************************************
 * BugGhostSteelDamage
 * 	 This function receives the Pokemon's enum types and the empty float array
 * 	 	of damage they would take. It calculates which damage should be stored
 * 	 	in the float array based on the enums and returns the array.
 * 	 ==> returns the damage array
 *****************************************************************************/
void BugGhostSteelDamage(const PokemonTypes &TYPE_1, //PROC - the enum of the
													 //       first type
						 const PokemonTypes &TYPE_2, //PROC - the enum of the
						 	 	 	 	 	 	 	 //       second type
						 float        damageTaken[]);//PROC - the float array of
	 	    										 //       damage

/******************************************************************************
 * FireWaterGrassDamage
 * 	 This function receives the Pokemon's enum types and the empty float array
 * 	 	of damage they would take. It calculates which damage should be stored
 * 	 	in the float array based on the enums and returns the array.
 * 	 ==> returns the damage array
 *****************************************************************************/
void FireWaterGrassDamage(const PokemonTypes &TYPE_1,     //PROC - the pokemon's
												          //       primary type
					      const PokemonTypes &TYPE_2,     //PROC - the pokemon's
						 	 	 	 	 	 	          //	  secondary type
					            float        damageTaken[]);//PROC - the damage
															//       array

/******************************************************************************
 * ElecPsyIceDamage
 * 	 This function receives the Pokemon's enum types and the empty float array
 * 	 	of damage they would take. It calculates which damage should be stored
 * 	 	in the float array based on the enums and returns the array.
 * 	 ==> returns the damage array
 *****************************************************************************/
void ElecPsyIceDamage(const PokemonTypes &TYPE_1, //PROC - the pokemon's
												  //       primary type
					  const PokemonTypes &TYPE_2, //PROC - the pokemon's
						 	 	 	 	 	 	  //	   secondary type
					  float        damageTaken[]);//PROC - the damage array

/******************************************************************************
 * DragDarkFairyDamage
 * 	 This function receives the Pokemon's enum types and the empty float array
 * 	 	of damage they would take. It calculates which damage should be stored
 * 	 	in the float array based on the enums and returns the array.
 * 	 ==> returns the damage array
 *****************************************************************************/
void DragDarkFairyDamage(const PokemonTypes &TYPE_1, //PROC - the pokemon's
													 //       primary type
						 const PokemonTypes &TYPE_2, //PROC - the pokemon's
						 	 	 	 	 	 	 	 //		 secondary type
						 float        damageTaken[]);//PROC - the damage array

/******************************************************************************
 * AssignDamageAr
* 	 This function receives an empty array that will hold the the damage that
* 	 	the pokemon will take and the different amounts of damage that the
* 	 	pokemon will take based the different types and will assign the
* 	 	corresponding damage into the array.
* 	 ==> returns the damage taken array stored with the values
 *****************************************************************************/
void AssignDamageAr(      float damageTaken[], //PROC - the float array of
											   //		damage
					const float NORMAL_DMG,    //PROC - the damage taken by
											   //       normal moves
					const float FIGHT_DMG,	   //PROC - the damage taken by
					   	   	   	   	   	   	   //       fighting moves
					const float FLY_DMG,	   //PROC - the damage taken by
					   	   	   	   	   	   	   //       flying moves
					const float POI_DMG,	   //PROC - the damage taken by
					   	   	   	   	   	   	   //       poison moves
					const float GRD_DMG,	   //PROC - the damage taken by
					   	   	   	   	   	       //       ground moves
					const float ROCK_DMG,	   //PROC - the damage taken by
					   	   	   	   	   	   	   //       rock moves
					const float BUG_DMG,	   //PROC - the damage taken by
					   	   	   	   	   	   	   //       bug moves
					const float GHOST_DMG,	   //PROC - the damage taken by
					   	   	   	   	   	   	   //       ghost moves
					const float STEEL_DMG,	   //PROC - the damage taken by
					   	   	   	   	   	   	   //       steel moves
					const float FIRE_DMG,	   //PROC - the damage taken by
					   	   	   	   	   	   	   //       fire moves
					const float WATER_DMG,	   //PROC - the damage taken by
					   	   	   	   	   	   	   //       water moves
					const float GRASS_DMG,	   //PROC - the damage taken by
					   	   	   	   	   	   	   //       grass moves
					const float ELEC_DMG,	   //PROC - the damage taken by
					   	   	   	   	   	   	   //       electric moves
					const float PSY_DMG,	   //PROC - the damage taken by
					  						   //       psychic moves
					const float ICE_DMG,	   //PROC - the damage taken by
					   	   	   	   	   	   	   //       ice moves
					const float DRGN_DMG,	   //PROC - the damage taken by
					   	   	   	   	   	   	   //       dragon moves
					const float DARK_DMG,	   //PROC - the damage taken by
					   	   	   	   	   	   	   //       dark moves
					const float FAIRY_DMG);	   //PROC - the damage taken by
											   //       fairy moves

#endif /* POKEDEX_H_ */
