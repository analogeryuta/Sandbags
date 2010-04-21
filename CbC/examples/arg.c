// optionの解析ルーチン作成
// long option, 例えば--helpなどは使えるように
// long optionは--から始まるものを有効
// strcmpは使わない
// c fileはincludeしない

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

#ifdef DEBUG
extern void breakp(void *,void *);
#define BREAKP(ret,env) breakp(ret,env)
#else
#define BREAKP(ret,env)
#endif

// evaluates matching table
code
opt5(int j, int i, int argc, char** argv, (*exit0)(int), void* env)
{
    if(j<LONG_OPTION_NUM){
	printf("match(%d): %d\n", j, match[j]);
	if(match[j]==score[j]){
	    printf("detected opt: ");
	    if(j==0){		// help
		help=1;
		printf("help\n");
		goto exit0(0), env;
	    }else if(j==1){	// file
		printf("file\n");
		printf("file: %s %s\n", outfile, argv[i]);
		if(outfile){
		    goto exit0(1), env;
		}else{
		    outfile=argv[i];
		    i++;
		    goto opt0(i, argc, argv, exit0, env);
		}
	    }else{
		printf("unknown\n");
		goto exit0(1), env;
	    }
	}
	j++;
	goto opt5(j, i, argc, argv, exit0, env);
    }else{
	goto exit0(1), env;
    }
}

// matching test
code
opt4(int k, int j, char* p, int i, int argc, char** argv, (*exit0)(int), void* env)
{
    char* o;
    if(*p!='\0'){
    o=optstr[j];
	if(j<LONG_OPTION_NUM){
	    if(*p==o[k]){
		match[j]++;
	    }
	    j++;
	}else{
	    k++;
	    p++;
	    j=0;
	}
	goto opt4(k, j, p, i, argc, argv, exit0, env);
    }
    goto opt5(0, i, argc, argv, exit0, env);
}

// initialize matching table
code
opt3(int j, char* p, int i, int argc, char** argv, (*exit0)(int), void* env)
{
    if(j<LONG_OPTION_NUM){
	match[j]=0;
	j++;
	goto opt3(j, p, i, argc, argv, exit0, env);
    }else{
	goto opt4(0, 0, p, i, argc, argv, exit0, env);
    }
}

// evaluates one hyphen options such like -f or -h.
code
opt2(char* p, int i, int argc, char** argv, (*exit0)(int), void* env)
{
    if(*p=='-'){
	p++;
	goto opt3(0, p, i, argc, argv, exit0, env);
    } else if(*(p+1)=='\0'){
	if(*p=='h'){
	    help=1;
	    goto exit0(0), env;
	}else if(*p=='f'){
	    if(argv[i]){
		if(outfile){
		    goto exit0(1), env;
		}else{
		    outfile=argv[i];
		    i++;
		    goto opt0(i, argc, argv, exit0, env);
		}
	    }else{
		goto exit0(1), env;
	    }
	}
    }
    goto exit0(1), env;
}

// sets 'infile'
code
opt1(char* p, int i, int argc, char** argv, (*exit0)(int), void* env)
{
    if(infile){
	printf("infile exists: infile=%s %s\n", infile, p);
	goto exit0(1), env;
    }else{
	infile=p;
	goto opt0(i, argc, argv, exit0, env);
    }
}

code
opt0(int i, int argc, char** argv, (*exit0)(int), void* env)
{
    char* p;
    BREAKP(exit0,env);
    if(i<argc){
	p=argv[i];
	i++;
	if(*p=='-'){
	    p++;
	    goto opt2(p, i, argc, argv, exit0, env);
	}else{
	    goto opt1(p, i, argc, argv, exit0, env);
	}
	goto opt0(i, argc, argv, exit0, env);
    }else{
	goto exit0(0), env;
    }
}

int
option(int argc, char** argv)
{
    BREAKP(return, environment);
    goto opt0(1, argc, argv, return, environment);
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

#ifndef DEBUG
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
#endif // DEBUG
