#ifndef TOWERCHOICE_H
#define TOWERCHOICE_H

#include <QDialog>
#include <QMediaPlayer>

namespace Ui {
class TowerChoice;
}

class TowerChoice : public QDialog
{
    Q_OBJECT

public:
    explicit TowerChoice(QWidget *parent = nullptr);
    ~TowerChoice();

private slots:
    void buildArrowTower();
    void buildFireBallTower();
    void buildStoneTower();
    void close_button();

private:
    Ui::TowerChoice *ui;
    QMediaPlayer * not_enough_gold;
};

#endif // TOWERCHOICE_H
