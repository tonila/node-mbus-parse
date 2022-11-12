var mbus = require('../index.js');

var buf = Buffer.from('682f2f6808017201309616ac484216d60000000c1405000000046d0c0bab2b426c00004c140000000042ec7ec1210f40010100ea16', 'hex');
const json = mbus.mbusParse(buf);

console.log(JSON.stringify(JSON.parse(json), null, 2));