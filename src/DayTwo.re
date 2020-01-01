/*
 Context:
     An Intcode program is a list of integers separated by commas (like 1,0,0,3,99).
     To run one, start by looking at the first integer (called position 0). Here, you will find an opcode -
     either 1, 2, or 99. The opcode indicates what to do; for example, 99 means that the program is finished
     and should immediately halt. Encountering an unknown opcode means something went wrong.
     Opcode 1 adds together numbers read from two positions and stores the result in a third position. The
     three integers immediately after the opcode tell you these three positions - the first two indicate
     the positions from which you should read the input values, and the third indicates the position at
     which the output should be stored.
     For example, if your Intcode computer encounters 1,10,20,30, it should read the values at positions
     10 and 20, add those values, and then overwrite the value at position 30 with their sum.
     Opcode 2 works exactly like opcode 1, except it multiplies the two inputs instead of adding them.
     Again, the three integers after the opcode indicate where the inputs and outputs are, not their values.
     Once you're done processing an opcode, move to the next one by stepping forward 4 positions.
 */
let opcodes = [|
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
  0,
|];

type operation =
  | Add
  | Multiply
  | Halt
  | Unknown;

let codeToOperation = (code: int) => {
  switch (code) {
  | 1 => Add
  | 2 => Multiply
  | 99 => Halt
  | _ => Unknown
  };
};

/*
 Once you have a working computer, the first step is to restore the gravity assist program (your puzzle input) to the
 "1202 program alarm" state it had just before the last computer caught fire. To do this, before running the program,
 replace position 1 with the value 12 and replace position 2 with the value 2.
 */
opcodes[1] = 12;
opcodes[2] = 2;

let halted = ref(false);

// There has to be a better way to do this without side effects 🤔
Array.mapi(
  (opcodeIdx, opcode) => {
    switch (opcodeIdx mod 4) {
    | 0 =>
      switch (codeToOperation(opcode)) {
      | Add =>
        let leftOperandIdx = opcodes[opcodeIdx + 1];
        let rightOperandIdx = opcodes[opcodeIdx + 2];
        let storeIdx = opcodes[opcodeIdx + 3];
        if (! halted^) {
          opcodes[storeIdx] =
            opcodes[leftOperandIdx] + opcodes[rightOperandIdx];
        };

        opcode;
      | Multiply =>
        let leftOperandIdx = opcodes[opcodeIdx + 1];
        let rightOperandIdx = opcodes[opcodeIdx + 2];
        let storeIdx = opcodes[opcodeIdx + 3];
        if (! halted^) {
          opcodes[storeIdx] =
            opcodes[leftOperandIdx] * opcodes[rightOperandIdx];
        };

        opcode;
      | Halt =>
        halted := true;
        opcode;
      | _ => opcode
      }
    | _ => opcode
    }
  },
  opcodes,
);

Js.log(opcodes);
