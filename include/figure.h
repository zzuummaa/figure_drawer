#ifndef FIGURE_DRAWER_FIGURES_H
#define FIGURE_DRAWER_FIGURES_H

namespace drawer {

class figure {};

struct rect : public figure {
	int left;
	int right;
	int top;
	int bottom;
};

} // namespace figure_drawer

#endif //FIGURE_DRAWER_FIGURES_H
