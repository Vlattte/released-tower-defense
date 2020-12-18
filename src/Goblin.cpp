#include "Goblin.h"
#include "Biggoblin.h"
#include "Skeleton.h"
#include "Base.h"
#include "game.h"
#include "mainwindow.h"

extern Game * game;
extern MainWindow * window;

#include <QPointF>
#include <QLineF>
#include <QVector>
#include <QPixmap>
#include <qmath.h>
#include <QTimer>
#include <QMessageBox>


Goblin::Goblin(QGraphicsItem* parent)
{
    //========================set=sounds==========================
    enemy_pain = new QMediaPlayer();
    enemy_pain->setMedia(QUrl("qrc:/sounds/sounds/goblin_pain.wav"));
    enemy_pain->setVolume(20);

    //set sounds of victory
    victory = new QMediaPlayer();
    victory->setMedia(QUrl("qrc:/sounds/sounds/its_victory.mp3"));

    //set sounds of lose
    lose = new QMediaPlayer();
    lose->setMedia(QUrl("qrc:/sounds/sounds/loser.mp3"));
    //============================================================

    //============================basic=values====================
    enemy_health = 3;
    gold_for_kill = 50;
    //============================================================

    //================set=the=picture=of=the=enemy================
    setPixmap(QPixmap(":/images/images/goblin.png"));
    //============================================================

    //===============show=health=of=enemy=above=his=head==========
    health_label->setText(QString::number(enemy_health));
    health_label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    health_label->setAlignment(Qt::AlignBottom | Qt::AlignRight);

    QPointF position = mapToScene(pos());
    int labelX = position.x() + 25;
    int labelY = position.y() - 10;
    health_label->move(labelX, labelY);
    //============================================================

    //====================rotate=to=the=point=====================
    chooseWay();

    if (random_dest == 1)
    {
          FP = game->settings.variety.bottom_way;
    }
    else if (random_dest == 2)
    {
          FP = game->settings.variety.upper_way;
    }

    if (way_num == 1)
    {
        setPos(FP.start);
        list_of_points << FP.a0 << FP.a1 << FP.a2
                       << FP.a3 << FP.a << FP.b << FP.c << FP.d << FP.e << FP.f
                       << FP.g << FP.h << FP.i << FP.j << game->settings.variety.finish;
    }
    else if (way_num == 2)
    {
        for (int i = 0; i < 5; ++i)
        {
            list_of_points << game->settings.variety.special_point[i]; //easy bottom way
        }
        if (game->mn == second_map)
        {
            FP = game->settings.variety.bottom_way;
            list_of_points << FP.a << FP.b << FP.c << FP.d << FP.e << FP.f
                           << FP.g << FP.h << FP.i << FP.j;
        }
        list_of_points << game->settings.variety.finish;
    }

    point_index = 0;
    destination = list_of_points[0];
    rotate(destination);
    //============================================================

    //=====================make=the=enemy=move====================
    QTimer * move_timer = new QTimer(this);
    connect (move_timer, SIGNAL(timeout()), this, SLOT(move()));
    move_timer->start(100);
    //============================================================
}

Goblin::~Goblin()
{
    delete enemy_pain;
    delete victory;
    delete lose;
}

void Goblin::move()
{
    if (game->pause == 1)
    {
        //-------------------moving process-----------------------
            QLineF line (QPointF(pos()), destination);
            if (line.length() < 10)
            {
                point_index++;
                if(point_index >= list_of_points.size())
                {
                    return;
                }
                destination = list_of_points[point_index];
                rotate(destination);
            }

            int step = 10;
            double alpha = rotation();

            double dx = step * qCos(qDegreesToRadians(alpha));
            double dy = step * qSin(qDegreesToRadians(alpha));

            setPos(x()+dx, y()+dy);

            QPointF position = mapToScene(pos());
            int labelX = position.x() + 25;
            int labelY = position.y() - 10;
            health_label->move(labelX, labelY);
        //---------------------------------------------------------

        //kill the enemy and decrease base's health if they collide
            QList <QGraphicsItem *> colliding_items = collidingItems();
            for (int i = 0; i < colliding_items.size(); ++i)
            {
                if (typeid(*(colliding_items[i])) == typeid(Base))
                {
                    game->scene->removeItem(this);
                    game->base_health->decrease(getHealth());

                    QList<QGraphicsItem *> list = game->scene->items();
                    int count_enemies = 0;

                    for (int i = 0; i < list.size() - 1; ++i)
                    {
                        if (typeid(*(list[i])) == typeid(Goblin) ||
                            typeid(*(list[i])) == typeid(BigGoblin)||
                            typeid(*(list[i])) == typeid (Skeleton))
                        {
                            count_enemies++;
                        }
                    }
                    //if you lose, game will be finished
                    if (game->base_health->getHealth() <= 0)
                    {
                        game->pause = -1;
                        lose->play();

                        //game over event
                        QMessageBox::StandardButton reply =
                        QMessageBox::question(game, "GAME OVER", "Would you like to try again?",
                                              QMessageBox::Yes | QMessageBox::No);

                        //ask for restarting the game
                        if (reply == QMessageBox::No)
                        {
                            game->scene->clear();
                            game->close();
                        }
                        else
                        {
                            game->scene->clear();
                            game->close();
                            game = new Game(game->mn);
                            game->show();
                        }
                    }

                    //if there are not enemies on scene
                    if (count_enemies == 0 && game->spawn_number[game->index] <= 0)
                    {
                        if (game->index == 3)
                        {
                            game->pause = -1;
                            victory->play();
                            game->chat->addText("You killed anyone!");
                            game->chat->addText("You are the best!!");
                            game->chat->addText("You saved all of us!!!");
                            game->chat->addText("Thank you for playing this game <3");

                            //restart window
                            game->reply =
                            QMessageBox::question(game, "Victory!", "Would you like to win again?",
                                                  QMessageBox::Yes | QMessageBox::No);

                            //ask for restarting the game
                            if (game->reply == QMessageBox::No)
                            {
                                game->scene->clear();
                                game->close();
                            }
                            else
                            {
                                game->scene->clear();
                                game->close();
                                game = new Game(game->mn);
                                game->show();
                            }
                        }
                        else
                        {
                            game->wave_change_ability = true;
                        }
                     }

                    //clear memory
                    delete health_label;
                    delete this;
                }
            }
        //---------------------------------------------------------

    }
}

void Goblin::closing()
{
    game->close();
}
