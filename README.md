TINY-LEX
========

Overview
--------

This is the homework of 'compiler' -- to implement a tiny lex.

MYLEX SYNTAX
------------

File Format

    [N] the number of entries
    [Entry]
    [Entry]
    ...

Entry Format

    [Regex]
    [Handler] with the param (shm_str)
    ========= (at least 4 '=')

Smaple

    22
    (\s)|(\t)
    printf("BLANK :: '%s'\n", shm_str);
    =====================================================
    (\n)|(\r)
    printf("New Line\n");
    =====================================================
    (if)|(else)|(while)|(do)|(break)|(switch)|(for)|(case)|(struct)|(typedef)
    printf("KEY WORD :: '%s'\n", shm_str);
    =====================================================
    (int)|(float)|(double)|(long)|(char)
    printf("TYPE :: '%s'\n", shm_str);
    =====================================================
    (un)?signed
    printf("TYPE_MODIFIER :: '%s'\n", shm_str);
    =====================================================
    #((include)|(define)|(undef)|(ifdef)|(ifndef)|(if)|(endif)|(elif)|(else))
    printf("PREPROC_DERIV :: '%s'\n", shm_str);
    =====================================================
    ([a-zA-Z_])([a-z0-9A-Z_]*)
    printf("IDENTIFIER :: '%s'\n", shm_str);
    =====================================================
    ([1-9])([0-9]*)|([0-9])
    printf("INTEGER :: '%s'\n", shm_str);
    =====================================================
    (\+)|(\-)|(\*)|/|%
    printf("ARITHMETIC_OP :: '%s'\n", shm_str);
    =====================================================
    (==)|(&&)|(\|\|)|!|<|>|(<=)|(>=)
    printf("LOGICAL_OP :: '%s'\n", shm_str);
    =====================================================
    ^|&|~|\|
    printf("BIT_OP :: '%s'\n", shm_str);
    =====================================================
    \->
    printf("ACCESS_OP :: '%s'\n", shm_str);
    =====================================================
    =
    printf("ASSIGN_OP :: '%s'\n", shm_str);
    =====================================================
    ;
    printf("SEMICOLON :: '%s'\n", shm_str);
    =====================================================
    \.
    printf("DOT :: '%s'\n", shm_str);
    =====================================================
    ,
    printf("COMMA :: '%s'\n", shm_str);
    =====================================================
    \[
    printf("LEFT_SQBRAC :: '%s'\n", shm_str);
    =====================================================
    \]
    printf("RIGHT_SQBRAC :: '%s'\n", shm_str);
    =====================================================
    \(
    printf("LEFT_PAREN :: '%s'\n", shm_str);
    =====================================================
    \)
    printf("RIGHT_PAREN :: '%s'\n", shm_str);
    =====================================================
    }
    printf("BLOCK_START :: '%s'\n", shm_str);
    =====================================================
    {
    printf("BLOCK_END :: '%s'\n", shm_str);
    =====================================================
