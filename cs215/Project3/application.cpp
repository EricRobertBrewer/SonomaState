#include"Maze.h"

int main()
{
  Maze M;
  M.Instructions(cout);
  M.Display(cout);
  bool solved = false;
  char d = ' ';
  while (!solved && d != 'q')
    { 
      cout << "What direction would you like to move?";
      cin >> d;
      solved = M.Move(d);
      M.Display(cout);
    }
  M.Message(solved, cout);

  Maze Q(11, 11);
  Q.Display(cout);
  bool solved2 = false;
  d = ' ';
  while (!solved2 && d != 'q')
    {
      cout << "Choose a direction.";
      cin >> d;
      solved2 = Q.Move(d);
      Q.Display(cout);
    }
  Q.Message(solved2, cout);

  Maze S(Q);
  S.Display(cout);
  bool solved3 = false;
  d = ' ';
  while (!solved3 && d != 'q')
    {
      cout << "Does this one seem familiar?";
      cin >> d;
      solved3 = S.Move(d);
      S.Display(cout);
    }
  S.Message(solved3, cout);

  Maze P;
  P = M;
  P.Display(cout);
  bool solved4 = false;
  d = ' ';
  while (!solved4 && d != 'q')
    {
      cout << "How about his one?";
      cin >> d;
      solved4 = P.Move(d);
      P.Display(cout);
    }
  P.Message(solved4, cout);

  return 0;
}

