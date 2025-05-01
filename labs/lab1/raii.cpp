#include <iostream>

struct openfile
{
private:
    FILE* f;
public:
    openfile(const char * filename){
        f = std::fopen(filename, "r");
        if(!isopen())
            std::perror("Error opening file.");
    }
    int getchar(){
        if(isopen())
            return std::getc(f);
        else
            return EOF;        
    }
    bool isopen(){
        return f != nullptr;
    }
    ~openfile(){
        if(isopen())
            fclose(f);
        else
            std::cout << "File pointer is null.";
    }
};

int main()
{   
    openfile of("myfile.in");
    int c = of.getchar();
    int linenr = 1;

    while( c != EOF ){
        if( c == '$' ){
            std::cout<< "illegal dollar sign in line " << linenr << std::endl;
            return -1;
        }
        if( c == '\n' )
            ++linenr;
        c = of.getchar();
    }
    return 0;
}