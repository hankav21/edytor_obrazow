#ifndef KLASY_MIEDZYPLIKOWE_H
#define KLASY_MIEDZYPLIKOWE_H

#include <QVector>
#include <QImage>
#include <QDebug>

struct RGB{
    int r;
    int g;
    int b;
};

struct IMG{
    int szer, wys;
    //std::vector<std::vector<RGB> > rgb;
    std::vector<RGB> rgb;   //orginal


    //Tworzy obraz QImage z vectorow RGB
    QImage Make_img_from_RGB(IMG rgb)
    {
        QImage img(rgb.szer, rgb.wys, QImage::Format_RGB32);
        int x;

        if(rgb.rgb.size() < 1)  return img;

        QRgb pom_rgb; // pomocnicza zmienna do liczenia rgb

        for(int i=0; i< rgb.wys; i++)
            for(int j=0; j< rgb.szer; j++)
                {
                    x = i* rgb.szer + j;

                    pom_rgb = qRgb(rgb.rgb[x].r, rgb.rgb[x].g, rgb.rgb[x].b); //wyciaga rgb z vektorow pikseli
                    img.setPixel(j,i,pom_rgb);    //nadaje pikselowi rgb

                }

        return img;
    }

    //Tworzy vectory RGB z obrazu
    bool Make_RGB_from_img(QImage img, IMG& rgb)
    {
        //do czytania obrazu
    //    bool test;
    //    test = img.load("obr1.bmp");
        rgb.wys = img.height();
        rgb.szer = img.width();

        //ustala wilkosc od razu
        rgb.rgb.resize(rgb.szer * rgb.wys);

        //pobiera rgb z obrazu
        //pixel bierze (szer,wys)
        for(int i = 0; i < rgb.wys; i++)
            for(int j=0; j < rgb.szer; j++)
            {
                rgb.rgb[i * rgb.szer + j].r = qRed(img.pixel(j,i));
                rgb.rgb[i * rgb.szer + j].g = qGreen(img.pixel(j,i));
                rgb.rgb[i * rgb.szer + j].b = qBlue(img.pixel(j,i));

            }

        return 1;
    }

    //Tworzy obraz QImage z vectorow RGB z gornym progiem dla R,G i B
    QImage Make_img_from_RGB_Upr(IMG* rgb, int R, int G, int B)
    {
        if(R>255 || R <0)   qDebug() << "Make_img_from_RGB_Upr -> R: " <<  R;
        if(G>255 || G <0)   qDebug() << "Make_img_from_RGB_Upr -> G: " <<  G;
        if(B>255 || B <0)   qDebug() << "Make_img_from_RGB_Upr -> B: " <<  B;


        QImage img(rgb->szer, rgb->wys, QImage::Format_RGB32);
        int x;

        if(rgb->rgb.size() < 1)  return img;

        QRgb pom_rgb; // pomocnicza zmienna do liczenia rgb

        for(int i=0; i< rgb->wys; i++)
            for(int j=0; j< rgb->szer; j++)
                {
                    x = i* rgb->szer + j;

                    int pr,pg,pb;

                    if(R>= rgb->rgb[x].r) pr = rgb->rgb[x].r; else pr = R;
                    if(G>= rgb->rgb[x].g) pg = rgb->rgb[x].g; else pg = G;
                    if(B>= rgb->rgb[x].b) pb = rgb->rgb[x].b; else pb = B;

                    pom_rgb = qRgb(pr, pg, pb); //wyciaga rgb z vektorow pikseli
                    img.setPixel(j,i,pom_rgb);    //nadaje pikselowi rgb
                }

        return img;
    }

};






#endif // KLASY_MIEDZYPLIKOWE_H
