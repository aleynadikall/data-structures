#include <stdio.h>
#include <stdlib.h>

struct nodeK
{
    int data;
    struct nodeK *next;
};

struct nodeS
{
    int data;
    struct nodeS *next;
};

struct nodeS *top = NULL;

struct nodeK *root = NULL;
struct nodeK *son = NULL;

int Kuyruk(int *sayiDizi, int Boyut)
{
    int sayi;
    int dizi[2];

    for (int i = 0; i < Boyut; i++)
    {

        if (i % 2 == 0)
        {
            if (sayiDizi[i] == 0)
            {
                dizi[0] = 10;
            }
            else
                dizi[0] = sayiDizi[i] * 10;
        }
        
        if (i % 2 == 1)
        {
            dizi[1]=sayiDizi[i];
            sayi = dizi[0] + dizi[1];
            if (root == NULL)
            {
                root = (struct nodeK *)malloc(sizeof(struct nodeK));
                root->data = sayi;
                root->next = NULL;
                son = root;
            }
            else
            {
                son->next = (struct nodeK *)malloc(sizeof(struct nodeK));
                son->next->data = sayi;
                son = son->next;
                son->next = NULL;
            }
        }
    }
    if (Boyut % 2 == 1)
    {
        if (sayiDizi[Boyut - 1] == 0)
            sayi = 10;
        else
        {
            sayi = sayiDizi[Boyut - 1] * 10;
        }
        son->next = (struct nodeK *)malloc(sizeof(struct nodeK));
        son->next->data = sayi;
        son = son->next;
        son->next = NULL;
    }

    printKuyruk(root);
}

int printKuyruk(struct NodeK *n)
{
    struct nodeK *temp = NULL;
    temp = root;
    if (temp == NULL)
    {
        printf("Liste bos");
        return;
    }

    printf("\n#####################################\n");
    printf("\n----  Olusan Kuyruk  ----\n");
    while (temp != NULL)
    {
        printf("%d =>", temp->data);
        temp = temp->next;
    }
}

int ort = 1;

int ortalama(struct NodeK *n)
{
    int toplam = 0;
    int sayac = 0;
    struct nodeK *temp = NULL;
    temp = root;
    while (temp != NULL)
    {
        toplam += temp->data;
        temp = temp->next;
        sayac++;
    }
    ort = toplam / sayac;
    printf("\n###############################\n");
    printf("\nKuyrugun Ortalamasi:%d", ort);
}

int Stack()
{
    struct nodeS *temp;
    temp = (struct nodeS *)malloc(sizeof(struct nodeS));
    temp = root;


    while(temp!=NULL)
    {
        if(temp->data<ort)
            push(temp->data);
        temp=temp->next;
    }

    printStack(top);
}



int diziyeCekme()
{
    int j = countStack(top);
    struct nodeS *temp;
    temp = (struct nodeS *)malloc(sizeof(struct nodeS));

    temp = top;
    int diziList[100];
    
    for (int i = 0; i < j; i++)
    {
        diziList[i] = temp->data;
        temp = temp->next;
    }

    printf("\n########################################\n");
    printf("\n----  Dizinin son Hali  ----\n");
    for (int i = 0; i < j; i++)
    {
        printf("%d  ", diziList[i]);
    }
    printf("\n");
    printf("\n########################################\n");
}

void push(int x)
{
    struct nodeK *temp;
    temp = (struct nodeK *)malloc(sizeof(struct nodeK));
    temp->next = NULL; //Bazı compilerlarda yazmamak sıkıntı verebilir.
    temp->data = x;
    if (top == NULL)
        top = temp;
    else
    {
        temp->next = top;
        top = temp;
    }
}

int countStack(struct nodeS *n)
{
    int count = 0;               // Initialize count
    struct nodeS *current = top; // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

int printStack(struct nodeS *n)
{
    if (top == NULL)
    {
        printf("Liste bos");
        return;
    }
    printf("\n########################################\n");
    printf("\n----  Olusan Stack  ----\n");
    while (n != NULL)
    {
        printf("%d =>", n->data);
        n = n->next;
    }
}

int txtBoyut(char file_name[])
{
    // opening the file in read mode
    FILE *fp = fopen(file_name, "r");

    // checking if the file exist or not
    if (fp == NULL)
    {
        printf("File Not Found!\n");
        return -1;
    }

    fseek(fp, 0L, SEEK_END);

    // calculating the size of the file
    int boyut = ftell(fp);

    // closing the file
    fclose(fp);

    return boyut;
}

int main()
{
    FILE *fPointer;
    fPointer = fopen("Sayilar.txt", "r");
    char file_name[] = {"Sayilar.txt"};
    int boyut = txtBoyut(file_name);
    if (boyut != -1)
        printf("\nSize of the file is %d bytes. \n", boyut);

    int *sayiDizi;
    char *p;
    p = (char *)malloc(boyut * sizeof(char));
    sayiDizi = (int *)malloc(boyut * sizeof(int));

    while (!feof(fPointer))
    {
        fgets(p, boyut + 1, fPointer);
    }
    printf("\ntxt dosyasinin icerigi:");
    puts(p);
    

    
    char gecici[1];
    for (int i = 0; i < boyut; i++)
    {
        gecici[0] = p[i];
        sayiDizi[i] = atoi(gecici);
    }

    Kuyruk(sayiDizi, boyut);
    ortalama(root);
    Stack();
    diziyeCekme();
    printf("\n");
}