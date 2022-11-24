/**
 * Copyright 2022 mohammad
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <stdlib.h>
#include <stdio.h>
typedef struct s_node
{
    int value;
    struct s_node *next;
} Node;

int main(int argc, char *argv[])
{
    int *a = malloc(sizeof(int));
    *a = 10;
    int **b = &a;
    int c = 30;
    *b = &c;
    *a = 40;
    printf("adresses: %p %p %d %p %p \n %p", a, &a, *a, b, &b, *b);
    free(a);
    return 0;
}