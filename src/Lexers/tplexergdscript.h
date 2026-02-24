#ifndef TPLEXERGDSCRIPT_H
#define TPLEXERGDSCRIPT_H

#include <Lexers/TpFamilyPythonLexer>

TP_NAMESPACE

inline const char *lexerGDScriptKeyword1 =
"as and assert await break breakpoint class class_name const continue elif else enum extends for func if in is match "
"namespace not or pass preload return self signal static super trait var void while when yield INF NAN PI TAU";

inline const char *lexerGDScriptKeyword2 =
"null bool int float String StringName NodePath Vector2 Vector2i Rect2 Vector3 Vector3i Transform2D Plane Quaternion "
"AABB Basis Transform3D Color RID Object Array PackedByteArray PackedInt32Array PackedInt64Array PackedFloat32Array "
"PackedFloat64Array PackedStringArray PackedVector2Array PackedVector3Array PackedVector4Array PackedColorArray "
"Dictionary Signal Callable";

class TpLexerGDScript : public TpFamilyPythonLexer
{
    Q_OBJECT

public:
    TpLexerGDScript(QObject *parent = nullptr);

public:
    const char *language() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERGDSCRIPT_H
