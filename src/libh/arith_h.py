#!/usr/bin/env python3

import sys

from util import ELIF, MAX, Appender, lutmacro, header

def ALTER(x):
    return ELIF(map(lambda n: (f'EQUAL(_MOD(r,{x}),{n})',chr(97+n)),range(x)))

h = Appender()

macros = h.section('macros')
helpers = h.section('helpers')

def lut(name, fn, *args):
    main, entry = lutmacro(name, fn, *args)
    macros.indirect(*main)
    for e in entry:
        helpers.define(*e)

div = (2,3,4,5,8,16,20,32,64,128)

lut('INC', lambda x: x+1, range(MAX))
lut('DEC', lambda x: x-1, range(1, MAX+1))
lut('MOD', lambda a, b: a % b, range(MAX), div)
lut('IDIV', lambda a, b: a // b, range(MAX), div)

#lut('MULT', lambda a, b: a * b, range(MAX), div)

h.macros('#define ODD(a) _MOD(a, 2)')
h.macros('#define EVEN(a) COMPL(_MOD(a, 2))')
h.macros('#define ODD_EVEN(r, a, b) IF_ELSE(_MOD(r, 2))(a, b)')
h.macros('#define EVEN_ODD(r, a, b) IF_ELSE(_MOD(r, 2))(b, a)')
h.macros('#define ALTER2(r, a, b) EVEN_ODD(r, a, b)')
h.macros('#define ALTER3(r, a, b, c) ' + ALTER(3))
h.macros('#define ALTER4(r, a, b, c, d) ' + ALTER(4))
#h.macros('#define MODX(a, b) EQUAL(MOD(a, b), DEC(b))')
#h.macros('#define MOD0(a, b) NOT(MOD(a, b))')

for i in range(5):
    h.compare.comparable(i)

h.print_all()
