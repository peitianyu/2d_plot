#include "core/tt_test.h"
#include "plot/plot_manage.h"
#include <random>

JUST_RUN_TEST(plot_manage, test)
TEST(plot_manage, test)
{
    PlotManager plot(100, 100);
    plot.draw_line(0, 0, 1, 1, 0);
    plot.draw_rect(0, 0, 1, 1, 1).drawFill();
    plot.draw_circle(0, 0, 1, 2).drawFill();

    auto& line = plot.line(2);
    for(uint i = 0; i < 5; ++i) {
        plot.draw_point(line, i, i).toFrame(i);
    }

    // plot.show_legend(line, "label", 2, 1); // 标签放置到位置
    plot.write("plot_manage.svg");
}

// JUST_RUN_TEST(plot_grid, test2)
TEST(plot_grid, test2)
{
    PlotManager plot(100, 100);

    plot.draw_grid(5, 5, 1, 0);

    plot.draw_rect(0, 0, 1, 1, 2).drawFill();

    plot.write("grid.svg");
}
