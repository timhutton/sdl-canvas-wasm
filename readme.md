Live demo: https://timhutton.github.io/sdl-canvas-wasm/

(If you want more sophisticated drawing than SDL can offer (e.g. 3D), then you should probably start [here](https://github.com/timhutton/opengl-canvas-wasm) instead.) 

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

    Chrome doesn't support file:// XHR requests, so you need to first start a webserver, e.g.:

    with Python 2: ```python -m SimpleHTTPServer 8080```
    
    with Python 3: ```python -m http.server 8080```

    and then open this URL:

    http://localhost:8080/
    
MIT license:
----------------

```
Copyright (c) 2018 Tim Hutton

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
