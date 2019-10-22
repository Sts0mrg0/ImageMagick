// This may look like C code, but it is really -*- C++ -*-
//
// Copyright Bob Friesenhahn, 1999, 2000, 2003
//
// Test STL averageImages function
//

#include <Magick++.h>
#include <string>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

using namespace Magick;

int main( int /*argc*/, char ** argv)
{

  // Initialize ImageMagick install location for Windows
  InitializeMagick(*argv);

  int failures=0;

  try {

    string srcdir("");
    if(getenv("SRCDIR") != 0)
      srcdir = getenv("SRCDIR");

    //
    // Test averageImages
    //
    
    list<Image> imageList;
    readImages( &imageList, srcdir + "test_image_anim.miff" );
    
    Image averaged;
    averageImages( &averaged, imageList.begin(), imageList.end() );
    // averaged.display();
    if (
        ( averaged.signature() != "be10086221b349ccf2ca03bf4e18d68c75a4ab434814e16de8c9a347f3b7d68f") &&
        ( averaged.signature() != "88bb7267b362b0b41a26b0cd681d6e4fed58edd901024728e3964025e0b50ec1") &&
        ( averaged.signature() != "90c4ba4b092f37a0600d51356f9aba89e7402ba3f59ac591ae216bace4a9d10b") &&
        ( averaged.signature() != "5edad755f33a1cf8358f3909ea9cb7db71c1eb64f2e8279db86826d1d6de678d") &&
        ( averaged.signature() != "a88e978776d45b73bc8c9f37f6726cc9f14a3118b9a82384ee5acf488c5c2863") &&
        ( averaged.signature() != "6bda37a8b6734ac271595f5b583d801cfb2479637401d056eae9be97127f558f")
       )
      {
	cout << "Line: " << __LINE__
	     << "  Averaging image failed, signature = "
	     << averaged.signature() << endl;
	averaged.display();
	++failures;
      }
  }

  catch( Exception &error_ )
    {
      cout << "Caught exception: " << error_.what() << endl;
      return 1;
    }
  catch( exception &error_ )
    {
      cout << "Caught exception: " << error_.what() << endl;
      return 1;
    }

  if ( failures )
    {
      cout << failures << " failures" << endl;
      return 1;
    }
  
  return 0;
}

