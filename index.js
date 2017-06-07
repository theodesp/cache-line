'use strict';
const common = require('./common');
const cacheLineSize = require(`./build/${common.buildType}/cacheLineSize`).cacheLineSize;

module.exports = () => {
  // TODO Handle Windows Platform
  return cacheLineSize();
};