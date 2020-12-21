QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src\Arrow.cpp \
    src\ArrowTower.cpp \
    src\Base.cpp \
    src\Biggoblin.cpp \
    src\Bone.cpp \
    src\Chat.cpp \
    src\Enemy.cpp \
    src\Fireball.cpp \
    src\Freballtower.cpp \
    src\Goblin.cpp \
    src\Health.cpp \
    src\Info.cpp \
    src\InfoIcon.cpp \
    src\Pausebutton.cpp \
    src\Skeleton.cpp \
    src\Stonebullet.cpp \
    src\Stonetower.cpp \
    src\Tower.cpp \
    src\Towerbuilder.cpp \
    src\Towerupgrade.cpp \
    src\UpdateHelper.cpp \
    src\game.cpp \
    src\gold.cpp \
    src\main.cpp \
    src\mainwindow.cpp \
    src\mapinfo.cpp \
    src\towerchoice.cpp

HEADERS += \
    src\Arrow.h \
    src\ArrowTower.h \
    src\Base.h \
    src\Biggoblin.h \
    src\Bone.h \
    src\Chat.h \
    src\Enemy.h \
    src\EnemyPoints.h \
    src\Fireball.h \
    src\Fireballtower.h \
    src\Goblin.h \
    src\Health.h \
    src\Info.h \
    src\InfoIcon.h \
    src\Pausebutton.h \
    src\Skeleton.h \
    src\Stonebullet.h \
    src\Stonetower.h \
    src\Tower.h \
    src\Towerbuilder.h \
    src\Towerupgrade.h \
    src\UpdateHelper.h \
    src\Upgrades.h \
    src\game.h \
    src\gold.h \
    src\mainwindow.h \
    src\mapinfo.h \
    src\towerchoice.h \
    src\Upgrades.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES += \
    .gitignore \
    towerBuilder.png

FORMS += \
    info.ui \
    mainwindow.ui \
    towerchoice.ui \
    towerupgrade.ui
