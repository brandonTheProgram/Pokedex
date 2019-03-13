
#include "pokedex.h"

/******************************************************************************
 * POKEDEX
 *-----------------------------------------------------------------------------
 * This program will allow the user to input as a choice from the menu how they
 *    wish the Pokedex to perform to help the user. It will display the
 *    information in an output file after the user choose to search by name,
 *    pokedex number, surprise them with a random Pokemon, or displaying the
 *    type effectivness chart. The program will end once the user chooses to
 *    exit the program. This program is meant to mimic the functions of the
 *    Pokedex as seen in anime and in the games.
 *-----------------------------------------------------------------------------
 * INPUT
 * 		The following information will be input for this program:
 * 	  		MenuChoice         	: The choice of action for the Pokedex
 * 	  		pokemonName         : The name of the Pokemon chosen
 * 	  		pokedexNum          : The index in the Pokedex chosen
 * OUTPUT
 * 	  	The following information will be output for this program:
			oFile    : The output file variable
			pokemonAr: The pokemon array
 ***********************************************************************/
int main()
{
	/**************************************************************************
	 * CONSTANTS
	 * ------------------------------------------------------------------------
	 * USED FOR I/O FILES
	 * ------------------------------------------------------------------------
	 * KANTO_INPUT_FILE  : the name of the input file for the Kanto region
	 * JOHTO_INPUT_FILE  : the name of the input file for the Johto region
	 * HOENN_INPUT_FILE  : the name of the input file for the Hoenn region
	 * SINNOH_INPUT_FILE : the name of the input file for the Sinnoh region
	 * UNOVA_INPUT_FILE	 : the name of the input file for the Unova region
	 * KALOS_INPUT_FILE  : the name of the input file for the Kalos region
	 * ALOLA_INPUT_FILE  : the name of the input file for the Alola region
	 * OUTPUT_FILE       : the name of the output file
	 *************************************************************************/
	const string KANTO_INPUT_FILE  = "Kanto.txt";
	const string JOHTO_INPUT_FILE  = "Johto.txt";
	const string HOENN_INPUT_FILE  = "Hoenn.txt";
	const string SINNOH_INPUT_FILE = "Sinnoh.txt";
	const string UNOVA_INPUT_FILE  = "Unova.txt";
	const string KALOS_INPUT_FILE  = "Kalos.txt";
	const string ALOLA_INPUT_FILE  = "Alola.txt";
	const string OUTPUT_FILE       = "OFile.txt";

	srand(time(NULL));				  //PROC - the random seed generator

	int  randomizer;                  //CALC - a random value

	ofstream oFile;                   //OUT  - the output file variable

	Menu menuChoice;                  //IN   - the choice from the menu

	pokemonInfo pokemonAr[AR_SIZE];   //PROC - the array holding the Pokemon
	                                  //       information from the input file

	//INPUT - Read in the data from the  Kanto file
	GetInputFromFile(pokemonAr, KANTO_INPUT_FILE, 151);

	//INPUT - Read in the data from the  Johto file
	GetInputFromFile(pokemonAr, JOHTO_INPUT_FILE, 251);

	//INPUT - Read in the data from the  Hoenn file
	GetInputFromFile(pokemonAr, HOENN_INPUT_FILE, 386);

	//INPUT - Read in the data from the  Sinnoh file
	GetInputFromFile(pokemonAr, SINNOH_INPUT_FILE, 493);

	//INPUT - Read in the data from the  Unova file
	GetInputFromFile(pokemonAr, UNOVA_INPUT_FILE, 649);

	//INPUT - Read in the data from the  Kalos file
	GetInputFromFile(pokemonAr, KALOS_INPUT_FILE, 721);

	//INPUT - Read in the data from the  Kalos file
	GetInputFromFile(pokemonAr, ALOLA_INPUT_FILE, 807);

	//OUTPUT - Open the output file
	oFile.open(OUTPUT_FILE.c_str());

	cout << "\nWelcome to the Pokemon Encyclopedia or Pokedex for short. "
			"\nMy name is Dexter, how may I help you on your "
			"journey to become a Pokemon Master? \n";

	/**************************************************************************
	 * INPUT - gets the choice from the menu as input and checks to make sure
	 *         that it is valid.
	 *************************************************************************/

	menuChoice = GetAndCheckMenu();

	/**************************************************************************
	 * PROCESSING - This is the primary loop for the program.
	 *              It will continue to ask the user what would like to do with
	 *              the Pokedex until they choose to exit.
	 *************************************************************************/
	while(menuChoice != EXIT)
	{
		//PROCESSING - depending on the user input, perform the task they wish
		switch(menuChoice)
		{
		case SEARCH_NAME            : SearchByName(pokemonAr, menuChoice,
												   oFile);
									  break;

		case SEARCH_NUM             : SearchByNum(pokemonAr, menuChoice, oFile);
		                              break;

		case TYPE_EFFECTIVNESS_CHART: TypeEffectivenessChart(oFile);
		                     	 	  break;

		case SURPRISE   			: randomizer = (rand() % AR_SIZE);

									  cout << "\nCheck the output file for "
										   << pokemonAr[randomizer].basic.name
										   << "\'s information";

							 	 	  DisplayPokemonInfo(pokemonAr, randomizer,
							 	 			oFile);

							 	 	  break;
		case END                    :
		case EXIT                   : cout << "\nERROR\n";
		}

		cout << endl;
		//INPUT - Ask the user what they wish to do now
		menuChoice = GetAndCheckMenu();
	}

	//Close the output file
	oFile.close();

	return 0;
}
