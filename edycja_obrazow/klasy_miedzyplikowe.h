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

struct MASK{
    std:: vector<std:: vector<int> > mask;
    int wys,szer,suma_mask;

    MASK(){
        wys = 0;
        szer = 0;
        suma_mask = 0;
    }



    MASK(const int wyp[], const int w, const int s){
        wys = w;
        szer = s;
        //mask.wyp_mask(wyp);
        //spr czy musze przypisac do mask?
        this->wyp_mask(wyp);
        this->obl_sume_mask();
    }

    //przyjmujemy, że rozmiar tablicy jest identyczny do utworzonej maski
    std:: vector<std:: vector<int> > wyp_mask(const int wyp[]){
        mask.resize(wys);
        for(int i = 0; i<wys; i++)
            mask[i].resize(szer);

        for(int i=0; i<wys; i++)
            for(int j=0; j<szer; j++)
                mask[i][j] = wyp[ i*szer + j];
        return mask;
    }

    int obl_sume_mask(){
        suma_mask = 0;
        for(int i = 0; i<wys; ++i)
            for(int j = 0; j < szer; ++j)
                suma_mask += mask[i][j];
        return suma_mask;
    }
};

struct IMG{
    int szer, wys;
    //std::vector<std::vector<RGB> > rgb;
    std::vector<RGB> rgb;   //orginal

    IMG(){
        szer = 0;
        wys = 0;
    }

    IMG(const int sz, const int w){
        szer = sz;
        wys = w;
        rgb.resize(szer * wys); //powinno byc inicjalizowane default-constructed values wiec tu zero (gdyby rozszerzał coś co juz ma to to dopiero nadmiarowe dane sa na nowo tworzone i dawane im zero)

    }

    IMG(const IMG* img){
        this->szer = img->szer;
        wys = img->wys;
        rgb.resize(szer * wys);

        for(int i = 0; i < wys; i++)
            for(int j=0; j < szer; j++)
            {
                this->rgb[i * szer + j].r = img->rgb[i * szer + j].r;
                rgb[i * szer + j].g = img->rgb[i * szer + j].g;
                rgb[i * szer + j].b = img->rgb[i * szer + j].b;
            }
    }

    //2 poniższe konstruktory !sz i w podajesz wartośc o ile z !jednej! strony obrazu!
    //konstruktor powiekszajacy krawędzie obrazu
    IMG(const int sz, const int w, const IMG *img){
        szer = img->szer + 2*sz;
        wys = img->wys + 2*w;

        rgb.resize(szer * wys);

        //wypełnianie identyczne środku jak w obranie img
        int nadmiar_gorny = w*szer;
        for(int i = 0; i<img->wys ; i++){
            for(int j = 0; j<img->szer ;j++){
                rgb[nadmiar_gorny+ i*szer+j+sz].r = img->rgb[i*img->szer+j].r;
                rgb[nadmiar_gorny+ i*szer+j+sz].g = img->rgb[i*img->szer+j].g;
                rgb[nadmiar_gorny+ i*szer+j+sz].b = img->rgb[i*img->szer+j].b;
            }
        }

        //wypełnianie krawędzi kolorem
        int ost_linia_img=img->szer * img->wys - img->szer;
        int ost_linia_this = szer * wys - szer*w;
        //wysokosciowe
        for(int i = 0; i<img->szer; i++){
            for(int j = 0; j<w; j++){
                //gora
                rgb[j*szer+i+sz].r = img->rgb[i].r;
                rgb[j*szer+i+sz].g = img->rgb[i].g;
                rgb[j*szer+i+sz].b = img->rgb[i].b;

                //dol
                rgb[ost_linia_this + j*szer+i+sz].r = img->rgb[ost_linia_img +i].r;
                rgb[ost_linia_this + j*szer+i+sz].g = img->rgb[ost_linia_img +i].g;
                rgb[ost_linia_this + j*szer+i+sz].b = img->rgb[ost_linia_img +i].b;
            }
        }
        //szerokosciowe
        for(int i = 0; i<img->wys; i++){
            for(int j = 0; j<sz; j++){
                //lewo
                rgb[(i + w )*szer + j ].r = img->rgb[i * img->szer].r;
                rgb[(i + w )*szer + j ].g = img->rgb[i * img->szer].g;
                rgb[(i + w )*szer + j ].b = img->rgb[i * img->szer].b;
                //prawo
                rgb[(i + w )*szer + j + img->szer  + sz].r = img->rgb[i * img->szer + img->szer -1].r;
                rgb[(i + w )*szer + j + img->szer  + sz].g = img->rgb[i * img->szer + img->szer -1].g;
                rgb[(i + w )*szer + j + img->szer  + sz].b = img->rgb[i * img->szer + img->szer -1].b;
            }
        }
        //rogi
        for(int i = 0; i<w; ++i){
            for(int j = sz -1; j>=0; j--){
                //lewy gorny
                rgb[i*szer + j].r = img->rgb[0].r;
                rgb[i*szer + j].g = img->rgb[0].g;
                rgb[i*szer + j].b = img->rgb[0].b;
                //prawy górny
                rgb[i*szer + j + img->szer + sz].r = img->rgb[img->szer - 1].r;
                rgb[i*szer + j + img->szer + sz].g = img->rgb[img->szer - 1].g;
                rgb[i*szer + j + img->szer + sz].b = img->rgb[img->szer - 1].b;
                //lewy dolny
                rgb[i*szer + j + ost_linia_this].r = img->rgb[ost_linia_img].r;
                rgb[i*szer + j + ost_linia_this].g = img->rgb[ost_linia_img].g;
                rgb[i*szer + j + ost_linia_this].b = img->rgb[ost_linia_img].b;
                //prawy dolny
                rgb[ost_linia_this + i * szer + j + sz + img->szer].r = img->rgb[ost_linia_img + img->szer - 1].r;
                rgb[ost_linia_this + i * szer + j + sz + img->szer].g = img->rgb[ost_linia_img + img->szer - 1].g;
                rgb[ost_linia_this + i * szer + j + sz + img->szer].b = img->rgb[ost_linia_img + img->szer - 1].b;
            }
        }
    }

    //konstruktor pomniejszajacy krawedzie obrazu (obraz wejsciowy, o ile szer i wys)
    IMG(const IMG *img, int sz, int w){
        szer = img->szer - 2*sz;
        wys = img->wys - 2*w;

        rgb.resize(szer * wys);

        int nadmiar_gorny =w*img->szer;
        for(int i = 0; i<wys ; i++){
            for(int j = 0; j<szer ;j++){
                rgb[i*szer+j].r = img->rgb[nadmiar_gorny+ i*img->szer+j+sz].r;
                rgb[i*szer+j].g = img->rgb[nadmiar_gorny+ i*img->szer+j+sz].g;
                rgb[i*szer+j].b = img->rgb[nadmiar_gorny+ i*img->szer+j+sz].b;
            }
        }
//        for(int i = 0; i < wys; i++)
//        {
//            qDebug() << "pom i:" << i;
//            int nadmiar_z_lewej = (i+1)*sz;
//            int nadmiar_z_prawej = i*sz;
//            int j;
//            for(j=0; j < szer; j++)
//            {
//                this->rgb[i * szer + j].r = img->rgb[nadmiar_gorny+nadmiar_z_lewej+nadmiar_z_prawej + img->szer*i + j].r;
//                rgb[i * szer + j].g = img->rgb[nadmiar_gorny+nadmiar_z_lewej+nadmiar_z_prawej + img->szer*i + j].g;
//                rgb[i * szer + j].b = img->rgb[nadmiar_gorny+nadmiar_z_lewej+nadmiar_z_prawej + img->szer*i + j].b;
//            }
//            //qDebug() << "pom j:" << j;
//        }
    }




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


    //wsadzamy juz powiekszony obraz->zeby tyle nie obliczaac -> nie wyswietli sie dodatkowych krawedzi zeby to ladnie wygladalo
    IMG Make_rgb_with_mask(IMG* img, MASK* mask){
        IMG img_out(img->szer, img->wys);
qDebug() << img->szer << img->wys;
        int wm = mask->wys/2;
        int sm = mask->szer/2;

        for(int i = wm; i < img->wys - wm - wm; i++)
            for(int j = mask->szer/2; j < img->szer - sm -sm; j++){
                for(int w = 0; w < mask->wys; w++)
                    for(int k = 0; k < mask->szer; k++){
                        int wsp_img = img->szer * (i - wm + w)      +       j - sm + k;
                        img_out.rgb[i * img_out.szer + j].r += img->rgb[wsp_img].r * mask->mask[w][k];
                        img_out.rgb[i * img_out.szer + j].g += img->rgb[wsp_img].g * mask->mask[w][k];
                        img_out.rgb[i * img_out.szer + j].b += img->rgb[wsp_img].b * mask->mask[w][k];

                    }
            img_out.rgb[i * img_out.szer + j].r /= mask->suma_mask;
            img_out.rgb[i * img_out.szer + j].g /= mask->suma_mask;
            img_out.rgb[i * img_out.szer + j].b /= mask->suma_mask;
        }

        return img_out;
    }
};






#endif // KLASY_MIEDZYPLIKOWE_H
