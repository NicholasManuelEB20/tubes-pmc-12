/** EL2008 Pemecahan Masalah dengan C 2021/2022
* Modul : Tugas Besar
* Kelompok : 12
* Nama File : source_code.c
* Deskripsi : Implementation logik minimisasi menggunakan metode Quine Mc-Clusky
*/

#include <stdio.h>
#include<math.h>
#define maxsize_array 10000

#include <stdio.h>
#include<math.h>
#define maxsize_array 10000
void border(){
    for (int s = 0; s <= 70; s++){
        printf("*");
    }
    printf("\n");
}

void convertbinary(int x,int y);int table[maxsize_array][maxsize_array]= {0,0};
int res[maxsize_array];int index=0,index2=0;

//Kode utama
void main(void)
{
    border();
    int jumlah_variabel,jumlah_minterm,minterm ;

    //Input jumlah variabel
    printf("Masukkan Jumlah Variabel = ");scanf("%d", &jumlah_variabel) ;
        if (jumlah_variabel == 0)
        {
        printf("Jumlah Variabel Harus >= 0, Silakan Mengulangi Program!\n");
        return 0;
        }

    //Input jumlah minterm
    printf("Masukkan Jumlah Minterms = ");scanf("%d", &jumlah_minterm);
    int c = jumlah_minterm;
    int count1=0,count2=0,count3=0,count4=0,count5=0,y=0,x=0,max=pow(2,jumlah_variabel);
    printf("Masukkan Minterms pada Range  = ");
    printf("( 0 ) and ( %d )\n", max-1);

    //Input minterm
    for(int i=0; i<jumlah_minterm; i++)
    {
    again:
        scanf("%d", &minterm);
        if(minterm>=max)
        {
            printf("Enter number in the range ( 0 ) and ( %d )\n", max-1);
            goto again ;
        }
        convertbinary(minterm,jumlah_variabel);
    }

    //Penyederhnaan menggunakan metode Quine Mc-Clusky
    for(int i=0; i<jumlah_minterm; i++)
    {
        if(x==0)
        {
            count1 = jumlah_minterm;
            x = 1;
        }
        for(int j=i; j<jumlah_minterm; j++)
        {
            for(int n=0; n < jumlah_variabel; n++)
            {
                if(table[i][n] != table[j][n]&&i!=j)
                {
                    count5 = count5 + 1;
                    y=n;
                }
            }
            if(count5==1)
            {
                table[i][jumlah_variabel] = 1;
                table[j][jumlah_variabel] = 1;
                count4= count4 + 2;
                for(int k=0; k<jumlah_variabel; k++)
                {
                    if(k==y)
                        table[c][k]=2;
                    else
                        table[c][k]=table[i][k];
                }
                c = c + 1;
                count2 = count2 + 1;
            }
            count5=0;


        }
        count3 = count3 + 1;
        if(count3==count1)
        {
            res[index2] = jumlah_minterm;
            index2 = index2 + 1;
            jumlah_minterm = jumlah_minterm + count2;
            x = 0;
            count2 = 0;
        }

    }
    count5=0;
    for(int i=0; i<c; i++)
    {
        for(int j=i; j<c; j++)
        {
            for (int n=0; n<jumlah_variabel; n++)
            {
                if(table[i][n]==table[j][n]&&i!=j)
                    count5++;
            }
            if(count5==jumlah_variabel)
            {
                table[j][jumlah_variabel]=1;
            }
            count5 = 0;
        }

    }
    printf("================================\n");

    for(int i=0; i<c; i++)
    {

        int n=0;
        for(int j=0; j<jumlah_variabel; j++)
        {
            if(table[i][j]==2||table[i][jumlah_variabel]==1){
            printf("");
            n = n + 1;
   }
                
            else if (table[i][j]==1) {
              printf("X %d ",j);
   }
               
            else {
              printf("X %d ^ ",j); 
   }
                
        }
        if(n != jumlah_variabel)
            printf("\n");

    }
    border();
}

void convertbinary(int a,int c)
{
    int k=c-1;int b=0;
    while(a!=0)
    {
        b=a%2;a=a/2;table[index][k]=b ;
        k = k - 1;
    }
    index = index + 1;
}