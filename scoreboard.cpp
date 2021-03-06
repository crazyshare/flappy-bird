#include "scoreboard.h"
#include"widget.h"
ScoreBoard::ScoreBoard():board(Res::User->res->score_board)
{
    auto & p=Res::User;
    layer=LAYER_TOP-1;
    over=p->res->nullimg;
    x_over=p->width()/2;
    y_over=p->height()/2-185;
    x_board=x_over;
    x_play=x_board;
    y_play=p->height()-230;
    y_board=p->height()+35;
    p->AddToSubThread(layer,this);
    play=Res::User->res->nullimg;
}

ScoreBoard::~ScoreBoard()
{

}



void ScoreBoard::frame()
{
    auto & User=Res::User;
    if(timer==29)
    {
        emit User->SoundSig(MYSOUND::PANEL);
    }
    else if(timer>=30&&timer<40)
    {
        y_over=User->height()/2-150+(timer-35)*(timer-35)*0.5;
    }
    else if(timer==60)
    {
        emit User->SoundSig(MYSOUND::PANEL);
    }
    else if(timer>60&&timer<=102)
    {
         y_board-=10;
    }
    else if(timer==130)
    {
        //

    }
    else if(timer>170)
        task=false;
    if(timer>110&&timer2<30)
    {
        timer2++;
    }
    timer++;
}

void ScoreBoard::show(QPainter & p)
{
    auto & User=Res::User;
    if(timer>30)
    {
        if(timer<40)
        {
            over=User->tools->SetAlgha(User->res->game_over,15+24*(timer-30));
        }
        DrawPixmapAtCenter(x_over,y_over,over,p);
    }
    if(timer>60)
    {
        DrawPixmapAtCenter(x_board,y_board,board,p);
    }
    if(timer>130)
    {
        if(timer<170)
        {
            play=User->tools->SetAlgha(User->res->button_play,15+6*(timer-130));
        }
        DrawPixmapAtCenter(x_play,y_play,play,p);
    }
    if(timer>110)
    {
        User->socre->ShowResult(p);
    }
}

void ScoreBoard::gameover()
{
    return;
}

void ScoreBoard::restart()
{
    del_flag=true;
}
