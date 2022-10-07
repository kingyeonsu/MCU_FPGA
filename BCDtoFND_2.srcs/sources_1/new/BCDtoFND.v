`timescale 1ns / 1ps

module BCDtoFND(
    input [1:0] i_digitSelect,
    input [3:0] i_value,
    input i_en,

    output [3:0] o_digit,
    output [7:0] o_font
    );

    digitSelectDecoder dut_0(
        .i_digitSelect(i_digitSelect),
        .i_en(i_en),
        .o_digit(o_digit)
    );

    BCDtoFNDdecoder dut_1(
        .i_value(i_value),
        .i_en(i_en),
        .o_font(o_font)
    );

endmodule
