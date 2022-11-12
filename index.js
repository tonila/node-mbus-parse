/* jshint -W097 */
// jshint strict:true
/*jslint node: true */
/*jslint esversion: 6 */
'use strict';

const mbusBinding = require('bindings')('mbus');
const xmlParser = require('xml2json');

function mbusParse(buffer) {
    const xml = mbusBinding.mbus_parse(buffer);
    return xmlParser.toJson(xml);
}

module.exports.mbusParse = mbusParse;
