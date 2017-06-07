# cache-line
> Returns the current CPU cache line size in bytes

Useful when you need to work with systems programming (locks, threads, optimization etc.).

## Usage

Print the cache line size.

```js
const cacheLineSize = require('cache-line');

console.log("Cache Line is", cacheLineSize()); // 64 on my machine
```

## Platforms
Works on Linux and MacOS but not for Windows(feel free to PR).

## License

MIT © [Theo Despoudis](https://theodespoudis.com)