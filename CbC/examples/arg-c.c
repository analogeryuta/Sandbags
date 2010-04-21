extern int printf(char*,...);
char* outfile;
char* infile;
int help;

#define LONG_OPTION_NUM 2
int match[LONG_OPTION_NUM];	// matching table
char* optstr[LONG_OPTION_NUM]={	// option string
    "help",
    "file",
};
int score[LONG_OPTION_NUM]={4,4}; // length of option string

int
option(int argc, char** argv)
{
    int i, j, k;
    char *p, *o;

    for(i=1; i<argc; ){
	p=argv[i];
	if(*p=='-'){
	i++;
	    p++;
	    if(*p=='-'){
		p++;
		for(j=0; j<LONG_OPTION_NUM; j++){
		    match[j]=0;
		}
		for(k=0; *p!=0; p++, k++){
		    for(j=0; j<LONG_OPTION_NUM; j++){
			o=optstr[j];
			if(*p==o[k]){
			    match[j]++;
			}
		    }
		}
		for(j=0; j<LONG_OPTION_NUM; j++){
		    if(match[j]==score[j]){
			if(j==0){	// help
			    help=1;
			    return 0;
			}else if(j==1){ // file
			    if(outfile){
				return 1;
			    }else{
				outfile=argv[i++];
			    }
			}else{	// unknown
			    return 1;
			}
		    }
		}
	    } else {
		if(*(p+1)=='\0'){
		    if(*p=='h'){
			help=1;
			return 0;
		    }else if(*p=='f'){
			if(outfile){
			    return 1;
			}else{
			    outfile=argv[i++];
			}
		    }
		}else{
		    return 1;
		}
	    }
	}else{
	    if(infile){
		return 1;
	    }else{
		infile=argv[i];
		i++;
	    }
	}
    }
    return 0;
}
// prints usage
void
usage()
{
    printf("Usage:porogram <option> <infile>\n");
    printf("-h: help\n");
    printf("-f: outfile\n");
}
int
main(int argc,char** argv)
{
    if(option(argc,argv)){
	printf("Invalid option\n");
	usage();
	return 1;
    }
    if(help){
	usage();
	return 0;
    }
    if(infile){
	printf("infile: %s\n", infile);
    } else{
	printf("Invalid usage\n");
	usage();
	return 1;
    }
    if(outfile){
	printf("outfile: %s\n", outfile);
    }
    return 0;
}
