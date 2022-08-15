/*
 ============================================================================
 Name        : llvm_pass.c
 Author      : Hannah Peeler
 Version     : 1.0
 Copyright   : 
 
    Copyright 2019 Arm Inc., Andrew Sloss, Hannah Peeler

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.

    Please refer to 
    https://github.com/ARM-software/Shackleton-Framework/blob/master/LICENSE.TXT
    for a full overview of the license covering this work.
    
 Description : LLVM optimization pass object type for use with the LLVM
                    integrated portion of the Shackleton Framework
 ============================================================================
 */

/*
 * IMPORT ...
 */

#include "../osaka/osaka.h"
#include "llvm_pass.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>

/*
 * ROUTINES
 */

uint32_t llvm_pass_uid(void)  {
    
    static uint32_t uid=0;
    return ++uid;

}

/*
char*** llvm_set_default_level_strings(const int num_levels) {
    char*** default_strings = malloc(sizeof(char**) * num_levels);
    char** opt = malloc(sizeof(char*) * 3);
    char** O0 = malloc(sizeof(char*) * 10);
    char** O1 = malloc(sizeof(char*) * 78);
    char** O2 = malloc(sizeof(char*) * 83);
    char** O3 = malloc(sizeof(char*) * 86);
    char** Os = malloc(sizeof(char*) * 81);
    char** Oz = malloc(sizeof(char*) * 80);

    opt = {"-tti", "-verify", "-targetlibinfo"};
    O0 = {"-tti", "-always-inline", "-basiccg", "-assumption-cache-tracker", "-verify", "-targetlibinfo", "-barrier", "-ee-instrument", "-forceattrs", "-profile-summary-info"};
    O1 = {"-licm", "-jump-threading", "-memoryssa", "-early-cse-memssa", "-memdep", "-tbaa", "-bdce", "-instsimplify", "-loop-sink", "-strip-dead-prototypes", "-aa", "-scalar-evolution", "-transform-warning", "-phi-values", "-early-cse", "-block-freq", "-globaldce", "-verify", "-instcombine", "-correlated-propagation", "-prune-eh", "-postdomtree", "-loop-unswitch", "-ipsccp", "-branch-prob", "-loop-unroll", "-basicaa", "-lower-expect", "-basiccg", "-loop-distribute", "-sccp", "-functionattrs", "-lazy-branch-prob", "-adce", "-float2int", "-alignment-from-assumptions", "-inferattrs", "-profile-summary-info", "-lazy-value-info", "-rpo-functionattrs", "-globals-aa", "-reassociate", "-libcalls-shrinkwrap", "-dse", "-loop-vectorize", "-domtree", "-mem2reg", "-opt-remark-emitter", "-loop-simplify", "-loop-idiom", "-pgo-memop-opt", "-lcssa-verification", "-called-value-propagation", "-demanded-bits", "-div-rem-pairs", "-forceattrs", "-globalopt", "-indvars", "-simplifycfg", "-tti", "-memcpyopt", "-loop-rotate", "-targetlibinfo", "-barrier", "-lcssa", "-loop-deletion", "-always-inline", "-loop-load-elim", "-sroa", "-lazy-block-freq", "-ee-instrument", "-loops", "-assumption-cache-tracker", "-loop-accesses", "-deadargelim", "-scoped-noalias", "-speculative-execution", "-tailcallelim"};
    O2 = {"-licm", "-jump-threading", "-memoryssa", "-early-cse-memssa", "-memdep", "-tbaa", "-bdce", "-instsimplify", "-loop-sink", "-strip-dead-prototypes", "-aa", "-scalar-evolution", "-transform-warning", "-phi-values", "-early-cse", "-block-freq", "-gvn", "-verify", "-globaldce", "-instcombine", "-correlated-propagation", "-prune-eh", "-postdomtree", "-mldst-motion", "-loop-unswitch", "-elim-avail-extern", "-ipsccp", "-slp-vectorizer", "-branch-prob", "-loop-unroll", "-basicaa", "-lower-expect", "-basiccg", "-loop-distribute", "-sccp", "-inline", "-functionattrs", "-lazy-branch-prob", "-adce", "-float2int", "-alignment-from-assumptions", "-inferattrs", "-profile-summary-info", "-lazy-value-info", "-rpo-functionattrs", "-globals-aa", "-constmerge", "-reassociate", "-libcalls-shrinkwrap", "-dse", "-loop-vectorize", "-domtree", "-mem2reg", "-opt-remark-emitter", "-loop-simplify", "-loop-idiom", "-pgo-memop-opt", "-lcssa-verification", "-called-value-propagation", "-demanded-bits", "-div-rem-pairs", "-forceattrs", "-globalopt", "-indvars", "-simplifycfg", "-tti", "-memcpyopt", "-loop-rotate", "-targetlibinfo", "-barrier", "-lcssa", "-loop-deletion", "-loop-load-elim", "-sroa", "-lazy-block-freq", "-ee-instrument", "-loops", "-assumption-cache-tracker", "-loop-accesses", "-deadargelim", "-scoped-noalias", "-speculative-execution", "-tailcallelim"};
    O3 = {"-licm", "-jump-threading", "-memoryssa", "-early-cse-memssa", "-memdep", "-tbaa", "-bdce", "-instsimplify", "-loop-sink", "-strip-dead-prototypes", "-aa", "-argpromotion", "-callsite-splitting", "-aggressive-instcombine", "-scalar-evolution", "-transform-warning", "-phi-values", "-early-cse", "-block-freq", "-gvn", "-verify", "-globaldce", "-instcombine", "-correlated-propagation", "-prune-eh", "-postdomtree", "-mldst-motion", "-loop-unswitch", "-elim-avail-extern", "-ipsccp", "-slp-vectorizer", "-branch-prob", "-loop-unroll", "-basicaa", "-lower-expect", "-basiccg", "-loop-distribute", "-sccp", "-inline", "-functionattrs", "-lazy-branch-prob", "-adce", "-float2int", "-alignment-from-assumptions", "-inferattrs", "-profile-summary-info", "-lazy-value-info", "-rpo-functionattrs", "-globals-aa", "-constmerge", "-reassociate", "-libcalls-shrinkwrap", "-dse", "-loop-vectorize", "-domtree", "-mem2reg", "-opt-remark-emitter", "-loop-simplify", "-loop-idiom", "-pgo-memop-opt", "-lcssa-verification", "-called-value-propagation", "-demanded-bits", "-div-rem-pairs", "-forceattrs", "-globalopt", "-indvars", "-simplifycfg", "-tti", "-memcpyopt", "-loop-rotate", "-targetlibinfo", "-barrier", "-lcssa", "-loop-deletion", "-loop-load-elim", "-sroa", "-lazy-block-freq", "-ee-instrument", "-loops", "-assumption-cache-tracker", "-loop-accesses", "-deadargelim", "-scoped-noalias", "-speculative-execution", "-tailcallelim"};
    Os = {"-licm", "-jump-threading", "-memoryssa", "-early-cse-memssa", "-memdep", "-tbaa", "-bdce", "-instsimplify", "-loop-sink", "-strip-dead-prototypes", "-aa", "-scalar-evolution", "-transform-warning", "-phi-values", "-block-freq", "-early-cse", "-gvn", "-verify", "-globaldce", "-instcombine", "-correlated-propagation", "-prune-eh", "-postdomtree", "-mldst-motion", "-loop-unswitch", "-elim-avail-extern", "-ipsccp", "-slp-vectorizer", "-branch-prob", "-loop-unroll", "-basicaa", "-lower-expect", "-basiccg", "-loop-distribute", "-sccp", "-inline", "-functionattrs", "-lazy-branch-prob", "-adce", "-float2int", "-alignment-from-assumptions", "-inferattrs", "-profile-summary-info", "-lazy-value-info", "-rpo-functionattrs", "-globals-aa", "-constmerge", "-reassociate", "-dse", "-loop-vectorize", "-domtree", "-mem2reg", "-opt-remark-emitter", "-loop-simplify", "-loop-idiom", "-lcssa-verification", "-called-value-propagation", "-demanded-bits", "-div-rem-pairs", "-forceattrs", "-globalopt", "-indvars", "-simplifycfg", "-tti", "-memcpyopt", "-loop-rotate", "-targetlibinfo", "-barrier", "-lcssa", "-loop-deletion", "-loop-load-elim", "-sroa", "-lazy-block-freq", "-ee-instrument", "-loops", "-assumption-cache-tracker", "-loop-accesses", "-deadargelim", "-scoped-noalias", "-speculative-execution", "-tailcallelim"};
    Oz = {"-licm", "-jump-threading", "-memoryssa", "-early-cse-memssa", "-memdep", "-tbaa", "-bdce", "-instsimplify", "-loop-sink", "-strip-dead-prototypes", "-aa", "-scalar-evolution", "-transform-warning", "-phi-values", "-block-freq", "-early-cse", "-gvn", "-verify", "-globaldce", "-instcombine", "-correlated-propagation", "-prune-eh", "-postdomtree", "-mldst-motion", "-loop-unswitch", "-elim-avail-extern", "-ipsccp", "-branch-prob", "-loop-unroll", "-basicaa", "-lower-expect", "-basiccg", "-loop-distribute", "-sccp", "-inline", "-functionattrs", "-lazy-branch-prob", "-adce", "-float2int", "-alignment-from-assumptions", "-inferattrs", "-profile-summary-info", "-lazy-value-info", "-rpo-functionattrs", "-globals-aa", "-constmerge", "-reassociate", "-dse", "-loop-vectorize", "-domtree", "-mem2reg", "-opt-remark-emitter", "-loop-simplify", "-loop-idiom", "-lcssa-verification", "-called-value-propagation", "-demanded-bits", "-div-rem-pairs", "-forceattrs", "-globalopt", "-indvars", "-simplifycfg", "-tti", "-memcpyopt", "-loop-rotate", "-targetlibinfo", "-barrier", "-lcssa", "-loop-deletion", "-loop-load-elim", "-sroa", "-lazy-block-freq", "-ee-instrument", "-loops", "-assumption-cache-tracker", "-loop-accesses", "-deadargelim", "-scoped-noalias", "-speculative-execution", "-tailcallelim"};
    
    char opt[3][50] = {"-tti", "-verify", "-targetlibinfo"};
    char O0[10][50] = {"-tti", "-always-inline", "-basiccg", "-assumption-cache-tracker", "-verify", "-targetlibinfo", "-barrier", "-ee-instrument", "-forceattrs", "-profile-summary-info"};
    char O1[78][50] = {"-licm", "-jump-threading", "-memoryssa", "-early-cse-memssa", "-memdep", "-tbaa", "-bdce", "-instsimplify", "-loop-sink", "-strip-dead-prototypes", "-aa", "-scalar-evolution", "-transform-warning", "-phi-values", "-early-cse", "-block-freq", "-globaldce", "-verify", "-instcombine", "-correlated-propagation", "-prune-eh", "-postdomtree", "-loop-unswitch", "-ipsccp", "-branch-prob", "-loop-unroll", "-basicaa", "-lower-expect", "-basiccg", "-loop-distribute", "-sccp", "-functionattrs", "-lazy-branch-prob", "-adce", "-float2int", "-alignment-from-assumptions", "-inferattrs", "-profile-summary-info", "-lazy-value-info", "-rpo-functionattrs", "-globals-aa", "-reassociate", "-libcalls-shrinkwrap", "-dse", "-loop-vectorize", "-domtree", "-mem2reg", "-opt-remark-emitter", "-loop-simplify", "-loop-idiom", "-pgo-memop-opt", "-lcssa-verification", "-called-value-propagation", "-demanded-bits", "-div-rem-pairs", "-forceattrs", "-globalopt", "-indvars", "-simplifycfg", "-tti", "-memcpyopt", "-loop-rotate", "-targetlibinfo", "-barrier", "-lcssa", "-loop-deletion", "-always-inline", "-loop-load-elim", "-sroa", "-lazy-block-freq", "-ee-instrument", "-loops", "-assumption-cache-tracker", "-loop-accesses", "-deadargelim", "-scoped-noalias", "-speculative-execution", "-tailcallelim"};
    char O2[83][50] = {"-licm", "-jump-threading", "-memoryssa", "-early-cse-memssa", "-memdep", "-tbaa", "-bdce", "-instsimplify", "-loop-sink", "-strip-dead-prototypes", "-aa", "-scalar-evolution", "-transform-warning", "-phi-values", "-early-cse", "-block-freq", "-gvn", "-verify", "-globaldce", "-instcombine", "-correlated-propagation", "-prune-eh", "-postdomtree", "-mldst-motion", "-loop-unswitch", "-elim-avail-extern", "-ipsccp", "-slp-vectorizer", "-branch-prob", "-loop-unroll", "-basicaa", "-lower-expect", "-basiccg", "-loop-distribute", "-sccp", "-inline", "-functionattrs", "-lazy-branch-prob", "-adce", "-float2int", "-alignment-from-assumptions", "-inferattrs", "-profile-summary-info", "-lazy-value-info", "-rpo-functionattrs", "-globals-aa", "-constmerge", "-reassociate", "-libcalls-shrinkwrap", "-dse", "-loop-vectorize", "-domtree", "-mem2reg", "-opt-remark-emitter", "-loop-simplify", "-loop-idiom", "-pgo-memop-opt", "-lcssa-verification", "-called-value-propagation", "-demanded-bits", "-div-rem-pairs", "-forceattrs", "-globalopt", "-indvars", "-simplifycfg", "-tti", "-memcpyopt", "-loop-rotate", "-targetlibinfo", "-barrier", "-lcssa", "-loop-deletion", "-loop-load-elim", "-sroa", "-lazy-block-freq", "-ee-instrument", "-loops", "-assumption-cache-tracker", "-loop-accesses", "-deadargelim", "-scoped-noalias", "-speculative-execution", "-tailcallelim"};
    char O3[86][50] = {"-licm", "-jump-threading", "-memoryssa", "-early-cse-memssa", "-memdep", "-tbaa", "-bdce", "-instsimplify", "-loop-sink", "-strip-dead-prototypes", "-aa", "-argpromotion", "-callsite-splitting", "-aggressive-instcombine", "-scalar-evolution", "-transform-warning", "-phi-values", "-early-cse", "-block-freq", "-gvn", "-verify", "-globaldce", "-instcombine", "-correlated-propagation", "-prune-eh", "-postdomtree", "-mldst-motion", "-loop-unswitch", "-elim-avail-extern", "-ipsccp", "-slp-vectorizer", "-branch-prob", "-loop-unroll", "-basicaa", "-lower-expect", "-basiccg", "-loop-distribute", "-sccp", "-inline", "-functionattrs", "-lazy-branch-prob", "-adce", "-float2int", "-alignment-from-assumptions", "-inferattrs", "-profile-summary-info", "-lazy-value-info", "-rpo-functionattrs", "-globals-aa", "-constmerge", "-reassociate", "-libcalls-shrinkwrap", "-dse", "-loop-vectorize", "-domtree", "-mem2reg", "-opt-remark-emitter", "-loop-simplify", "-loop-idiom", "-pgo-memop-opt", "-lcssa-verification", "-called-value-propagation", "-demanded-bits", "-div-rem-pairs", "-forceattrs", "-globalopt", "-indvars", "-simplifycfg", "-tti", "-memcpyopt", "-loop-rotate", "-targetlibinfo", "-barrier", "-lcssa", "-loop-deletion", "-loop-load-elim", "-sroa", "-lazy-block-freq", "-ee-instrument", "-loops", "-assumption-cache-tracker", "-loop-accesses", "-deadargelim", "-scoped-noalias", "-speculative-execution", "-tailcallelim"};
    char Os[81][50] = {"-licm", "-jump-threading", "-memoryssa", "-early-cse-memssa", "-memdep", "-tbaa", "-bdce", "-instsimplify", "-loop-sink", "-strip-dead-prototypes", "-aa", "-scalar-evolution", "-transform-warning", "-phi-values", "-block-freq", "-early-cse", "-gvn", "-verify", "-globaldce", "-instcombine", "-correlated-propagation", "-prune-eh", "-postdomtree", "-mldst-motion", "-loop-unswitch", "-elim-avail-extern", "-ipsccp", "-slp-vectorizer", "-branch-prob", "-loop-unroll", "-basicaa", "-lower-expect", "-basiccg", "-loop-distribute", "-sccp", "-inline", "-functionattrs", "-lazy-branch-prob", "-adce", "-float2int", "-alignment-from-assumptions", "-inferattrs", "-profile-summary-info", "-lazy-value-info", "-rpo-functionattrs", "-globals-aa", "-constmerge", "-reassociate", "-dse", "-loop-vectorize", "-domtree", "-mem2reg", "-opt-remark-emitter", "-loop-simplify", "-loop-idiom", "-lcssa-verification", "-called-value-propagation", "-demanded-bits", "-div-rem-pairs", "-forceattrs", "-globalopt", "-indvars", "-simplifycfg", "-tti", "-memcpyopt", "-loop-rotate", "-targetlibinfo", "-barrier", "-lcssa", "-loop-deletion", "-loop-load-elim", "-sroa", "-lazy-block-freq", "-ee-instrument", "-loops", "-assumption-cache-tracker", "-loop-accesses", "-deadargelim", "-scoped-noalias", "-speculative-execution", "-tailcallelim"};
    char Oz[80][50] = {"-licm", "-jump-threading", "-memoryssa", "-early-cse-memssa", "-memdep", "-tbaa", "-bdce", "-instsimplify", "-loop-sink", "-strip-dead-prototypes", "-aa", "-scalar-evolution", "-transform-warning", "-phi-values", "-block-freq", "-early-cse", "-gvn", "-verify", "-globaldce", "-instcombine", "-correlated-propagation", "-prune-eh", "-postdomtree", "-mldst-motion", "-loop-unswitch", "-elim-avail-extern", "-ipsccp", "-branch-prob", "-loop-unroll", "-basicaa", "-lower-expect", "-basiccg", "-loop-distribute", "-sccp", "-inline", "-functionattrs", "-lazy-branch-prob", "-adce", "-float2int", "-alignment-from-assumptions", "-inferattrs", "-profile-summary-info", "-lazy-value-info", "-rpo-functionattrs", "-globals-aa", "-constmerge", "-reassociate", "-dse", "-loop-vectorize", "-domtree", "-mem2reg", "-opt-remark-emitter", "-loop-simplify", "-loop-idiom", "-lcssa-verification", "-called-value-propagation", "-demanded-bits", "-div-rem-pairs", "-forceattrs", "-globalopt", "-indvars", "-simplifycfg", "-tti", "-memcpyopt", "-loop-rotate", "-targetlibinfo", "-barrier", "-lcssa", "-loop-deletion", "-loop-load-elim", "-sroa", "-lazy-block-freq", "-ee-instrument", "-loops", "-assumption-cache-tracker", "-loop-accesses", "-deadargelim", "-scoped-noalias", "-speculative-execution", "-tailcallelim"};
    
    default_strings[0] = opt;
    default_strings[1] = O0;
    default_strings[2] = O1;
    default_strings[3] = O2;
    default_strings[4] = O3;
    default_strings[5] = Os;
    default_strings[6] = Oz;
    return default_strings;

}*/

/*
 *
 *
 *
 * char*** llvm_set_default_level_strings(int* default_string_lengths, const int num_levels)
 * and
 * int* llvm_default_level_string_lengths_(const int num_levels)
 * and 
 * void llvm_pass_set_valid_values(object_llvm_pass_str* o)
 *
 * ARE MOVED TO src/passes/llvm_pass_dflt.c;
 * 
 *
 **/



object_llvm_pass_str *llvm_pass_createobject(void)    {

    object_llvm_pass_str *o;
    pass_struct *s;

    o = malloc(sizeof(object_llvm_pass_str));
    s = malloc(sizeof(pass_struct));

    assert(o!=NULL);
    assert(s!=NULL);

    PASS_STRUCT(o) = s;
    PASS_INDEX(o) = -1;
    PASS(o) = "not set";
    
    llvm_pass_set_valid_values(o);

    return o;

}

void llvm_pass_randomizeobject(object_llvm_pass_str* o) {
    
    if (PASS_CONSTRAINED(o)) {

        int num_valid_values = PASS_NUM_VALID_VALUES(o);
        int new_item = (int) (num_valid_values * (rand() / (RAND_MAX + 1.0)));
        PASS_INDEX(o) = new_item;
        PASS(o) = PASS_VALID_VALUES(o)[new_item];

    }
    else {
        
        int rand_length = (int) (20 * (rand() / (RAND_MAX + 1.0)));
        PASS(o) = randomString(rand_length);

    }

}

void llvm_pass_setobject(object_llvm_pass_str* o, char* pass) {
    if (PASS_CONSTRAINED(o)) {
        int num_valid_values = PASS_NUM_VALID_VALUES(o);
        int new_item = llvm_find_pass(PASS_VALID_VALUES(o), num_valid_values, pass);
        if (new_item < 0) {
            new_item = (int) (num_valid_values * (rand() / (RAND_MAX + 1.0)));
        }
        PASS_INDEX(o) = new_item;
        PASS(o) = PASS_VALID_VALUES(o)[new_item];

    }
    else {
        int rand_length = (int) (20 * (rand() / (RAND_MAX + 1.0)));
        PASS(o) = randomString(rand_length);
    }
}

int llvm_find_pass(char** values, int num_valid_values, char* pass) {
    for (int i = 0; i < num_valid_values; i++) {
        if (strcmp(values[i], pass) == 0) {
            //printf("passes are equal: %s, %s\n", values[i], pass);
            return i;
        }
    }
    return -1;
}

void llvm_pass_printobject(object_llvm_pass_str *o)   {

    printf("pass : %s(%d)", PASS(o), PASS_INDEX(o));

}

void llvm_pass_describeobject(char* desc, object_llvm_pass_str *o) {

    strcat(desc, PASS(o));

}

void llvm_pass_deleteobject(object_llvm_pass_str *s)  {

    assert(s!=NULL);

    free(PASS_VALID_VALUES(s));
    free(PASS_STRUCT(s));
    free(s);

}

void llvm_pass_writeobject(FILE *stream,object_llvm_pass_str *o)  {

    assert(stream!=NULL);

    fwrite(o,sizeof(object_llvm_pass_str),1,stream);

}

void *llvm_pass_readobject(FILE *stream)   {

    object_llvm_pass_str *o;
    pass_struct *s;

    assert(stream!=NULL);


    o=malloc(sizeof(object_llvm_pass_str));
    s=malloc(sizeof(pass_struct));
    assert(o!=NULL);
    assert(s!=NULL);

    fread(o,sizeof(object_llvm_pass_str),1,stream);

    return o;

}

void *llvm_pass_copyobject(object_llvm_pass_str *o)   {

    object_llvm_pass_str *c = llvm_pass_createobject();

    PASS_INDEX(c) = PASS_INDEX(o);
    PASS(c) = PASS_VALID_VALUES(c)[PASS_INDEX(c)];

    return c;

}

bool llvm_pass_compareobject(object_llvm_pass_str *o1, object_llvm_pass_str *o2)   {

    return PASS_INDEX(o1) == PASS_INDEX(o2);
}
