#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void save_cmd_result_to_file( char* cmd, char* filename );

int main( int argc, char* argv[] )
{
    char* cmd = argv[1];
    char* filename = argv[2];
    save_cmd_result_to_file( cmd, filename);
    return 1;
}

void save_cmd_result_to_file( char* cmd, char* filename )
{
    if( NULL == cmd || NULL == filename )
    {
        printf("cmd or filename is null!\n");
        return;
    }

    FILE* fp;
    char buffer[1024];

    //清空数组，读取cmd指令内容到buffer
    memset( buffer, 0, sizeof(buffer) );
    fp = popen( cmd, "r");
    if( NULL == fp )
    {
        printf("popen return null\n");
        return;
    }
    fread( buffer, sizeof(char), sizeof(buffer)-1, fp);
    buffer[sizeof(buffer)-1] = '\0';
    fclose( fp );

    //新建文件，并把buffer中的内容写入
    fp = fopen( filename, "wt");
    fwrite( buffer, sizeof(char), strlen(buffer)+1, fp);
    fclose( fp );
    
}