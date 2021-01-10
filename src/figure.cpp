//
// Created by Stepan on 09.01.2021.
//

#include <figure.h>

using namespace drawer;

color::color(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) {}

unsigned char color::get_r() const {
	return r;
}

void color::set_r(unsigned char r) {
	color::r = r;
}

unsigned char color::get_g() const {
	return g;
}

void color::set_g(unsigned char g) {
	color::g = g;
}

unsigned char color::get_b() const {
	return b;
}

void color::set_b(unsigned char b) {
	color::b = b;
}

rect::rect(int left, int top, int right, int bottom) : x(left), y(top), dim(right - left, bottom - top) {}

rect::rect(int x, int y, const drawer::dimension& d) : x(x), y(y), dim(d) {}

int rect::get_x() const {
	return x;
}

void rect::set_x(int x) {
	rect::x = x;
}

int rect::get_y() const {
	return y;
}

void rect::set_y(int y) {
	rect::y = y;
}

const dimension& rect::get_dim() const {
	return dim;
}

void rect::set_dim(const dimension& dim) {
	rect::dim = dim;
}

int rect::get_width() const {
	return dim.get_width();
}

int rect::get_height() const {
	return dim.get_height();
}

drawer::dimension::dimension(int width, int height) : width(width), height(height) {}

int dimension::get_width() const {
	return width;
}

void dimension::set_width(int width) {
	dimension::width = width;
}

int dimension::get_height() const {
	return height;
}

void dimension::set_height(int height) {
	dimension::height = height;
}
