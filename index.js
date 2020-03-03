'use strict'

const addon = require('bindings')('addon')

let res
res = addon.add(2, 3)
console.log(res)
res = addon.add(5, 7)
console.log(res)
res = addon.add(11, 13)
console.log(res)