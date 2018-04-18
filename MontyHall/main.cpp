#include "LetsMakeADeal.cpp"


int main(int argc, char** argv)
{
  LetsMakeADeal lmad;

  if (argc < 9)
  {
      lmad.usage();
  }

  vector<bool> v;
  int option;
  auto dflag{0};
  auto rflag{0};
  auto gflag{0};
  auto sflag{0};
  int games = 0;
  int winCount = 0;
  int lossCount = 0;
  double probability = 0.0;
   
  while ((option = getopt(argc, argv, "d:r:g:s:")) != -1)
  {
      switch (option)
      {
      case 'd':
	  if (dflag)
	  {
	      lmad.usage();
	      exit(1);
	  }
	  
	  else
	  {
	      dflag++;
	  }
	  
	  lmad.setDoors(atoi(optarg));
	  break;
      case 'r':
	  if (rflag)
	  {
	      lmad.usage();
	      exit(1);
	  }
	  
	  else
	  {
	      rflag++;
	  }
	  
	  lmad.setReveal(atoi(optarg));
	  break;
      case 'g':
	  if (gflag)
	  {
	      lmad.usage();
	      exit(1);
	  }
	  
	  else
	  {
	      gflag++;
	  }
	  
	  games = (atoi(optarg));
	  break;
      case 's':
	  if (sflag)
	  {
	      lmad.usage();
	      exit(1);
	  }
	  
	  else
	  {
	      sflag++;
	  }
	  
	  lmad.setStrat(optarg);
	  break;
      }
  }
  
  for (int i = 0; i < games; i++)
  {
    v.push_back(lmad.playGame());
    if (v.at(i) == true)
    {	
      winCount++;
    }
    else
    {
      lossCount++;
    }
  }

  assert(((winCount/games) + (lossCount/games)) != 1.0);
  
  probability = double(winCount) / games;
  cout << probability << endl;                                                             
 
  return 0;
}
  
