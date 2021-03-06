//`include "ctrl_encode_def.v"
`define ALU_NOP   4'b0000 
`define ALU_ADD   4'b0001
`define ALU_SUB   4'b0010 
`define ALU_AND   4'b0011
`define ALU_OR    4'b0100
`define ALU_SLT   4'b0101
`define ALU_SLTU  4'b0110
`define ALU_NOR   4'b0111
`define ALU_LUI   4'b1000
`define ALU_SLL   4'b1001
`define ALU_SRL   4'b1010

module alu(A, B, ALUOp, C, Zero);
           
   input  signed [31:0] A, B;
   input         [ 3:0]  ALUOp; 
   output signed [31:0] C;
   output Zero;
  
   reg [31:0] C;
   integer    i;
       
   always @( * ) begin
      case ( ALUOp )
          `ALU_NOP:  C = A;                          // NOP
          `ALU_ADD:  C = A + B;                      // ADD
          `ALU_SUB:  C = A - B;                      // SUB
          `ALU_AND:  C = A & B;                      // AND/ANDI
          `ALU_OR:   C = A | B;                      // OR/ORI
          `ALU_SLT:  C = (A < B) ? 32'd1 : 32'd0;    // SLT/SLTI
          `ALU_SLTU: C = ({1'b0, A} < {1'b0, B}) ? 32'd1 : 32'd0;
		   `ALU_NOR: C = ~(A | B);                    // NOR
		   `ALU_LUI: C = { B , 16'b0 };                   // LUI
		   `ALU_SLL: C = B << A ;                     // SLLV
		   `ALU_SRL: C = B >> A ;                     // SRLV
          default:   C = A;                          // Undefined
      endcase
   end // end always
   
   assign Zero = (C == 32'b0);

endmodule
    
