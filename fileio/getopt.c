#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[]){
	int f;
	while((f = getopt(argc,argv,"ab:c::")) != -1) {
		switch(f){
			case 'a':
				printf("it has argument a!\n");
				break;
			case 'b':
				printf("it has argument b with value: %s\n",optarg);
				break;
			case 'c':
				if(optarg)
					printf("it has argument c with value: %s\n",optarg);
				else
					printf("it has argument c\n");
				break;
			default:
				printf("error opterr:%s\n",opterr);
				break;
		}
	}
	return 1;
}
