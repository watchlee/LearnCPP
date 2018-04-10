#include "stdafx.h"
#include "ImplementFILE.h"

ImplementFILE::ImplementFILE()
{
}


ImplementFILE::~ImplementFILE()
{
}

void ImplementFILE::close()
{
	/*close all file
	*/
	if ( outfile )
		outfile.close();
	if ( inputfile )
		inputfile.close();
	if ( file )
		file.close();
}
