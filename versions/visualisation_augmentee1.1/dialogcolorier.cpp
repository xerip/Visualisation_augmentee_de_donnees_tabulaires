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

    // TEST
    connect(_myColonneView, SIGNAL (clicked(QModelIndex)), this, SLOT(on_afficher_caseTab(QModelIndex)));
}


void DialogColorier::initialiser_couleurs_disponibles()
{
    qDebug() << "<" << __FUNCTION__ << ">" << endl;

    for (int r=0; r<=25; r++) {
        for (int v=0; v<=25; v++) {
            for (int b=0; b<=25; b++) {
                couleurUtilises[r][v][b] = 0;
            }
        }
    }

    qDebug() << "nombre de lignes = " << _model->rowCount();
    //tabAttribCouleur = new attribCouleur[_model->rowCount()];

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

    for (int ligne=0; ligne < _model->rowCount(); ligne++) {
        /*
        qDebug() << "tabAttribCouleur[" << ligne << "].idRow = " << tabAttribCouleur[ligne].idRow;
        qDebug() << "tabAttribCouleur[" << ligne << "].r = " << tabAttribCouleur[ligne].r;
        qDebug() << "tabAttribCouleur[" << ligne << "].g = " << tabAttribCouleur[ligne].g;
        qDebug() << "tabAttribCouleur[" << ligne << "].b = " << tabAttribCouleur[ligne].b;
        */
    }

    qDebug() << "</" << __FUNCTION__ << ">" << endl;
}

QStandardItemModel *DialogColorier::model()
{
    return _model;
}


/********************** SIGNAUX SLIDERS *******************************************/


void DialogColorier::on_colorChanged()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();

    // Définition et construction de la couleur en RVB représentée par les sliders
    QColor color;
    color.setRgb( myHorizontalSliderRouge->value(),
                  myHorizontalSliderVert->value(),
                  myHorizontalSliderBleu->value() );

    qDebug() << "The color is" << color;
    // La couleur est maintenant utilisée pour une couleur de fenêtre
    QPalette pal;
    pal.setColor( QPalette::Window, color );
    //_myLOldColor->setPalette( pal );
    _myLNewColor->setPalette( pal );
}

/********************** SIGNAUX PUSH BUTTONS *******************************************/

void DialogColorier::on_appliquerColor()
{
    qDebug() << "<" << __FUNCTION__ << ">" << endl;
    qDebug() << __FUNCTION__ << "The event sender is" << sender();

    if (_currentRow < 0) {
        qDebug() << "Selectionnez une case" << endl;
        qDebug() << "</" << __FUNCTION__ << ">" << endl;
        return;
    }

    int r = myHorizontalSliderRouge->value();
    int v = myHorizontalSliderVert->value();
    int b = myHorizontalSliderBleu->value();
    adapt_colors_to_data(r, v, b);
    qDebug() << "r = " << r << "v = " << v << "b = " << b << endl;

    if (couleurUtilises[r][v][b]) {
        qDebug() << "Couleur déjà utilisée";
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


    /*
    // FAIRE EN SORTE DE PASSER SUR LA LIGNE SUIVANTE ET DE DONC METTRE A JOUR _currentRow
    if (_currentRow >= _model->rowCount()-1)
        _currentRow = 0;
    else
        _currentRow++;

    QModelIndex index = _model->index(_currentRow, 0);
    emit _myColonneView->clicked(index);
    */

    qDebug() << "</" << __FUNCTION__ << ">" << endl;
}

void DialogColorier::on_reinitColor()
{
    qDebug() << "<" << __FUNCTION__ << ">" << endl;
    qDebug() << __FUNCTION__ << "The event sender is" << sender();

    libererCouleur();
}

void DialogColorier::on_colorAleatoire()
{
    qDebug() << "<" << __FUNCTION__ << ">" << endl;

    if (colors_empty()) {
        // TMP faire un vrai message d'erreur
        qDebug() << "Il n'y a plus de couleurs disponibles" << endl;
        return;
    }

    int r, v, b;
    r = rand()%(25+1-0) +0;
    v = rand()%(25+1-0) +0;
    b = rand()%(25+1-0) +0;
    // Si couleur déjà prise
    if (couleurUtilises[r][v][b]) {
        // On cherche itérativement une autre couleur qui soit libre.
        trouverPremiereCouleurLibre(r, v, b);
    }

    qDebug() << "r = " << r << "v = " << v << "b = " << b << endl;

    myHorizontalSliderRouge->setValue(r*10);
    myHorizontalSliderVert->setValue(v*10);
    myHorizontalSliderBleu->setValue(b*10);

    emit on_colorChanged();

    qDebug() << "</" << __FUNCTION__ << ">" << endl;
}

void DialogColorier::on_tout_aleatoire()
{
    qDebug() << "<" << __FUNCTION__ << ">" << endl;

    // On refait tout en aléatoire, peu importe les couleurs d'avant donc on reinitialise ce tableau
    for (int r=0; r<=25; r++) {
        for (int v=0; v<=25; v++) {
            for (int b=0; b<=25; b++) {
                couleurUtilises[r][v][b] = 0;
            }
        }
    }

    for (int ligne=0; ligne < _model->rowCount(); ligne++)
    {
        if (colors_empty()) {
            // TMP faire un vrai message d'erreur
            qDebug() << "Il n'y a plus de couleurs disponibles" << endl;
            return;
        }
        QModelIndex modelInd = _model->index(ligne, 0);
        int r, v, b;
        r = rand()%(25+1-0) +0;
        v = rand()%(25+1-0) +0;
        b = rand()%(25+1-0) +0;
        // Si couleur déjà prise
        if (couleurUtilises[r][v][b]) {
            // On cherche itérativement une autre couleur qui soit libre.
            trouverPremiereCouleurLibre(r, v, b);
        }
        couleurUtilises[r][v][b] = 1;
        //qDebug() << "i = " << i << "r = " << r << "v = " << v << "b = " << b << endl;
        QColor color;
        color.setRgb( r*10, v*10, b*10 );
        _model->itemFromIndex(modelInd)->setBackground(QColor (color));
        colorier_occurences(modelInd.data().toString(), color);
    }

    updateColor();

    qDebug() << "</" << __FUNCTION__ << ">" << endl;
}


void DialogColorier::on_tout_reinitialiser()
{
    qDebug() << "<" << __FUNCTION__ << ">" << endl;

    // On refait tout en aléatoire, peu importe les couleurs d'avant donc on reinitialise ce tableau
    for (int r=0; r<=25; r++) {
        for (int v=0; v<=25; v++) {
            for (int b=0; b<=25; b++) {
                couleurUtilises[r][v][b] = 0;
            }
        }
    }

    for (int ligne=0; ligne < _model->rowCount(); ligne++)
    {
        QModelIndex modelInd = _model->index(ligne, 0);
        QBrush brush;
        _model->itemFromIndex(modelInd)->setBackground(brush);
    }

    updateColor();

    qDebug() << "</" << __FUNCTION__ << ">" << endl;
}



/************************** SIGNAUX QTABLEVIEW *********************************/

void DialogColorier::on_afficher_caseTab(QModelIndex _myIndex)
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();

    if (_myIndex.column() != 0) return;

    _currentRow = _myIndex.row();
    QModelIndex modelInd = _model->index(_myIndex.row(),_myIndex.column());


    QString val = modelInd.data().toString();
    _myLOldColor->setText(val);

    // ça marche, si problèmes c'est juste qu'on a pas initialisé les couleurs de tableView mais c'est normal.
    /*
    QBrush brush = _model->itemFromIndex(modelInd)->background();
    QColor color = brush.color();
    QPalette pal;
    pal.setColor( QPalette::Window, color );
    _myLOldColor->setPalette( pal );
    */
    updateColor();


    /*
    QStandardItem *caseTab;
    QColor color;
    color.setRgb( rand()%(250-0) +0,
                  rand()%(250-0) +0,
                  rand()%(250-0) +0 );

    QString text = QString("coucou");

    QModelIndex modelInd = _model->index(_myIndex.row(),_myIndex.column());

    _model->itemFromIndex(modelInd)->setBackground(QColor (color));
    _model->setData(_myIndex, text);
    */

    /*
    caseTab = _model->takeItem(index.row(), index.column());
    caseTab->setBackground( brush );
    caseTab->setForeground( brush );
    _model->setItem(index.row(), index.column(), caseTab);
    */
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
    qDebug() << "</" << __FUNCTION__ << ">" << endl;

    QModelIndex modelInd = _model->index(_currentRow, 0);
    QBrush brush = _model->itemFromIndex(modelInd)->background();
    QColor color = brush.color();
    int oldR = color.red();
    int oldV = color.green();
    int oldB = color.blue();
    adapt_colors_to_data(oldR, oldV, oldB);
    couleurUtilises[oldR][oldV][oldB] = 0;
    qDebug() << "Couleurs libérées : oldR = " << oldR << "oldV = " << oldV << "oldB = " << oldB << endl;
    //QBrush brushNot;
    //_model->itemFromIndex(modelInd)->setBackground(brushNot);
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

/*---------------------------------------------------------------------------------------------------
 * Parcours itérativement le tableau @couleurUtilises et renvoie les indices @r @g @b
 * de la première couleur trouvée libre (==0)
 * Vérifier avant que le tableau ne soit pas déja remplit (permet d'optimiser le temps de calcul)
 * Commence aux indices+1 de @r, @g et @b.
 * -------------------------------------------------------------------------------------------------*/
void DialogColorier::trouverPremiereCouleurLibre(int &r, int &g, int &b)
{
    //qDebug() << "<" << __FUNCTION__ << ">" << endl;

    int c1, c2, c3;
    int choix = rand()%(2+1-0) +0;
    switch (choix) {
        case 0:
            c1=r;   c2=g;   c3=b;
            break;
        case 1:
            c1=g;   c2=b;   c3=r;
            break;
        default:
            c1=b;   c2=r;   c3=g;
            break;
    }

    //qDebug() << "choix " << choix << "c1=" << c1 << "c2=" << c2 << "c3=" << c3;


    int c1Base = c1, c2Base=c2, c3Base=c3;
    c1++; c2++; c3++;
    int bouclesAutorises=0;
    while (c1!=c1Base && bouclesAutorises<26)
    {
        if (c1>25) c1=0;
        //qDebug() << "\nc1 : " << c1;

        while (c2!=c2Base)
        {
            if (c2>25) c2=0;
            //qDebug() << "\nc2 : " << c2;

            while (c3!=c3Base)
            {
                if (c3>25) c3=0;
                //qDebug() << "c3 : " << c3;

                if (!couleurUtilises[c1][c2][c3]) {
                    r = c1; g=c2;   b=c3;
                    return;
                }
                c3++;
            }
            c3++;
            c2++;
        }
        c2++;
        c1++;
        bouclesAutorises++;
    }

    //qDebug() << "</" << __FUNCTION__ << ">" << endl;
}

































