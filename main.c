
#include <string.h>
#include <stdio.h>
#include "str.h" 
#include "lwjson/lwjson.h"


int processMsg(uint8_t *buff, int len);

static lwjson_token_t tokens[128];
static lwjson_t lwjson;

int main(){

	int sz = strlen(json_str);
	/* printf("%s",json_str); */
	processMsg( json_str, sz );
	/* printf("%s",json_str); */

	return 0;
}
/*
        "sender":"supercap",
        "receiver":"Broker",
        "hw_id":"XXYYZZ0002",
        "message_id":"PER_DT",
        "group_id":"a93cf2ff-2a0a-4992-bb54-cc8bdeed1902",
        "state":"OPERN",
        "timestamp":"1699947499",
 
*/
static lwjson_token_t tokens[128];
static lwjson_t lwjson;

int processMsg(uint8_t *buff, int len){
	char *value;
	const lwjson_token_t* t1;
	char key[] = "timestamp";

	lwjson_init(&lwjson, tokens, LWJSON_ARRAYSIZE(tokens));
	if (lwjson_parse(&lwjson, (const char*) buff) == lwjsonOK)
	{

		printf("%s",buff);
		printf("\nparse ok\n");

		if ((t1 = lwjson_find(&lwjson, key) != NULL))
			value  = printf("\nfound '%s'",key );
			lwjson_get_val_string(t, &length);
			printf("\nvalue:'%s'", value);

		else{
			printf("\ncouldn't find '%s'",key);
		}

		if ((t1 = lwjson_find(&lwjson, "Capacitor_ata") != NULL)){
			printf("\n found capacitor data 'key' \n");
		}
		else{
			printf("\n couldn't find key' \n");
		}

}
		/* char* str = lwjson_get_val_string(t, &length); */
success:
		lwjson_free(&lwjson);
		return 1;
fail:
		lwjson_free(&lwjson);
		return 0;
	}
