/*
 * gi_llvm_pass.c
 *
 * Created on: <created_date>
 * Author: Auto-generated .c file using Shackleton tool
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <stdint.h>
 #include <assert.h>
 #include <string.h>

 #include "../osaka/osaka.h"
 #include "gi_llvm_pass.h"
 #include "llvm_pass.h"

uint32_t gi_llvm_pass_uid(void) {

    static uint32_t uid=0;
    return ++uid;

}

void gi_llvm_pass_patch_type_set_valid_values(object_gi_llvm_pass_str* o) {

	char** values = malloc(sizeof(char*) * 3);
	values[0] = "insertion";
	values[1] = "deletion";
	values[2] = "replacement";
	GI_LLVM_PASS_PATCH_TYPE_VALID_VALUES(o) = values;
	GI_LLVM_PASS_PATCH_TYPE_CONSTRAINED(o) = true;
	GI_LLVM_PASS_PATCH_TYPE_NUM_VALID_VALUES(o) = 3;

	return;

}

char*** gi_llvm_set_default_level_strings(int* default_string_lengths, const int num_levels) {
  return llvm_set_default_level_strings(default_string_lengths, num_levels);
}

int* gi_llvm_default_level_string_lengths(const int num_levels) {
  return llvm_default_level_string_lengths(num_levels) ;
}


void gi_llvm_pass_new_pass_set_valid_values(object_gi_llvm_pass_str* o) {
  // creating a quick temporary object here
  object_llvm_pass_str o_temp;
  pass_struct pass ;
  o_temp.pass = &pass;

  // loading the valid values
  llvm_pass_set_valid_values(&o_temp);

  // and copying them to the gi_ object
  o->pass_type->constrained = o_temp.pass->constrained;
  o->pass_type->valid_values = o_temp.pass->valid_values;
  o->pass_type->num_values = o_temp.pass->num_values;


}

object_gi_llvm_pass_str *gi_llvm_pass_createobject(void) {

    object_gi_llvm_pass_str *o;
	gi_llvm_pass_patch_type *gi_llvm_pass_patch_type_o;
	gi_llvm_pass_location *gi_llvm_pass_location_o;
	gi_llvm_pass_new_pass *gi_llvm_pass_new_pass_o;

    o = malloc(sizeof(object_gi_llvm_pass_str));
	gi_llvm_pass_patch_type_o = malloc(sizeof(gi_llvm_pass_patch_type));
	gi_llvm_pass_location_o = malloc(sizeof(gi_llvm_pass_location));
	gi_llvm_pass_new_pass_o = malloc(sizeof(gi_llvm_pass_new_pass));

	assert(o!=NULL);
	assert(gi_llvm_pass_patch_type_o!=NULL);
	assert(gi_llvm_pass_location_o!=NULL);
	assert(gi_llvm_pass_new_pass_o!=NULL);

	GI_LLVM_PASS_PATCH_TYPE_STRUCT(o) = gi_llvm_pass_patch_type_o;
	GI_LLVM_PASS_LOCATION_STRUCT(o) = gi_llvm_pass_location_o;
	GI_LLVM_PASS_NEW_PASS_STRUCT(o) = gi_llvm_pass_new_pass_o;

	GI_LLVM_PASS_PATCH_TYPE_MY_PATCH_TYPE(o) = "not set";
	GI_LLVM_PASS_PATCH_TYPE_MY_PATCH_TYPE_INDEX(o) = -1;
	gi_llvm_pass_patch_type_set_valid_values(o);

	GI_LLVM_PASS_LOCATION_MY_LOCATION(o) = -1;
	GI_LLVM_PASS_LOCATION_CONSTRAINED(o) = false;
	GI_LLVM_PASS_LOCATION_VALID_VALUES(o) = NULL;
	GI_LLVM_PASS_LOCATION_NUM_VALID_VALUES(o) = 0;

	GI_LLVM_PASS_NEW_PASS_MY_NEW_PASS(o) = "not set";
	GI_LLVM_PASS_NEW_PASS_MY_NEW_PASS_INDEX(o) = -1;
	gi_llvm_pass_new_pass_set_valid_values(o);

	return o;

}

void gi_llvm_pass_randomizeobject(object_gi_llvm_pass_str *o) {

	uint32_t num_valid_values0 = GI_LLVM_PASS_PATCH_TYPE_NUM_VALID_VALUES(o);
	uint32_t new_index0 = (uint32_t) (num_valid_values0 * (rand() / (RAND_MAX + 1.0)));
	GI_LLVM_PASS_PATCH_TYPE_MY_PATCH_TYPE_INDEX(o) = new_index0;
	GI_LLVM_PASS_PATCH_TYPE_MY_PATCH_TYPE(o) = GI_LLVM_PASS_PATCH_TYPE_VALID_VALUES(o)[new_index0];

	GI_LLVM_PASS_LOCATION_MY_LOCATION(o) = rand() / (RAND_MAX + 1.0);
    //printf("NEW OBJECT LOCATION: %lf\n\n", GI_LLVM_PASS_LOCATION_MY_LOCATION(o));

	uint32_t num_valid_values1 = GI_LLVM_PASS_NEW_PASS_NUM_VALID_VALUES(o);
	uint32_t new_index1 = (uint32_t) (num_valid_values1 * (rand() / (RAND_MAX + 1.0)));
	GI_LLVM_PASS_NEW_PASS_MY_NEW_PASS_INDEX(o) = new_index1;
	GI_LLVM_PASS_NEW_PASS_MY_NEW_PASS(o) = GI_LLVM_PASS_NEW_PASS_VALID_VALUES(o)[new_index1];

}

void gi_llvm_pass_setobject(object_gi_llvm_pass_str* o, char* pass) {
    
	return;

}

char* gi_llvm_pass_get_type(object_gi_llvm_pass_str *o) {
    return GI_LLVM_PASS_PATCH_TYPE_MY_PATCH_TYPE(o);
}

double gi_llvm_pass_get_loc(object_gi_llvm_pass_str *o) {
    return GI_LLVM_PASS_LOCATION_MY_LOCATION(o);
}

char* gi_llvm_pass_get_pass(object_gi_llvm_pass_str *o) {
    return GI_LLVM_PASS_NEW_PASS_MY_NEW_PASS(o);
}

void gi_llvm_pass_printobject(object_gi_llvm_pass_str *o) {

	printf("PATCH_TYPE : %s ; ", GI_LLVM_PASS_PATCH_TYPE_MY_PATCH_TYPE(o));
	printf("LOCATION : %lf ; ", GI_LLVM_PASS_LOCATION_MY_LOCATION(o));
	printf("NEW_PASS : %s", GI_LLVM_PASS_NEW_PASS_MY_NEW_PASS(o));

}

void *gi_llvm_pass_describeobject(char* desc, object_gi_llvm_pass_str *o) {

    char* pass_type = GI_LLVM_PASS_PATCH_TYPE_MY_PATCH_TYPE(o);

    float location = GI_LLVM_PASS_LOCATION_MY_LOCATION(o);
    char loc_str[8];
    gcvt(location, 4, loc_str);
    char* new_pass = GI_LLVM_PASS_NEW_PASS_MY_NEW_PASS(o);
    
    strcat(desc, pass_type);
    strcat(desc, " ");
    strcat(desc, loc_str);
    strcat(desc, " ");
    strcat(desc, new_pass);
    strcat(desc, "\n");

}

void gi_llvm_pass_deleteobject(object_gi_llvm_pass_str *s) {

	assert(s!=NULL);

	free(GI_LLVM_PASS_PATCH_TYPE_VALID_VALUES(s));
	free(GI_LLVM_PASS_PATCH_TYPE_STRUCT(s));
	free(GI_LLVM_PASS_LOCATION_STRUCT(s));
	free(GI_LLVM_PASS_NEW_PASS_VALID_VALUES(s));
	free(GI_LLVM_PASS_NEW_PASS_STRUCT(s));

	free(s);

}

void gi_llvm_pass_writeobject(FILE *stream, object_gi_llvm_pass_str *o) {

    assert(stream!=NULL);
    fwrite(o, sizeof(object_gi_llvm_pass_str), 1, stream);

}

void *gi_llvm_pass_readobject(FILE *stream) {

    object_gi_llvm_pass_str *o;
	gi_llvm_pass_patch_type *gi_llvm_pass_patch_type_o;
	gi_llvm_pass_location *gi_llvm_pass_location_o;
	gi_llvm_pass_new_pass *gi_llvm_pass_new_pass_o;

	assert(stream!=NULL);

	o = malloc(sizeof(object_gi_llvm_pass_str));
	gi_llvm_pass_patch_type_o = malloc(sizeof(gi_llvm_pass_patch_type));
	gi_llvm_pass_location_o = malloc(sizeof(gi_llvm_pass_location));
	gi_llvm_pass_new_pass_o = malloc(sizeof(gi_llvm_pass_new_pass));

	assert(o!=NULL);
	assert(gi_llvm_pass_patch_type_o!=NULL);
	assert(gi_llvm_pass_location_o!=NULL);
	assert(gi_llvm_pass_new_pass_o!=NULL);

	GI_LLVM_PASS_PATCH_TYPE_STRUCT(o) = gi_llvm_pass_patch_type_o;
	GI_LLVM_PASS_LOCATION_STRUCT(o) = gi_llvm_pass_location_o;
	GI_LLVM_PASS_NEW_PASS_STRUCT(o) = gi_llvm_pass_new_pass_o;

	fread(o, sizeof(object_gi_llvm_pass_str), 1, stream);

	return o;

}

void *gi_llvm_pass_copyobject(object_gi_llvm_pass_str *o) {

	//printf("\nNow in copy object\n");
    object_gi_llvm_pass_str *c = gi_llvm_pass_createobject();

    //printf("\nObject has been created\n");
	GI_LLVM_PASS_PATCH_TYPE_MY_PATCH_TYPE_INDEX(c) = GI_LLVM_PASS_PATCH_TYPE_MY_PATCH_TYPE_INDEX(o);
	GI_LLVM_PASS_PATCH_TYPE_MY_PATCH_TYPE(c) = GI_LLVM_PASS_PATCH_TYPE_VALID_VALUES(c)[GI_LLVM_PASS_PATCH_TYPE_MY_PATCH_TYPE_INDEX(o)];
    //printf("\nGot through editing the patch type\n");

	GI_LLVM_PASS_LOCATION_MY_LOCATION(c) = GI_LLVM_PASS_LOCATION_MY_LOCATION(o);
    //printf("\nGot through editing the location\n");

	GI_LLVM_PASS_NEW_PASS_MY_NEW_PASS_INDEX(c) = GI_LLVM_PASS_NEW_PASS_MY_NEW_PASS_INDEX(o);
	GI_LLVM_PASS_NEW_PASS_MY_NEW_PASS(c) = GI_LLVM_PASS_NEW_PASS_VALID_VALUES(c)[GI_LLVM_PASS_NEW_PASS_MY_NEW_PASS_INDEX(o)];
    //printf("\nGot through editing the new pass\n");

	return c;

}

bool gi_llvm_pass_compareobject(object_gi_llvm_pass_str *o1, object_gi_llvm_pass_str *o2)   {
    if (GI_LLVM_PASS_PATCH_TYPE_MY_PATCH_TYPE_INDEX(o1) != GI_LLVM_PASS_PATCH_TYPE_MY_PATCH_TYPE_INDEX(o2)) {
        return false;
    }
    if (GI_LLVM_PASS_NEW_PASS_MY_NEW_PASS_INDEX(o1) != GI_LLVM_PASS_NEW_PASS_MY_NEW_PASS_INDEX(o2)) {
        return false;
    }
    if (fabs(GI_LLVM_PASS_LOCATION_MY_LOCATION(o1) - GI_LLVM_PASS_LOCATION_MY_LOCATION(o2)) > 0.001) {
        return false;
    }
    return true;

}
