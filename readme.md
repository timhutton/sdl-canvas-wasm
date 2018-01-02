Live demo: https://timhutton.github.io/sdl-canvas-wasm/

----

Instructions:
-------------

1. Install Emscripten:

    http://emscripten.org

2. Clone this repo:

    ```git clone https://github.com/timhutton/sdl-canvas-wasm.git```
    
    ```cd sdl-canvas-wasm```
    
3. Build index.js and index.wasm:

    ```emcc core.cpp -s WASM=1 -s USE_SDL=2 -O3 -o index.js```

4. Open index.html in a web browser. You should see a moving blue square in a red square:

    ![image](https://user-images.githubusercontent.com/647092/34481732-a649fefa-efab-11e7-9fe3-aa0c9c870858.png)
