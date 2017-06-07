/* eslint-disable required-modules */
'use strict';

exports.isWindows = process.platform === 'win32';
exports.isLinux = process.platform === 'linux';
exports.isOSX = process.platform === 'darwin';
exports.buildType = process.config.target_defaults.default_configuration;