/* jshint -W097 */// jshint strict:false
/*jslint node: true */
/*jshint expr: true*/
const expect = require('chai').expect;
const mbus = require('../index.js');

describe('Test mbus', function() {
    it('Test parse buffer', function () {
        var buf = Buffer.from('682f2f6808017201309616ac484216d60000000c1405000000046d0c0bab2b426c00004c140000000042ec7ec1210f40010100ea16', 'hex');
        const json = mbus.mbusParse(buf);
        const { MBusData } = JSON.parse(json);
        const { SlaveInformation, DataRecord } = MBusData;
        expect(SlaveInformation.Id).to.be.equal("16963001");
        expect(SlaveInformation.Medium).to.be.equal("Cold water");

        expect(DataRecord[0].Unit).to.be.equal("m^3")
        expect(DataRecord[0].Value).to.be.equal("0.050000")
    });
});
