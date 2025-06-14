#pragma once

#include <QQuickRhiItem>
#include <QVector>
#include "TextRenderer.h"
#include "TextFramebuffer.h"

namespace ui::textview::qml {

class TextView;

class QuickTextViewRenderer : public QQuickRhiItemRenderer
{
public:
    QuickTextViewRenderer() = default;

protected:
    void initialize(QRhiCommandBuffer *cb) override;
    void synchronize(QQuickRhiItem *item) override;
    void render(QRhiCommandBuffer *cb) override;

private:
    TextView *m_view = nullptr;
    QVector<ui::textview::RenderCell> m_cells;
    ui::textview::TextRenderer m_renderer;
};

} // namespace ui::textview::qml
