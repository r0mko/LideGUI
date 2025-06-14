#pragma once

#include <QColor>

namespace ui::textview {

class FontLoader;

class TextAttributes
{
public:
    struct Data {
        QColor background;
        QColor color;
        QColor outlineColor;
        float outlineWidth = 0.f;
        FontLoader *font = nullptr;
    };

    TextAttributes();
    TextAttributes(const QColor &background,
                   const QColor &color,
                   const QColor &outlineColor,
                   float outlineWidth,
                   FontLoader *font);

    bool isValid() const;
    const Data &data() const;

private:
    const Data *m_data = nullptr;
    static const Data *get(const Data &data);
};

} // namespace ui::textview
