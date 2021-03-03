#include "../include/FrameBuffer.hpp"

void Framebuffer::add(unsigned x, unsigned y, Color c) {
    this->buffer(x, y) = c;
}

png::image<png::rgb_pixel> Framebuffer::png() const {
	png::image<png::rgb_pixel> out(buffer.w, buffer.h);
	
	buffer.for_each([&](unsigned x, unsigned y) {
        Color c(buffer(x,y));
        c.clamp255();
        out[buffer.h - y - 1][x] = png::rgb_pixel(c.red, c.green, c.blue);
	});
	return out;
}

void Framebuffer::clear() {
	this->buffer.clear(Color(0,0,0,0));
}