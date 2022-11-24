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

#include <stdio.h>
#include "debug.h"
#include "value.h"

static int simpleInstruction(const char *name, int offset);
static int constantInstruction(const char *name, Chunk *chunk, int offset);

void disassembleChunk(Chunk *chunk, const char *name)
{
    printf("== %s == \n", name);

    for (int offset = 0; offset < chunk->count;)
    {
        offset = disassembleInstruction(chunk, offset);
    }
}

int disasssebmleInstruction(Chunk *chunk, int offset)
{
    printf("%04d", offset);
    if (offset > 0 && chunk->lines[offset] == chunk->lines[offset - 1])
    {
        printf("%4d ", offset);
    }
    else
    {
        printf("%4d ", chunk->lines[offset]);
    }
    uint8_t instruction = chunk->code[offset];
    switch (instruction)
    {
    case OP_RETURN:
        return simpleInstruction("OP_RETURN", offset);
    case OP_CONSTANT:
        return constantInstruction("OP_CONSTANT", chunk, offset);
    case OP_NEGATE:
        return simpleInstruction("OP_NEGATE", offset);
    case OP_ADD:
        return simpleInstruction("OP_ADD", offset);
    case OP_SUBTRACT:
        return simpleInstruction("OP_SUBTRACT", offset);
    case OP_MULTIPLY:
        return simpleInstruction("OP_MULTIPLY", offset);
    case OP_DIVIDE:
        return simpleInstruction("OP_DIVIDE", offset);
    case OP_NIL:
        return simpleInstruction("OP_NIL", offset);
    case OP_TRUE:
        return simpleInstruction("OP_TRUE", offset);
    case OP_FALSE:
        return simpleInstruction("OP_FALSE", offset);
    case OP_NOT:
        return simpleInstruction("OP_NOT", offset);
    case OP_EQUAL:
        return simpleInstruction("OP_EQUAL", offset);
    case OP_GREATER:
        return simpleInstruction("OP_GREATER", offset);
    case OP_LESS:
        return simpleInstruction("OP_LESS", offset);
    default:
        printf("Unknown opcode %d\n", instruction);
        return offset + 1;
    }
}

static int simpleInstruction(const char *name, int offset)
{
    printf("%s\n", name);
    return offset + 1;
}

static int constantInstruction(const char *name, Chunk *chunk, int offset)
{
    uint8_t constant = chunk->code[offset + 1];
    printf("%-16s %4d", name, constant);
    printValue(chunk->constants.values[constant]);
    printf("\n");
    return offset + 2;
}