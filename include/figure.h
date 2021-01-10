#ifndef FIGURE_DRAWER_FIGURES_H
#define FIGURE_DRAWER_FIGURES_H

namespace drawer {

class color {
	unsigned char r;
	unsigned char g;
	unsigned char b;

public:
	color(unsigned char r, unsigned char g, unsigned char b);

	unsigned char get_r() const;

	void set_r(unsigned char r);

	unsigned char get_g() const;

	void set_g(unsigned char g);

	unsigned char get_b() const;

	void set_b(unsigned char b);
};

class figure {};

class dimension {
	int width;
	int height;
public:
	dimension(int width, int height);

	int get_width() const;

	void set_width(int width);

	int get_height() const;

	void set_height(int height);
};

class rect : public figure {
	int x;
	int y;
	dimension dim;

public:
	rect(int left, int top, int right, int bottom);
	rect(int x, int y, const dimension& d);

	int get_x() const;

	void set_x(int x);

	int get_y() const;

	void set_y(int y);

	const dimension& get_dim() const;

	void set_dim(const dimension& dim);

	int get_width() const;

	int get_height() const;
};

} // namespace figure_drawer

#endif //FIGURE_DRAWER_FIGURES_H
