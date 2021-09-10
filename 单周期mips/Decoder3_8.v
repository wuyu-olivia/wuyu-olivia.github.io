module Decoder3_8(num, sel);
    input  [2: 0] num;       // ����ܱ�ţ�0~7
    output reg [7:0] sel;       // 7�������Ƭѡ�źţ��͵�ƽ��Ч

    always @(num) begin
        case(num)
            3'd0: sel = 8'b11111110;
            3'd1: sel = 8'b11111101;
            3'd2: sel = 8'b11111011;
            3'd3: sel = 8'b11110111;
            3'd4: sel = 8'b11101111;
            3'd5: sel = 8'b11011111;
            3'd6: sel = 8'b10111111;
            3'd7: sel = 8'b01111111;
            default: sel = 8'b11111111;
        endcase
    end

endmodule
