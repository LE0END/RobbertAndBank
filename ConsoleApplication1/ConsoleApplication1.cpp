#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Карта
int Map[17][25] = {
         {3, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 3, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 3},
         {3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3},
         {3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3},
         {3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3},
         {3, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 3, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 3},
         {3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3},
         {3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3},
         {3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3},
         {3, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 3, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 3},
         {3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3},
         {3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3},
         {3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3},
         {3, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 3, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 3},
         {3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3},
         {3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3},
         {3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 3},
         {3, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 3, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 3}
};
string Letters = "ABCDEFGHIJKLMNOPQRSTUVWXY";
int Rob_position[4][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0} };
int Pol_position[4][2] = { {0, 0}, {0, 0}, {0, 0}, {0, 0} };
int lift[3] = { -2, -2, -2 }; //1-policeman, -1-Free, 2-robert

// Find Letter
int find_letter(char a) {
    return Letters.find(a);
}

// Вывод позиций грабителей
void write_robbers() {
    for (int i = 0; i < 4; i++) {
        cout << Letters[Rob_position[i][1]];
        cout << Letters[Rob_position[i][0]];
        cout << " ";
    }
}

// Ввод позиций полицейских
void write_police() {
    for (int i = 0; i < 4; i++) {
        cout << Letters[Pol_position[i][1]];
        cout << Letters[Pol_position[i][0]];
        cout << " ";
    }
    for (int i = 0; i < 3; i++)
        cout<<lift[i];
}

void input_police() 
{
    string inp;
    for (int i = 0; i < 4; i++) {
        cin >> inp;
        Pol_position[i][1] = find_letter(inp[0]);
        Pol_position[i][0] = find_letter(inp[1]);
    }
    cin >> inp;
    for (int i = 0; i < 3; i++)
        lift[i] = inp[i] == 'F' ? -2 : lift[i] > -1 ? lift[i] : -1;

}

int NowFloor(int y)
{
    double dop;
    dop = (y / 4)+1;
    if (dop == floor(dop))
        return floor(dop);
  
    
    return -1;
    

}
// Персонаж 
class Person {
public: 
    //int use_lift[2] = { -1,0 };//First: Up/Down; Second: Target Floor
    int position_x=1;
    int position_y=1;
    //int id;
    int TargetFloor=-1;
    bool MoveLift = false;
    void set_location(int x, int y) 
    {
        position_x = x;
        position_y = y;
       // Rob_position[id][0] = x;
        //Rob_position[id][1] = y;
    }

    /*void In_Lift()
    {
        if (use_lift[1])
        {
            set_location(position_x, position_y + 2);
            
        }
        else 
        {
            set_location(position_x, position_y - 2);
        }
        
        cout << 'I';
    }*/
    void Lift(int target)
    {
        TargetFloor = target;

        if (NowFloor(position_y) == target)
        {
            TargetFloor = -1;
            MoveLift = false;
            lift[position_x / 12] = 0;
        }
        else

        {
            if (!MoveLift)
            {
                if (target > (position_y/4+1))
                {
                    set_location(position_x, position_y + 2);
                }
                else
                {
                    set_location(position_x, position_y - 2);

                }
                MoveLift = true;
                cout << target;
                lift[position_x / 12] = 2;

            }
            else
            {
                if (target > (position_y/4+1))
                {
                    set_location(position_x, position_y + 2);
                }
                else
                {
                    set_location(position_x, position_y - 2);

                }
                cout << 'I';
                lift[position_x / 12] = 2;
            }
        }   
    }
    void move_up()
    {
       // if ((Map[position_x][position_y] == 3) && lift[position_x / 12] == -2)
            set_location(position_x, position_y + 1);
            cout << 'U';
    }
    void Nomove()
    {
        cout << 'S';
    }
    /*void Lift_down(int target)
    {
        TargetFloor = target;
        if (NowFloor(position_y) == target)
        {
            TargetFloor = -1;
            MoveLift = false;
            lift[position_x / 12] = 0;
        }
        else
        {
            if (!MoveLift)
            {
                set_location(position_x, position_y - 2);
                MoveLift = true;
                cout << target;
                lift[position_x / 12] = 2;

            }
            else
            {
                set_location(position_x, position_y - 2);
                cout << 'I';
                lift[position_x / 12] = 2;
            }
        }
    }*/
    void move_down()
    {
        //if ((Map[position_x][position_y] == 3) && lift[position_x / 12] == -2)
        
        
            set_location(position_x, position_y - 1);
            cout << 'D';
      
    }
    void move_Right()
    {
        set_location(position_x+1, position_y );
        cout << 'R';
    }
    void move_Left()
    {
        set_location(position_x - 1, position_y );
        cout << 'L';
    }
    
};

class Robber: public Person {
public:
    
};

class Policeman : public Person {
public:
    void set_location(int x, int y) {
    position_x = x;
    position_y = y;
   // Pol_position[id][0] = x;
   // Pol_position[id][1] = y;
}
};

const int height = 17;
const int width = 25;








int main()
{
    // Начальные данные
    int limit, side;
    cin >> limit;
    cin >> side;
    // Создание персонажей
    Robber ArrRob[4];
    Policeman ArrPol[4];
    /*for (int i = 0; i < 4; i++)
    {
        ArrRob[i].id = i;
    }*/
    ArrPol[0].set_location(10, 0);

    ArrPol[1].set_location(11, 0);

    ArrPol[2].set_location(13, 0);

    ArrPol[3].set_location(14, 0);


    ArrRob[0].set_location(6, 16);
    
    ArrRob[1].set_location(14, 16);
    
    ArrRob[2].set_location(4, 12);
    
    ArrRob[3].set_location(16, 8);

    write_robbers();
    cout << endl;
    cout << NowFloor(find_letter('I'));
    cout << endl;
 
    write_robbers();
    input_police();
    write_police();

 
}
