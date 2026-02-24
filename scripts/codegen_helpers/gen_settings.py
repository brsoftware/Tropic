l: list[str] = []

lang: str = input("Lex: ")

def ends_with_number(str):
    ends_with: bool = False
    for i in range(48, 58):
        if str.endswith(chr(i)):
            if (not str[-2].isdigit()) and ("Set" in str):
                return False
            ends_with = True
    return ends_with

while True:
    inp: str = input(">>> ")
    if inp == "ok":
        break
    inp = inp.replace(" ", "")
    inp = inp.replace(",", "")
    inp = inp.replace("=", "")
    while ends_with_number(inp):
        inp = inp[:-1]
    l.append(inp)

modes = {
    "Color": ("QColor", "defaultColor"),
    "Fill": ("bool", "defaultEolFill"),
    "Font": ("QFont", "defaultFont"),
    "BgColor": ("QColor", "defaultPaper")
}

for mode in modes:
    print(f"{modes[mode][0]} TpLexer{lang}::{modes[mode][1]}(int style) const\n{{")
    print(f"    DEF_SETTINGS;")
    print()
    print(f"    switch (style)")
    print(f"    {{")
    print(f"    default:")
    print(f"        return GET_SETTINGS(\"Lexer/{lang}/{mode}/Universal\", {modes[mode][0]});")

    for i in l:
        print(f"    case {i}:")
        print(f"        return GET_SETTINGS(\"Lexer/{lang}/{mode}/{i}\", {modes[mode][0]});")

    print(f"    }}")
    print()
    print(f"    return TpGeneralLexer::{modes[mode][1]}(style);")
    print(f"}}")
    print()

print(); print(); print()

for i in l:
    print(f"    INIT_SETTINGS(\"Lexer/{lang}/Color/{'Universal' if 'Default' in i else i}\", defaultColorScheme->{i});")

for i in l:
    print(f"    INIT_SETTINGS(\"Lexer/{lang}/BgColor/{'Universal' if 'Default' in i else i}\", defaultColorScheme->Bg{i});")

print()

for i in l:
    print(f"    INIT_SETTINGS(\"Lexer/{lang}/Fill/{'Universal' if 'Default' in i else i}\", false);")

print()

for i in l:
    print(f"    INIT_SETTINGS(\"Lexer/{lang}/Font/{'Universal' if 'Default' in i else i}\", defaultFontScheme->{i});")

print(); print()

while True:
    ...


