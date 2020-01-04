#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;
#include "functions.h"
#include<string>
using namespace std;

int main()
{
    srand(time(0)); int snakeLength=3; int direction=5; snakeUnits u[300]; fruit f; obstacle obs[80];
    Texture background, unit, fru, paus, start, gameOver,obstacle,victory;
    background.loadFromFile("background.png");
    unit.loadFromFile("red.png"); fru.loadFromFile("green.png"); paus.loadFromFile("pause.png"); start.loadFromFile("start.png");
    gameOver.loadFromFile("gameOver.png"); obstacle.loadFromFile("obstacle.png"); victory.loadFromFile("victory.png");
    Sprite sprite1(background); Sprite sprite2(unit); Sprite sprite3(fru); Sprite sprite4(paus); Sprite sprite5(start);
    Sprite sprite6(gameOver); Sprite sprite7(obstacle); Sprite sprite8(victory);
    Font fot; fot.loadFromFile("arial.ttf");
    Text txt1, txt2, txt3, txt4;
    txt1.setFont(fot); txt2.setFont(fot); txt3.setFont(fot); txt4.setFont(fot);
    int score =0;
    string scre= to_string(score);
    txt1.setString(scre);
    txt2.setString("Score:");
    txt3.setString("press P to pause");
    txt4.setString("target:20");

    int winFlag=0; int fruFlag; int pause=0; int gameoverflag=0;

    //initial u[0]
    u[0].x=5; u[0].y=7;

    //initial u[1]
    u[1].x=5; u[1].y=6;

    //initial u[2]
    u[2].x=5; u[2].y=5;
    //initial f
    f.x=15; f.y=15;
    //the obstacles
    // firstly, the vertical obstacles
    for(int i=0;i<7;i++)
    {
        obs[i].x=0; obs[i].y=i;
    }
    int yCordin=23;
    for(int i=7;i<14;i++)
    {
        obs[i].x=0; obs[i].y=yCordin;
        yCordin++;
    }
    int yCordin2=0;
    for(int i=14;i<21;i++)
    {
        obs[i].x=29; obs[i].y=yCordin2;
        yCordin2++;
    }
    int yCordin3=23;
    for(int i=21;i<28;i++)
    {
        obs[i].x=29; obs[i].y=yCordin3;
        yCordin3++;
    }
    //second, the horizontal obstacles
    int xCordin=1;
    for(int i=28;i<34;i++)
    {
        obs[i].x=xCordin; obs[i].y=0;
        xCordin++;
    }
    int xCordin2=23;
    for(int i=34;i<40;i++)
    {
        obs[i].x=xCordin2; obs[i].y=0;
        xCordin2++;
    }
    int xCordin3=1;
    for(int i=40;i<46;i++)
    {
        obs[i].x=xCordin3; obs[i].y=29;
        xCordin3++;
    }
    int xCordin4=23;
    for(int i=46;i<52;i++)
    {
        obs[i].x=xCordin4; obs[i].y=29;
        xCordin4++;
    }
    //the two obstacles in the center
    int xCordin5=7;
    for(int i=52;i<66;i++)
    {
        obs[i].x=xCordin5; obs[i].y=9;
        xCordin5++;
    }
    int xCordin6=7;
    for(int i=66;i<80;i++)
    {
        obs[i].x=xCordin6; obs[i].y=18;
        xCordin6++;
    }


    Clock clk; float timer=0, delay=.1;

    RenderWindow window(VideoMode(960,960), "Snake Game",Style::Close );

    while (window.isOpen())
    {
        // updating the window after each .1 s
        float time=clk.getElapsedTime().asSeconds();
        clk.restart();
        timer+=time;

        // controlling the window
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
            {
                window.close();
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            pause=0; direction=1;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            pause=0; direction=2;
        }
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            pause=0; direction=3;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            pause=0; direction=0;
        }
        if (Keyboard::isKeyPressed(Keyboard::P))
        {
            pause=1;
        }
        if (Keyboard::isKeyPressed(Keyboard::R))
        {
            gameoverflag=0;
            winFlag=0;
            snakeLength=3;
            direction=5;
            score=0;
            delay=.1;
            scre= to_string(score);
            txt1.setString(scre);
            u[0].x=5; u[0].y=7;
            u[1].x=5; u[1].y=6;
            u[2].x=5; u[2].y=5;
            f.x=15; f.y=15;
        }

        if(timer>delay)
        {
            timer=0;

            if((pause==0)&&(gameoverflag==0)&&(winFlag==0))
            {
                // update();
                if (direction!=5)
                {

                    for (int i=snakeLength-1;i>0;--i)
                    {
                        u[i].x=u[i-1].x; u[i].y=u[i-1].y;
                    }

                    if ((direction==0)&&((u[2].y-u[1].y)!=1))
                    {
                        u[0].y+=1;
                    }else if((direction==0)&&((u[2].y-u[1].y)==1))
                    {
                        u[0].y-=1;
                    }
                    if ((direction==1)&&((u[1].x-u[2].x)!=1))
                    {
                        u[0].x-=1;
                    }else if ((direction==1)&&((u[1].x-u[2].x)==1))
                    {
                        u[0].x+=1;
                    }
                    if ((direction==2)&&((u[2].x-u[1].x)!=1))
                    {
                        u[0].x+=1;
                    }else if ((direction==2)&&((u[2].x-u[1].x)==1))
                    {
                        u[0].x-=1;
                    }
                    if ((direction==3)&&((u[1].y-u[2].y)!=1))
                    {
                        u[0].y-=1;
                    }else if((direction==3)&&((u[1].y-u[2].y)==1))
                    {
                        u[0].y+=1;
                    }

                    if (u[0].x>29){ u[0].x=0;}
                    if (u[0].x<0) { u[0].x=29;}
                    if (u[0].y>29){ u[0].y=0;}
                    if (u[0].y<0) { u[0].y=29;}

                    if ((u[0].x==f.x) && (u[0].y==f.y))
                    {
                        snakeLength++; u[snakeLength-1].x=u[snakeLength-2].x; u[snakeLength-1].y=u[snakeLength-2].y;
                        score++; scre= to_string(score); txt1.setString(scre);
                        fruFlag=1;
                            while(fruFlag==1)
                            {
                                fruFlag=0;
                                f.y=rand()%29 + 0; f.x=rand() % 29 + 0;
                                for (int i=0;i<snakeLength;i++)
                                {
                                    if ((f.x==u[i].x) && (f.y==u[i].y))
                                    {
                                        fruFlag=1;
                                    }
                                }
                                for (int i=0;i<80;i++)
                                {
                                    if((f.x==obs[i].x) && (f.y==obs[i].y))
                                    {
                                        fruFlag=1;
                                    }

                                }
                            }
                    }


                    //game over places
                    for (int i=1;i<snakeLength;i++)
                    {
                        if (u[0].x==u[i].x && u[0].y==u[i].y)
                        {
                            gameoverflag=1;
                        }
                    }
                    for (int i=0;i<80;i++)
                    {
                        if(u[0].x==obs[i].x && u[0].y==obs[i].y)
                        {
                            gameoverflag=1;
                        }
                    }
                    //speed levels of the game
                    //level 2
                    if(score==5)
                    {
                        delay=.08;
                    }
                    //level 3
                    if(score==10)
                    {
                        delay=.06;
                    }
                    //level 4
                    if(score==18)
                    {
                        delay=.05;
                    }

                    //winning time
                    if(score==20)
                    {
                        winFlag=1;
                    }

                }
            }
        }

        window.clear();
        // draw //
        window.draw(sprite1);
        window.draw(sprite7);


        for (int i=0;i<snakeLength;i++)
        {
            sprite2.setPosition(u[i].x*32, u[i].y*32);  window.draw(sprite2);
        }

        sprite3.setPosition(f.x*32,f.y*32); window.draw(sprite3);

        txt1.setCharacterSize(28); txt2.setCharacterSize(25); txt1.setPosition(32*2.5,0);
        window.draw(txt1); window.draw(txt2);
        txt3.setCharacterSize(25); txt3.setPosition(32*23.3,0);
        window.draw(txt3);
        txt4.setCharacterSize(25); txt4.setPosition(32*3.5,0);
        window.draw(txt4);

        if(pause!=0)
        {
            window.draw(sprite4);
        }

        if ((direction==5)&&(gameoverflag==0)&&(winFlag==0))
        {
            window.draw(sprite5);
        }
        if (gameoverflag==1)
        {
            window.draw(sprite6);
        }
        if(winFlag==1)
        {
            window.draw(sprite8);
        }

        window.display();
    }

    return 0;
}

