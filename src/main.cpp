#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

struct Field_t
{
    string name;
    int exp;
};

class Fields
{
  public:
    vector<Field_t> camp{
        {"lake", 1},
        {"cabin", 1},
        {"abandoned cabin", 1},
        {"burned cabin", 1},
        {"shower room", 1},
        {"archery range", 1},
        {"fireplace", 1},
        {"tent", 1},
        {"cave", 1},
        {"old mine", 1},
        {"bunker", 1},
        {"toilet", 1},
        {"storage room", 1},
        {"shed", 1},
        {"administration", 1},
        {"fountain"},
        {"barn", 1}};

    Field_t field;

    struct Field_t create()
    {
        field = camp[rand() % camp.size()];
        cout << field.name;
        return field;
    }
};

class World
{
  public:
    Fields fields;

    vector<string> names_t{
        "pinewood",
        "eagle",
        "grizzly",
        "eagle nest",
        "beaver lodge"};

    struct
    {
        int x = 5;
        int y = 5;
    } size;

    string name;

    vector<vector<Field_t>> world;

    vector<vector<Field_t>> create()
    {
        name = names_t[rand() % names_t.size()];

        /*add forest*/
        world.resize(size.x, vector<Field_t>(size.y));
        for (int y = 0; y < size.y; y++)
        {
            for (int x = 0; x < size.x; x++)
            {
                world[x][y] = {"forest", 1};
            }
        }
        /*add camp fields*/
        int number = rand() % 3 + 3;

        for (int i = 0; i < number; i++)
        {
            world[rand() % size.x][rand() % size.y] =
                {fields.camp[rand() % fields.camp.size()]};
        }

        /*add tents*/
        for (int i = 0; i < 3; i++)
        {
            world[rand() % size.x][rand() % size.y] =
                {fields.camp[7]};
        }

        /*add cabins*/
        for (int i = 0; i < 4; i++)
        {
            world[rand() % size.x][rand() % size.y] =
                {fields.camp[1]};
        }

        /*add shower room*/
        world[rand() % size.x][rand() % size.y] =
            {fields.camp[4]};

        /*add fireplace*/
        world[rand() % size.x][rand() % size.y] =
            {fields.camp[6]};

        /*add toilet*/
        world[rand() % size.x][rand() % size.y] =
            {fields.camp[11]};

        return world;
    }

    void show()
    {
        struct
        {
            int x;
            int y;
        } pos;

        pos.x = 1;
        pos.y = 7;

        gotoxy(pos.x, pos.y);
        cout << "> camp " << name << " (" << rand() % 5 + 1981 << ")";
        pos.y = 10;

        for (int y = 0; y < size.y; y++)
        {
            for (int x = 0; x < size.x; x++)
            {
                gotoxy(pos.x, pos.y);
                cout << world[x][y].name;
                gotoxy(pos.x, pos.y + 1);
                cout << world[x][y].exp;
                pos.x += 17;
            }
            pos.x = 1;
            pos.y += 6;
        }
        cout << endl
             << endl;
    }
};

class Title
{
  public:
    void out()
    {
        gotoxy(1, 2);
        cout << "> slasher!";
        gotoxy(12, 2);
        cout << "(vers. 0.1)";
        gotoxy(1, 4);
        cout << "> by feenfleisch";
        return;
    }
};

int main()
{
    Title title;
    World world;

    srand(time(NULL));
    title.out();
    world.create();
    world.show();
    return 0;
}