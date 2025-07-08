#pragma once
#include <SDL3/SDL.h>

namespace fox {
	class Renderer {
	public:
		Renderer() = default;

		bool Initialize();
		void Shutdown();
		bool CreateWindow(const std::string& name, int width, int height);

		void Clear();
		void Present();

		void SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
		void DrawLine(float x1, float y1, float x2, float y2);
		void DrawPoint(float x1, float y1);

	private:
		SDL_Window* window{ nullptr };
		SDL_Renderer* renderer{ nullptr };
	};
};