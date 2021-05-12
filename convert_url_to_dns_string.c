#include<stdio.h>
#include<string.h>

void util_convert_url_to_dns_string( const char* url, char* dns_format_string );
void main()
{
    char* url = "https://www.baidu.com/hello/client.html:80";
    char ans[256];
    util_convert_url_to_dns_string( url, ans);
    printf("%s\n", ans);
}

void util_convert_url_to_dns_string( const char* url, char* dns_format_string )
{
    if( NULL == url || url == '\0' )
    {
        return;
    }
    
    char buffer[256];
    char* first_match_position = NULL;

    memset( buffer, 0, sizeof(buffer) );
    strncpy( buffer, url, sizeof(buffer) );
    buffer[sizeof(buffer)-1] = '\0';

    first_match_position = strstr( url, "://" );
    if( NULL != first_match_position )
    {
        memmove( buffer, first_match_position+3, strlen(first_match_position+3)+1 );
    }

    first_match_position = strstr( buffer, ":");
    if( NULL != first_match_position )
    {
        *first_match_position = '\0';
    }

    first_match_position = strstr( buffer, "/" );
    if( NULL != first_match_position)
    {
        *first_match_position = '\0';
    }
    
    memmove( dns_format_string, buffer, sizeof(buffer) );
}
