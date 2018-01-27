#include "TXLib.h"

void risovat_buratino(int x, int y, HDC buratino);
void risovat_moneta(int x, int y, HDC moneta);
void risovat_panel(HDC panel, int monetok_s_soboi, int monetok_v_kopilke);
void risovat_kopilka(HDC kopilka);
void risovat_buratino_sleva(int x, int y,HDC buratino2);
 //void fon(HDC FON);
int main()
{
    txCreateWindow (1000,1000);

    int x = 5;
    int y = 5;
    int speed = 8;
    int monetok_s_soboi = 0;
    int monetok_v_kopilke = 0;
    int razmer_ekran= 1000;

     //HDC FON = txLoadImage("FON.bmp");


    HDC moneta = txLoadImage("moneta.bmp");
    int moneta_x = random(razmer_ekran);
    int moneta_y = random(razmer_ekran);

    int i;
    HDC buratino2 = txLoadImage("buratino2.bmp");
    HDC kopilka = txLoadImage("kopilka.bmp");
    HDC buratino = txLoadImage("buratino.bmp");
    HDC panel = txLoadImage("panel.bmp");
    txBegin();
    while (x < 20000)
    {
        txClear();
 //fon(FON);
        risovat_kopilka(kopilka);
 risovat_moneta(moneta_x, moneta_y, moneta);
        risovat_panel(panel, monetok_s_soboi, monetok_v_kopilke);
        txSetFillColor (TX_WHITE);

        //f1
        if (GetAsyncKeyState(VK_LEFT)&& x > 0)
        {
            risovat_buratino_sleva(x, y, buratino2);
            x -= speed;
        }
        else if (GetAsyncKeyState(VK_RIGHT) && x < 1000-156)
        {
            risovat_buratino(x, y, buratino);
            x += speed;
        }
        else
        {
            risovat_buratino(x, y, buratino);
        }

        if (GetAsyncKeyState(VK_UP)&& y > 0)
        {
            y -= speed;
        }
        else if (GetAsyncKeyState(VK_DOWN)&& y < 1000)
        {
            y += speed;
        }

       //Собрал монету
        if (abs (x - moneta_x) + abs (y - moneta_y) < 150 && monetok_s_soboi<=4 && monetok_v_kopilke <5)
        {
            if (monetok_s_soboi <= 5)
            {

                moneta_x = random(1000);
                moneta_y = random(1000);
                monetok_s_soboi = monetok_s_soboi + 1;
            }
        }

        //Отнес в копилку
        if (abs (x - 650) + abs (y - 650) < 150 )
        {
            if (monetok_s_soboi <=5)
            {
                monetok_v_kopilke = monetok_v_kopilke + monetok_s_soboi;
                monetok_s_soboi = 0;
            }
            }

        txSleep(20);
    }
    txEnd();
    return 0;
}

void risovat_buratino(int x, int y, HDC buratino) {
    txTransparentBlt (txDC(), x, y, 150, 276, buratino, 0, 0, TX_WHITE);
}

void risovat_moneta(int x, int y, HDC moneta){
    txTransparentBlt (txDC(), x, y, 156, 157, moneta,0, 0, TX_WHITE);
}
void risovat_panel(HDC panel, int monetok_s_soboi, int monetok_v_kopilke) {
    txBitBlt (txDC(), 0, 0, 1000, 1000, panel,0, 0);

    char monetok_s_soboi_stroka[100];
    sprintf(monetok_s_soboi_stroka, "%d", monetok_s_soboi);
    txSetColor(TX_BLACK);
    txSelectFont("Comic Sans MS", 60);
    txTextOut(230, 5, monetok_s_soboi_stroka);

    char monetok_v_kopilke_stroka[100];
    sprintf(monetok_v_kopilke_stroka, "%d", monetok_v_kopilke);
    txSetColor(TX_BLACK);
    txSelectFont("Comic Sans MS", 60);
    txTextOut(930, 5, monetok_v_kopilke_stroka);
}
 void risovat_kopilka(HDC kopilka){
   txTransparentBlt (txDC(), 650, 650, 230, 158, kopilka, 0, 0, TX_WHITE);
 }

void risovat_buratino_sleva(int x, int y, HDC buratino2) {
    txTransparentBlt (txDC(), x, y, 150, 276, buratino2, 0, 0, TX_WHITE);
}

