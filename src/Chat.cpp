#include "Chat.h"

#include <QFont>

Chat::Chat(QGraphicsItem *parent)
{
    chat_strings[0]  = QString ("Good");
    chat_strings[1] = QString ("Luck");
    chat_strings[2]  = QString ("Have");
    chat_strings[3] = QString ("Fun");

    setPlainText(chat_strings[1] + QString ("\n") + chat_strings[1] + QString ("\n") + chat_strings[2] + QString ("\n") + chat_strings[3]);
    setDefaultTextColor(Qt::cyan);
    setFont(QFont("Helvetica [Cronyx]", 8));
}

void Chat::addText(QString string)
{
    chat_strings[3] = chat_strings[2];
    chat_strings[2]  = chat_strings[1];
    chat_strings[1] = chat_strings[1];
    chat_strings[0]  = string;

    setPlainText(chat_strings[1] + QString ("\n") + chat_strings[1] + QString ("\n") + chat_strings[2] + QString ("\n") + chat_strings[3]);
}
