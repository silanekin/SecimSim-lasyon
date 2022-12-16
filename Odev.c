#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int plaka_kodu[5],mv_kontenjani[5],oy_listesi[5][6],genel_oy_liste[6],toplam_oy[5],genel_toplam_oy=0,oy_listesi_mv[5][6],mv_listesi[5][6],oy_listesi_kopya[5][6],genel_mv_listesi[6],toplam_mv=0,genel_oy_kopya[6],birincilik_liste[6];
char parti_listesi[6][20],parti_listesi_kopya[6][20],parti_listesi_mv[6][20],genel_parti_liste[6][20];


float yuzde_hesapla(float oy, int sehir)
{
    float yuzde=0;
    yuzde = (oy / toplam_oy[sehir]) * 100;
    return yuzde;

}

int mv_hesapla(int sehir){
   int i,k,g,m;
   for (g=0;g<mv_kontenjani[sehir];g++){
    m = mv_sirala(sehir);
    mv_listesi[sehir][m] += 1;
    genel_mv_listesi[m] += 1;
    oy_listesi_mv[sehir][0] /= 2;
   }


   }

int genel_parti_bul(int oy){
    int i;
    for (i=0;i<6;i++){
        if (oy == genel_oy_kopya[i])
        return i;}


}

float mv_yuzde(float mv){
  float yuzde;
  yuzde = (mv / toplam_mv) * 100;
  return yuzde;

}




int parti_bul(int oy,int sehir){
  int i;
  for (i=0;i<6;i++){
    if (oy == oy_listesi_kopya[sehir][i]){
       return i;}
}


}
void genel_oy_sirala(){
  int i,j,k,gecici;
  char gecici_c[20];
  for (i=0;i<6;i++){
    for (k=0;k<6;k++){
      if (genel_oy_liste[k] < genel_oy_liste[k+1]){
        gecici = genel_oy_liste[k];
        genel_oy_liste[k] = genel_oy_liste[k+1];
        genel_oy_liste[k+1] = gecici;
        strcpy(gecici_c,genel_parti_liste[k]);
        strcpy(genel_parti_liste[k],genel_parti_liste[k+1]);
        strcpy(genel_parti_liste[k+1],gecici_c);
        }
    }
  }
}

float genel_yuzde(float oy){
   float yuzde;
   yuzde = (oy / genel_toplam_oy) * 100;
   return yuzde;

}



int mv_sirala(int sehir){
   int i,k,gecici,s;
   char gecici_c[20];

   for (i=0;i<6;i++){
     for (k=0;k<5 -i;k++){
        if (oy_listesi_mv[sehir][k] < oy_listesi_mv[sehir][k+1]){
            gecici = oy_listesi_mv[sehir][k];
            oy_listesi_mv[sehir][k] = oy_listesi_mv[sehir][k+1];
            oy_listesi_mv[sehir][k+1] = gecici;
            strcpy(gecici_c,parti_listesi_mv[k]);
            strcpy(parti_listesi_mv[k],parti_listesi_mv[k+1]);
            strcpy(parti_listesi_mv[k+1],gecici_c);
        }
     }
}

   for (i=0;i<6;i++){
    if (strcmp(parti_listesi_mv[0],parti_listesi[i] ) == 0){
      return i;}
    }

}


void turkiye_geneli_yaz()
{
    printf("Ulke Geneli\nMilletvekili Kontenjani:%d\nGecerli Oy Sayisi:%d\n\t\t     Oy Sayisi\t\tOy Yuzdesi\t\tMv Sayisi\tMV Yuzdesi\n\t\t     --------\t\t----------\t\t---------\t----------\n",toplam_mv,genel_toplam_oy);
    int i,m;
    for (i=0;i<6;i++){
       m = genel_mv_listesi[genel_parti_bul(genel_oy_liste[i])];
       printf("%s Partisi\t  %10d\t\t%8.2f\t\t   %2d\t\t%8.2f\n",genel_parti_liste[i],genel_oy_liste[i],genel_yuzde(genel_oy_liste[i]),m,mv_yuzde(m));}
    printf("\nIktidar Partisi: %s\nAna Muhalefet Partisi: %s\n",genel_parti_liste[0],genel_parti_liste[1]);
    printf("\nPartilerin Oy Sayilarina Gore Il Birincilikleri:\n%s Partisi: %d\n%s Partisi: %d",genel_parti_liste[0],birincilik_liste[genel_parti_bul(genel_oy_liste[0])],genel_parti_liste[1],birincilik_liste[genel_parti_bul(genel_oy_liste[1])]);


}



void oylari_yaz(){
    int i,k,j=0,p;
    for (k=0;k<5;k++){
        for (p=0;p<6;p++)
           strcpy(parti_listesi_mv[p],parti_listesi[p]);
        oylari_sirala(k);
        mv_hesapla(k);
        printf("Il plaka kodu:%d\nMilletvekili Kontenjani:%d\nGecerli Oy Sayisi:%d\n\t\t     Oy Sayisi\t\tOy Yuzdesi\t\tMv Sayisi\n\t\t     ---------\t\t----------\t\t---------\n",plaka_kodu[k],mv_kontenjani[k],toplam_oy[k]);
        for (i=0;i<6;i++){
            printf("%s Partisi\t  %10d\t\t%8.2f\t\t    %d\n",parti_listesi_kopya[i],oy_listesi[k][i],yuzde_hesapla(oy_listesi[k][i],k),mv_listesi[k][parti_bul(oy_listesi[k][i],k)]);
        }
    printf("Devam etmek icin bir tusa basiniz...");
    if (j==0){
    getchar();
    getchar();
    j = 1;
    printf("\n");}
    else{
    getchar();
    printf("\n");}
    birincilik_liste[parti_bul(oy_listesi[k][0],k)] += 1;
    }
    genel_oy_sirala();
    turkiye_geneli_yaz();
}

void oylari_sirala(int sehir){
   int i,k,gecici,s;
   char gecici_c[20];
   for (i=0;i<6;i++)
       strcpy(parti_listesi_kopya[i],parti_listesi[i]);
   for (i=0;i<6;i++){
    for (k=0;k<5 -i;k++){
        if (oy_listesi[sehir][k] < oy_listesi[sehir][k +1]){
            gecici = oy_listesi[sehir][k];
            oy_listesi[sehir][k] = oy_listesi[sehir][k +1];
            oy_listesi[sehir][k+1] = gecici;
            strcpy(gecici_c,parti_listesi_kopya[k]);
            strcpy(parti_listesi_kopya[k],parti_listesi_kopya[k +1]);
            strcpy(parti_listesi_kopya[k+1],gecici_c);

        }
    }
   }

}


int main()
{
    int i,k,n,j=0,oy,s,secim=0,z=0;
    char parti[20];

    for (n=0;n<5;n++){
      toplam_oy[n] =0;
      printf("%d. ilin plaka kodunu giriniz: ",n+1);
      scanf("%d",&plaka_kodu[n]);
      printf("Ilin milletvekili kontenjanini giriniz: ");
      scanf("%d",&mv_kontenjani[n]);
      if (z==0)
        printf("Sirasiyla 6 parti ve oy sayilarini girebilirsiniz.\n");
      if (j==0){
            for(k=0;k<6;k++){
             printf("%d. Partinin ismini giriniz: ",k+1);
             scanf("%s",parti);
             strcpy(parti_listesi[k],parti);
             strcpy(genel_parti_liste[k],parti);
             printf("Aldigi oy sayisini giriniz: ");
             scanf("%d",&oy);
             oy_listesi[n][k] = oy;
             genel_oy_liste[k] = oy;
             toplam_oy[n] += oy;
             genel_toplam_oy += oy;
             mv_listesi[n][k] = 0;
             genel_mv_listesi[k] =0;
         }
         }
        else {
            for (i=0;i<6;i++){
                printf("%s Partisinin Oyu: ",parti_listesi[i]);
                scanf("%d",&oy);
                oy_listesi[n][i] = oy;
                genel_oy_liste[i] += oy;
                toplam_oy[n] += oy;
                genel_toplam_oy += oy;
                mv_listesi[n][i] = 0;
            }

         }
    printf("\n");
    z =1;
    toplam_mv += mv_kontenjani[n];
    j=1;
    for (k=0;k<6;k++)
        oy_listesi_mv[n][k] = oy_listesi[n][k];
    for (k=0;k<6;k++)
        oy_listesi_kopya[n][k] = oy_listesi[n][k];
    for (k=0;k<6;k++)
        genel_oy_kopya[k] = genel_oy_liste[k];

    }
    oylari_yaz();

    }




