
#include <string.h>
#include <stdio.h>
#include "str.h" 
#include "lwjson/lwjson.h"


int processMsg(uint8_t *buff, int len);


static lwjson_token_t tokens[2128];
static lwjson_t lwjson;

int main(){
	int sz = strlen(json_str);
	processMsg( json_str, sz );
	return 0;
}

int processMsg(uint8_t *buff, int len){
	char *value;
	int length;
	const lwjson_token_t* t1;
	char key[] = "timestamp";

	lwjson_init(&lwjson, tokens, LWJSON_ARRAYSIZE(tokens));
	if (lwjson_parse(&lwjson, (const char*) buff) != lwjsonOK)
		goto fail;

	printf("%s",buff);
	printf("\nparse ok\n");

	if ((t1 = lwjson_find(&lwjson, key) != NULL)){
		value  = printf("\nfound '%s'",key );
		lwjson_get_val_string(t1, &length);
		printf("\nvalue:'%s'", value);

	}
	else{
		printf("\ncouldn't find '%s'",key);
		goto fail;
	}

	if ((t1 = lwjson_find(&lwjson, "Capacitor_ata") != NULL)){
		printf("\n found capacitor data 'key' \n");
	}
	else{
		printf("\n couldn't find key' \n");
		goto fail;
	}
	/* char* str = lwjson_get_val_string(t, &length); */
success:
	lwjson_free(&lwjson);
	return 1;
fail:
	lwjson_free(&lwjson);
	return 0;
}
