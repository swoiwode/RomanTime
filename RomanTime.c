// RomanTime.c - Convert time to roman numerals.
// 05/04/2013 - Scott Woiwode - github/swoiwode

#include "stdio.h"
#include "time.h"
#include "string.h"

main( )
{
  time_t RawTime;
	struct tm *Now;
	int ThousandsDigit = 0;
	int HundredsDigit = 0;
	int TensDigit = 0;
	int OnesDigit = 0;
	char NumeralBuffer[14] = "\0";
	
	time( &RawTime );
	
	Now = localtime( &RawTime );

// Debug - biggest conversion 1838 equals MDCCCXXXVIII or 2338 equals MMCCCXXXVIII
// Now->tm_hour = 18;
// Now->tm_min = 38;
	
	ThousandsDigit = Now->tm_hour / 10;
	HundredsDigit = Now->tm_hour - ( ThousandsDigit * 10 );
	TensDigit = Now->tm_min / 10;
	OnesDigit = Now->tm_min - ( TensDigit * 10 );

	// We need to build the Roman Numerals from left to right.
	// Handle the '00' hour
	if( ThousandsDigit + HundredsDigit == 0 ) strcat( NumeralBuffer, "MMCD" );

	// Handle the 'thousands' dight.
	if( ThousandsDigit == 1 ) strcat( NumeralBuffer, "M" );
	else if( ThousandsDigit == 2 ) strcat( NumeralBuffer, "MM" );

	// Handle the 'hundreds' digit.
	if( HundredsDigit == 1 ) strcat( NumeralBuffer, "C" );
	else if( HundredsDigit == 2 ) strcat( NumeralBuffer, "CC" );
	else if( HundredsDigit == 3) strcat( NumeralBuffer, "CCC" );
	else if( HundredsDigit == 4 ) strcat( NumeralBuffer, "CD" );
	else if( HundredsDigit == 5 ) strcat( NumeralBuffer, "D" );
	else if( HundredsDigit == 6 ) strcat( NumeralBuffer, "DC" );
	else if( HundredsDigit == 7 ) strcat( NumeralBuffer, "DCC" );
	else if( HundredsDigit == 8 ) strcat( NumeralBuffer, "DCCC" );
	else if( HundredsDigit == 9 ) strcat( NumeralBuffer, "CM" );

	// Handle the 'tens' digit.
	if( TensDigit == 1 ) strcat( NumeralBuffer, "X" );
	else if( TensDigit == 2 ) strcat( NumeralBuffer, "XX" );
	else if( TensDigit == 3 ) strcat( NumeralBuffer, "XXX" );
	else if( TensDigit == 4 ) strcat( NumeralBuffer, "XL" );
	else if( TensDigit == 5 ) strcat( NumeralBuffer, "L" );
	
	// Handle the 'ones' digit.
	if( OnesDigit == 1 ) strcat( NumeralBuffer, "I" );
	else if( OnesDigit == 2 ) strcat( NumeralBuffer, "II" );
	else if( OnesDigit == 3 ) strcat( NumeralBuffer, "III" );
	else if( OnesDigit == 4 ) strcat( NumeralBuffer, "IV" );
	else if( OnesDigit == 5 ) strcat( NumeralBuffer, "V" );
	else if( OnesDigit == 6 ) strcat( NumeralBuffer, "VI" );
	else if( OnesDigit == 7 ) strcat( NumeralBuffer, "VII" );
	else if( OnesDigit == 8 ) strcat( NumeralBuffer, "VIII" );
	else if( OnesDigit == 9 ) strcat( NumeralBuffer, "IX" );
		
	printf( "%s - %d%d%d%d\n", NumeralBuffer, ThousandsDigit, HundredsDigit, TensDigit, OnesDigit );
}
