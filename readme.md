Live demo: https://timhutton.github.io/sdl-canvas-wasm/

This branch has the compiled code present. See the source code alone on the [master branch](https://github.com/timhutton/sdl-canvas-wasm/tree/master).

Build index.js and index.wasm with Emscripten:

```emcc core.cpp -s WASM=1 -s USE_SDL=2 -O3 -o index.js```

Then open index.html in a web browser.
