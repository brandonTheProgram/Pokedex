
#include "pokedex.h"

/************************************************************************
* FUNCTION WordWrap
*----------------------------------------------------------------------
* 	 This function receives a sentence and the width of each line. It then
* 	 	returns the sentence as a paragraph according to the line width.
* 	 ==> returns the sentence wrapped as a paragraph
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in:
* 		sentence - the string
* 		STRING_SIZE - the size the string will be

* POST-CONDITIONS
* 	==> returns a shortened version of the string
*************************************************************************/
string WordWrap(const string &SENTENCE,    //PROC - the sentence
		        const int    &LINE_WIDTH)  //PROC - the width of each line
{
    istringstream words(SENTENCE);

    ostringstream wrapped;

    string        word;

    if (words >> word)
    {
        wrapped << word;

        size_t space_left = LINE_WIDTH - word.length();

        while (words >> word)
        {
            if (space_left < word.length() + 1)
            {
                wrapped << '\n' << word;

                space_left = LINE_WIDTH - word.length();
            }
            else
            {
                wrapped << ' ' << word;

                space_left -= word.length() + 1;
            }
        }
    }
    return wrapped.str();
}
