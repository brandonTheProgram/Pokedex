
#include "pokedex.h"

/************************************************************************
* FUNCTION GetAndCheckInput
*----------------------------------------------------------------------
* 	 This function receives nothing and allows the user to
* 	 	select what action they wish the Pokedex to perform and returns the
* 	 	valid input selected
* 	 ==> returns the desired action by the user
*-----------------------------------------------------------------------
* PRE-CONDITIONS
*
* POST-CONDITIONS
* 	==> Returns the desired action by the user
*************************************************************************/
Menu GetAndCheckMenu()
{
	/**************************************************************************
	 * CONSTANTS
	 * ------------------------------------------------------------------------
	 * USED FOR SPECIFIED VALUES
	 * ------------------------------------------------------------------------
	 * MENU : The menu for the program
	 *************************************************************************/
	const string MENU = "\nPokedex MENU:\n"
						"1 - Search for a Pokemon by name\n"
						"2 - Search for a Pokemon by pokedex number\n"
						"3 - Look at the Type Effectiveness Chart\n"
						"4 - Surprise me with a Pokemon\n"
						"0 - EXIT\n"
						"Enter a command (0 to exit): ";

	Menu menuChoice;     //PROC       - the choice from menu converted to an
		                 //             enum

	int  choiceFromMenu; //IN         - the choice from the menu;

	bool   invalid;      //PROC       - the condition for invalid inputs
	bool   fail;         //PROC       - the condition for failed inputs

	string menuString;   //PROC & OUT - the menu choice converted to a string
	string errorMessage; //OUT        - the message when an error is encountered

	do
	{
		cout << MENU;
		cin  >> choiceFromMenu;

		menuChoice = Menu(choiceFromMenu);

		invalid = (menuChoice != EXIT && menuChoice != SEARCH_NAME &&
				   menuChoice != SEARCH_NUM  &&
				   menuChoice != TYPE_EFFECTIVNESS_CHART &&
				   menuChoice != SURPRISE);

		fail    = (cin.fail());

		if(invalid || fail)
		{
			//If input fail, then specify that a number should be entered
			if(fail)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\n**** Please input a NUMBER between " << EXIT
					 << " and " << (END - 1) << " ****\n";
			}
			//Output an error message
			else
			{
				menuString = to_string(menuChoice);
				errorMessage = ("The number " + menuString
											  + " is an invalid entry");
				cout << left << endl;
				cout << "**** " << setw(INVALID_COL) << (errorMessage)
					 << " ****";
				cout << "\n**** " << "Please input a number between "
					 << EXIT  <<  " and " << (END - 1) << " ****\n\n";
				cout << right;
			}
		}

	}while(invalid || fail);

	cin.ignore(1000, '\n');

	return menuChoice;
}
