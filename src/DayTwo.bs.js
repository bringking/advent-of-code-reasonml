// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var Caml_array = require("bs-platform/lib/js/caml_array.js");
var Caml_int32 = require("bs-platform/lib/js/caml_int32.js");

var opcodes = /* array */[
  1,
  0,
  0,
  3,
  1,
  1,
  2,
  3,
  1,
  3,
  4,
  3,
  1,
  5,
  0,
  3,
  2,
  9,
  1,
  19,
  1,
  19,
  5,
  23,
  1,
  9,
  23,
  27,
  2,
  27,
  6,
  31,
  1,
  5,
  31,
  35,
  2,
  9,
  35,
  39,
  2,
  6,
  39,
  43,
  2,
  43,
  13,
  47,
  2,
  13,
  47,
  51,
  1,
  10,
  51,
  55,
  1,
  9,
  55,
  59,
  1,
  6,
  59,
  63,
  2,
  63,
  9,
  67,
  1,
  67,
  6,
  71,
  1,
  71,
  13,
  75,
  1,
  6,
  75,
  79,
  1,
  9,
  79,
  83,
  2,
  9,
  83,
  87,
  1,
  87,
  6,
  91,
  1,
  91,
  13,
  95,
  2,
  6,
  95,
  99,
  1,
  10,
  99,
  103,
  2,
  103,
  9,
  107,
  1,
  6,
  107,
  111,
  1,
  10,
  111,
  115,
  2,
  6,
  115,
  119,
  1,
  5,
  119,
  123,
  1,
  123,
  13,
  127,
  1,
  127,
  5,
  131,
  1,
  6,
  131,
  135,
  2,
  135,
  13,
  139,
  1,
  139,
  2,
  143,
  1,
  143,
  10,
  0,
  99,
  2,
  0,
  14,
  0
];

function codeToOperation(code) {
  var switcher = code - 1 | 0;
  if (switcher === 0 || switcher === 1) {
    if (switcher !== 0) {
      return /* Multiply */1;
    } else {
      return /* Add */0;
    }
  } else if (switcher !== 98) {
    return /* Unknown */3;
  } else {
    return /* Halt */2;
  }
}

Caml_array.caml_array_set(opcodes, 1, 12);

Caml_array.caml_array_set(opcodes, 2, 2);

var halted = {
  contents: false
};

$$Array.mapi((function (opcodeIdx, opcode) {
        var match = opcodeIdx % 4;
        if (match !== 0) {
          return opcode;
        } else {
          var match$1 = codeToOperation(opcode);
          switch (match$1) {
            case /* Add */0 :
                var leftOperandIdx = Caml_array.caml_array_get(opcodes, opcodeIdx + 1 | 0);
                var rightOperandIdx = Caml_array.caml_array_get(opcodes, opcodeIdx + 2 | 0);
                var storeIdx = Caml_array.caml_array_get(opcodes, opcodeIdx + 3 | 0);
                if (!halted.contents) {
                  Caml_array.caml_array_set(opcodes, storeIdx, Caml_array.caml_array_get(opcodes, leftOperandIdx) + Caml_array.caml_array_get(opcodes, rightOperandIdx) | 0);
                }
                return opcode;
            case /* Multiply */1 :
                var leftOperandIdx$1 = Caml_array.caml_array_get(opcodes, opcodeIdx + 1 | 0);
                var rightOperandIdx$1 = Caml_array.caml_array_get(opcodes, opcodeIdx + 2 | 0);
                var storeIdx$1 = Caml_array.caml_array_get(opcodes, opcodeIdx + 3 | 0);
                if (!halted.contents) {
                  Caml_array.caml_array_set(opcodes, storeIdx$1, Caml_int32.imul(Caml_array.caml_array_get(opcodes, leftOperandIdx$1), Caml_array.caml_array_get(opcodes, rightOperandIdx$1)));
                }
                return opcode;
            case /* Halt */2 :
                halted.contents = true;
                return opcode;
            case /* Unknown */3 :
                return opcode;
            
          }
        }
      }), opcodes);

console.log(opcodes);

exports.opcodes = opcodes;
exports.codeToOperation = codeToOperation;
exports.halted = halted;
/*  Not a pure module */
