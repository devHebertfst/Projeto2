#include "trem.h"
#include <QtCore>
#include <QMutex>


QSemaphore semaforo0(1);
QSemaphore semaforo1(1);
QSemaphore semaforo2(1);
QSemaphore semaforo3(1);
QSemaphore semaforo4(1);
QSemaphore semaforo5(1);
QSemaphore semaforo6(1);
QSemaphore semaforo7(2);
QSemaphore semaforo8(2);
QSemaphore semaforo9(2);
QSemaphore semaforo10(3);

//Construtor
Trem::Trem(int ID, int x, int y)
{
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}


//Função a ser executada após executar trem->START
void Trem::run()
{
    while (true)
    {
        switch (ID)
        {
        case 1: //Trem 1

            // Quero entrar na Via 0
            if (x == 530 && y == 110){
                semaforo10.acquire();
                semaforo8.acquire();
                semaforo0.acquire();
            }

            // Estou na Via 0 e quero ir para a VIA 2
            if (x == 550 && y == 210){
                semaforo7.acquire();
                semaforo2.acquire();

            }
            // Deixando a Via 0
            if(x == 530 && y == 230){
                semaforo8.release();
                semaforo0.release();
            }

            // Estou na Via 2 e quero ir para a Via 1
            if(x == 440 && y == 230){
                semaforo10.release();
                semaforo1.acquire();
            }

            // Entrei na Via 1 e Liberei a Via 2
            if(x == 400 && y == 230){
                semaforo7.release();
                semaforo2.release();
            }

            // Deixando a Via  1
            if(x == 280 && y == 210){
                semaforo1.release();

            }

            // Movimentação do TREM 5
            if(getVelocidade() == 200){
                break;
            }
            if(getVelocidade() == 200)
                break;
            if (y == 110 && x <550)
                x+=10;
            else if (x == 550 && y < 230)
                y+=10;
            else if (x > 280 && y == 230)
                x-=10;
            else
                y-=10;

           emit updateGUI(ID, x,y);    //Emite um sinal
           break;

        case 2: //Trem 2

            // Quero entrar na Via 4
            if (x == 820 && y ==210){
                semaforo10.acquire();
                semaforo9.acquire();
                semaforo4.acquire();
            }
            // Estou na VIa 4 e quero entrar na Via 3
            if (x == 710 && y == 230){
                semaforo8.acquire();
                semaforo3.acquire();
            }

            // Deixei a Via 4 e estou na Via 3
            if (x == 670 && y == 230){
                semaforo9.release();
                semaforo4.release();
            }

            // Estou na VIa 3 e quero entrar na Via 0
            if (x ==570 && y == 230){
                semaforo0.acquire();
            }

            // Estou deixando a Via 3
            if (x == 550 && y == 210){
                semaforo10.release();
                semaforo3.release();
                semaforo8.release();
            }

            // Estou deixando a via 0
            if (x == 570 && y == 110){
                semaforo0.release();
            }


            // Movimentação do TREM 4
            if(getVelocidade() == 200){
                break;
            }
            if (y == 110 && x <820)
                x+=10;
            else if (x ==820 && y < 230)
                y+=10;
            else if (x > 550 && y == 230)
                x-=10;
            else
                y-=10;

            emit updateGUI(ID, x,y);    //Emite um sinal
            break;

        case 3: //Trem 3

            // Quero entrar na Via 1
            if (x == 260 && y == 230){
                semaforo10.acquire();
                semaforo7.acquire();
                semaforo1.acquire();
            }

            // Estou na Via 1 e quero entrar na Via 5
            if (x == 400 && y == 230){
                semaforo5.acquire();
            }

            // Estou na Via 5 e libero a Via 1
            if (x == 420 && y == 250){
                semaforo10.release();
                semaforo7.release();
                semaforo1.release();
            }

            // Libero a Via 5
            if (x == 400 && y == 350){
                semaforo5.release();
            }

            // Movimentaçãodo TREM 3
            if(getVelocidade() == 200){
                break;
            }
            if (y == 230 && x < 420)
                x+=10;
            else if (x == 420 && y < 350)
                y+=10;
            else if (x > 150 && y == 350)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;

        case 4: //Trem 4

            // Na porta de saída para entrar na VIA 5
            if (x == 440 && y == 350){
                semaforo10.acquire();
                semaforo7.acquire();
                semaforo5.acquire();
            }
            // Quero sair da Via 5 e entrar na Via 2
            if (x == 420 && y == 250){
                semaforo8.acquire();
                semaforo2.acquire();
             }
            // Estou na Via 2 e vou liberar a Via 5
            if (x == 440 && y == 230){
                semaforo7.release();
                semaforo5.release();
            }

            // Quero sair da Via 2 e entrar na Via 3
            if (x == 530 && y == 230){
                semaforo9.acquire();
                semaforo3.acquire();
            }

            // Estou na via 3 e vou liberar a Via 2
            if (x ==  570 && y == 230){
                semaforo10.release();
                semaforo8.release();
                semaforo2.release();
            }

            // QUERO Sair da Via 3 e entrar na Via 6
            if (x == 670 && y == 230){
                semaforo6.acquire();
            }

            // Estou na Via 6 e libero a Via 3
            if (x ==  690 && y == 250){
                semaforo9.release();
                semaforo3.release();
            }

            // Libero a Via 6
            if (x ==  670 && y == 350){
                semaforo6.release();
            }

            // Movimentação do TREM 2
            if(getVelocidade() == 200)
                break;

            if (y == 230 && x < 690)
                x+=10;
            else if (x == 690 && y < 350)
                y+=10;
            else if (x > 420 && y == 350)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;

        case 5:
            //Trem 1
            // Quero entrar na Via 6
            if (x == 710 && y == 350){
                semaforo10.acquire();
                semaforo9.acquire();
                semaforo6.acquire();

            }
            // Quero sair da Via 6 entrar na Via 4
            if (x ==  690 && y == 250){
               semaforo4.acquire();

            }
            // Sai da Via 6
            if (x == 710 && y == 230){
                semaforo10.release();
                semaforo9.release();
                semaforo6.release();
            }
            // Sai da Via 4
            if (x ==  840 && y == 230){
                semaforo4.release();
            }
            // Movimentação do TREM 5
            if(getVelocidade() == 200)
                break;
            if (y == 230 && x <960)
                x+=10;
            else if (x == 960 && y < 350)
                y+=10;
            else if (x > 690 && y == 350)
                x-=10;
            else
                y-=10;

            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}
void Trem::setVelocidade(int velocidade){
    this->velocidade = velocidade;
}

int Trem::getVelocidade(){
    return velocidade;
}
