#pragma once

namespace wibe {

	class RenderContext
	{
	public:
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;
	private:
	};

}
