#include "dialogcolorier.h"

#include <QDebug>
#include <QColor>   // Utilisation de la classe QColor
#include <QPalette> // Utilisation de la classe QPalette pour le changement de couleur
#include <QMessageBox>



/********************** CONSTRUCTEURS *******************************************/

DialogColorier::DialogColorier(QWidget *parent, QStandardItemModel *_model) :
    QDialog(parent)
{
    setupUi(this);

    this->_model = _model;

    _model->insertColumn(1);
    _myColonneView->setModel(_model);
    _myColonneView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    _myColonneView->setSelectionBehavior(QAbstractItemView::SelectRows);

    initialiser_couleurs_disponibles();

    connect(myHorizontalSliderRouge, &QSlider::valueChanged, this, &DialogColorier::on_colorChanged );
    connect( myHorizontalSliderVert, SIGNAL( valueChanged(int)), this, SLOT( on_colorChanged()) );
    connect( myHorizontalSliderBleu, SIGNAL( valueChanged(int)), this, SLOT( on_colorChanged()) );

    connect(myPushButtonReinit, SIGNAL(pressed()), this, SLOT(on_reinitColor()));
    connect(myPushButtonAleatoire, SIGNAL(pressed()), this, SLOT(on_colorAleatoire()));
    connect(myPushButtonAppliquer, SIGNAL(pressed()), this, SLOT(on_appliquerColor()));
    connect(_myPBAllHasard, SIGNAL(pressed()), this, SLOT(on_tout_aleatoire()));
    connect(_myPBAllReinit, SIGNAL(pressed()), this, SLOT(on_tout_reinitialiser()));

    connect(_myColonneView, SIGNAL (clicked(QModelIndex)), this, SLOT(on_afficher_caseTab(QModelIndex)));
}


void DialogColorier::initialiser_couleurs_disponibles()
{
    reinit_couleurs_occupees();

    for (int ligne=0; ligne < _model->rowCount(); ligne++) {

        QModelIndex modelInd = _model->index(ligne, 0);

        QBrush brush = _model->itemFromIndex(modelInd)->background();
        QColor color = brush.color();
        int r = color.red();
        int g = color.green();
        int b = color.blue();
        adapt_colors_to_data(r, g, b);
        couleurUtilises[r][g][b] = 1;

    }
}

QStandardItemModel *DialogColorier::model()
{
    return _model;
}


/********************** SIGNAUX SLIDERS *******************************************/


void DialogColorier::on_colorChanged()
{
    // Définition et construction de la couleur en RVB représentée par les sliders
    QColor color;
    color.setRgb( myHorizontalSliderRouge->value(),
                  myHorizontalSliderVert->value(),
                  myHorizontalSliderBleu->value() );

    // La couleur est maintenant utilisée pour une couleur de fenêtre
    QPalette pal;
    pal.setColor( QPalette::Window, color );
    _myLNewColor->setPalette( pal );
    // Réinitialiser le message d'erreur
    emit on_message_erreur("");
}

/********************** SIGNAUX PUSH BUTTONS *******************************************/

void DialogColorier::on_appliquerColor()
{
    if (_currentRow < 0) {
        qDebug() << "Selectionnez une case" << endl;
        return;
    }

    int r = myHorizontalSliderRouge->value();
    int v = myHorizontalSliderVert->value();
    int b = myHorizontalSliderBleu->value();
    adapt_colors_to_data(r, v, b);

    if (couleurUtilises[r][v][b]) {
        qDebug() << "Couleur déjà utilisée";
        emit on_message_erreur("Couleur déjà utilisée");
        //emit change_text("Couleur déjà utilisée");
        qDebug() << "</" << __FUNCTION__ << ">" << endl;
        return;
    }
    couleurUtilises[r][v][b] = 1;

    // On libère l'ancienne couleur utilisée
    libererCouleur();

    QModelIndex modelInd = _model->index(_currentRow, 0);
    QColor color;
    color.setRgb(r*10, v*10, b*10);
    _model->itemFromIndex(modelInd)->setBackground(color);
    colorier_occurences(modelInd.data().toString(), color);

    updateColor();
}

void DialogColorier::on_message_erreur(QString value)
{
    _myLabelError->setText(value);
}

void DialogColorier::on_reinitColor()
{
    emit on_message_erreur("");
    libererCouleur();
}

void DialogColorier::on_colorAleatoire()
{
    if (colors_empty()) {
        // TMP faire un vrai message d'erreur
        qDebug() << "Il n'y a plus de couleurs disponibles" << endl;
        return;
    }

    int r, v, b;
    do {
        r = rand()%(25+1-0) +0;
        v = rand()%(25+1-0) +0;
        b = rand()%(25+1-0) +0;
    }
    while (couleurUtilises[r][v][b]);

    myHorizontalSliderRouge->setValue(r*10);
    myHorizontalSliderVert->setValue(v*10);
    myHorizontalSliderBleu->setValue(b*10);

    emit on_colorChanged();
}

void DialogColorier::on_tout_aleatoire()
{
    // On refait tout en aléatoire, peu importe les couleurs d'avant donc on reinitialise ce tableau
    reinit_couleurs_occupees();

    _progress = new QProgressDialog("Coloration...", "Annulation", 0, _model->rowCount(), this);
    _progress->setWindowModality(Qt::WindowModal);
    int kProgress = 0;

    for (int ligne=0; ligne < _model->rowCount(); ligne++)
    {
        if (_progress->wasCanceled()) {
            on_tout_reinitialiser();
            return;
        }
        if (colors_empty()) {
            _progress->cancel();
            // TMP faire un vrai message d'erreur
            qDebug() << "Il n'y a plus de couleurs disponibles" << endl;
            reinit_couleurs_occupees();
            return;
        }
        QModelIndex modelInd = _model->index(ligne, 0);
        int r, v, b;
        do {
            if (_progress->wasCanceled()) {
                on_tout_reinitialiser();
                return;
            }
            r = rand()%(25+1-0) +0;
            v = rand()%(25+1-0) +0;
            b = rand()%(25+1-0) +0;
        }
        while (couleurUtilises[r][v][b]);
        couleurUtilises[r][v][b] = 1;
        QColor color;
        color.setRgb( r*10, v*10, b*10 );
        _model->itemFromIndex(modelInd)->setBackground(QColor (color));
        colorier_occurences(modelInd.data().toString(), color);

        kProgress++;
        _progress->setValue(kProgress);
    }

    updateColor();
    emit on_message_erreur("");
}


void DialogColorier::on_tout_reinitialiser()
{
    // On refait tout en aléatoire, peu importe les couleurs d'avant donc on reinitialise ce tableau
    reinit_couleurs_occupees();

    for (int ligne=0; ligne < _model->rowCount(); ligne++)
    {
        QModelIndex modelInd = _model->index(ligne, 0);
        QBrush brush;
        _model->itemFromIndex(modelInd)->setBackground(brush);
    }

    updateColor();
    emit on_message_erreur("");
}



/************************** SIGNAUX QTABLEVIEW *********************************/

void DialogColorier::on_afficher_caseTab(QModelIndex _myIndex)
{
    if (_myIndex.column() != 0) return;

    _currentRow = _myIndex.row();
    QModelIndex modelInd = _model->index(_myIndex.row(),_myIndex.column());

    QString val = modelInd.data().toString();
    _myLOldColor->setText(val);

    updateColor();
}


/****************************** UTILITAIRES *******************************/

/*-------------------------------------------------------------------------------------
 * Prend en entrée les couleurs brutes, et les divise par 10 pour accéder au
 * bon indice dans le tableau de stockage @couleurUtilises
 * ------------------------------------------------------------------------------------*/
void DialogColorier::adapt_colors_to_data(int &color_r, int &color_v, int &color_b)
{
    color_r = color_r/10;
    color_v = color_v/10;
    color_b = color_b/10;
}

int DialogColorier::colors_empty()
{
    for (int r=0; r<=25; r++) {
        for (int v=0; v<=25; v++) {
            for (int b=0; b<=25; b++) {
                if (!couleurUtilises[r][v][b]) return 0;
            }
        }
    }
    return 1;
}

/*-------------------------------------------------------------------------------------
 * Colorie toutes les cases avec la couleur @color
 * pour toutes les occurences @val dans @_myColonneView
 * ------------------------------------------------------------------------------------*/
void DialogColorier::colorier_occurences(QString val, QColor color)
{
    for (int ligne=0; ligne < _model->rowCount(); ligne++)
    {
        QModelIndex modelInd = _model->index(ligne, 0);
        QString valLigne = modelInd.data().toString();
        if (QString::compare(val, valLigne) == 0) {
            _model->itemFromIndex(modelInd)->setBackground(QColor (color));
        }
    }
}

/*-------------------------------------------------------------------------------------
 * Réinitialise la couleur de toutes les cases (QBrush vide) pour toutes
 * les occurences @val dans @_myColonneView
 * ------------------------------------------------------------------------------------*/
void DialogColorier::reinit_occurences(QString val)
{
    QBrush brushNot;
    for (int ligne=0; ligne < _model->rowCount(); ligne++)
    {
        QModelIndex modelInd = _model->index(ligne, 0);
        QString valLigne = modelInd.data().toString();
        if (QString::compare(val, valLigne) == 0) {
            _model->itemFromIndex(modelInd)->setBackground(brushNot);
        }
    }
}

/*---------------------------------------------------------------------------------------------------
 * Libère la couleur dans @couleurUtilises de la case de @_myColonneView à la position @_currentRow,
 * et réinitialise l'affichage pour elle-même et toutes ses occurences.
 * -------------------------------------------------------------------------------------------------*/
void DialogColorier::libererCouleur()
{
    QPalette pal;
    // La palette n'est pas initialisée afin de rendre les couleurs d'origine à l'objet où cette fonction s'applique.
    _myLOldColor->setPalette( pal );

    QModelIndex modelInd = _model->index(_currentRow, 0);
    QBrush brush = _model->itemFromIndex(modelInd)->background();
    QColor color = brush.color();
    int oldR = color.red();
    int oldV = color.green();
    int oldB = color.blue();
    adapt_colors_to_data(oldR, oldV, oldB);
    couleurUtilises[oldR][oldV][oldB] = 0;
    reinit_occurences(modelInd.data().toString());
    updateColor();
}

/*---------------------------------------------------------------------------------------------------
 * Met à jour l'affichage de @_myLOldColor
 * -------------------------------------------------------------------------------------------------*/
void DialogColorier::updateColor()
{
    QModelIndex modelInd = _model->index(_currentRow, 0);
    QBrush brush = _model->itemFromIndex(modelInd)->background();
    QColor color = brush.color();

    QPalette pal;
    if (color.red()!=0 || color.green()!=0 || color.blue()!=0) {
        pal.setColor( QPalette::Window, color );
    }
    _myLOldColor->setPalette( pal );
}


void DialogColorier::reinit_couleurs_occupees()
{
    for (int r=0; r<=25; r++) {
        for (int v=0; v<=25; v++) {
            for (int b=0; b<=25; b++) {
                couleurUtilises[r][v][b] = 0;
            }
        }
    }
}

void DialogColorier::mousePressEvent(QMouseEvent *event)
{
    // left click
    if(event->button() == Qt::LeftButton)
    {
       emit on_message_erreur("");
    }
}




























