#include <stdio.h>
//A.M.M.S.Attanayake

void encrypttext(char *plaintext,int def_shiftkey);
void decrypttext(char *plaintext,int def_shiftkey);



int main(){
	char plaintext[100];
	char entext[100];
	char detext[100];
	char txt;
	int i,n,m,c,p;
	int def_shiftkey;
    int exit=0;

    while(exit==0){
	printf("_______Welcome to the encrypt & decrypt programme using ceaser cypher______\n");
    printf("Choose one of the following to continue\n");
	printf("	1)Encryption\n");
	printf("	2)Decryption\n");
	printf("Enter your choice \n");
	scanf("%d",&n);
	printf("Do you want to use your own shift key? \n");
	printf("1]yes\n");
	printf("2]no\n");
	scanf("%d",&m);
	if(m==1){
     printf("Enter your choice for the shift key.... \n");
     scanf("%d",&c);
     def_shiftkey = c;
	}
	else{
     printf("....programme will use a default shift key.... \n");
     def_shiftkey = 3;
	}

	printf("Enter the text that you want to encrypt or decrypt..\n");
	scanf(" %[^\n]",&plaintext);
	//gets(plaintext);
	if(n==1){
   		encrypttext(plaintext,def_shiftkey);
	}
	else{
        decrypttext(plaintext,def_shiftkey);
	}
    printf("Do you want to continue the programme? \n");
    printf("1]yes\n");
    printf("2]no \n");
    scanf("%d",&p);
    if(p==2){
        printf("Thank you for using our service!!! \n");
        exit=1;
    }

    }


}


void encrypttext(char *plaintext,int def_shiftkey){
	int i;

	for(i=0;plaintext[i] != '\0';i++){

		if(plaintext[i] >= 'a' && plaintext[i] <= 'z'){
		plaintext[i] = plaintext[i] + def_shiftkey;

		if(plaintext[i]>'z'){
            plaintext[i] = plaintext[i] - 'z' + 'a' - 1;
		}

       // 97-122  125-122+97-1
		}

		else if(plaintext[i] >= 'A' && plaintext[i]<= 'Z'){
		plaintext[i] = plaintext[i] + def_shiftkey;

        if(plaintext[i]>'Z'){
            plaintext[i] = plaintext[i] - 'Z' + 'A' - 1;
		}

		}


	}
   printf("Encrypted message is %s \n",plaintext);

}

void decrypttext(char *plaintext,int def_shiftkey){
	int i;

	for(i=0;plaintext[i] != '\0';i++){

		if(plaintext[i] >= 'a' && plaintext[i] <= 'z'){
		char str = plaintext[i] - def_shiftkey;

		if(str<'a'){
            plaintext[i] = 'z'-('a'- str)+1;
		}
		else
             plaintext[i] =str;


		}

		else if(plaintext[i] >= 'A' && plaintext[i]<= 'Z'){
		char str = plaintext[i] - def_shiftkey;

		if(str<'A'){
            plaintext[i] = 'Z'-('A'- str)+1;
		}
		else
             plaintext[i] =str;



		}




	}
   printf("Decrypted message is %s \n",plaintext);

}


