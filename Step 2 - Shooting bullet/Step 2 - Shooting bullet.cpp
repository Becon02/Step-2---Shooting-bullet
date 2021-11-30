#include <string>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <chrono>
#include <thread>

using namespace std;
using namespace this_thread;
using namespace chrono;

void FireUntilEmpty();
void SpaceLine();
void TimeDelay(int x);

#define PlayerAmmo 5

int main()
{
    SpaceLine();

    FireUntilEmpty();
}

void SpaceLine()
{
    cout << "-------------------------------------------------------------------------\n";
}

void FireBullet()
{
    cout << "Bullet fired ";
}

void Reload()
{
    TimeDelay(10);

    cout << "|Takes magazine out|" << endl;

    TimeDelay(10);
    cout << "|Put magazine in gun|" << endl;

    TimeDelay(10);

    cout << "Sniper realoded lets go back into combat !!" << endl;
}

void RunOutOfBullets()
{
    TimeDelay(10);

    cout << "|Stops shooting|" << endl;

    TimeDelay(10);

    cout << "Reloading the sniper, cover me !!" << endl;

    SpaceLine();

    Reload();

    SpaceLine();

    FireUntilEmpty();
}

void FireUntilEmpty()
{
    string EnemySpotted;
    bool CorrectAnswer = false;

    while (CorrectAnswer == false)
    {
        TimeDelay(10);

        cout << "Do you see an enemy ? (Yes/No)" << endl;
        cin >> EnemySpotted;

        SpaceLine();

        if (EnemySpotted == "Yes")
        {
            for (int i = PlayerAmmo; i > 0; i--)
            {
                TimeDelay(1);
                FireBullet();
                cout << "(" << i - 1 << "/" << PlayerAmmo << ") !!\n";
            }

            SpaceLine();

            RunOutOfBullets();

            CorrectAnswer = true;
        }
        else if (EnemySpotted == "No")
        {
            TimeDelay(10);

            cout << "Perfect no need to waste bullets then. Keep looking around." << endl;

            CorrectAnswer = true;
            SpaceLine();
            
            TimeDelay(10);

            cout << "";
        }
        else
        {
            cout << "Make sure you type the answer correctly." << endl;
            CorrectAnswer = false;
        }
    }
}

void TimeDelay(int x)
{
    sleep_for(nanoseconds(x));
    sleep_until(system_clock::now() + seconds(1));
}
