#include <iostream>
#include <stdlib.h>

using namespace std;

//kolejno: liczba zestawów danych, liczba wskazówek, kierunek(0-3), ilosc kroków
int d,n;

//współrzędne studni na osi XY
constexpr int well_x = 0;
constexpr int well_y = 0; 

/*legenda:
    0 - północ
    1 - południe
    2 - zachód
    3 - wschód
*/
main ()
{
    cout << "Enter no of data sets: " << endl;
    cin >> d;

    for (int i = 0; i < d;i++)
    {   
        //obecne wsółrzędne skarbu 
        int treasure_x = 0;
        int treasure_y = 0;

        cout << "Enter no of hints: " << endl;
        cin >> n;

        for (int j = 0; j < n;j++)
        {
            int a , b;
            
            cout <<"Enter direction & no of steps (move: " << (j+1) << "): " << endl;
            //dane wejsciowe: jaki kierunek, ile kroków
            cin >> a >> b; 

            //szukanie współrzędnych skarbu

            switch (a)
            {
                //w przyoadku kiedy 0 (północ) zwiększ współrzędne y 'skarbu' o 'b'
                case 0:
                treasure_y += b;
                break;

                //w przyoadku kiedy 1 (poludnie) zmniejsz współrzędne y 'skarbu' o 'b'
                case 1:
                treasure_y -= b;
                break;

                //w przyoadku kiedy 2 (zachód) zmniejsz współrzędne x 'skarbu' o 'b'
                case 2:
                treasure_x -= b;
                break;

                //w przyoadku kiedy 3 (wschód) zwiększ współrzędne x 'skarbu' o 'b'
                case 3:
                treasure_x += b;
                break;

                default:
                cout << "Entered value isn't defined on directions list " << endl;
                exit (0);
            }
        }

        //szukanie najszybszej drogi
        
        //jeżeli współżędna y 'skarbu' jest większa od 0 to obranym kierónkiem jest północ
        if (treasure_y > 0)
        {
            cout << 0 << " " << abs(treasure_y) << endl;
        }
        //jeżeli współżędna y 'skarbu' jest mniejsza od 0 to obranym kierónkiem jest południe
        else if (treasure_y < 0)
        {
            cout << 1 << " " << abs(treasure_y) << endl;
        }

        //jeżeli współżędna x 'skarbu' jest większa od 0 to obranym kierónkiem był wschód
        if(treasure_x > 0)
        {
            cout << 3 << " " << abs(treasure_x) << endl;
        }

        //jeżeli współżędna x 'skarbu' jest mniejsza od 0 to obranym kierónkiem był zachód
        else if(treasure_x < 0)
        {
            cout << 2 << " " << abs(treasure_x) << endl;
        }

        // jeżeli współrzędne skarbu pokrywają się ze współrzednymi 'studni' wypisany zostanie tekst: "studnia"
        if (treasure_y == well_y && treasure_x == well_x)
        {
            cout << "studnia" <<endl;
        }
        
    }

    return 0;
}