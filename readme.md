Live demo: https://timhutton.github.io/sdl-canvas-wasm/
See the compiled code on the gh-pages branch: https://github.com/timhutton/sdl-canvas-wasm/tree/gh-pages

Build index.js and index.wasm with Emscripten:

```emcc core.cpp -o index.js -s WASM=1```
