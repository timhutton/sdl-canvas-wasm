Live demo: https://timhutton.github.io/sdl-canvas-wasm/

Build with Emscripten:

```emcc core.cpp -s WASM=1 -s USE_SDL=2 -O3 -o index.js```

Then open index.html in a web browser.
