#include <iostream>
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

    for (int i = 0;i<d;i++)
    {   
        //obecne wsółrzędne skarbu 
        int tresure_x = 0;
        int tresure_y = 0;

        cout << "Enter no of hints: " << endl;
        cin >> n;

        for (int j = 0; j<n;j++)
        {
            int a , b;
            cout <<"Enter direction & no of steps: " << endl;
            //dane wejsciowe: jaki kierunek, ile kroków
            cin >> a >> b; 

            switch (a)
            {
                case 0:
                tresure_y += b;
                break;

                case 1:
                tresure_y -=b;
                break;

                case 2:
                tresure_x -=b;
                break;

                case 3:
                tresure_x +=b;
                break;
            }
        
        }
        cout<<tresure_x<<endl<<tresure_y;
    }

    return 0;
}