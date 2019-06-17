const addonExample = require("./build/Release/addon-example.node");
console.log(addonExample.hello());
module.exports = addonExample;